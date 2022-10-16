#include <iostream>
#include <vector>

int main(){
	int n = 0;
	std::cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		int p = 0;
		std::cin >> p;
		v[p - 1] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		std::cout << v[i] << " ";
	}
}
