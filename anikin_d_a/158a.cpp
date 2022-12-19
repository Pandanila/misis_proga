#include <iostream>
#include <array>

int main() {
    int n, k, a, s;
    s = 0;
    std::cin >> n >> k;
    const int Nmax = 1000;
    std::array <int, Nmax> Array{ 0 };
    for (int i = 1; i <= n; i += 1) {
        std::cin >> a;
        Array[i] = a;
    }
    for (int i = 1; i <= n; i += 1) {
        if (Array[i] >= Array[k] && Array[i] >= 1) {
            s += 1;
        }
        else {
            break;
        }
    }
    std::cout << s;
    return 0;
}
