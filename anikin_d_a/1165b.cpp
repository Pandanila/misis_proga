#include <iostream>
#include <vector>

int main(){
	std::vector<int> nums;
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; i += 1) {
		int a = 0;
		std::cin >> a;
		nums.push_back(a);
	}



	std::cout << nums.size();
}

решить с помощью сортирвоки массива
