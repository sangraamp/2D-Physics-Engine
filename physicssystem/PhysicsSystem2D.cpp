#include <cmath>
#include "PhysicsSystem2D.h"
#include "../primitives/Collider2D.h"
#include "../rigidbody/Collisions.h"
#include "../util/CMath.h"

// Constructor definition
PhysicsSystem2D::PhysicsSystem2D(float fixedUpdateDt, Vector2f gravity) : gravity(gravity), fixedUpdateDt(fixedUpdateDt) {}

// Perform a fixed update
void PhysicsSystem2D::fixedUpdate() {
    this->bodies1.clear();
    this->bodies2.clear();
    this->collisions.clear();

    // Find any collisions
    // Can optimize this, but works for now
    for(int i=0; i<this->rigidbodies.size(); i++) {
        for(int j=i; j<this->rigidbodies.size(); j++) {
            if(i == j) continue;

            CollisionManifold* result = new CollisionManifold();
            Rigidbody2D* rb1(this->rigidbodies[i]);
            Rigidbody2D* rb2(this->rigidbodies[j]);
            Collider2D* c1 = rb1->getCollider();
            Collider2D* c2 = rb2->getCollider();
            
            if(c1 && c2 && !(rb1->hasInfiniteMass() && rb2->hasInfiniteMass())) {
                result = Collisions::findCollisionFeatures(c1, c2);
            }

            if(result && result->isColliding()) {
                this->bodies1.push_back(rb1);
                this->bodies2.push_back(rb2);
                this->collisions.push_back(result);
            }
        }
    }


    // Update forces
    forceRegistry.updateForces(this->fixedUpdateDt);

    // Resolve collisions using iterative impulse resolution
    // Iterate a certain amount of times to approximate the solution
    for(int k=0; k<this->impulseIterations; k++) {
        // One iteration
        for(int i=0; i<this->collisions.size(); i++) {
            int numContactPoints = this->collisions[i]->getContactPoints().size();
            for(int j=0; j<numContactPoints; j++) {
                // We add the bodies at the same time so the colliding bodies will be at the same index.
                Rigidbody2D* r1 = bodies1[i];
                Rigidbody2D* r2 = bodies2[i];
                _applyImpulse(r1, r2, collisions[i]);
            }
        }
    }

    // Update the velocities of all rigidbodies
    for(Rigidbody2D* body : this->rigidbodies) {
        body->physicsUpdate(this->fixedUpdateDt);
        // std::cout << "physicsSystem.update(): Position: " << body->getPosition() << '\n';
    }
}

void PhysicsSystem2D::_applyImpulse(Rigidbody2D* r1, Rigidbody2D* r2, CollisionManifold* cm) {
    // Solve for linear velocity
    float invMass1 = 1.0f / r1->getMass();
    float invMass2 = 1.0f / r1->getMass();
    float invMassSum = invMass1 + invMass2;

    // Return if we have two bodies with infinite mass
    if(Math::compare(invMassSum, 0.0f)) {
        return;
    }

    // Relative velocity
    Vector2f relativeVel = r2->getLinearVelocity() - r1->getLinearVelocity();
    // Relative normal (goes from r1 to r2)
    Vector2f relativeNormal = cm->getNormal();

    // Do nothing if bodies are moving away from each other
    if(relativeVel.dot(relativeNormal) > 0.0f) {
        return;
    }

    // Coefficient of restitution (just choose the smaller of the two, approximately correct for now)
    float e = std::min(r1->getCor(), r2->getCor());

    float impulseNumerator = -((1.0f + e) * relativeVel.dot(relativeNormal));
    // Impulse for the entire rigidbody
    float impulseMagnitude = impulseNumerator / invMassSum;

    // If multiple contact points, distribute impulse evenly across them (approximately realistic for this use case)
    if(cm->getContactPoints().size() > 0 && !Math::compare(impulseMagnitude, 0.0f)) {
        impulseMagnitude /= (float)cm->getContactPoints().size();
    }

    Vector2f impulse = relativeNormal * impulseMagnitude;
    r1->setLinearVelocity(r1->getLinearVelocity() + impulse * invMass1);
    r2->setLinearVelocity(r2->getLinearVelocity() - impulse * invMass2);
}

// Update function
void PhysicsSystem2D::update(float dt) {
    /*
    Ideally frames are supposed to be updated every 1/60th of a second
    or every 0.16ms. But sometimes it is 0.17, 0.14, 0.2, and so on. 
    This difference can accumulate and get considerably big, like 0.33ms,
    in which case we would have to make up for the difference by updating
    our physics twice so that it doesn't fall behind.
    */
   // For now, just calling fixedUpdate until we implement this:
   fixedUpdate();
}

// Add a rigidbody to the system
void PhysicsSystem2D::addRigidbody(Rigidbody2D* body, bool addGravity) {
    this->rigidbodies.push_back(body);
    if(addGravity) {
        // Register gravity
        this->forceRegistry.add(body, &gravity);
    }
}
