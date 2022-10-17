#include <iostream>

int main(){
	int t = 0;
	std::cin >> t;
	
	for (int i = 0; i < t; i++) {
		int s = 0;
		
		for (int j = 0; j < 4; j++) {
			int a = 0;
			std::cin >> a;
			if (a == 1) {
				s += 1;
			}
		}
		if (s == 0) {
			std::cout << 0 << "\n";
		}
		else if (s == 4) {
			std::cout << 2 << "\n";
		}
		else {
			std::cout << 1 << "\n";
		}
	}
}
