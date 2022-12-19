#include <iostream>
#include <vector>

int main() {
    int n = 0;
    int t = 0;
    std::cin >> n >> t;
    std::string s = "";
    std::cin >> s;
    while (t) {
        for (int i = 1; i < n; i += 1) {
            if (s[i - 1] == 'B' && s[i] == 'G') {
                s[i - 1] = 'G';
                s[i] = 'B';
                i += 1;
            }
        }
        t = t - 1;
    }
    std::cout << s;
    return 0;
}
