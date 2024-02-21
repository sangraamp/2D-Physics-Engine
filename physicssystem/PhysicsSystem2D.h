#pragma once

#include <vector>
#include "../forces/ForceRegistry.h"
#include "../rigidbody/Rigidbody2D.h"
#include "../forces/Gravity2D.h"
#include "../rigidbody/CollisionManifold.h"

class PhysicsSystem2D {
private:
    ForceRegistry forceRegistry;
    Gravity2D gravity;

    std::vector<Rigidbody2D*> rigidbodies;

    // For collisions
    std::vector<Rigidbody2D*> bodies1;
    std::vector<Rigidbody2D*> bodies2;
    std::vector<CollisionManifold*> collisions;

    // Fixed dt
    float fixedUpdateDt;

    const static int impulseIterations = 6;

    void _applyImpulse(Rigidbody2D* r1, Rigidbody2D* r2, CollisionManifold* cm);

public:
    // Constructor
    PhysicsSystem2D(float fixedUpdateDt, Vector2f gravity);

    // Perform a fixed update
    void fixedUpdate();

    // Update function
    void update(float dt);

    // Add a rigidbody to the system
    void addRigidbody(Rigidbody2D* body, bool addGravity);
};
