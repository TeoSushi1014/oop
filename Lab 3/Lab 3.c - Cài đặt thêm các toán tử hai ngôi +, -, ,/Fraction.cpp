#include "Fraction.h"

int Fraction::ucln(int a, int b) const {
    return b == 0 ? abs(a) : ucln(b, a % b);
}

void Fraction::rutgon() {
    int divisor = ucln(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction(int num, int den) {
    numerator = num;
    denominator = den;
}

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator,
                   denominator * other.denominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator,
                   denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction kq(numerator * other.numerator, denominator * other.denominator);
    kq.rutgon();
    return kq;
}

Fraction Fraction::operator/(const Fraction& other) const {
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction temp = *this;
    numerator += denominator;
    return temp;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction temp = *this;
    numerator -= denominator;
    return temp;
}

ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}
