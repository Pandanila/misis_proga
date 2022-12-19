#include <iostream>

int main() {
    unsigned long long int n, m, a, s;
    std::cin >> n >> m >> a;
    std::cout << std::endl;
    s = ((n + a - 1) / a) * ((m + a - 1) / a);
    std::cout << s;
    return 0;
}
