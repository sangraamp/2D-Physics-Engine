#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H

#include "../util/Vector2f.h"

class Rigidbody2D {
private:
    Vector2f position = Vector2f(0, 0);
    float rotation = 0.0f;
    Vector2f linearVelocity = Vector2f(0, 0);
    float angularVelocity = 0.0f;
    float linearDamping = 0.0f;
    float angularDamping = 0.0f;
    bool fixedRotation = false;

public:
    // Constructor
    Rigidbody2D(); // Declaration only

    // Getter for position
    const Vector2f& getPosition() const;

    // Setter for position and rotation
    void setTransform(const Vector2f& position, const float& rotation);

    // Setter for position
    void setTransform(const Vector2f& position);

    // Getter for rotation
    float getRotation() const;

    // Equality comparison operator
    bool operator==(const Rigidbody2D& other) const; 
};

#endif // RIGIDBODY2D_H
