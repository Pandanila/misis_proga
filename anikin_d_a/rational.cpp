#include <ostream>

class Rational{
private:
    int32_t num{0};
    int32_t denum{1};
    static const char separator = '/';
public:
    Rational() = default;
    Rational(const Rational&) = default;
    Rational(int32_t in_num, int32_t in_denum);
    ~Rational() = default;
    std::istream& ReadFrom(std::istream& istrm);
    std::ostream& WriteTo(std::ostream& ostrm) const;
    void gcd();
    void common_denom(Rational& second);
    void operator+=(Rational& rhs);
    void operator-=(Rational& rhs);
    void operator*=(const Rational& rhs);
    void operator/=(const Rational& rhs);
    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational &rhs) const;
    bool operator>( Rational &rhs);
    bool operator<( Rational &rhs);
    bool operator>=( Rational &rhs);
    bool operator<=( Rational &rhs);
};

Rational::Rational(int32_t in_num, int32_t in_denum){
    if (in_denum <= 0){
        throw;
    }
    else {
        num = in_num;
        denum = in_denum;
    }
}

std::istream& Rational::ReadFrom(std::istream& istrm){
    char slash = 0;
    int32_t in_num = 0;
    int32_t in_denum = 1;
    istrm >> in_num >> slash >> in_denum;
    //std::cout << in_num << ' ' << slash << ' ' << in_denum << '\n';
    if (istrm.good()){
        if (slash == Rational::separator){
            num = in_num;
            denum = in_denum;
            gcd();
        }
        else{
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const{
    ostrm << num << separator << denum;
    return ostrm;
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs){
    return rhs.ReadFrom(istrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, Rational& rhs){
    return rhs.WriteTo(ostrm);
}


void Rational::gcd(){

    int32_t a = std::abs(num);
    int32_t b = std::abs(denum);
    int32_t divisor = 0;

    while (a % b != 0 || b % a != 0){
        if (a > b){
            a -= b;
        }
        else{
            b -= a;
        }
    }
    divisor = std::min(a, b);

    num /= divisor;
    denum /= divisor;

}

void Rational::common_denom(Rational& second){
    int32_t common_denom;
    common_denom = denum * second.denum;
    num *= second.denum;
    second.num *= denum;
    denum = common_denom;
    second.denum = common_denom;
}

void Rational::operator+=(Rational& rhs) {
    common_denom(rhs);
    num += rhs.num;
    gcd();
}

void Rational::operator-=(Rational& rhs) {
    common_denom(rhs);
    num -= rhs.num;
    gcd();
}

void Rational::operator*=(const Rational& rhs) {
    num *= rhs.num;
    denum *= rhs.denum;
    gcd();
}

void Rational::operator/=(const Rational& rhs){
    num *= rhs.denum;
    denum *= rhs.num;
    gcd();
}

bool Rational::operator==(const Rational& rhs) const {
    return (num == rhs.num) && (denum == rhs.denum);
}

bool Rational::operator!=(const Rational& rhs) const {
    return (num != rhs.num) || (denum != rhs.denum);
}

bool Rational::operator>(Rational &rhs){
    common_denom(rhs);
    return num > rhs.num;
};

bool Rational::operator<( Rational &rhs){
    common_denom(rhs);
    return num < rhs.num;
}

bool Rational::operator>=( Rational &rhs){
    common_denom(rhs);
    return num >= rhs.num;
}

bool Rational::operator<=( Rational &rhs){
    common_denom(rhs);
    return num <= rhs.num;
}

Rational& operator+(Rational& lhs, Rational& rhs){
    lhs += rhs;
    return lhs;
}

Rational& operator-(Rational& lhs, Rational& rhs){
    lhs -= rhs;
    return lhs;
}

Rational& operator*(Rational& lhs, Rational& rhs){
    lhs *= rhs;
    return lhs;
}

Rational& operator/(Rational& lhs, Rational& rhs){
    lhs /= rhs;
    return lhs;
}

int main() {
    Rational num_1 = Rational();
    Rational num_2 = Rational();
    std::cin >> num_1;
    std::cin >> num_2;
    std::cout << (num_1 >= num_2);
}
