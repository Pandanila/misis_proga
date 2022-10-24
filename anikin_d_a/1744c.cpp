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
		colors = colors + colors;

		int cur_k = 0;
		int cur_g = 0;
		int flag = 0;

		std::vector<int> lengths;

		for (int m = 0; m < colors.length(); m++) {
			if ((colors[m] == cur_col) && (not flag)) {
				cur_k = m;
				flag = 1;
			}

			if (colors[m] == 'g' && flag){
				lengths.push_back(m - cur_k);
				flag = 0;
			}
		}

		int max_l = -1;
		for (int m = 0; m < lengths.size(); m++) {
			if (lengths[m] > max_l) {
				max_l = lengths[m];
			}
		}

		std::cout << max_l << "\n";
	}
}
