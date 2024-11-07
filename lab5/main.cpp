#include "memory_resource.h"
#include "dynamic_array.h"
#include <iostream>
#include <memory_resource>

struct ComplexType {
    int id;
    double value;
    ComplexType(int id, double value) : id(id), value(value) {}
};

int main() {
    FixedMemoryResource memoryResource(32, 10);
    DynamicArray<int> intArray(&memoryResource);

    intArray.push_back(1);
    intArray.push_back(2);
    intArray.push_back(3);

    std::cout << "Integer array elements: ";
    for (const auto& elem : intArray) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    DynamicArray<ComplexType> complexArray(&memoryResource);
    complexArray.push_back(ComplexType(1, 10.5));
    complexArray.push_back(ComplexType(2, 20.5));

    std::cout << "ComplexType array elements:\n";
    for (const auto& elem : complexArray) {
        std::cout << "ID: " << elem.id << ", Value: " << elem.value << std::endl;
    }

    return 0;
}
