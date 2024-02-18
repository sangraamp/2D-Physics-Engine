#include "../rigidbody/Rigidbody2D.h"

// Interface
class ForceGenerator {
    virtual void updateForce(Rigidbody2D body, float dt) = 0;
};