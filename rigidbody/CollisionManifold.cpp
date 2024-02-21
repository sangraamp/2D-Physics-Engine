#include "CollisionManifold.h"

// Constructors
CollisionManifold::CollisionManifold() {
    this->depth = 0.0f;
    this->colliding = false;
}

CollisionManifold::CollisionManifold(const Vector2f& normal, float depth)
    : normal(normal.normalize()), depth(depth) {}

// Normal getter
const Vector2f& CollisionManifold::getNormal() const {
    return normal;
}

void CollisionManifold::addContactPoint(const Vector2f& contactPoint) {
    this->contactPoints.push_back(contactPoint);
}

// Contact points getter
const std::vector<Vector2f>& CollisionManifold::getContactPoints() const {
    return contactPoints;
}

// Depth getter
float CollisionManifold::getDepth() const {
    return depth;
}

bool CollisionManifold::isColliding() const {
    return this->colliding;
}
