#include <iostream>
#include <set>
#include <vector>
 
int main() {
	int n = 0;
	std::cin >> n;
	std::vector<int> marks;
	std::multiset<int> rate;
 
	for (int i = 0; i < n; i++) {
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		std::cin >> a >> b >> c >> d;
		marks.push_back(a + b + c + d);
		rate.insert(a + b + c + d);
	}
 
	std::set<int>::iterator it = rate.begin();
	long long int place = -1;
 
	for (int i = 0;  it != rate.end(); it++, i++) {
		if (*it == marks[0] && i >= place) {
			place = i;
		}
	}
 
	std::cout << rate.size() - place;
}
