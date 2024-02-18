#include "IntersectionDetector2D.h"

bool IntersectionDetector2D::isPointOnLine(Vector2f point, Line2D line) {
    // y = mx + c; m = (dy / dx)
    float dy = line.getEnd().getY() - line.getStart().getY();
    float dx = line.getEnd().getX() - line.getStart().getX();
    // Vertical line
    if(dx == 0.0f) {
        return Math::compare(point.getX(), line.getEnd().getX());
    } 

    float c = line.getEnd().getY() - (dy / dx) * line.getEnd().getX();

    return point.getY() == (dy / dx) * point.getX() + c;
}

bool IntersectionDetector2D::isPointInAABB(Vector2f point, AABB box) {
    return point.getX() <= box.getMax().getX() && box.getMin().getX() <= point.getX()
            && point.getY() <= box.getMax().getY() && box.getMin().getY() <= point.getY();
}

bool IntersectionDetector2D::isPointInBox2D(Vector2f point, Box2D box) {
    Vector2f pointInLocalBoxSpace = Math::rotate(point, box.getRigidbody().getPosition(), box.getRigidbody().getRotation());
    return pointInLocalBoxSpace.getX() <= box.getLocalMax().getX() && box.getLocalMin().getX() <= pointInLocalBoxSpace.getX()
            && pointInLocalBoxSpace.getY() <= box.getLocalMax().getY() && box.getLocalMin().getY() <= pointInLocalBoxSpace.getY();
}

bool IntersectionDetector2D::isPointInCircle(Vector2f point, Circle circle) {
    Vector2f circleCenter = circle.getCenter();
    Vector2f centerToPoint = point - circleCenter;

    return circle.getRadius() * circle.getRadius() > centerToPoint.magnitudeSquared();
}

bool IntersectionDetector2D::lineAndCircle(Line2D line, Circle circle) {
    Vector2f ab = line.getEnd() - line.getStart();

    // Project point (circle center) onto ab (line segment)
    // to get a parameterized position t
    Vector2f circleCenter = circle.getCenter();
    Vector2f centerToLineStart = circleCenter - line.getStart();
    float t = centerToLineStart.dot(ab) / ab.dot(ab);

    // It should be on the line segment ab
    if(t < 0.0f || t > 1.0f) {
        return false;
    }

    // Find the point on the line segment closest to the circle center
    Vector2f closestPoint = line.getStart() + ab * t;

    return isPointInCircle(closestPoint, circle);
}

bool IntersectionDetector2D::lineAndAABB(Line2D line, AABB box) {
    if(isPointInAABB(line.getStart(), box) || isPointInAABB(line.getEnd(), box)) {
        return true;
    }

    Vector2f unitVector = line.getEnd() - line.getStart();
    unitVector.normalize();
    
    // Way of dealing with division by zero
    float newX = (unitVector.getX() != 0) ? 1.0f / unitVector.getX() : 0.0f;
    float newY = (unitVector.getY() != 0) ? 1.0f / unitVector.getY() : 0.0f;
    unitVector.setX(newX);
    unitVector.setY(newY);

    Vector2f minV = (box.getMin() - line.getStart()) * unitVector;
    Vector2f maxV = (box.getMax() - line.getStart()) * unitVector;

    // Get the length along the line segment of the 1st and 2nd points of intersection
    float tmin = std::max(std::min(minV.getX(), maxV.getX()), std::min(minV.getY(), maxV.getY()));
    float tmax = std::min(std::max(minV.getX(), maxV.getX()), std::max(minV.getY(), maxV.getY()));

    if(tmax < 0 || tmin > tmax) {
        return false;
    }

    float t = (tmin < 0) ? tmax : tmin;
    return t > 0.0f && t * t < line.lengthSquared();
}

bool IntersectionDetector2D::lineAndBox2D(Line2D line, Box2D box) {
    // Just bring the line to the box's local space then call the above function as it essentially becomes a lineAndAABB problem.
    float theta = box.getRigidbody().getRotation();
    Vector2f center = box.getRigidbody().getPosition();

    Vector2f localStart = Math::rotate(line.getStart(), center, theta);
    Vector2f localEnd = Math::rotate(line.getEnd(), center, theta);

    Line2D localLine(localStart, localEnd);
    AABB aabb(box.getLocalMin(), box.getLocalMax());

    return lineAndAABB(localLine, aabb);
}

