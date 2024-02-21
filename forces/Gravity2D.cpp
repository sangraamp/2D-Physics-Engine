#include "Gravity2D.h"

Gravity2D::Gravity2D(const Vector2f &force) : gravity(force) {}

void Gravity2D::updateForce(Rigidbody2D* body, float dt) {
    body->addForce(this->gravity * body->getMass());
}
