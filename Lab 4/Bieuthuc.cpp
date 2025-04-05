#include "Bieuthuc.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

void Bieuthuc::sinhSoNgauNhien(int level) {
    switch (level) {
        case 1: // Level 1: Số từ 1-10
            a = random(1, 10);
            b = random(1, 10);
            break;
        case 2: // Level 2: Số từ 10-30
            a = random(10, 30);
            b = random(10, 30);
            break;
        case 3: // Level 3: Số từ 10-50
            a = random(10, 50);
            b = random(10, 50);
            break;
        default: // Level 4+: Số từ 10-100
            a = random(10, 100);
            b = random(10, 100);
    }
}

void Bieuthuc::sinhPhepToanNgauNhien(int level) {
    switch (level) {
        case 1: // Level 1: Chỉ cộng
            pheptoan = '+';
            break;
        case 2: // Level 2: Cộng hoặc trừ
            pheptoan = (random(0, 1) == 0) ? '+' : '-';
            break;
        default: // Level 3+: Tất cả phép toán
            int op = random(0, 2);
            pheptoan = (op == 0) ? '+' : (op == 1) ? '-' : '*';
    }
    
    // Đảm bảo kết quả phép trừ không âm
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