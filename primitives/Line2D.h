#ifndef LINE2D_H
#define LINE2D_H

#include "../util/Vector2f.h"

class Line2D {
private:
    Vector2f from;
    Vector2f to;

public:
    // Constructor
    Line2D(Vector2f from, Vector2f to);

    // Getter for start point
    Vector2f getStart();

    // Getter for end point
    Vector2f getEnd();

    // Squared length of the segment
    float lengthSquared();
};

#endif // LINE2D_H
