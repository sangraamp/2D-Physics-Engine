#ifndef VECTOR2F_H
#define VECTOR2F_H

#include <iostream>
#include <cmath>

class Vector2f {
public:
    // Constructors
    Vector2f();
    Vector2f(float x, float y);

    // Copy constructor
    Vector2f(const Vector2f& other);

    // Assignment operator
    Vector2f& operator=(const Vector2f& other);

    // Getters and setters
    float getX() const;
    float getY() const;
    void setX(float x);
    void setY(float y);

    // Addition
    Vector2f operator+(const Vector2f& other) const;

    // Subtraction
    Vector2f operator-(const Vector2f& other) const;

    // Element wise multiplication
    Vector2f operator*(const Vector2f& other) const;

    // Scalar multiplication
    Vector2f operator*(float scalar) const;

    // Dot product
    float dot(const Vector2f& other) const;

    // Magnitude (length) of the vector
    float magnitude() const;

    // Magnitude squared of the vector
    float magnitudeSquared() const;

    // Normalization (produces a unit vector)
    Vector2f normalize() const;

    // ToString method
    friend std::ostream& operator<<(std::ostream& os, const Vector2f& vec);

    bool operator==(const Vector2f& other) const; // Declaration of == operator

    Vector2f& operator+=(const Vector2f& other);

    // Zero method
    void zero();
private:
    float x;
    float y;
};

#endif // VECTOR2F_H
