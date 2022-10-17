#include <iostream>
#include <vector>

int main(){
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		int flow_len = 1;
		std::cin >> n;
		std::vector<int> v(n);

		for (int j = 0; j < n; j++) {
			std::cin >> v[j];
		}

		if (v[0] == 1) {
			flow_len += 1;
		}

		for (int j = 1; j < n; j++) {
			if (v[j] == 1) {
				flow_len += 1;
				if (v[j - 1] == 1) {
					flow_len += 4;
				}
			}
			if (v[j] == 0 && v[j-1] == 0) {
				flow_len = -1;
				break;
			}
		}

		std::cout << flow_len << "\n";
	}
}
