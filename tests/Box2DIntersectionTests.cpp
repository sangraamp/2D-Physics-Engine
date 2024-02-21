#include <gtest/gtest.h>
#include "../rigidbody/IntersectionDetector2D.h"

TEST(Box2DIntersectionTesterTest, PointInBox2DShouldReturnTrueTestOne) {
    Box2D box;
    box.setSize(Vector2f(5, 5) - Vector2f(-5, -5));
    Rigidbody2D body;
    box.setRigidbody(body);

    Vector2f point(4, 4.3f);

    ASSERT_TRUE(IntersectionDetector2D::isPointInBox2D(point, box));
}

TEST(Box2DIntersectionTesterTest, PointInBox2DShouldReturnTrueTestTwo) {
    Box2D box;
    box.setSize(Vector2f(5, 5) - Vector2f(-5, -5));
    Rigidbody2D body;
    box.setRigidbody(body);

    Vector2f point(-4.9f, -4.9f);

    ASSERT_TRUE(IntersectionDetector2D::isPointInBox2D(point, box));
}

TEST(Box2DIntersectionTesterTest, PointInBox2DShouldReturnFalseTestOne) {
    Box2D box;
    box.setSize(Vector2f(5, 5) - Vector2f(-5, -5));
    Rigidbody2D body;
    box.setRigidbody(body);

    Vector2f point(0, 5.1f);

    ASSERT_FALSE(IntersectionDetector2D::isPointInBox2D(point, box));
}

TEST(Box2DIntersectionTesterTest, PointInBox2DShouldReturnTrueTestThree) {
    Box2D box;
    box.setSize(Vector2f(5, 5) - Vector2f(-5, -5));
    Rigidbody2D body;
    body.setTransform(Vector2f(10, 10));
    box.setRigidbody(body);

    Vector2f point(4 + 10, 4.3f + 10);

    ASSERT_TRUE(IntersectionDetector2D::isPointInBox2D(point, box));
}

TEST(Box2DIntersectionTesterTest, PointInBox2DShouldReturnTrueTestFour) {
    Box2D box;
    box.setSize(Vector2f(5, 5) - Vector2f(-5, -5));
    Rigidbody2D body;
    body.setTransform(Vector2f(10, 10));
    box.setRigidbody(body);

    Vector2f point(-4.9f + 10, -4.9f + 10);

    ASSERT_TRUE(IntersectionDetector2D::isPointInBox2D(point, box));
}

TEST(Box2DIntersectionTesterTest, PointInBox2DShouldReturnFalseTestTwo) {
    Box2D box;
    box.setSize(Vector2f(5, 5) - Vector2f(-5, -5));
    Rigidbody2D body;
    body.setTransform(Vector2f(10, 10));
    box.setRigidbody(body);

    Vector2f point(0 + 10, 5.1f + 10);

    ASSERT_FALSE(IntersectionDetector2D::isPointInBox2D(point, box));
}

TEST(Box2DIntersectionTesterTest, PointInRotatedBox2DShouldReturnTrueTestOne) {
    Box2D box;
    box.setSize(Vector2f(5, 5) - Vector2f(-5, -5));
    Rigidbody2D body;
    body.setTransform(Vector2f(0, 0), 45);
    box.setRigidbody(body);

    Vector2f point(-1, -1);

    ASSERT_TRUE(IntersectionDetector2D::isPointInBox2D(point, box));
}

TEST(Box2DIntersectionTesterTest, PointInRotatedBox2DShouldReturnTrueTestTwo) {
    Box2D box;
    box.setSize(Vector2f(5, 5) - Vector2f(-5, -5));
    Rigidbody2D body;
    body.setTransform(Vector2f(0, 0), 45);
    box.setRigidbody(body);

    Vector2f point(-3.43553390593f, 3.43553390593f);

    ASSERT_TRUE(IntersectionDetector2D::isPointInBox2D(point, box));
}

TEST(Box2DIntersectionTesterTest, PointInRotatedBox2DShouldReturnFalseTestOne) {
    Box2D box;
    box.setSize(Vector2f(5, 5) - Vector2f(-5, -5));
    Rigidbody2D body;
    body.setTransform(Vector2f(10, 10), 45);
    box.setRigidbody(body);

    Vector2f point(-3.63553390593f, 3.63553390593f);

    ASSERT_FALSE(IntersectionDetector2D::isPointInBox2D(point, box));
}

TEST(Box2DIntersectionTesterTest, PointInRotatedBox2DShouldReturnTrueTestThree) {
    Box2D box;
    box.setSize(Vector2f(5, 5) - Vector2f(-5, -5));
    Rigidbody2D body;
    body.setTransform(Vector2f(10, 10), 45);
    box.setRigidbody(body);

    Vector2f point(-1 + 10, -1 + 10);

    ASSERT_TRUE(IntersectionDetector2D::isPointInBox2D(point, box));
}

TEST(Box2DIntersectionTesterTest, PointInRotatedBox2DShouldReturnTrueTestFour) {
    Box2D box;
    box.setSize(Vector2f(5, 5) - Vector2f(-5, -5));
    Rigidbody2D body;
    body.setTransform(Vector2f(10, 10), 45);
    box.setRigidbody(body);

    Vector2f point(-3.43553390593f + 10, 3.43553390593f + 10);

    ASSERT_TRUE(IntersectionDetector2D::isPointInBox2D(point, box));
}

TEST(Box2DIntersectionTesterTest, PointInRotatedBox2DShouldReturnFalseTestTwo) {
    Box2D box;
    box.setSize(Vector2f(5, 5) - Vector2f(-5, -5));
    Rigidbody2D body;
    body.setTransform(Vector2f(10, 10), 45);
    box.setRigidbody(body);

    Vector2f point(-3.63553390593f + 10, 3.63553390593f + 10);

    ASSERT_FALSE(IntersectionDetector2D::isPointInBox2D(point, box));
}