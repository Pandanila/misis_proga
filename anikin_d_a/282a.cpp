#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>

int main() {
	int a, x = 0;
	std::string s;
	std::cin >> a;
	for (int i = 0; i < a; i += 1) {
		std::cin >> s;
		if (s[0] == '+' || s[1] == '+' || s[2] == '+') {
			x += 1;
		}
		else {
			x -= 1;
		}
	}
	std::cout << x;
	return 0;
}
