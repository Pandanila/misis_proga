#include <iostream>
#include <cmath>
#include <fstream>

struct Rdec2D {
	double x = 0;
	double y = 0;
};

struct Rpol2D {
	double r = 0;
	double phi = 0;
};

std::ostream& operator<<(std::ostream &out, const Rpol2D &point) {
	out << "(" << point.r << "," << point.phi << ")";
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
	out << "(" << point.x << "," << point.y << ")";
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

Rdec2D operator*=(Rdec2D& lhs, const int& rhs) {
	lhs.x *= rhs;
	lhs.y *= rhs;
	return lhs;
}

Rdec2D operator*(Rdec2D& lhs, const int& rhs) {
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

Rpol2D operator+=(Rpol2D lhs, Rpol2D rhs) {
	Rdec2D new_lhs = ToDec(lhs);
	Rdec2D new_rhs = ToDec(rhs);
	new_lhs += new_rhs;
	lhs = ToPol(new_lhs);
	std::cout << lhs << "\n";
	return lhs;
}
//модификация № 1. Когда неизвестна первоначальная скорость противоядра
int main() {
	Rdec2D core_rad_vector_1 = { 0, 6 };
	Rdec2D core_velocity_1 = { 10, 1000 };
	Rdec2D core_velocity_x_1 = { core_velocity_1.x, 0 };
	Rdec2D core_velocity_y_1 = { 0, core_velocity_1.y };
	Rdec2D core_rad_vector_2 = { 200, 6 };
	Rdec2D core_velocity_2 = { -10, 5000 };
	Rdec2D core_velocity_x_2 = { core_velocity_2.x, 0 };
	Rdec2D core_velocity_y_2 = { 0, core_velocity_2.y };
	Rdec2D g = { 0, -9.8 };
	double s = norm(core_rad_vector_1 - core_rad_vector_2);
	double t_1 = 0;
	double delta_t = 0.1;

	//вычисляем время, за которое звук достигнет точки запуска противоядра
	double sound_t = s / 331;
	//double sound_t = 1;

	std::ofstream file; 
	file.open("new.csv");



	while (t_1 < 25 && core_rad_vector_1.y >= 0) {
		t_1 += delta_t;
		core_velocity_y_1 += g;
		core_velocity_1 = core_velocity_x_1 + core_velocity_y_1;
		core_rad_vector_1 += core_velocity_1;
		if (t_1 >= sound_t) {
			core_velocity_y_2 += g;
			core_velocity_2 = core_velocity_x_2 + core_velocity_y_2;
			core_rad_vector_2 += core_velocity_2;
			/*core_velocity_y_1 += g;
			core_velocity_1 = core_velocity_x_1 + core_velocity_y_1;
			core_rad_vector_1 += core_velocity_1;
			core_velocity_2 = core_rad_vector_1 - core_rad_vector_2 - g;
			std::cout << core_velocity_2;*/
			file << core_rad_vector_1.x << "\t" << core_rad_vector_1.y << " \t" << core_rad_vector_2.x << "\t" << core_rad_vector_2.y << "\n";
			if (core_rad_vector_2.y == core_rad_vector_1.y && core_rad_vector_2.x == core_rad_vector_1.x) {
				std::cout << "";
				break;
			}
		}
	}

	file.close();
}
