#include <gtest/gtest.h>
#include <memory>
#include "../include/Triangle.h"
#include "../include/Rectangle.h"
#include "../include/Square.h"
#include "../include/Array.h"

TEST(TriangleTests, CalculateArea) {
    Point<double> a(0.0, 0.0);
    Point<double> b(1.0, 0.0);
    Point<double> c(0.0, 1.0);
    Triangle<double> triangle(a, b, c);

    double area = static_cast<double>(triangle);

    EXPECT_DOUBLE_EQ(area, 0.5);
}

TEST(TriangleTests, GetCenter) {
    Point<double> a(0.0, 0.0);
    Point<double> b(6.0, 0.0);
    Point<double> c(0.0, 6.0);
    Triangle<double> triangle(a, b, c);

    std::shared_ptr<Point<double>> center = triangle.getCenter();

    EXPECT_DOUBLE_EQ(center->getX(), 2.0);
    EXPECT_DOUBLE_EQ(center->getY(), 2.0);
}

TEST(RectangleTests, CalculateArea) {
    Point<double> topLeft(0.0, 0.0);
    Rectangle<double> rectangle(topLeft, 4.0, 5.0);

    double area = static_cast<double>(rectangle);

    EXPECT_DOUBLE_EQ(area, 20.0);
}

TEST(RectangleTests, GetCenter) {
    Point<double> topLeft(0.0, 0.0);
    Rectangle<double> rectangle(topLeft, 4.0, 6.0);

    std::shared_ptr<Point<double>> center = rectangle.getCenter();

    EXPECT_DOUBLE_EQ(center->getX(), 2.0);
    EXPECT_DOUBLE_EQ(center->getY(), -3.0);
}

TEST(SquareTests, CalculateArea) {
    Point<double> topLeft(0.0, 0.0);
    Square<double> square(topLeft, 3.0);

    double area = static_cast<double>(square);

    EXPECT_DOUBLE_EQ(area, 9.0);
}

TEST(SquareTests, GetCenter) {
    Point<double> topLeft(0.0, 0.0);
    Square<double> square(topLeft, 4.0);

    std::shared_ptr<Point<double>> center = square.getCenter();

    EXPECT_DOUBLE_EQ(center->getX(), 2.0);
    EXPECT_DOUBLE_EQ(center->getY(), -2.0);
}

TEST(ArrayTests, AddAndGetTotalArea) {
    Array<double> figureArray;
    auto triangle = std::make_shared<Triangle<double>>(
        Point<double>(0.0, 0.0), Point<double>(1.0, 0.0), Point<double>(0.0, 1.0)
    );
    auto rectangle = std::make_shared<Rectangle<double>>(
        Point<double>(0.0, 0.0), 2.0, 3.0
    );
    auto square = std::make_shared<Square<double>>(
        Point<double>(0.0, 0.0), 2.0
    );

    figureArray.add(triangle);
    figureArray.add(rectangle);
    figureArray.add(square);
    double totalArea = figureArray.getTotalArea();

    EXPECT_DOUBLE_EQ(totalArea, 0.5 + 6.0 + 4.0);
}

TEST(ArrayTests, RemoveAndPrintDetails) {
    Array<double> figureArray;
    auto triangle = std::make_shared<Triangle<double>>(
        Point<double>(0.0, 0.0), Point<double>(1.0, 0.0), Point<double>(0.0, 1.0)
    );
    auto rectangle = std::make_shared<Rectangle<double>>(
        Point<double>(0.0, 0.0), 2.0, 3.0
    );

    figureArray.add(triangle);
    figureArray.add(rectangle);

    figureArray.remove(0);
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    figureArray.printDetails();
    std::cout.rdbuf(oldCout);

    std::string expectedOutput = "Figure 1: Center (1, -1.5), Area 6\n";
    EXPECT_EQ(output.str(), expectedOutput);
}