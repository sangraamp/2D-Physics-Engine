#ifndef CIRCLE_H
#define CIRCLE_H

#include "../rigidbody/Rigidbody2D.h"
#include "../util/Vector2f.h"

class Circle {
private:
    float radius;
    Rigidbody2D rigidbody;

public:
    Circle();
    Circle(float radius, const Rigidbody2D& rigidbody);
    Circle(const Circle& other);
    Circle& operator=(const Circle& other);
    ~Circle();

    float getRadius() const;
    void setRadius(const float& radius);
    Vector2f getCenter() const;
    void setCenter(const Vector2f& center);
    void setRigidbody(const Rigidbody2D& rb);
};

#endif // CIRCLE_H
