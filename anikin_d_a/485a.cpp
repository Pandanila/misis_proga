#include <iostream>
#include <string>
#include <vector>
#include <set>

int main() {
	int a = 0;
	int m = 0;
	int rem = 0;
	int flag = 1;

	std::cin >> a >> m;

	std::set<int> remains;
	rem = a % m;

	while (remains.count(rem) != 1) {
		a += rem;
		remains.insert(rem);

		if (a % m == 0) {
			flag = 0;
			break;
		}
		rem = a % m;
	}

	if (flag) {
		std::cout << "No";
	}
	else {
		std::cout << "Yes";
	}
}
