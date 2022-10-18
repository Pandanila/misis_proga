#include <iostream>
#include <string>
#include <vector>

int main(){
	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i += 1) {
		int n = 0;
		std::cin >> n;

		char cur_col;
		std::cin >> cur_col;

		std::string colors;
		std::cin >> colors;

		if (colors.length() == 1 && colors[0] == 'g') {
			std::cout << 0 << "\n";
			continue;
		}

		colors += colors;

		int flag = 1;
		int time = -1;
		int count = 0;

		for (int j = 0; j < n * 2; j++) {
			if (colors[j] == cur_col && flag) {
				count = 0;
				flag = 0;
			}
			if (colors[j] == 'g') {
				if (count > time) {
					time = count;
					flag = 1;
				}
			}
			else {
				count += 1;
			}
		}

		std::cout << time;
	}
}
