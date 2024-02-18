#ifndef RAYCAST_RESULT_H
#define RAYCAST_RESULT_H

#include "../util/Vector2f.h"

class RaycastResult {
private:
    // Point at which the Ray2D intersects the primitive
    Vector2f point;
    // The direction in which it is bouncing off of the primitive
    Vector2f normal;
    // The length along the Ray2D from the origin to the point of intersection
    float t;
    // Did the Ray2D hit the primitive?
    bool hit;

public:
    RaycastResult();

    void init(Vector2f point, Vector2f normal, float t, bool hit);

    static void reset(RaycastResult* result);
};

#endif // RAYCAST_RESULT_H
