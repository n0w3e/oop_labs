#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Rectangle.h"
#include "../include/Array.h"
#include <gtest/gtest.h>

TEST(FigureTest, TriangleArea) {
    Triangle<double> triangle(Point<double>(0, 0), Point<double>(0, 4), Point<double>(3, 0));
    ASSERT_DOUBLE_EQ(triangle.area(), 6.0);
}

TEST(FigureTest, TriangleCenter) {
    Triangle<double> triangle(Point<double>(0, 0), Point<double>(0, 4), Point<double>(3, 0));
    auto center = triangle.center();
    ASSERT_DOUBLE_EQ(center.getX(), 1.0);
    ASSERT_DOUBLE_EQ(center.getY(), 4.0 / 3.0);
}

TEST(FigureTest, SquareArea) {
    Square<double> square(Point<double>(0, 0), 4);
    ASSERT_DOUBLE_EQ(square.area(), 16.0);
}

TEST(FigureTest, SquareCenter) {
    Square<double> square(Point<double>(0, 0), 4);
    auto center = square.center();
    ASSERT_DOUBLE_EQ(center.getX(), 2.0);
    ASSERT_DOUBLE_EQ(center.getY(), 2.0);
}

TEST(FigureTest, RectangleArea) {
    Rectangle<double> rectangle(Point<double>(0, 0), 4, 6);
    ASSERT_DOUBLE_EQ(rectangle.area(), 24.0);
}

TEST(FigureTest, RectangleCenter) {
    Rectangle<double> rectangle(Point<double>(0, 0), 4, 6);
    auto center = rectangle.center();
    ASSERT_DOUBLE_EQ(center.getX(), 2.0);
    ASSERT_DOUBLE_EQ(center.getY(), 3.0);
}

TEST(ArrayTest, AddAndRemoveFigures) {
    Array<std::shared_ptr<Figure<double>>> array;

    auto triangle = std::make_shared<Triangle<double>>(Point<double>(0, 0), Point<double>(0, 4), Point<double>(3, 0));
    auto square = std::make_shared<Square<double>>(Point<double>(0, 0), 4);
    auto rectangle = std::make_shared<Rectangle<double>>(Point<double>(0, 0), 4, 6);

    array.add(triangle);
    array.add(square);
    array.add(rectangle);

    ASSERT_EQ(array.getSize(), 3);

    array.remove(1);
    ASSERT_EQ(array.getSize(), 2);

    ASSERT_DOUBLE_EQ(array[0]->area(), triangle->area());
    ASSERT_DOUBLE_EQ(array[1]->area(), rectangle->area());
}

TEST(ArrayTest, TotalArea) {
    Array<std::shared_ptr<Figure<double>>> array;

    auto triangle = std::make_shared<Triangle<double>>(Point<double>(0, 0), Point<double>(0, 4), Point<double>(3, 0));
    auto square = std::make_shared<Square<double>>(Point<double>(0, 0), 4);

    array.add(triangle);
    array.add(square);

    ASSERT_DOUBLE_EQ(array.totalArea(), triangle->area() + square->area());
}
