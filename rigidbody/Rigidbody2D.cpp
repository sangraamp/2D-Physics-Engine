#include "../util/Vector2f.h"
#include "Rigidbody2D.h"

// Constructor definition
Rigidbody2D::Rigidbody2D() {
    // Optionally initialize members here
}

// Getter for position definition
const Vector2f& Rigidbody2D::getPosition() const {
    return this->position;
}

// Getter for rotation definition
float Rigidbody2D::getRotation() const {
    return this->rotation;
}

// Setter for position and rotation
void Rigidbody2D::setTransform(const Vector2f& position, const float& rotation) {
    this->position = position;
    this->rotation = rotation;
}

// Setter for position
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

// Getter and setter for mass
float Rigidbody2D::getMass() {
    return this->mass;
}

void Rigidbody2D::setMass(const float& mass) {
    this->mass = mass;
    if(this->mass != 0.0f) {
        this->inverseMass = 1.0f / this->mass;
    }
}

void Rigidbody2D::physicsUpdate(float dt) {
    if(this->mass == 0.0f) return;
    Vector2f acceleration = this->forceAccumulator * this->inverseMass;
    this->linearVelocity += acceleration * dt;
    this->position += this->linearVelocity * dt;
    // std::cout << "Acceleration: " << acceleration << ", Linear Velocity: " << this->linearVelocity << ", Position: " << this->position << '\n';

    syncCollisionTransforms();
    clearAccumulators();
}

void Rigidbody2D::clearAccumulators() {
    forceAccumulator.zero();
}

void Rigidbody2D::syncCollisionTransforms() {
    // if(this->rawTransform != NULL) {
    //     this->rawTransform.position.set(this->position);
    // }
}

void Rigidbody2D::addForce(const Vector2f& force) {
    this->forceAccumulator += force;
}

bool Rigidbody2D::hasInfiniteMass() {
    return this->mass == 0.0f;
}

void Rigidbody2D::setCollider(Collider2D* collider) {
    this->collider = collider;
}

Collider2D* Rigidbody2D::getCollider() const {
    return this->collider;
}

Vector2f Rigidbody2D::getLinearVelocity() const {
    return this->linearVelocity;
}

void Rigidbody2D::setLinearVelocity(const Vector2f& linearVelocity) {
    this->linearVelocity = linearVelocity;
}

float Rigidbody2D::getCor() const {
    return this->e;
}

void Rigidbody2D::setCor(const float& e) {
    this->e = e;
}
