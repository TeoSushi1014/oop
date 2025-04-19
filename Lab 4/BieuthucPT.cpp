#include "BieuthucPT.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

BieuthucPT::BieuthucPT(int level) : Bieuthuc(level) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
    
    int gioihanln = (level <= 3) ? 10 : 100;
    
    a = rand() % gioihanln + 1;
    b = rand() % gioihanln + 1;
    c = rand() % gioihanln + 1;
    d = rand() % gioihanln + 1;
    
    if (level == 1) {
        pheptoan = '+';
    }
    else if (level == 2 || level == 4) {
        pheptoan = (rand() % 2 == 0) ? '+' : '-';
    }
    else {
        int op = rand() % 3;
        switch (op) {
            case 0: pheptoan = '+'; break;
            case 1: pheptoan = '-'; break;
            case 2: pheptoan = '*'; break;
        }
    }
}

ostream& operator<<(ostream& out, BieuthucPT bt) {
    out << "(" << bt.a << " " << bt.pheptoan << " " << bt.b << ") " 
        << bt.pheptoan << " "
        << "(" << bt.c << " " << bt.pheptoan << " " << bt.d << ")";
    return out;
}

bool BieuthucPT::kiemtra(float traloi) {
    return fabs(giatri() - traloi) < 0.0001;
}

float BieuthucPT::giatri() {
    float first, second;
    
    switch (pheptoan) {
        case '+': first = a + b; break;
        case '-': first = a - b; break;
        case '*': first = a * b; break;
        default: first = 0;
    }
    
    switch (pheptoan) {
        case '+': second = c + d; break;
        case '-': second = c - d; break;
        case '*': second = c * d; break;
        default: second = 0;
    }
    
    switch (pheptoan) {
        case '+': return first + second;
        case '-': return first - second;
        case '*': return first * second;
        default: return 0;
    }
} 