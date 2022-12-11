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

std::ostream& operator<<(std::ostream &out, const Rpol2D &point) {
	out << "(" << point.r << "," << point.phi << ")" << "\n";
	return out;
}

Rdec2D ToDec(Rpol2D vector) {
	double x = std::cos(vector.phi) * vector.r;
	double y = std::sin(vector.phi) * vector.r;
	Rdec2D new_vector{ x, y };
	return new_vector;
}

Rpol2D ToPol(Rdec2D vector) {
	double r = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	double phi = std::asin(vector.y / r);
	Rpol2D new_vector{ r, phi };
	return new_vector;
}

std::ostream& operator<<(std::ostream &out, const Rdec2D &point) {
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

Rdec2D operator*=(Rdec2D& lhs, const double& rhs) {
	lhs.x *= rhs;
	lhs.y *= rhs;
	return lhs;
}

Rdec2D operator/=(Rdec2D& lhs, const double& rhs) {
	lhs.x /= rhs;
	lhs.y /= rhs;
	return lhs;
}

Rdec2D operator*(Rdec2D lhs, const double& rhs) {
	Rdec2D& res = lhs;
	res *= rhs;
	return res;
}

Rdec2D operator/(Rdec2D lhs, const double& rhs) {
	Rdec2D& res = lhs;
	res /= rhs;
	return res;
}

double norm(const Rdec2D& vec) {
	return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}

double dot(const Rdec2D& lhs, const Rdec2D& rhs) {
	return (lhs.x*rhs.x + lhs.y*rhs.y);
}

Rpol2D operator+=(Rpol2D& lhs, const Rpol2D& rhs) {
	Rdec2D new_lhs = ToDec(lhs);
	Rdec2D new_rhs = ToDec(rhs);
	new_lhs += new_rhs;
	lhs = ToPol(new_lhs);
	return lhs;
}

Rpol2D operator-=(Rpol2D& lhs, const Rpol2D& rhs) {
	Rdec2D new_lhs = ToDec(lhs);
	Rdec2D new_rhs = ToDec(rhs);
	new_lhs -= new_rhs;
	lhs = ToPol(new_lhs);
	return lhs;
}

Rpol2D operator+(const Rpol2D& lhs, const Rpol2D& rhs) {
	Rpol2D res = lhs;
	res += rhs;
	return res;
}

Rpol2D operator-(const Rpol2D& lhs, const Rpol2D& rhs) {
	Rpol2D res = lhs;
	res -= rhs;
	return res;
}

int main() {
	/*Rdec2D point_1{ 0, 1 };
	Rdec2D point_2{ 1, 3 };
	point_1 += point_2;
	std::cout << point_1;
	Rdec2D point = point_1 + point_2;
	std::cout << point_1;
	std::cout << point_1 * 2;
	std::cout << norm(point_1) << '\n';
	std::cout << dot(point_1, point_2);*/


	Rdec2D point{ 929.087,1922.01 };
	Rpol2D new_point = ToPol(point);
	Rpol2D point_1 = { 12, 0 };
	new_point += point_1;
	std::cout << new_point;
	//point += new_point;
	//std::cout << point;
}
