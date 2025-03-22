#include "Fraction.h"

int Fraction::ucln(int a, int b) const {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void Fraction::rutgon() {
    int ucln_val = ucln(numerator, denominator);
    numerator /= ucln_val;
    denominator /= ucln_val;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}
Fraction::Fraction(int num, int den) {
    if (den == 0) {
        numerator = 0;
        denominator = 1;
    }
    else {
        numerator = num;
        denominator = den;
        rutgon();
    }
}
Fraction Fraction::randomFraction(int range) {
    if (range <= 0) range = 1;
    int num = rand() % (range + 1);
    int den = rand() % range + 1;
    return Fraction(num, den);
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}
bool Fraction::operator>(const Fraction& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}
bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}
ostream& operator<<(ostream& os, const Fraction& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}