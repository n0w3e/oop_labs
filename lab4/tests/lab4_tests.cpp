#include <gtest/gtest.h>
#include <memory>
#include "Point.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Array.h"

using ScalarType = double;

TEST(PointTest, Initialization) {
    Point<ScalarType> p(3.5, 7.2);
    EXPECT_EQ(p.getX(), 3.5);
    EXPECT_EQ(p.getY(), 7.2);
}

TEST(TriangleTest, AreaCalculation) {
    Triangle<ScalarType> triangle(
        Point<ScalarType>(0, 0),
        Point<ScalarType>(4, 0),
        Point<ScalarType>(2, 3)
    );
    EXPECT_NEAR(triangle.getArea(), 6.0, 1e-6);
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle<ScalarType> rectangle(Point<ScalarType>(1, 1), 4, 3);
    EXPECT_EQ(rectangle.getArea(), 12.0);
}

TEST(SquareTest, CenterCalculation) {
    Square<ScalarType> square(Point<ScalarType>(-2, -2), 2);
    auto center = square.getCenter();
    EXPECT_NEAR(center->getX(), -1.0, 1e-6);
    EXPECT_NEAR(center->getY(), -3.0, 1e-6);
}

TEST(ArrayTest, TotalAreaCalculation) {
    auto triangle = std::make_shared<Triangle<ScalarType>>(
        Point<ScalarType>(0, 0),
        Point<ScalarType>(4, 0),
        Point<ScalarType>(2, 3)
    );

    auto rectangle = std::make_shared<Rectangle<ScalarType>>(
        Point<ScalarType>(1, 5), 4, 3
    );

    auto square = std::make_shared<Square<ScalarType>>(
        Point<ScalarType>(-3, -3), 2
    );

    Array<ScalarType> figures;
    figures.add(triangle);
    figures.add(rectangle);
    figures.add(square);

    EXPECT_NEAR(figures.getTotalArea(), 6.0 + 12.0 + 4.0, 1e-6);
}

TEST(ArrayTest, RemoveFigure) {
    auto triangle = std::make_shared<Triangle<ScalarType>>(
        Point<ScalarType>(0, 0),
        Point<ScalarType>(4, 0),
        Point<ScalarType>(2, 3)
    );

    Array<ScalarType> figures;
    figures.add(triangle);
    EXPECT_EQ(figures.getTotalArea(), 6.0);

    figures.remove(0);
    EXPECT_EQ(figures.getTotalArea(), 0.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
