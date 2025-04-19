#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>
#include <cmath>

using namespace std;

class phanso {
private:
    int tu, mau;
    int timucln(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (a != b) {
            if (a > b) a -= b;
            else b -= a;
        }
        return a;
    }

public:
    phanso(int t = 0, int m = 1) {
        if (m == 0) {
            cout << "Mẫu số phải khác 0" << endl;
            tu = 0;
            mau = 1;
        }
        else {
            tu = t;
            mau = m;
        }
    }

    void dattuso(int t) {
        tu = t;
    }
    void datmauso(int m) {
        if (m == 0) {
            cout << "Mẫu số phải khác 0" << endl;
            return;
        }
        mau = m;
    }

    int laytuso() {
        return tu;
    }
    int laymauso() {
        return mau;
    }
    void nhap() {
        string input;
        bool valid = false;
        
        while (!valid) {
            getline(cin, input);
            
            size_t pos = input.find('/');
            
            if (pos != string::npos) {
                try {
                    string tuso = input.substr(0, pos);
                    string mauso = input.substr(pos + 1);
                    
                    tu = stoi(tuso);
                    mau = stoi(mauso);
                    
                    if (mau == 0) {
                        cout << "Mẫu số phải khác 0. Vui lòng nhập lại: ";
                    } else {
                        valid = true;
                    }
                } catch (...) {
                    cout << "Định dạng không hợp lệ. Vui lòng nhập lại (dạng a/b): ";
                }
            } else {
                cout << "Định dạng không hợp lệ. Vui lòng nhập lại (dạng a/b): ";
            }
        }
    }
    void xuat() {
        rutgon();
        if (mau == 1) {
            cout << tu << endl;
        } else {
            cout << tu << "/" << mau << endl;
        }
    }
    void rutgon() {
        if (tu == 0) {
            return;
        }
        int ucln = timucln(abs(tu), abs(mau));
        tu /= ucln;
        mau /= ucln;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }
    phanso operator+(phanso b) {
        phanso c;
        c.tu = tu * b.mau + b.tu * mau;
        c.mau = mau * b.mau;
        c.rutgon();
        return c;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    
    char choice;
    do {
        system("cls");
        cout << "====================================================================================" << endl;
        cout << "MSSV: 066206005044" << endl;
        cout << "Họ và tên: Hoàng Việt Quang" << endl;
        cout << "Source code: https://github.com/TeoSushi1014/oop/tree/main/066206005044_Chuong3_Bai2" << endl;
        cout << "====================================================================================" << endl;
        cout << endl;
        
        phanso ps1, ps2;
        
        cout << "Nhập phân số thứ nhất (dạng a/b): ";
        ps1.nhap();
        
        cout << "Nhập phân số thứ hai (dạng a/b): ";
        ps2.nhap();
        
        phanso tong = ps1 + ps2;
        cout << "Tổng hai phân số: ";
        tong.xuat();
        
        cout << "\nBạn có muốn tiếp tục? (y/n): ";
        cin >> choice;
        cin.ignore();
        
    } while (choice == 'y' || choice == 'Y');
    
    cout << "Kết thúc chương trình." << endl;
    return 0;
}