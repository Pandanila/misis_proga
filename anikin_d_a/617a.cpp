#include <iostream>

int main() {
    int a, b, k = 0;
    std::cin >> a >> b;
    while (a <= b) {
        a *= 3;
        b *= 2;
        k += 1;
    }
    std::cout << k;
}
