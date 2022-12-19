#include <iostream>
#include <cmath>
#include <vector>
#include <iterator>

int main() {
	int t, n, a, s = 0, k = 0, mx = 100000, k0 = 0;
	std::cin >> t;
	for (int i = 0; i < t; i += 1) {
		mx = 10000000;
		s = 0;
		std::cin >> n;
		std::vector <int> A;
		for (int j = 0; j < n; j += 1) {
			std::cin >> a;
			A.push_back(a);
		}
		k0 = 0;
		for (int j = 0; j < n; j += 1) {
			if (A[j] == 0) {
				k0 += 1;
				s = n - k0;
				if (s < mx) {
					mx = s;
				}
			}
			for (int k = j + 1; k < n; k += 1) {
				if (A[j] == A[k]) {
					s = n;
					if (s < mx) {
						mx = s;
					}
				}
				else {
					s = n + 1;
					if (s < mx) {
						mx = s;
					}
				}

			}
		}
		std::cout << mx << std::endl;
	}
	return 0;
}
