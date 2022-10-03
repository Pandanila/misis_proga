#include <iostream>
#include <cmath>

int main()
{
	const float E = 2.7182818284;
	std::cout << "x" << "\t" << "s(x)" << "\t" << "f(x)" << "\n";
	int a = 0;
	int b = 1;
	float g = 0.1;
	float e = 0.0001;
	for (float x = a; x < b + g; x += g) {
		int i = 0;
		float s = 0;

		int fact = 1;
		for (int j = 1; j < i + 1; j++) {
			fact *= j;
		}

		float k = std::pow(2*x, i) / fact;
		s = k;
		i = 1;

		while (k >= e) {
			int fact = 1;
			for (int j = 1; j < i + 1; j++) {
				fact *= j;
			}

			k = std::pow(2 * x, i) / fact;
			s += k;
			i += 1;
		}

		float f = std::pow(E, 2 * x);
		std::cout << x << "\t" << s << "\t" << f << "\n";
	}
}
