#include "../include/six.h"
#include <iostream>

int main() {
    try {
        Six s1({1, 2, 3});
        Six s2({2, 3, 4});

        std::cout << "s1: 123 \n";
        std::cout << "s2: 234 \n";

        s1 += s2;
        std::cout << "s1 + s2 = (результат будет в шестиричной системе)\n";

        Six s3 = s2;
        s3 -= s1;
        std::cout << "s2 - s1 = (результат будет в шестиричной системе)\n";

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