#include "Ray2D.h"

Ray2D::Ray2D(Vector2f origin, Vector2f direction) {
    this->origin = origin;
    if(direction.magnitudeSquared() != 1) {
        direction.normalize();
    }
    this->direction = direction;
}

Vector2f Ray2D::getOrigin() {
    return this->origin;
}

Vector2f Ray2D::getDirection() {
    return this->direction;
}
