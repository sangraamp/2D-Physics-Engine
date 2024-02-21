#include "ForceRegistry.h"
#include <algorithm>

ForceRegistry::ForceRegistry() {
    this->registry = std::vector<ForceRegistration>();
}

void ForceRegistry::add(Rigidbody2D* rb, ForceGenerator* fg) {
    registry.push_back(ForceRegistration(fg, rb));
}

void ForceRegistry::remove(Rigidbody2D* rb, ForceGenerator* fg) {
    auto it = std::find(registry.begin(), registry.end(), ForceRegistration(fg, rb));
    if (it != registry.end()) {
        registry.erase(it);
    }
}

void ForceRegistry::clear() {
    registry.clear();
}

void ForceRegistry::updateForces(float dt) {
    for(ForceRegistration fr: registry) {
        fr.getForceGenerator()->updateForce(fr.getRigidbody(), dt);
    }
}

void ForceRegistry::zeroForces() {
    for(ForceRegistration fr: registry) {
        // TODO
        // fr.getRigidbody().zeroForces();
    }
}
