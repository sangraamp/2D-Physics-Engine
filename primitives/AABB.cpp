#include "AABB.h"

AABB::AABB() {
    // Initialize size and halfSize with default constructor of Vector2f
    this->size = Vector2f();
    this->halfSize = Vector2f();
}

AABB::AABB(Vector2f min, Vector2f max) {
    this->size = max - min;
    this->halfSize = this->size * 0.5f;
}

Vector2f AABB::getMin() {
    return this->rigidbody.getPosition() - this->halfSize;
}

Vector2f AABB::getMax() {
    return this->rigidbody.getPosition() + this->halfSize;
}

Vector2f* AABB::getVertices() {
    Vector2f boxMin = this->getMin();
    Vector2f boxMax = this->getMax();
    Vector2f vertices[] = {
        Vector2f(boxMin.getX(), boxMin.getY()),
        Vector2f(boxMin.getX(), boxMax.getY()),
        Vector2f(boxMax.getX(), boxMin.getY()),
        Vector2f(boxMax.getX(), boxMax.getY())
    };
    return vertices;
}

void AABB::setRigidbody(const Rigidbody2D& rb) {
    this->rigidbody = rb;
}

void AABB::setSize(const Vector2f& size) {
    this->size = size;
    this->halfSize = size * 0.5f;
}
