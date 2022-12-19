#include <iostream>
#include <string>
#include <array>

int main() {
    std::string s;
    std::cin >> s;
    const int N = 4;
    std::array <int, N> A {0};
    int k_plus = 0;
    for (int i = 0; i < s.length(); i += 1) {
        if (s[i] == '1') {
            A[1] += 1;
            k_plus += 1;
        }
        else if (s[i] == '2') {
            A[2] += 1;
            k_plus += 1;
        }
        else if (s[i] == '3') {
            A[3] += 1;
            k_plus += 1;
        }
    }
    k_plus -= 1;
    for (int i = 0; i < s.length(); i += 1) {
        if (A[1] != 0 && k_plus != 0) {
            std::cout << '1' << '+';
            A[1] -= 1;
            k_plus -= 1;
        }
        else if (A[1] != 0 && k_plus == 0) {
            std::cout << '1';
            A[1] -= 1;
            k_plus -= 1;
        }
        else if (A[2] != 0 && k_plus != 0) {
            std::cout << '2' << '+';
            A[2] -= 1;
            k_plus -= 1;
        }
        else if (A[2] != 0 && k_plus == 0) {
            std::cout << '2';
            A[2] -= 1;
            k_plus -= 1;
        }
        else if (A[3] != 0 && k_plus != 0) {
            std::cout << '3' << '+';
            A[3] -= 1;
            k_plus -= 1;
        }
        else if (A[3] != 0 && k_plus == 0) {
            std::cout << '3';
            A[3] -= 1;
            k_plus -= 1;
        }
    }
    return 0;
}
