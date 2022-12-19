#include <iostream>
#include <cmath>
#include <string>

int main() {
	int n, k;
	std::cin >> n >> k;
	for (int i = 0; i < k; i += 1) {
		if (n % 10 != 0) {
			n = n - 1;
		}
		else {
			n = n / 10;
		}
	}
	std::cout << n;
	return 0;
}
