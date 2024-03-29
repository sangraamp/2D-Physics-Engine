#ifndef CIRCLE_H
#define CIRCLE_H

#include "../rigidbody/Rigidbody2D.h"
#include "../util/Vector2f.h"
#include "Collider2D.h"

class Circle : public Collider2D {
private:
    float radius;
    Rigidbody2D* rigidbody;

public:
    Circle();
    Circle(float radius, Rigidbody2D* rigidbody);
    Circle(const Circle& other);
    Circle& operator=(const Circle& other);
    virtual ~Circle() override;

    float getRadius() const;
    void setRadius(const float& radius);
    Vector2f getCenter() const;
    void setCenter(const Vector2f& center);
    void setRigidbody(Rigidbody2D* rb);
};

#endif // CIRCLE_H
