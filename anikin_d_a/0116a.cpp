#include <iostream>
#include <set>
#include <string>
int main() {
    int n = 0;
    std::cin >> n;
    int a = 0;
    int b = 0;
    int cap = 0;
    int cur = 0;
    for (int i = 0; i < n; i += 1) {
        std::cin >> a >> b;
        if (a == 0) {
            cur +=  b;
            if (cur > cap) {
                cap = cur;
            }
        }
        else {
            cur = cur - a + b;
            if (cur > cap) {
                cap = cur;
            }
        }
    }
    std::cout << cap;
    return 0;
}
