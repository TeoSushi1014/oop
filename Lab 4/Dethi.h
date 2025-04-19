#pragma once
#include "Bieuthuc.h"
#include <vector>
#include <iostream>

using namespace std;
class Dethi {
private:
    vector<Bieuthuc> cauhoi;
    vector<float> dapan;
    int socaudung;
    int level;
    int socaulientiep;
    
public:
    Dethi(int n1 = 3, int n2 = 4, int n3 = 3);
    
    void taoCauHoi(int level, int socau);
    void hienThiCauHoi(int stt);
    bool kiemTraDapAn(int stt, float traloi);
    void capNhatLevel();
    
    int getSoCau() const { return cauhoi.size(); }
    int getSoCauDung() const { return socaudung; }
    int getLevel() const { return level; }
    int getSoCauLienTiep() const { return socaulientiep; }
    
    void luuKetQua(const string& tenfile);
    void docKetQua(const string& tenfile);
};