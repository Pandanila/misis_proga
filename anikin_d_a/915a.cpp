#include <iostream>
 
int main(){
	int n = 0;
	int k = 0;
	std::cin >> n >> k;
	int hours = 1000000;
	for (int i = 0; i < n; i++) {
		int vedro = 0;
		std::cin >> vedro;
		if (k % vedro == 0 && k / vedro < hours){
			hours = k / vedro;
		}
	}
	std::cout << hours;
}
