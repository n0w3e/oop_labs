#include <iostream>
#include "Array.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"

int main() {
    try {
        Array<Figure<double>> figures;

        auto triangle = std::make_shared<Triangle<double>>(
            Point<double>(0, 0), Point<double>(4, 0), Point<double>(0, 3));
        figures.add(triangle);

        auto square = std::make_shared<Square<double>>(
            Point<double>(2, 2), 4.0);
        figures.add(square);

        auto rectangle = std::make_shared<Rectangle<double>>(
            Point<double>(5, 5), 6.0, 3.0);
        figures.add(rectangle);

        for (size_t i = 0; i < figures.getSize(); ++i) {
            std::cout << "Figure " << i + 1 << ":\n";
            std::cout << *figures[i] << "\n";
            std::cout << "Area: " << figures[i]->area() << "\n";
            std::cout << "Geometric Center: " << *figures[i]->getGeometricCenter() << "\n\n";
        }

        std::cout << "Total Area: " << figures.totalArea() << "\n";

        if (figures.remove(1)) {
            std::cout << "Figure 2 removed.\n";
        }

        std::cout << "Remaining Figures:\n";
        for (size_t i = 0; i < figures.getSize(); ++i) {
            std::cout << "Figure " << i + 1 << ":\n";
            std::cout << *figures[i] << "\n";
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }

    return 0;
}
