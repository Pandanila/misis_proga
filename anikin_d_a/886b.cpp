#include <iostream>
#include <set>
#include <vector>
 
int main() {
	int n = 0;
	std::cin >> n;
	std::vector<int> v;
	std::set<int> s;
	
	for (int i = 0; i < n; i++) {
		int a = 0;
		std::cin >> a;
		v.push_back(a);
		s.insert(a);
	}
 
	std::set<int> s_1;
 
	for (int i = v.size() - 1; i > -1; i -= 1) {
		if (s.size() - 1 == s_1.size() && s_1.count(v[i]) == 0) {
			std::cout << v[i];
			break;
		}
		s_1.insert(v[i]);
	}
}
