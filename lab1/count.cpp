#include "count.h"

int count_one_in_number(int n) {
    int count = 0;
    while (n > 0) {
        count += n % 2;
        n /= 2;
    }

    return count;
}

int count_one_in_range(int a, int b) {
    int total = 0;
    for (int i = a; i <= b; i++) {
        total += count_one_in_number(i);
    }

    return total;
}