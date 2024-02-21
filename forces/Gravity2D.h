#ifndef GRAVITY2D_H
#define GRAVITY2D_H

#include "ForceGenerator.h"
#include "../rigidbody/Rigidbody2D.h"
#include "../util/Vector2f.h"

class Gravity2D : public ForceGenerator {
private:
    Vector2f gravity;

public:
    Gravity2D(const Vector2f &force);
    void updateForce(Rigidbody2D* body, float dt) override;
};

#endif // GRAVITY2D_H
