#include "Dethi.h"
#include "Bieuthuc.h"
#include "BieuthucCong.h"
#include "BieuthucTru.h"
#include "BieuthucNhan.h"

Dethi::Dethi(int n1, int n2, int n3, int level) {
    int i;
    
    for (i = 0; i < n1; i++) {
        ds.push_back(BieuthucCong(level));
    }
    
    for (i = 0; i < n2; i++) {
        ds.push_back(BieuthucTru(level));
    }
    
    for (i = 0; i < n3; i++) {
        ds.push_back(BieuthucNhan(level));
    }
}

void Dethi::xuat(ostream& output) {
    int i;
    int n = ds.size();
    for (i = 0; i < n; i++) {
        output << ds[i];
        output << "\n";
    }
}

int Dethi::danhgia(istream& input) {
    int i;
    int diem = 0;
    int dapan;
    int n = ds.size();
    
    for (i = 0; i < n; i++) {
        input >> dapan;
        if (dapan == ds[i].giatri()) {
            diem = diem + 1;
        }
    }
    
    return diem;
}
