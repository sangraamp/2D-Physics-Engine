#pragma once

#include "../rigidbody/Rigidbody2D.h"

// Interface
class ForceGenerator {
public:
    /*
    In C++, when you inherit from a base class and override
    its virtual functions, it's essential to mark the base 
    class destructor as virtual as well. This ensures that 
    when you delete an object through a pointer to its base class, 
    the appropriate derived class destructor is called.
    */
    virtual ~ForceGenerator() {} // Virtual destructor
    virtual void updateForce(Rigidbody2D* body, float dt) = 0;
};