#include "gtest/gtest.h"
#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Rectangle.h"
#include "../include/Array.h"

TEST(ArrayTests, AddFigureIncreasesSize) {
    Array figureArray;
    Figure* triangle = new Triangle(3);

    figureArray.add(triangle);

    EXPECT_EQ(figureArray.getSize(), 1);
}

TEST(ArrayTests, RemoveFigureDecreasesSize) {
    Array figureArray;
    figureArray.add(new Triangle(3));
    figureArray.add(new Square(4));

    bool removed = figureArray.remove(0);

    EXPECT_TRUE(removed);
    EXPECT_EQ(figureArray.getSize(), 1);
}

TEST(ArrayTests, RemoveInvalidIndexReturnsFalse) {
    Array figureArray;
    figureArray.add(new Triangle(3));

    bool removed = figureArray.remove(5);

    EXPECT_FALSE(removed);
}

TEST(ArrayTests, TotalAreaCalculatesCorrectly) {
    Array figureArray;
    figureArray.add(new Triangle(3));
    figureArray.add(new Square(4));

    double totalArea = figureArray.totalArea();

    EXPECT_NEAR(totalArea, 19.897, 0.001);
}

TEST(ArrayTests, AccessOperatorReturnsCorrectFigure) {
    Array figureArray;
    Figure* triangle = new Triangle(3);
    figureArray.add(triangle);

    Figure* retrievedFigure = figureArray[0];

    EXPECT_EQ(retrievedFigure, triangle);
}

TEST(ArrayTests, ArrayResizesCorrectly) {
    Array figureArray;
    for (int i = 0; i < 11; ++i) {
        figureArray.add(new Triangle(3));
    }

    size_t sizeAfterAdding = figureArray.getSize();

    EXPECT_EQ(sizeAfterAdding, 11);
}

TEST(ArrayTests, CloneFunctionality) {
    Array figureArray;
    Figure* originalTriangle = new Triangle(3);
    figureArray.add(originalTriangle);

    Figure* clonedTriangle = originalTriangle->clone();

    EXPECT_NE(clonedTriangle, originalTriangle);
    EXPECT_EQ(clonedTriangle->area(), originalTriangle->area());

    delete clonedTriangle;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
