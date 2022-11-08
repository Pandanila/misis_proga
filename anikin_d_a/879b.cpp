#include <iostream>
#include <set>
#include <queue>

int main() {
	long int n = 0;
	unsigned long long int k = 0;

	std::cin >> n >> k;
	std::queue<int> pls;
	std::multiset<int> pls_m;

	for (int i = 0; i < n; i++) {
		long int a = 0;
		std::cin >> a;
		pls.push(a);
		pls_m.insert(a);
	}

	int count = 0;
	long int cur_1 = pls.front();
	pls.pop();
	long int cur_2 = pls.front();
	pls.pop();

	if (k >= n) {
		std::cout << *pls_m.rbegin();
	}
	else {
		while (count != k) {
			if (cur_1 > cur_2) {
				pls.push(cur_2);
				cur_2 = pls.front();
				pls.pop();
				count += 1;
			}
			else {
				pls.push(cur_1);
				cur_1 = pls.front();
				pls.pop();
				count = 1;
			}
		}

		std::cout << cur_1;
	}
}
