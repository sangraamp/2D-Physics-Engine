#include "Vector2f.h"

// Constructors
Vector2f::Vector2f() : x(0.0f), y(0.0f) {}
Vector2f::Vector2f(float x, float y) : x(x), y(y) {}

// Copy constructor
Vector2f::Vector2f(const Vector2f& other) : x(other.x), y(other.y) {}

// Assignment operator
Vector2f& Vector2f::operator=(const Vector2f& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Getters and setters
float Vector2f::getX() const { return x; }
float Vector2f::getY() const { return y; }
void Vector2f::setX(float x) { this->x = x; }
void Vector2f::setY(float y) { this->y = y; }

// Addition
Vector2f Vector2f::operator+(const Vector2f& other) const {
    return Vector2f(x + other.x, y + other.y);
}

// Subtraction
Vector2f Vector2f::operator-(const Vector2f& other) const {
    return Vector2f(x - other.x, y - other.y);
}

// Element wise multiplication
Vector2f Vector2f::operator*(const Vector2f &other) const {
    return Vector2f(x * other.x, y * other.y);
}

// Scalar multiplication
Vector2f Vector2f::operator*(float scalar) const {
    return Vector2f(x * scalar, y * scalar);
}

// Dot product
float Vector2f::dot(const Vector2f& other) const {
    return x * other.x + y * other.y;
}

// Magnitude (length) of the vector
float Vector2f::magnitude() const {
    return std::sqrt(x * x + y * y);
}

// Magnitude of the vector squared
float Vector2f::magnitudeSquared() const {
    return x * x + y * y;
}

// Normalization (produces a unit vector)
Vector2f Vector2f::normalize() const {
    float mag = magnitude();
    if (mag != 0) {
        return *this * (1.0f / mag);
    }
    return Vector2f(0, 0); // Avoid division by zero
}

// ToString method
std::ostream& operator<<(std::ostream& os, const Vector2f& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

// Equality check
bool Vector2f::operator==(const Vector2f& other) const {
    return (this->x == other.x) && (this->y == other.y);
}

// Addition assignment
Vector2f& Vector2f::operator+=(const Vector2f& other) {
    x += other.x;
    y += other.y;
    return *this;
}

// Zero method
void Vector2f::zero() {
    x = 0.0f;
    y = 0.0f;
}
