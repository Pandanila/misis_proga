#include <iostream>
#include <cmath>

int main()
{
	std::cout << "x" << "\t" << "s(x)" << "\t" << "f(x)" << "\n";
	int a = -1;
	int b = 1;
	float g = 0.1;
	float e = 0.001;
	for (float x = a; x < b + g; x += g) {
		int i = 0;
		float s = 0;
		int fact = 1;
		for (int j = 1; j < 2*i + 1; j++) {
			fact *= j;
		}
		float k = (std::pow((-1), i) * std::pow(x, 2 * i)) / fact;
		s = k;
		i = 1;
		while (k >= e) {
			fact = 1;
			for (int j = 1; j < 2 * i + 1; j++) {
				fact *= j;
			}
			k = (std::pow((-1), i) * std::pow(x, 2 * i)) / fact;
			s += k;
			i += 1;
		}
		float f = 0;
		f = std::cos(x);
		std::cout << x << "\t" << s << "\t" << f << "\n";
	}
}
