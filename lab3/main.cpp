#include <iostream>
#include <memory>
#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Rectangle.h"
#include "../include/Array.h"

void printFigureData(const Figure& figure) {
    std::cout << figure << "\n";
    std::cout << "Geometric center: (" << figure.getGeometricCenter().first << ", "
              << figure.getGeometricCenter().second << ")\n";
    std::cout << "Area: " << static_cast<double>(figure.area()) << "\n\n";
}

int main() {
    Array figureArray;
    int choice;

    while (true) {
        std::cout << "Choose an option:\n"
                  << "1. Add Triangle\n"
                  << "2. Add Square\n"
                  << "3. Add Rectangle\n"
                  << "4. Display all figures\n"
                  << "5. Calculate total area\n"
                  << "6. Delete figure by index\n"
                  << "0. Exit\n"
                  << "Choice: ";
        std::cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1: {
                double side;
                std::cout << "Enter side length for Triangle: ";
                std::cin >> side;
                figureArray.add(new Triangle(side));
                break;
            }
            case 2: {
                double side;
                std::cout << "Enter side length for Square: ";
                std::cin >> side;
                figureArray.add(new Square(side));
                break;
            }
            case 3: {
                double width, height;
                std::cout << "Enter width and height for Rectangle: ";
                std::cin >> width >> height;
                figureArray.add(new Rectangle(width, height));
                break;
            }
            case 4: {
                std::cout << "Figures in array:\n";
                for (size_t i = 0; i < figureArray.getSize(); ++i) {
                    std::cout << "Figure " << i + 1 << ":\n";
                    printFigureData(*figureArray[i]);
                }
                break;
            }
            case 5: {
                double totalArea = figureArray.totalArea();
                std::cout << "Total area of all figures: " << totalArea << "\n";
                break;
            }
            case 6: {
                size_t index;
                std::cout << "Enter index of figure to delete: ";
                std::cin >> index;
                if (figureArray.remove(index)) {
                    std::cout << "Figure removed successfully.\n";
                } else {
                    std::cout << "Invalid index.\n";
                }
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}
