#include <iostream>
#include <string>

int main() {
    int t, n, k, k0, k1;
    std::cin >> t;
    for (int i = 0; i < t; i += 1) {
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        k0 = 0;
        k1 = 0; 
        int flag = 1;
        for (int j = 0; j < n; j += 1) {
            if (s[j] != '?' && s[j % k] != '?' && s[j] != s[j % k]) { //для того, чтобы строка была сбалансирована, нужно,
                flag = 0;                                            //чтобы k-блоки были идентичными
                break;
            }
            if (s[j] != '?') {
                s[j % k] = s[j];
            }
        }
        for (int j = 0; j < k; j += 1) {
            if (s[j] == '1') {
                k1 += 1;
            }
            if (s[j] == '0') {
                k0 += 1;
            }
        }

        if (flag == 1 && k1 <= k / 2 && k0 <= k / 2) {
            std::cout << "YES" << std::endl;
        }
        else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
