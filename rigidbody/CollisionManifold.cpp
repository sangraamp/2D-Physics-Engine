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

// Normal setter
void CollisionManifold::setNormal(const Vector2f& normal) {
    if(normal.magnitudeSquared() != 1.0f) {
        normal.normalize();
    }
    this->normal = normal;
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

// Depth setter
void CollisionManifold::setDepth(const float& depth) {
    this->depth = depth;
}

// Getter for: are the bodies colliding?
bool CollisionManifold::getColliding() const {
    return this->colliding;
}

// Setter for: are the bodies colliding?
void CollisionManifold::setColliding(const bool& colliding) {
    this->colliding = colliding;
}
