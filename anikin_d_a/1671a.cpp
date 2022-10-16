#include <iostream>
#include <vector>
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
		if (s.length() == 1) {
			std::cout << "NO";
			continue;
		}
		for (int j = 1; j < s.length(); j++) {
			if (s[j] == us[0]) {
				us += s[j];
			}
			else {
				if (not(us.length() % 2 == 0 | us.length() % 3 == 0)) {
					std::cout << "NO";
					flag = 0;
					break;
				}
				us = s[j];
			}
		}
		if (flag) {
			std::cout << "YES";
		}
	}
}
