#pragma once
#include <concepts>
#include <vector>
#include <memory>
#include "Figure.h"

template <typename T>
concept Scalar = std::is_arithmetic_v<T>;

template <Scalar T>
class Array {
public:
    void add(std::shared_ptr<Figure<T>> figure) {
        figures.push_back(figure);
    }

    void remove(size_t index) {
        if (index < figures.size()) {
            figures.erase(figures.begin() + index);
        }
    }

    T getTotalArea() const {
        T totalArea = 0;
        for (const auto& figure : figures) {
            totalArea += figure->getArea();
        }
        return totalArea;
    }

    void printDetails() const {
        for (size_t i = 0; i < figures.size(); ++i) {
            auto center = figures[i]->getCenter();
            std::cout << "Figure " << i + 1 << ": Center (" << center->getX()
                      << ", " << center->getY() << "), Area " << figures[i]->getArea()
                      << "\n";
        }
    }

private:
    std::vector<std::shared_ptr<Figure<T>>> figures;
};
