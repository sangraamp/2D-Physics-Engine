#ifndef INTERSECTIONDETECTOR2D_H
#define INTERSECTIONDETECTOR2D_H

#include "../primitives/Line2D.h"
#include "../util/Vector2f.h"
#include "../primitives/Circle.h"
#include "../primitives/AABB.h"
#include "../primitives/Box2D.h"
#include "../primitives/Ray2D.h"
#include "../primitives/RaycastResult.h"
#include "../util/CMath.h"

class IntersectionDetector2D {
private:
    // Helper functions for AABB vs. Primitive tests
    // Gets the min and max coordinates (along the given axis) of an AABB. Axis should be normalized.
    static Vector2f getInterval(AABB &rect, Vector2f &axis);
    static Vector2f getInterval(Box2D &rect, Vector2f &axis);
    
    // Returns true if the two AABBs/Box2Ds overlap on the given axis. Makes use of getInterval. Axis should be normalized.
    static bool overlapOnAxis(AABB &b1, AABB &b2, Vector2f &axis);
    static bool overlapOnAxis(AABB &b1, Box2D &b2, Vector2f &axis);
    static bool overlapOnAxis(Box2D &b1, Box2D &b2, Vector2f &axis);
public:
    // Point vs Primitive tests
    static bool isPointOnLine(Vector2f point, Line2D line);
    static bool isPointInAABB(Vector2f point, AABB box);
    static bool isPointInBox2D(Vector2f point, Box2D box);
    static bool isPointInCircle(Vector2f point, Circle circle);

    // Line vs Primitive tests
    static bool lineAndCircle(Line2D line, Circle circle);
    static bool lineAndAABB(Line2D line, AABB box);
    static bool lineAndBox2D(Line2D line, Box2D box);

    // Raycasts
    static bool raycast(Circle circle, Ray2D ray, RaycastResult* result);
    static bool raycast(AABB box, Ray2D ray, RaycastResult* result);
    static bool raycast(Box2D box, Ray2D ray, RaycastResult* result);

    // Circle vs Primitive tests
    static bool circleAndLine(Circle &circle, Line2D &line);
    static bool circleAndCircle(Circle &c1, Circle &c2);
    static bool circleAndAABB(Circle &circle, AABB &box);
    static bool circleAndBox2D(Circle &circle, Box2D &box);

    // AABB vs Primitive tests
    static bool AABBAndCircle(AABB &box, Circle &circle);
    static bool AABBAndAABB(AABB &b1, AABB &b2);
    static bool AABBAndBox2D(AABB &b1, Box2D &b2);
};

#endif // INTERSECTIONDETECTOR2D_H