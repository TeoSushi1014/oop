#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
public:
    Fraction(int num = 0, int den = 1);
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);
    friend ostream& operator<<(ostream& os, const Fraction& f);
};