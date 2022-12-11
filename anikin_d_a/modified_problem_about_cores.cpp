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

int collision_of_cores(Rdec2D r_1, Rdec2D v_1_x, Rdec2D v_1_y,
                       Rdec2D r_2, Rdec2D v_2_x, Rdec2D v_2_y,
                       double delta_t, double delta_s){            /*delta_s - допустимая погрещность в
                                                                    координатах при столкновении*/
    //описываем скалярные величины
    double s = norm(r_1 - r_2);      //расстояние между ядрами
    double t_of_sound = s / 331;         //время, за которое звук дойдет от ядра до противоядра
    double t = 0;                        //счетчик времени
    //описываем векторные величины
    Rdec2D g = {0, -9.8};          //вектор ускорения свободного падения
    Rdec2D v_1 = v_1_x + v_1_y;          // вектор скорости ядра
    Rdec2D v_2 = v_2_x + v_2_y;          // вектор скорости противоядра

    // смотрим, столкнутся или нет
    while (true){
        t += delta_t;
        v_1_y += g;
        v_1 = v_1_y + v_1_x;             //считаем вектор скорости ядра в каждый момент времени
        r_1 += v_1;                      //считаем расположение ядра в каждый момент времени

        if (t >= t_of_sound){            //если пришло время, запускаем противоядро
            v_2_y += g;
            v_2 = v_2_y + v_2_x;
            r_2 += v_2;
        }

        if (std::abs(norm(r_1 - r_2)) <= delta_s){
            return 1;
        }

        if (r_1.x < r_2.x){
            return 0;
        }
    }
}
