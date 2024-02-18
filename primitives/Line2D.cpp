#include "Line2D.h"

// Constructor definition
Line2D::Line2D(Vector2f from, Vector2f to) : from(from), to(to) {}

// Getter for start point definition
Vector2f Line2D::getStart() {
    return this->from;
}

// Getter for end point definition
Vector2f Line2D::getEnd() {
    return this->to;
}

// Length squared of the segment
float Line2D::lengthSquared() {
    return (this->to - this->from).magnitudeSquared();
}
