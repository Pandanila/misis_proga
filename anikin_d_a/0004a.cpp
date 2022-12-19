#include <iostream>

int main() {
    int n, k, f, t, fn, mx = -100000000000000000;
    std::cin >> n >> k;
    for (int i = 0; i < n; i += 1) {
        std::cin >> f >> t;
        if (t <= k) {
            fn = f;
            if (fn >= mx) {
                mx = fn;
            }
        }
        else {
            fn = f - (t - k);
            if (fn >= mx) {
                mx = fn;
            }
        }
    }
    std::cout << mx;
    return 0;
}
