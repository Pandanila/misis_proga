#include <iostream>
#include <string>
#include <vector>

int main(){
	int t = 0;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		std::string s;
		std::getline(std::cin, s);

		std::vector<std::string> field(0);

		for (int j = 0; j < 8; j++) {
			std::string l;
			std::cin >> l;

			field.push_back(l);
		}

		int f = 1;

		int a = 0;
		int b = 0;

		for (int j = 1; j < 7; j++) {
			if (f) {
				for (int k = 1; k < 7; k++) {
					if (field[j][k] == '#') {
						if (field[j - 1][k - 1] == '#' && field[j + 1][k - 1] == '#' && field[j - 1][k + 1] == '#' && field[j + 1][k + 1] == '#') {
							a = j + 1;
							b = k + 1;
							f = 0;
							break;
						}
					}
				}
			}
		}

		std::cout << a << " " << b << "\n";
	}
}
