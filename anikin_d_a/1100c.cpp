#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

int main() {
    int n, r;
    double R;
    std::cin >> n >> r;
    R = (r * sin(M_PI / n)) / (1 - sin(M_PI / n));

    std::cout.setf(std::ios::fixed);
    std::cout.precision(7);
    std::cout << R;
    return 0;
}
