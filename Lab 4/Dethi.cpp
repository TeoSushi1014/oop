#include "Dethi.h"
#include "Bieuthuc.h"
#include "BieuthucCong.h"
#include "BieuthucTru.h"
#include "BieuthucNhan.h"
#include <fstream>

Dethi::Dethi(int n1, int n2, int n3) {
    level = 1;
    socaudung = 0;
    socaulientiep = 0;
    
    taoCauHoi(1, n1);
    taoCauHoi(2, n2);
    taoCauHoi(3, n3);
    
    dapan.resize(cauhoi.size(), 0);
}

void Dethi::taoCauHoi(int level, int socau) {
    for (int i = 0; i < socau; i++) {
        cauhoi.push_back(Bieuthuc(level));
    }
}

void Dethi::hienThiCauHoi(int stt) {
    if (stt >= 0 && stt < cauhoi.size()) {
        cout << "Câu " << stt + 1 << ": ";
        cout << cauhoi[stt];
    }
}

bool Dethi::kiemTraDapAn(int stt, float traloi) {
    if (stt >= 0 && stt < cauhoi.size()) {
        dapan[stt] = traloi;
        bool ketqua = cauhoi[stt].kiemtra(traloi);
        if (ketqua) {
            socaudung++;
            socaulientiep++;
        } else {
            socaulientiep = 0;
        }
        return ketqua;
    }
    return false;
}

void Dethi::capNhatLevel() {
    if (socaulientiep >= 3) {
        level = min(level + 1, 4);
        socaulientiep = 0;
    }
    else if (socaulientiep == 0 && level > 1) {
        level--;
    }
}

void Dethi::luuKetQua(const string& tenfile) {
    ofstream file(tenfile);
    if (file.is_open()) {
        file << "Số câu: " << getSoCau() << endl;
        file << "Số câu đúng: " << getSoCauDung() << endl;
        file << "Level đạt được: " << getLevel() << endl;
        
        for (int i = 0; i < cauhoi.size(); i++) {
            file << "Câu " << i + 1 << ": ";
            file << cauhoi[i].getA() << " " << cauhoi[i].getPhepToan() << " " 
                 << cauhoi[i].getB() << " = " << dapan[i];
            file << " (" << (cauhoi[i].kiemtra(dapan[i]) ? "Đúng" : "Sai") << ")" << endl;
        }
        file.close();
    }
}

void Dethi::docKetQua(const string& tenfile) {
    ifstream file(tenfile);
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
