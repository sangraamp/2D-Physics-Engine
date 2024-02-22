#pragma once

#include "../util/Vector2f.h"
#include <vector>

class CollisionManifold {
private:
    Vector2f normal; // Collision normal
    std::vector<Vector2f> contactPoints; // Collision contact points
    float depth; // Depth of the collision
    bool colliding; // Are the bodies colliding?

public:
    // Constructors
    CollisionManifold();

    CollisionManifold(const Vector2f& normal, float depth);

    void addContactPoint(const Vector2f& contactPoint);

    // Normal getter
    const Vector2f& getNormal() const;

    // Normal setter
    void setNormal(const Vector2f& normal);

    // Contact points getter
    const std::vector<Vector2f>& getContactPoints() const;

    // Depth getter
    float getDepth() const;

    // Depth setter
    void setDepth(const float& depth);

    // Getter for: are the bodies colliding?
    bool getColliding() const;

    // Setter for: are the bodies colliding?
    void setColliding(const bool& colliding);
};
