#include <iostream>
#include <string>
#include <vector>
#include <cmath>

int main() {
	int t = 0;

	std::cin >> t;

	for (int i = 0; i < t; i += 1) {
		int n = 0;
		int  m = 0;
		std::cin >> n >> m;

		int f = 1;

		for (int j = 0; j < n; j += 1) {
			for (int k = 0; k < m / 2; k += 1) {
				if (f) {
					std::cout << "1 0 ";
					f = 0;
				}
				else {
					std::cout << "0 1 ";
					f = 1;
				}
			}
			std::cout << std::endl;

			if (m % 4 == 0) {
				if (j % 2 == 0) {
					f = std::abs(f - 1);
				}
			}
			else {
				if (j % 2 != 0) {
					f = std::abs(f - 1);
				}
			}
		}
	}
}
