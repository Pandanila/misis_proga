#include <iostream>
 
int main(){
	int x = 0;
	std::cin >> x;
	int count = 0;
	
	while (x != 0){
	    if ((x % 2) & 1){
	        count += 1;
	    }
	    x >>= 1;
	}
	
	std::cout << count;
}
