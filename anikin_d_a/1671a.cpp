#include <iostream>
#include <string>

int main(){
	int t = 0;
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::string s;
		std::cin >> s;
		std::string us;
		us = s[0];
		int flag = 1;
		for (int j = 1; j < s.length(); j++) {
			if (s[j] == us[0]) {
				us += s[j];
			}
			else {
				if (us.length() == 1) {
					std::cout << "NO" << "\n";
					flag = 0;
					break;
				}
				us = s[j];
			}
		}
		if (us.length() == 1 && flag) {
			std::cout << "NO" << "\n";
		}
		else if (flag) {
			std::cout << "YES" << "\n";
		}
	}
}
