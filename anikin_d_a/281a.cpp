#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
    s[0] = toupper(s[0]);
    std::cout << s[0];
    for (int i = 1; i < s.length(); i += 1) {
    std::cout << s[i];
    }
    return 0;
}
