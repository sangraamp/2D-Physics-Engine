#include <gtest/gtest.h> // Include the Google Test header
#include "../util/Vector2f.h" // Include the header file for the class to be tested
#include "../primitives/Line2D.h"
#include "../rigidbody/IntersectionDetector2D.h"

// Test fixture for Vector2f class
class Vector2fTest : public ::testing::Test {
protected:
    // Define common setup code here
};

class Line2DTest : public ::testing::Test {
protected:
    IntersectionDetector2D iDtr;
    // Common setup code
    void SetUp() override {
        
    }
};

// Test case to verify the magnitude calculation of Vector2f
TEST_F(Vector2fTest, MagnitudeTest) {
    // Create a Vector2f object with components (3, 4)
    Vector2f vec(3.0f, 4.0f);

    // Expected magnitude is 5 (based on the Pythagorean theorem)
    float expectedMagnitude = 5.0f;

    // Verify that the computed magnitude matches the expected value
    EXPECT_FLOAT_EQ(vec.magnitude(), expectedMagnitude);
}

TEST_F(Line2DTest, IsPointOnLineTestForEndpoints) {
    Vector2f start(2.0f, 3.0f);
    Vector2f end(6.0f, 2.0f);
    Line2D line(start, end);
    // ASSERT_TRUE(iDtr.isPointOnLine(start, line));
    // ASSERT_TRUE(iDtr.isPointOnLine(end, line));
}

// Main function to run all the tests
int main(int argc, char **argv) {
    // Initialize Google Test
    ::testing::InitGoogleTest(&argc, argv);
    // Run all tests
    return RUN_ALL_TESTS();
}
