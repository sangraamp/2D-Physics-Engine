#ifndef AABB_H
#define AABB_H

#include "../util/Vector2f.h"
#include "../rigidbody/Rigidbody2D.h"

class AABB {
private:
    Vector2f size;
    Vector2f halfSize;
    Rigidbody2D rigidbody;

public:
    AABB();
    AABB(Vector2f min, Vector2f max);
    Vector2f getMin();
    Vector2f getMax();
    Vector2f* getVertices();
    void setRigidbody(const Rigidbody2D& rb);
    void setSize(const Vector2f& size);
};

#endif // AABB_H
