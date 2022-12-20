#include <iostream>
#include <cmath>

int main() {
    float x = 0.1;
    float delta_x = 0.05;
    float eps = 0.0001;
    float s = 0;
    float elem = 0;
    while (x <= 1.001){
        for (int i = 1; i < 100000000; i += 1){
            elem = std::pow(-1, i + 1) * (std::pow(x, 2*i+1) / (4 * std::pow(i, 2) - 1));
            if (elem < eps){
                break;
            }
            s += elem;
        }
        std::cout << x << " "<< s << "\n";
        x += delta_x;
    }
    return 0;
}
