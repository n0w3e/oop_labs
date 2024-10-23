#include "../include/six.h"
#include <iostream>

void printSix(const Six& number) {
    std::cout << "(Число в шестиричной системе)\n";
}

int main() {
    try {
        unsigned char digits1[] = {1, 2, 3};
        unsigned char digits2[] = {2, 3, 4};
        
        Six s1(digits1, 3);
        Six s2(digits2, 3);

        std::cout << "s1: 123 \n";
        std::cout << "s2: 234 \n";

        s1 += s2;
        std::cout << "s1 + s2 = ";
        printSix(s1);

        Six s3 = s2;
        s3 -= s1;
        std::cout << "s2 - s1 = ";
        printSix(s3);

        if (s1 > s2) {
            std::cout << "s1 больше s2\n";
        } else {
            std::cout << "s1 меньше или равно s2\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
