#include <iostream>
#include <string>
#include <vector>

int main(){
	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		int n = 0;
		int m = 0;
		std::cin >> n >> m;

		std::vector<std::string> v1(0);


		for (int j = 0; j < n; j++) {
			std::string s;
			std::cin >> s;
			v1.push_back(s);
		}

		std::vector<int> coords(2);

		int f = 1;

		for (int l = 0; l < n; l++) {
			if (f) {
				for (int k = 0; k < m; k++) {
					if (v1[l][k] == 'R') {
						coords[0] = l;
						coords[1] = k;
						f = 0;
						break;
					}
				}
			}
		}

		int flag = 1;

		for (int l = 0; l < n; l++) {
			for (int k = 0; k < m; k++) {
				if (v1[l][k] == 'R') {
					if (l > coords[0] && k < coords[1]) {
						flag = 0;
					}
				}
			}
		}

		if (flag) {
			std::cout << "YES" << "\n";
		}
		else {
			std::cout << "NO" << "\n";
		}
	}
}
