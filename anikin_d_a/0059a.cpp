#include <iostream>
#include <set>
#include <string>
int main() {
    std::string s = "";
    std::cin >> s;
    int k_m = 0;
    int k_b = 0;
    for (int i = 0; i < size(s); i += 1) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            k_b += 1;
        }
        else {
            k_m += 1;
        }
    }
    if (k_b > k_m) {
        for (int i = 0; i < size(s); i += 1) {
            s[i] = toupper(s[i]);
        }
    }
    else {
        for (int i = 0; i < size(s); i += 1) {
            s[i] = tolower(s[i]);
        }
    }
    std::cout << s;
    return 0;
}
