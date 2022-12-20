#include <iostream>
#include <cmath>

int main() {
    float x = 0;
    float y = 0;

    float good_points = 0;
    float k = 0;

    int n = 10;

    for (int i = 0; i < n; i += 1){
        std::cin >> x >> y;
        if ((y >= 2 - std::pow(x, 2)) && (std::pow(x, 2) + std::pow(y, 2) <= 4)){
            good_points += 1;
        }
        k += 1;
    }

    std::cout << good_points / k;

}

