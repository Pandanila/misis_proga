#include <iostream>
#include <vector>

int main(){
	int t = 0;
	std::cin >> t;
	
	for (int i = 0; i < t; i++) {
		int n = 0;
		std::cin >> n;
		
		int time = 0;

		std::vector<int> start(1);
		start[0] = 0;
		std::vector<int> finish(1);
		finish[0] = 0;

		for (int j = 0; j < n; j++) {
			int a = 0;
			int b = 0;
			std::cin >> a >> b;
			start.push_back(a);
			finish.push_back(b);
		}

		std::vector<int> lating(0);

		for (int j = 0; j < n; j++) {
			int tm = 0;
			std::cin >> tm;
			lating.push_back(tm);
		}

		for (int j = 1; j < n + 1; j++) {
			time += start[j] - finish[j - 1] + lating[j - 1];

			if (j == n) {
				break;
			}

			int extra = 0;
			if ((finish[j] - start[j]) % 2 == 0) {
				extra = (finish[j] - start[j]) / 2;
			}
			else {
				extra = (finish[j] - start[j]) / 2 + 1;
			}

			if (time + extra >= finish[j]) {
				time += extra;
			}
			else {
				time = finish[j];
			}
		}
		
		std::cout << time << "\n";
	}
}
