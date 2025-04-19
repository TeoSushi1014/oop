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
    static Fraction randomFraction(int range);
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    friend ostream& operator<<(ostream& os, const Fraction& f);
};