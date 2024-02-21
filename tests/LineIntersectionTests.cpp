#include <gtest/gtest.h>
#include "../primitives/Line2D.h"
#include "../rigidbody/IntersectionDetector2D.h"

// Line Intersection tests
TEST(IntersectionDetector2DTests, PointOnLine2DShouldReturnTrueTest) {
    Line2D line(Vector2f(0, 0), Vector2f(12, 4));
    Vector2f point(0, 0);

    ASSERT_TRUE(IntersectionDetector2D::isPointOnLine(point, line));
}

TEST(IntersectionDetector2DTests, PointOnLine2DShouldReturnTrueTestTwo) {
    Line2D line(Vector2f(0, 0), Vector2f(12, 4));
    Vector2f point(12, 4);

    ASSERT_TRUE(IntersectionDetector2D::isPointOnLine(point, line));
}

TEST(IntersectionDetector2DTests, PointOnVerticalLineShouldReturnTrue) {
    Line2D line(Vector2f(0, 0), Vector2f(0, 10));
    Vector2f point(0, 5);

    ASSERT_TRUE(IntersectionDetector2D::isPointOnLine(point, line));
}

TEST(IntersectionDetector2DTests, PointOnLineShouldReturnTrueTestOne) {
    Line2D line(Vector2f(0, 0), Vector2f(12, 4));
    Vector2f point(0, 0);

    ASSERT_TRUE(IntersectionDetector2D::isPointOnLine(point, line));
}

TEST(IntersectionDetector2DTests, PointOnLineShouldReturnTrueTestTwo) {
    Line2D line(Vector2f(0, 0), Vector2f(12, 4));
    Vector2f point(6, 2);

    ASSERT_TRUE(IntersectionDetector2D::isPointOnLine(point, line));
}

TEST(IntersectionDetector2DTests, PointOnLineShouldReturnFalseTestOne) {
    Line2D line(Vector2f(0, 0), Vector2f(12, 4));
    Vector2f point(4, 2);

    ASSERT_FALSE(IntersectionDetector2D::isPointOnLine(point, line));
}

TEST(IntersectionDetector2DTests, PointOnLineShouldReturnFalseTestTwo) {
    Line2D line(Vector2f(10, 10), Vector2f(22, 14));
    Vector2f point(14, 12);

    ASSERT_FALSE(IntersectionDetector2D::isPointOnLine(point, line));
}

TEST(IntersectionDetector2DTests, PointOnLineShouldReturnTrueTestThree) {
    Line2D line(Vector2f(10, 10), Vector2f(22, 14));
    Vector2f point(10, 10);

    ASSERT_TRUE(IntersectionDetector2D::isPointOnLine(point, line));
}

TEST(IntersectionDetector2DTests, PointOnLineShouldReturnTrueTestFour) {
    Line2D line(Vector2f(10, 10), Vector2f(22, 14));
    Vector2f point(16, 12);

    ASSERT_TRUE(IntersectionDetector2D::isPointOnLine(point, line));
}

// TODO: Implement remaining tests as needed
