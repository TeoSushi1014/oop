#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
    int ucln(int a, int b) const;
    void rutgon();
public:
    Fraction(int num = 0, int den = 1);
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);
    friend ostream& operator<<(ostream& os, const Fraction& f);
};