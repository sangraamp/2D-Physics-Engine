#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H

#include "../util/Vector2f.h"
#include "../primitives/Collider2D.h"

class Rigidbody2D {
private:
    // Add a setter for this transform as well
    // Transform rawTransform; -> to integrate this with the game engine
    Vector2f position = Vector2f(0, 0);
    float rotation = 0.0f;
    Vector2f linearVelocity = Vector2f(0, 0);
    float angularVelocity = 0.0f;
    float linearDamping = 0.0f;
    float angularDamping = 0.0f;
    bool fixedRotation = false;
    float mass = 0.0f;
    float inverseMass = 0.0f;
    // Will store the sum of all the forces acting on this body at any time
    Vector2f forceAccumulator;
    Collider2D* collider;

    // Coefficient of restitution
    float e = 1.0f;

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

    // Getter and setter for mass
    float getMass();

    void setMass(const float& mass);

    void physicsUpdate(float dt);

    void clearAccumulators();

    void syncCollisionTransforms();

    void addForce(const Vector2f& force);

    bool hasInfiniteMass();

    void setCollider(Collider2D* collider);

    Collider2D* getCollider() const;

    Vector2f getLinearVelocity() const;

    void setLinearVelocity(const Vector2f& linearVelocity);

    // Getter for coefficient of restitution
    float getCor() const;

    // Setter for coefficient of restitution
    void setCor(const float& e);
};

#endif // RIGIDBODY2D_H
