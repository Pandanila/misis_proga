#include <iostream>
#include <string>
#include <vector>
#include <cmath>


int razl(int num){
	int count = 0;
	while (num % 2 == 0) {
		count += 1;
		num /= 2;
	}
	return count;
}

 
int main(){
	int t = 0;
	std::cin >> t;
 
	for (int i = 0; i < t; i += 1) {
		int n = 0;
		std::cin >> n;
		int num_2 = 0;

		for (int k = 0; k < n; k++) {
			int number = 0;
			std::cin >> number;
			num_2 += razl(number);
		}
		
		if (num_2 >= n){
		    std::cout << 0 << "\n";
		    continue;
		}
		
		int tries = 0;
		int q = 0;
		int flag = 1;
		int j = 0;
		
		q = int(std::log(n)/std::log(2));
		
		std::cout << q;
		
		while (q != 0){
		    q = int(std::log(n)/std::log(2)) - j;
		    for (int k = 1; k < n + 1; k++){
		        if (razl(k) == q){
		            num_2 += q;
		            tries += 1;
		        }
		        if (num_2 >= n){
		            std::cout << tries;
		            flag = 0;
		            break;
		        }
		    }
		    j += 1; 
		}
		
		if (flag) {
		    std::cout << -1;
		}
	}
}
