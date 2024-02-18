#include "CMath.h"
#include <cmath>
#include <limits>

namespace Math {
    Vector2f rotate(Vector2f point, const Vector2f& center, float rotation) {
        float radians = rotation * 3.14159f / 180.0f; // Convert degrees to radians
        float sinValue = std::sin(radians);
        float cosValue = std::cos(radians);

        // Translate point relative to center
        point = point - center;

        // Perform rotation
        float newX = point.getX() * cosValue - point.getY() * sinValue;
        float newY = point.getX() * sinValue + point.getY() * cosValue;

        // Translate back to original position
        point.setX(newX + center.getX());
        point.setY(newY + center.getY());

        return point;
    }

    bool compare(float x, float y, float epsilon) {
        return std::abs(x - y) <= epsilon * std::max(1.0f, std::max(std::abs(x), std::abs(y)));
    }

    bool compare(Vector2f &vec1, Vector2f &vec2, float epsilon) {
        return compare(vec1.getX(), vec2.getX(), epsilon) && compare(vec1.getY(), vec2.getY(), epsilon);
    }
}
