#include <cassert>
#include <iostream>
#include "Collisions.h"

CollisionManifold* Collisions::findCollisionFeatures(Collider2D* c1, Collider2D* c2) {
    // Check if both c1 and c2 are Circles
    if (Circle* circle1 = dynamic_cast<Circle*>(c1)) {
        if (Circle* circle2 = dynamic_cast<Circle*>(c2)) {
            return findCollisionFeatures(circle1, circle2);
        }
    }

    std::cerr << "At least one of the Collider2D*s is not a circle in findCollisionFeatures().\n";
    assert(false);
    return nullptr;
}

CollisionManifold* Collisions::findCollisionFeatures(Circle* a, Circle* b) {
    CollisionManifold* result = new CollisionManifold();
    float sumRadii = a->getRadius() + b->getRadius();
    Vector2f distance = b->getCenter() - a->getCenter();
    // Return if not colliding
    if (distance.magnitudeSquared() > sumRadii * sumRadii) {
        return result;
    }

    // If we're here, then the bodies are colliding.
    // Multiply by 0.5 because we want to separate each circle by the 
    // same amount. Consider updating to factor in momentum.
    float depth = (sumRadii - distance.magnitude()) * 0.5;
    Vector2f collisionNormal = distance;
    collisionNormal.normalize();

    float distanceApproxFromCenterToContactPoint = a->getRadius() - depth;
    Vector2f contactPoint = a->getCenter() + collisionNormal * distanceApproxFromCenterToContactPoint;
    result->addContactPoint(contactPoint);
    result->setColliding(true);
    result->setNormal(collisionNormal);
    result->setDepth(depth);

    return result;
}
