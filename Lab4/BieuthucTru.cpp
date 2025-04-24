#include "BieuthucTru.h"
#include <cstdlib>
#include <ctime>

BieuthucTru::BieuthucTru(int level) : Bieuthuc(level) {
    pheptoan = '-';
    
    if (level <= 2) {
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
    }
}

float BieuthucTru::giatri() {
    return a - b;
} 