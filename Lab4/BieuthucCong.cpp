#include "BieuthucCong.h"
#include <cstdlib>
#include <ctime>

BieuthucCong::BieuthucCong(int level) : Bieuthuc(level) {
    pheptoan = '+';
}

float BieuthucCong::giatri() {
    return a + b;
} 