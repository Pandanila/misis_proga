#include <iostream>
#include <vector>
#include <string>

int main() {
    int t, n, a_i;
    std::cin >> t;
    for (int i = 0; i < t; i += 1) {
        std::cin >> n;
        std::vector <int> Wheels;
        for (int j = 0; j < n; j += 1) {
            std::cin >> a_i;
            Wheels.push_back(a_i);
        }
        std::string s = "";
        int k;
        for (int j = 0; j < n; j += 1) {
            std::cin >> k;
            std::cin >> s;
            for (int z = 0; z < k; z += 1) {
                if (s[z] == 'U') {
                    Wheels[j] -= 1;
                    if (Wheels[j] == -1) {
                        Wheels[j] = 9;
                    }
                }
                else if (s[z] == 'D') {
                    Wheels[j] += 1;
                    if (Wheels[j] == 10) {
                        Wheels[j] = 0;
                    }
                }
            }
        }
        for (int z = 0; z < n; z += 1) {
            std::cout << Wheels[z] << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}
