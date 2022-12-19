#include <iostream>
#include <cmath>
#include <string>

int main() {
	unsigned long long int n, k;
	std::cin >> n;
	k = 0; // количество цифр в числе
	int fl = 0;
	while (n > 0) {
		if (n % 10 == 4 || n % 10 == 7) {
			k += 1;
		}
		n = n / 10;
	}
	while (k > 0) {
		if (k % 10 == 4 || k % 10 == 7) {
			fl = 1;
		}
		else {
			fl = 0;
			break;
		}
		k = k / 10;
	}
	if (fl == 1) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	return 0;
}
