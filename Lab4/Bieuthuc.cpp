#include "Bieuthuc.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Bieuthuc::Bieuthuc(int level) {
    srand(time(NULL));
    
    int gioihanln = (level <= 3) ? 10 : 100;
    
    a = rand() % gioihanln + 1;
    b = rand() % gioihanln + 1;
    
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

ostream& operator<<(ostream& out, Bieuthuc bt) {
    out << bt.a << " " << bt.pheptoan << " " << bt.b;
    return out;
}

bool Bieuthuc::kiemtra(float traloi) {
    return abs(giatri() - traloi) < 0.0001;
}

float Bieuthuc::giatri() {
    switch (pheptoan) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default: return 0;
    }
}