#include "Fraction.h"

Fraction::Fraction(int t, int m) {
    tu = t;
    mau = (m == 0) ? 1 : m;
}

ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.tu << "/" << f.mau;
    return out;
}

float Fraction::giatri() const {
    return (float)tu / mau;
}

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(tu * other.mau + other.tu * mau, mau * other.mau);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(tu * other.mau - other.tu * mau, mau * other.mau);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(tu * other.tu, mau * other.mau);
} 