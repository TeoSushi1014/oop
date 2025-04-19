#pragma once
#include "Bieuthuc.h"
#include <iostream>
using namespace std;
class BieuthucPT : public Bieuthuc
{
private:
    int c, d;
public:
    BieuthucPT(int level);
    friend ostream& operator<<(ostream& out, BieuthucPT bt);
    bool kiemtra(float traloi);
    float giatri();
}; 