bool IntersectionDetector2D::raycast(Circle circle, Ray2D ray, RaycastResult* result) {
    RaycastResult().reset(result);
    Vector2f originToCircleCenter = circle.getCenter() - ray.getOrigin();
    float radiusSquared = circle.getRadius() * circle.getRadius();
    
    // Project the vector from the ray origin to circle center onto the direction of the ray
    // Length (along the ray) from the origin of the ray to the other end of the projection
    float a = originToCircleCenter.dot(ray.getDirection());
    // The third side of the triangle whose other sides are originToCircleCenter and a
    float bSquared = originToCircleCenter.magnitudeSquared() - a * a;

    if(radiusSquared - bSquared < 0.0f) {
        return false;
    }

    float f = (float)std::sqrt(radiusSquared - bSquared);
    float t = 0;

    // Checking if ray starts inside the circle
    if(originToCircleCenter.magnitudeSquared() < radiusSquared) {
        t = a + f;
    } else {
        t = a - f;
    }

    // The intersection can't be behind the origin of the ray
    if(t < 0) return false;

    if(result != NULL) {
        // The point at which the ray hits the circle
        Vector2f point = ray.getOrigin() + ray.getDirection() * t;
        // The direction in which the ray goes after hitting the circle
        Vector2f normal = point - circle.getCenter();
        if(normal.magnitudeSquared() != 1) {
            normal.normalize();
        }
        result->init(point, normal, t, true);
    }

    return true;
}

bool IntersectionDetector2D::raycast(AABB box, Ray2D ray, RaycastResult* result) {
    RaycastResult().reset(result);
    Vector2f unitVector = ray.getDirection();
    
    // Way of dealing with division by zero
    float newX = (unitVector.getX() != 0) ? 1.0f / unitVector.getX() : 0.0f;
    float newY = (unitVector.getY() != 0) ? 1.0f / unitVector.getY() : 0.0f;
    unitVector.setX(newX);
    unitVector.setY(newY);

    Vector2f minV = (box.getMin() - ray.getOrigin()) * unitVector;
    Vector2f maxV = (box.getMax() - ray.getOrigin()) * unitVector;

    // Get the length along the line segment of the 1st and 2nd points of intersection
    float tmin = std::max(std::min(minV.getX(), maxV.getX()), std::min(minV.getY(), maxV.getY()));
    float tmax = std::min(std::max(minV.getX(), maxV.getX()), std::max(minV.getY(), maxV.getY()));

    if(tmax < 0 || tmin > tmax) {
        return false;
    }

    float t = (tmin < 0) ? tmax : tmin;
    bool hit = t > 0.0f; // && t * t < ray.getMaximum();
    if(!hit) {
        return false;
    }

    if(result != NULL) {
        Vector2f point = ray.getOrigin() + ray.getDirection() * t;
        // Normal will be exactly opposite to the direction of point
        Vector2f normal = ray.getOrigin() - point;
        if(normal.magnitudeSquared() != 1) {
            normal.normalize();
        }

        result->init(point, normal, t, hit);
    }

    return true;
}

