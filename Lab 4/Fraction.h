#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
    int tu, mau;
public:
    Fraction(int t = 0, int m = 1);
    friend ostream& operator<<(ostream& out, const Fraction& f);
    float giatri() const;
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
};