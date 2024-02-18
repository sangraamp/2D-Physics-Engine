#include "Box2D.h"
#include "../util/CMath.h"

Box2D::Box2D() {
    this->size = Vector2f();
    this->halfSize = Vector2f();
}

Box2D::Box2D(const Box2D& other) : size(other.size), halfSize(other.halfSize), rigidbody(other.rigidbody) {}

Box2D::Box2D(Vector2f min, Vector2f max) {
    this->size = max - min;
    this->halfSize = this->size * 0.5f;
}

Vector2f Box2D::getLocalMin() {
    return this->rigidbody.getPosition() - this->halfSize;
}

Vector2f Box2D::getLocalMax() {
    return this->rigidbody.getPosition() + this->halfSize;
}

Vector2f Box2D::getHalfSize() {
    return this->halfSize;
}

Rigidbody2D Box2D::getRigidbody() {
    return this->rigidbody;
}

Vector2f* Box2D::getVertices() {
    Vector2f min = this->getLocalMin();
    Vector2f max = this->getLocalMax();

    Vector2f* vertices = new Vector2f[4];
    vertices[0] = Vector2f(min.getX(), min.getY());
    vertices[1] = Vector2f(min.getX(), max.getY());
    vertices[2] = Vector2f(max.getX(), min.getY());
    vertices[3] = Vector2f(max.getX(), max.getY());

    if (!Math::compare(this->rigidbody.getRotation(), 0.0f)) {
        for (int i = 0; i < 4; ++i) {
            vertices[i] = Math::rotate(vertices[i], this->rigidbody.getPosition(), this->rigidbody.getRotation());
        }
    }

    return vertices;
}

void Box2D::setRigidbody(const Rigidbody2D& rb) {
    this->rigidbody = rb;
}

void Box2D::setSize(const Vector2f& size) {
    this->size = size;
    this->halfSize = size * 0.5f;
}
