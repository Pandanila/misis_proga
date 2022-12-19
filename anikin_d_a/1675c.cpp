#include <iostream>
#include <string>

int main() {
    int t = 0;
    std::cin >> t;
    for (int i = 0; i < t; i += 1) {
        std::string s = "";
        std::cin >> s;
        int n = s.size();
        int l1 = 0;
        int f0 = n - 1;
        for (int j = 0; j < n; j += 1) {
            if (s[j] == '1' && j > l1) {
                l1 = j;
            }
            if (s[j] == '0' && j < f0) {
                f0 = j;
            }
        }
        std::cout << f0 - l1 + 1 << std::endl;
    }
    return 0;
}
