#ifndef CMATH_H
#define CMATH_H

#include "Vector2f.h"

namespace Math {
    // Rotate a point about a center by rotation degrees
    Vector2f rotate(Vector2f point, const Vector2f& center, float rotation);
    bool compare(float x, float y, float epsilon=std::numeric_limits<float>::min());
    bool compare(Vector2f &vec1, Vector2f &vec2, float epsilon=std::numeric_limits<float>::min());
}

#endif // CMATH_H
