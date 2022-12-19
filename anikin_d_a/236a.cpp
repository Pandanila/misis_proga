#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;
    std::vector <int> A (26, 0); //динамический массив A длиной 26, заполненный нулями
    for (int i = 0; i < s.length(); i += 1) {
        A[s[i] - 'a'] = 1;
    }
    int k;
    k = 0;
    for (int i = 0; i < std::size(A); i += 1) {
        k += A[i];
    }
    if (k % 2 == 0) {
        std::cout << "CHAT WITH HER!";
    }
    else {
        std::cout << "IGNORE HIM!";
    }
    return 0;
}
