#include "Bieuthuc.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

void Bieuthuc::sinhSoNgauNhien(int level) {
    switch (level) {
        case 1:
            a = random(1, 10);
            b = random(1, 10);
            break;
        case 2:
            a = random(10, 30);
            b = random(10, 30);
            break;
        case 3:
            a = random(10, 50);
            b = random(10, 50);
            break;
        default:
            a = random(10, 100);
            b = random(10, 100);
    }
}

void Bieuthuc::sinhPhepToanNgauNhien(int level) {
    switch (level) {
        case 1:
            pheptoan = '+';
            break;
        case 2:
            pheptoan = (random(0, 1) == 0) ? '+' : '-';
            break;
        default:
            int op = random(0, 2);
            pheptoan = (op == 0) ? '+' : (op == 1) ? '-' : '*';
    }
    
    if (pheptoan == '-' && b > a) {
        std::swap(a, b);
    }
}

Bieuthuc::Bieuthuc(int level) {
    sinhSoNgauNhien(level);
    sinhPhepToanNgauNhien(level);
}

ostream& operator<<(ostream& out, Bieuthuc bt) {
    out << bt.a << " " << bt.pheptoan << " " << bt.b << " = ";
    return out;
}

bool Bieuthuc::kiemtra(float traloi) {
    return traloi == giatri();
}

float Bieuthuc::giatri() {
    switch (pheptoan) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default: return 0;
    }
}