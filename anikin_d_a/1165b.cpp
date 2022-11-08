#include <iostream>
#include <string>
#include <set>

int main() {
	int n = 0;

	std::cin >> n;
	std::multiset<int> s;

	for (int i = 0; i < n; i += 1) {
		int a = 0;
		std::cin >> a;
		s.insert(a);
	}

	int count = 0;
	int day = 1;

	std::set<int>::iterator it = s.begin();

	while (it != s.end()) {
		if (*it >= day) {
			day += 1;
			count += 1;
		}
		it++;
	}

	std::cout << count;
}
