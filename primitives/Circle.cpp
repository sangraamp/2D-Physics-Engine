#include "Circle.h"

// Default constructor
Circle::Circle() : radius(0), rigidbody() {}

// Constructor with radius and Rigidbody2D
Circle::Circle(float radius, const Rigidbody2D& rigidbody) : radius(radius), rigidbody(rigidbody) {}

// Copy constructor
Circle::Circle(const Circle& other) : radius(other.radius), rigidbody(other.rigidbody) {}

// Assignment operator
Circle& Circle::operator=(const Circle& other) {
    if (this != &other) {
        radius = other.radius;
        rigidbody = other.rigidbody;
    }
    return *this;
}

// Destructor
Circle::~Circle() {}

// Getter for radius
float Circle::getRadius() const {
    return radius;
}

// Setter for radius
void Circle::setRadius(const float& radius) {
    this->radius = radius;
}

// Getter for center (position of the Rigidbody2D)
Vector2f Circle::getCenter() const {
    return rigidbody.getPosition();
}

// Setter for center
void Circle::setCenter(const Vector2f& center) {
    rigidbody.setTransform(center);
}

void Circle::setRigidbody(const Rigidbody2D& rb) {
    this->rigidbody = rb;
}
