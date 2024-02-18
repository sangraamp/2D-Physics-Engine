#ifndef FORCE_REGISTRY_H
#define FORCE_REGISTRY_H

#include <vector>
#include "ForceRegistration.h"
#include "ForceGenerator.h"
#include "../rigidbody/Rigidbody2D.h"

class ForceRegistry {
private:
    std::vector<ForceRegistration> registry; 

public:
    ForceRegistry();
    void add(Rigidbody2D rb, ForceGenerator* fg);
    void remove(Rigidbody2D rb, ForceGenerator* fg);
    void clear();
    void updateForces(float dt);
    void zeroForces();
};

#endif // FORCE_REGISTRY_H
