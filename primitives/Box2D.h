#ifndef BOX2D_H
#define BOX2D_H

#include "../util/Vector2f.h"
#include "../rigidbody/Rigidbody2D.h"

class Box2D {
private:
    Vector2f size;
    Vector2f halfSize;
    Rigidbody2D rigidbody;

public:
    Box2D();
    Box2D(const Box2D& other);
    Box2D(Vector2f min, Vector2f max);
    Vector2f getLocalMin();
    Vector2f getLocalMax();
    Vector2f getHalfSize();
    Rigidbody2D getRigidbody();
    // A Box2D is essentially stored as an AABB until this function is called which explicitly rotates the vertices.
    Vector2f* getVertices();
    void setRigidbody(const Rigidbody2D& rb);
    void setSize(const Vector2f& size);
};

#endif // BOX2D_H
