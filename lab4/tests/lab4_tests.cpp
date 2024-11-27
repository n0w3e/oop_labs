#include <gtest/gtest.h>
#include "Array.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"

TEST(TriangleTest, AreaCalculation) {
    Triangle<double> triangle(Point<double>(0, 0), Point<double>(4, 0), Point<double>(0, 3));
    ASSERT_DOUBLE_EQ(triangle.area(), 6.0);
}

TEST(SquareTest, AreaCalculation) {
    Square<double> square(Point<double>(0, 0), 4.0);
    ASSERT_DOUBLE_EQ(square.area(), 16.0);
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle<double> rectangle(Point<double>(0, 0), 4.0, 6.0);
    ASSERT_DOUBLE_EQ(rectangle.area(), 24.0);
}

TEST(ArrayTest, AddAndRemoveFigures) {
    Array<Figure<double>> figures;

    auto triangle = std::make_shared<Triangle<double>>(
        Point<double>(0, 0), Point<double>(4, 0), Point<double>(0, 3));
    auto square = std::make_shared<Square<double>>(
        Point<double>(0, 0), 4.0);

    figures.add(triangle);
    figures.add(square);

    ASSERT_EQ(figures.getSize(), 2);

    ASSERT_TRUE(figures.remove(0));
    ASSERT_EQ(figures.getSize(), 1);

    ASSERT_TRUE(figures.remove(0));
    ASSERT_EQ(figures.getSize(), 0);
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array<Figure<double>> figures;

    auto triangle = std::make_shared<Triangle<double>>(
        Point<double>(0, 0), Point<double>(4, 0), Point<double>(0, 3));
    auto square = std::make_shared<Square<double>>(
        Point<double>(0, 0), 4.0);
    auto rectangle = std::make_shared<Rectangle<double>>(
        Point<double>(0, 0), 4.0, 6.0);

    figures.add(triangle);
    figures.add(square);
    figures.add(rectangle);

    ASSERT_DOUBLE_EQ(figures.totalArea(), 6.0 + 16.0 + 24.0);
}
