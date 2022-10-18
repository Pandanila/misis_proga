#include <iostream>
#include <string>
#include <vector>

int main(){
	int n = 0;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int x = 0;
	int y = 0;

	if (s[0] == 'R') {
		x += 1;
	}
	if (s[0] == 'U') {
		y += 1;
	}

	int x1 = 0;
	int y1 = 0;
	x1 = x;
	y1 = y;

	int k = 0;

	for (int i = 1; i < n; i++) {
		if (s[i] == 'R') {
			x += 1;
		}
		if (s[i] == 'U') {
			y += 1;
		}
		if (x1 == y1 && (y - y1 == 1 | x - x1 == 1)) {
			k += 1;
		}
		x1 = x;
		y1 = y;
	}
	std::cout << k << "\n"; 
}
