#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

int main() {
	int a;
	std::string s;
	std::cin >> a;
	std::cin >> s;
	int k = 0;
	for (int i = 0; i < a-1; i += 1) {
		if (s[i] == s[i + 1]) {
			k += 1;
		}
	}
	std::cout << k;
	return 0;
}
