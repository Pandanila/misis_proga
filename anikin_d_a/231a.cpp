#include <iostream>

int main() {
    int n, a, b, c, s;
    s = 0;
    std::cin >> n;
    for (int i = 0; i < n; i += 1) {
        std::cin >> a >> b >> c;
        if (a + b + c >= 2) {
            s += 1;
        }
    }
    std::cout << s;
    return 0;
}
