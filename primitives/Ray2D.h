#ifndef RAY_2D_H
#define RAY_2D_H

#include "../util/Vector2f.h"

class Ray2D {
private:
    Vector2f origin;
    Vector2f direction; // This should be normalized always

public:
    Ray2D(Vector2f origin, Vector2f direction);

    Vector2f getOrigin();

    Vector2f getDirection();
};

#endif // RAY_2D_H
