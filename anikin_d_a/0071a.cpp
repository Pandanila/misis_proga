#include <iostream>
#include <vector>
#include <string>
#include <array>

int main() {
    int n, lg;
    std::cin >> n;
    for (int i = 0; i < n; i += 1) {
        std::string s;
        std::cin >> s;
        if (s.size() <= 10) {
            std::cout << s << std::endl;
        }
        else if (s.size() > 10) {
            lg = s.size();
            std::cout << s[0] << lg - 2 << s[s.size() - 1] << std::endl;
        }
    }
}
