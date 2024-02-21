#ifndef COLLIDER2D_H
#define COLLIDER2D_H

#include "../components/Component.h"
#include "../util/Vector2f.h"

class Collider2D : public Component {
protected:
    Vector2f offset;

public:
    Collider2D();
    virtual ~Collider2D();

    const Vector2f& getOffset() const;
    void setOffset(const Vector2f& offset);

    // TODO: implement this
    // virtual float getInertiaTensor(float mass) const = 0; // Pure virtual function
};

#endif // COLLIDER2D_H
