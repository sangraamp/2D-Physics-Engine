#include <gtest/gtest.h>
#include "../rigidbody/IntersectionDetector2D.h"
#include "../util/Vector2f.h"

TEST(CircleIntersectionTesterTest, PointInCircleShouldReturnTrueTestOne) {
    Circle circle;
    circle.setRadius(5.0f);
    Rigidbody2D body;
    circle.setRigidbody(body);

    Vector2f point(3, -2);

    bool result = IntersectionDetector2D::isPointInCircle(point, circle);
    ASSERT_TRUE(result);
}

TEST(CircleIntersectionTesterTest, PointInCircleShouldReturnTrueTestTwo) {
    Circle circle;
    circle.setRadius(5.0f);
    Rigidbody2D body;
    circle.setRigidbody(body);

    Vector2f point(-4.9f, 0);

    bool result = IntersectionDetector2D::isPointInCircle(point, circle);
    ASSERT_TRUE(result);
}

TEST(CircleIntersectionTesterTest, PointInCircleShouldReturnFalseTestOne) {
    Circle circle;
    circle.setRadius(5.0f);
    Rigidbody2D body;
    circle.setRigidbody(body);

    Vector2f point(-6, -6);

    bool result = IntersectionDetector2D::isPointInCircle(point, circle);
    ASSERT_FALSE(result);
}

TEST(CircleIntersectionTesterTest, PointInCircleShouldReturnTrueTestFour) {
    Circle circle;
    circle.setRadius(5.0f);
    Rigidbody2D body;
    body.setTransform(Vector2f(10, 10));
    circle.setRigidbody(body);

    Vector2f point(3 + 10, -2 + 10);

    bool result = IntersectionDetector2D::isPointInCircle(point, circle);
    ASSERT_TRUE(result);
}

TEST(CircleIntersectionTesterTest, PointInCircleShouldReturnTrueTestFive) {
    Circle circle;
    circle.setRadius(5.0f);
    Rigidbody2D body;
    body.setTransform(Vector2f(10, 10));
    circle.setRigidbody(body);

    Vector2f point(-4.9f + 10, 0 + 10);

    bool result = IntersectionDetector2D::isPointInCircle(point, circle);
    ASSERT_TRUE(result);
}

TEST(CircleIntersectionTesterTest, PointInCircleShouldReturnFalseTestTwo) {
    Circle circle;
    circle.setRadius(5.0f);
    Rigidbody2D body;
    body.setTransform(Vector2f(10, 10));
    circle.setRigidbody(body);

    Vector2f point(-6 + 10, -6 + 10);

    bool result = IntersectionDetector2D::isPointInCircle(point, circle);
    ASSERT_FALSE(result);
}