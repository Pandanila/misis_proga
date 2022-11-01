#include <iostream>
#include <string>
#include <vector>

int main(){
	int a = 0;
	int c = 0;
	std::cin >> a >> c;

	std::vector<int> av;
	std::vector<int> cv;

	while (a != 0) {
		av.push_back(a % 3);
		a /= 3;
	}

	while (c != 0) {
		cv.push_back(c % 3);
		c /= 3;
	}

	if (av.size() != cv.size()) {
		while (av.size() < cv.size()) {
			av.push_back(0);
		}
		while (av.size() > cv.size()) {
			cv.push_back(0);
		}
	}

	std::vector<int> bv;

	for (int i = 0; i < av.size(); i += 1) {
		if ()
	}
}
