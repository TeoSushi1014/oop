#include "Fraction.h"

Fraction::Fraction(int num, int den) {
    numerator = num;
    denominator = den;
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
