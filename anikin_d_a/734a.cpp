#include <iostream>
#include <set>
#include <string>
int main() {
    int n = 0;
    std::cin >> n;
    std::string s = "";
    std::cin >> s;
    int a = 0;
    int d = 0;
    for (int i = 0; i < n; i += 1) {
        if (s[i] == 'A') {
            a += 1;
        }
        else {
            d += 1;
        }
    }
    if (a > d) {
        std::cout << "Anton";
    }
    else if (d > a) {
        std::cout << "Danik";
    }
    else {
        std::cout << "Friendship";
    }
    return 0;
}
