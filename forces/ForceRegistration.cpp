#include "ForceRegistration.h"
#include <typeinfo>

ForceRegistration::ForceRegistration(ForceGenerator* fg, Rigidbody2D rb) {
    this->fg = fg;
    this->rb = rb;
}

ForceGenerator* ForceRegistration::getForceGenerator() const {
    return fg;
}

Rigidbody2D ForceRegistration::getRigidbody() const {
    return rb;
}

bool ForceRegistration::operator==(const ForceRegistration& other) const {
    if (!&other) return false;
    if (typeid(other) != typeid(ForceRegistration)) return false;
    return (this->fg == other.fg) && (this->rb == other.rb);
}
