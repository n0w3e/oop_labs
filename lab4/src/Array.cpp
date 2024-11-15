#include "../include/Array.h"

template <typename T>
void Array<T>::add(const std::shared_ptr<T>& element) {
    elements.push_back(element);
}

template <typename T>
void Array<T>::remove(size_t index) {
    if (index >= elements.size()) {
        throw std::out_of_range("Index out of range.");
    }
    elements.erase(elements.begin() + index);
}

template <typename T>
size_t Array<T>::getSize() const {
    return elements.size();
}

template <typename T>
std::shared_ptr<T> Array<T>::operator[](size_t index) const {
    if (index >= elements.size()) {
        throw std::out_of_range("Index out of range.");
    }
    return elements[index];
}

template <typename T>
double Array<T>::totalArea() const {
    double total = 0.0;
    for (const auto& element : elements) {
        total += static_cast<double>(element->area());
    }
    return total;
}

template <typename T>
void Array<T>::printAll() const {
    for (const auto& element : elements) {
        std::cout << *element << "\n";
    }
}

// Explicit instantiation
template class Array<Figure<float>>;
template class Array<Figure<double>>;