bool IntersectionDetector2D::raycast(Box2D box, Ray2D ray, RaycastResult* result) {
    RaycastResult().reset(result);

    Vector2f xAxis(1, 0);
    Vector2f yAxis(0, 1);
    Vector2f origin(0, 0);
    xAxis = Math::rotate(xAxis, origin, -box.getRigidbody().getRotation());
    yAxis = Math::rotate(yAxis, origin, -box.getRigidbody().getRotation());

    // Here we use p, a vector from the origin of the ray to the center of the box
    Vector2f p = box.getRigidbody().getPosition() - ray.getOrigin();

    // Project the direction of the ray onto each axis of the box
    Vector2f f(xAxis.dot(ray.getDirection()), yAxis.dot(ray.getDirection()));

    // Next, project p onto the x and y axes
    Vector2f e(xAxis.dot(p), yAxis.dot(p));

    // minX, maxX, minY, maxY
    float tArr[] = {0, 0, 0, 0};

    // Loop over the x and y axes
    for(int i=0; i<2; i++) {
        // Component of f in the direction of the other axis
        float fCompPrime = (i == 0) ? f.getY() : f.getX();
        // Component of f in the direction of the current axis
        float fComp = (i == 0) ? f.getX() : f.getY();
        // Component of e in the direction of the current axis
        float eComp = (i == 0) ? e.getX() : e.getY();
        if(Math::compare(fCompPrime, 0)) {
            // If the ray is parallel to the current axis and the origin of the ray is not inside the box, then we have no hit
            if(eComp * eComp > box.getHalfSize().magnitudeSquared()) {
                // No hit
                return false;
            }
            
            // Set fCompPrime to a really small value to avoid division by zero
            (i == 0) ? f.setY(0.00001f) : f.setX(0.00001f);
        }

        // Component of the box half size in the direction of the current axis
        float boxHalfsizeComp = (i == 0) ? box.getHalfSize().getX() : box.getHalfSize().getY();
        tArr[i * 2 + 0] = (eComp + boxHalfsizeComp) / fComp; // tmax for this axis
        tArr[i * 2 + 1] = (eComp - boxHalfsizeComp) / fComp; // tmin for this axis
    }

    float tmin = std::max(std::min(tArr[0], tArr[1]), std::min(tArr[2], tArr[3]));
    float tmax = std::min(std::max(tArr[0], tArr[1]), std::max(tArr[2], tArr[3]));

    if(tmax < 0 || tmin > tmax) {
        return false;
    }

    float t = (tmin < 0) ? tmax : tmin;
    bool hit = t > 0.0f; // && t * t < ray.getMaximum();
    if(!hit) {
        return false;
    }

    if(result != NULL) {
        Vector2f point = ray.getOrigin() + ray.getDirection() * t;
        // Normal will be exactly opposite to the direction of point
        Vector2f normal = ray.getOrigin() - point;
        if(normal.magnitudeSquared() != 1) {
            normal.normalize();
        }

        result->init(point, normal, t, hit);
    }

    return true;
}

// Circle vs Primitive tests
bool IntersectionDetector2D::circleAndLine(Circle &circle, Line2D &line) {
    return lineAndCircle(line, circle);
}

bool IntersectionDetector2D::circleAndCircle(Circle &c1, Circle &c2) {
    Vector2f vecBetweenCenters = c1.getCenter() - c2.getCenter();
    float radiiSum = c1.getRadius() + c2.getRadius();

    return vecBetweenCenters.magnitudeSquared() <= radiiSum * radiiSum;
}

bool IntersectionDetector2D::circleAndAABB(Circle &circle, AABB &box) {
    Vector2f closestPointToCircle = circle.getCenter();
    Vector2f boxMin = box.getMin();
    Vector2f boxMax = box.getMax();

    // Find closest X
    if(closestPointToCircle.getX() < boxMin.getX()) {
        closestPointToCircle.setX(boxMin.getX());
    } else if(closestPointToCircle.getX() > boxMax.getX()) {
        closestPointToCircle.setX(boxMax.getX());
    }

    // Find closest Y
    if(closestPointToCircle.getY() < boxMin.getY()) {
        closestPointToCircle.setY(boxMin.getY());
    } else if(closestPointToCircle.getY() > boxMax.getY()) {
        closestPointToCircle.setY(boxMax.getY());
    }

    Vector2f circleToBox = circle.getCenter() - closestPointToCircle;

    return circle.getRadius() * circle.getRadius() >= circleToBox.magnitudeSquared();
}

