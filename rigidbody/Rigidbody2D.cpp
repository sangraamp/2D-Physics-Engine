#include "../util/Vector2f.h"
#include "Rigidbody2D.h"

// Constructor definition
Rigidbody2D::Rigidbody2D() {
    // Optionally initialize members here
}

// Getter for position definition
const Vector2f& Rigidbody2D::getPosition() const {
    return position;
}

// Getter for rotation definition
float Rigidbody2D::getRotation() const {
    return rotation;
}

void Rigidbody2D::setTransform(const Vector2f& position, const float& rotation) {
    this->position = position;
    this->rotation = rotation;
}

void Rigidbody2D::setTransform(const Vector2f& position) {
    this->position = position;
}

bool Rigidbody2D::operator==(const Rigidbody2D& other) const {
    return (this->position == other.position) &&
           (this->rotation == other.rotation) &&
           (this->linearVelocity == other.linearVelocity) &&
           (this->angularVelocity == other.angularVelocity) &&
           (this->linearDamping == other.linearDamping) &&
           (this->angularDamping == other.angularDamping) &&
           (this->fixedRotation == other.fixedRotation);
}
