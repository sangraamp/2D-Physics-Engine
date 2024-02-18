#ifndef FORCE_REGISTRATION_H
#define FORCE_REGISTRATION_H

#include "../rigidbody/Rigidbody2D.h"
#include "ForceGenerator.h"

class ForceRegistration {
private:
    ForceGenerator* fg;
    Rigidbody2D rb;

public:
    ForceRegistration(ForceGenerator* fg, Rigidbody2D rb);
    
    // Getters for fg and rb
    ForceGenerator* getForceGenerator() const;
    Rigidbody2D getRigidbody() const;
    
    // Define the equality comparison operator
    bool operator==(const ForceRegistration& other) const;
};

#endif // FORCE_REGISTRATION_H