bool IntersectionDetector2D::circleAndBox2D(Circle &circle, Box2D &box) {
    Vector2f origin(0, 0);
    float rotation = -box.getRigidbody().getRotation();
    // Bring the circle to the box's local space
    Circle c(circle);
    c.setCenter(Math::rotate(c.getCenter(), origin, rotation));

    // Rotate the box
    Vector2f newMin = Math::rotate(box.getLocalMin(), origin, rotation);
    Vector2f newMax = Math::rotate(box.getLocalMax(), origin, rotation);
    // Now it is just an AABB vs Circle problem
    AABB b(newMin, newMax);

    return circleAndAABB(c, b);
}

// AABB vs Primitive tests
bool IntersectionDetector2D::AABBAndCircle(AABB &box, Circle &circle) {
    return circleAndAABB(circle, box);
}

bool IntersectionDetector2D::AABBAndAABB(AABB &b1, AABB &b2) {
    Vector2f axesToTest[] = {Vector2f(1, 0), Vector2f(0, 1)};
    for(Vector2f axis: axesToTest) {
        if(!overlapOnAxis(b1, b2, axis)) {
            return false;
        }
    }
    return true;
}

bool IntersectionDetector2D::AABBAndBox2D(AABB &b1, Box2D &b2) {
    Vector2f xAxis(1, 0);
    Vector2f yAxis(0, 1);
    Vector2f origin(0, 0);
    Vector2f boxXAxis(Math::rotate(xAxis, origin, b2.getRigidbody().getRotation()));
    Vector2f boxYAxis(Math::rotate(yAxis, origin, b2.getRigidbody().getRotation()));
    Vector2f axesToTest[] = {xAxis, yAxis, boxXAxis, boxYAxis};

    for(Vector2f axis: axesToTest) {
        if(!overlapOnAxis(b1, b2, axis)) {
            return false;
        }
    }
    return true;
}

bool IntersectionDetector2D::overlapOnAxis(AABB &b1, AABB &b2, Vector2f &axis) {
    Vector2f i1 = getInterval(b1, axis);
    Vector2f i2 = getInterval(b2, axis);

    float b1Min = i1.getX();
    float b1Max = i1.getY();
    float b2Min = i2.getX();
    float b2Max = i2.getY();

    return b1Max >= b2Min && b1Min <= b2Max;
}

bool IntersectionDetector2D::overlapOnAxis(AABB &b1, Box2D &b2, Vector2f &axis) {
    Vector2f i1 = getInterval(b1, axis);
    Vector2f i2 = getInterval(b2, axis);

    float b1Min = i1.getX();
    float b1Max = i1.getY();
    float b2Min = i2.getX();
    float b2Max = i2.getY();

    return b1Max >= b2Min && b1Min <= b2Max;
}

bool IntersectionDetector2D::overlapOnAxis(Box2D &b1, Box2D &b2, Vector2f &axis) {
    Vector2f i1 = getInterval(b1, axis);
    Vector2f i2 = getInterval(b2, axis);

    float b1Min = i1.getX();
    float b1Max = i1.getY();
    float b2Min = i2.getX();
    float b2Max = i2.getY();

    return b1Max >= b2Min && b1Min <= b2Max;
}

Vector2f IntersectionDetector2D::getInterval(AABB &rect, Vector2f &axis) {
    Vector2f result(0, 0);

    Vector2f* vertices = rect.getVertices();

    // Initialise result (result will store (min, max) along the given axis)
    result.setX(axis.dot(vertices[0]));
    result.setY(result.getX());

    // Get interval
    for(int i=0; i<4; i++) {
        float projection = axis.dot(vertices[i]);
        if(projection < result.getX()) {
            result.setX(projection);
        }
        if(projection > result.getY()) {
            result.setY(projection);
        }
    }

    return result;
}

Vector2f IntersectionDetector2D::getInterval(Box2D &rect, Vector2f &axis) {
    Vector2f result(0, 0);

    Vector2f* vertices = rect.getVertices();

    // Initialise result (result will store (min, max) along the given axis)
    result.setX(axis.dot(vertices[0]));
    result.setY(result.getX());

    // Get interval
    for(int i=0; i<4; i++) {
        float projection = axis.dot(vertices[i]);
        if(projection < result.getX()) {
            result.setX(projection);
        }
        if(projection > result.getY()) {
            result.setY(projection);
        }
    }

    return result;
}
