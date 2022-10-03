#include <iostream>
#include <cmath>

int main()
{
	const float PI = 3.14159265358979323846;
	std::cout << "x" << "\t" << "s(x)" << "\t" << "f(x)" << "\n";
	int a = 0;
	int b = 1;
	float g = 0.05;
	float e = 0.001;
	for (float x = a; x < b + g; x += g) {
		int i = 1;
		float s = 0;

		float k = std::pow(x, i) * std::sin(i * PI);
		s = k;
		i = 2;

		while (k >= e) {
			k = std::pow(x, i) * std::sin(i * PI);
			s += k;
			i += 1;
		}

		float f = (x * std::sin(PI / 4)) / (1 - 2 * x*std::cos(PI / 4));
		std::cout << x << "\t" << s << "\t" << f << "\n";
	}
}
