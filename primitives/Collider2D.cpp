#include "Collider2D.h"

Collider2D::Collider2D() : offset(0.0f, 0.0f) {}

Collider2D::~Collider2D() {}

const Vector2f& Collider2D::getOffset() const {
    return this->offset;
}

void Collider2D::setOffset(const Vector2f& offset) {
    this->offset = offset;
}
