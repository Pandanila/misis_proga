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

std::ostream& operator<<(std::ostream &out, const Rpol2D &point);

Rdec2D ToDec(Rpol2D vector);

Rpol2D ToPol(Rdec2D vector);

std::ostream& operator<<(std::ostream &out, const Rdec2D &point);

Rdec2D operator+=(Rdec2D& lhs, const Rdec2D& rhs);

Rdec2D operator-=(Rdec2D& lhs, const Rdec2D& rhs);

Rdec2D operator+(const Rdec2D& lhs, const Rdec2D& rhs);

Rdec2D operator-(const Rdec2D& lhs, const Rdec2D& rhs);

Rdec2D operator*=(Rdec2D& lhs, const double& rhs);

Rdec2D operator/=(Rdec2D& lhs, const double& rhs);

Rdec2D operator*(Rdec2D lhs, const double& rhs);

Rdec2D operator/(Rdec2D lhs, const double& rhs);

double norm(const Rdec2D& vec);

double dot(const Rdec2D& lhs, const Rdec2D& rhs);

Rpol2D operator+=(Rpol2D& lhs, const Rpol2D& rhs);

Rpol2D operator-=(Rpol2D& lhs, const Rpol2D& rhs);

Rpol2D operator+(const Rpol2D& lhs, const Rpol2D& rhs);

Rpol2D operator-(const Rpol2D& lhs, const Rpol2D& rhs);
