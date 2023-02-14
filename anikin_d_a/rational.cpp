#include <iostream>
#include <istream>
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
    void common_denom(Rational& first, Rational& second);
    Rational& operator+=(Rational& rhs);
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
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs){
    return rhs.ReadFrom(istrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, Rational& rhs){
    rhs.WriteTo(ostrm);
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

void Rational::common_denom(Rational& first, Rational& second){
    int32_t common_denom;
    common_denom = first.denum * second.denum;
    first.num *= second.denum;
    second.num *= first.denum;
    first.denum = common_denom;
    second.denum = common_denom;
}

Rational& Rational::operator+=(Rational &rhs) {

}

int main() {
    Rational num_1 = Rational(1, 2);
    std::cin >> num_1;
    //num_1.gcd();
    std::cout << num_1;
}
