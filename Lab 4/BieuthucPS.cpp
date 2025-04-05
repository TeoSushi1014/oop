#include "BieuthucPS.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

BieuthucPS::BieuthucPS(int level) : Bieuthuc(level) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
    
    int gioihanln = (level <= 3) ? 10 : 100;
    
    a = Fraction(rand() % gioihanln + 1, rand() % gioihanln + 1);
    b = Fraction(rand() % gioihanln + 1, rand() % gioihanln + 1);
}

ostream& operator<<(ostream& out, BieuthucPS bt) {
    out << bt.a << " " << bt.pheptoan << " " << bt.b;
    return out;
}

bool BieuthucPS::kiemtra(float traloi) {
    return fabs(giatri() - traloi) < 0.0001;
}

float BieuthucPS::giatri() {
    switch (pheptoan) {
        case '+': return (a + b).giatri();
        case '-': return (a - b).giatri();
        case '*': return (a * b).giatri();
        default: return 0;
    }
} 