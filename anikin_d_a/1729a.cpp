#include <iostream>
#include <cmath>

int main()
{
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int a = 0;
		int b = 0;
		int c = 0;
		std::cin >> a >> b >> c;
		if (a < (std::abs(b - c) + c)) {
			std::cout << 1 << "\n";
		}
		else if (a > (std::abs(b - c) + c)) {
			std::cout << 2 << "\n";
		}
		else {
			std::cout << 3 << "\n";
		}
	}
}
