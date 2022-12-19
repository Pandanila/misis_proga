#include <iostream>
#include <string>

int main() {
    std::string s1;
    std::string s2;
    std::cin >> s1;
    std::cin >> s2;
    int fl = 1;
    for (int i = 0; i < s1.length(); i += 1) {
        if (tolower(s1[i]) < tolower(s2[i])) {
            fl = -1;
            break;
        }
        else if (tolower(s1[i]) == tolower(s2[i])) {
            fl = 0;
        }
        else {
            fl = 1;
            break;
        }
    }
    std::cout << fl;
    return 0;
}
