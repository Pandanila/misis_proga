#include <iostream>
#include <cmath>

struct Rdec2D {
	double x = 0;
	double y = 0;
};

struct Rpol2D {
	double r = 0;
	double phi = 0;
};

std::ostream& operator<<(std::ostream &out, const Rdec2D &point){
	out << "(" << point.x << "," << point.y << ")" << "\n";
	return out;
}

Rdec2D operator+=(Rdec2D& lhs, const Rdec2D& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return lhs;
}

Rdec2D operator-=(Rdec2D& lhs, const Rdec2D& rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	return lhs;
}

Rdec2D operator+(const Rdec2D& lhs, const Rdec2D& rhs) {
	Rdec2D res = lhs;
	res += rhs;
	return res;
}

Rdec2D operator-(const Rdec2D& lhs, const Rdec2D& rhs) {
	Rdec2D res = lhs;
	res -= rhs;
	return res;
}

Rdec2D& operator*=(Rdec2D& lhs, const int& rhs) {
	lhs.x *= rhs;
	lhs.y *= rhs;
	return lhs;
}

Rdec2D& operator*(Rdec2D& lhs, const int& rhs) {
	Rdec2D& res = lhs;
	res *= rhs;
	return res;
}

double norm(const Rdec2D& vec) {
	return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

double dot(const Rdec2D& lhs, const Rdec2D& rhs) {
	return (lhs.x*rhs.x + lhs.y*rhs.y);
}

int main() {
	Rdec2D point_1{ 0, 1 };
	Rdec2D point_2{ 1, 3 };
	point_1 += point_2;
	std::cout << point_1;
	Rdec2D point = point_1 + point_2;
	std::cout << point_1;
	std::cout << point_1 * 2;
	std::cout << norm(point_1) << '\n';
	std::cout << dot(point_1, point_2);
}
