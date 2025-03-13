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
        cout << "Nhập tử số: ";
        cin >> tu;
        do {
            cout << "Nhập mẫu số: ";
            cin >> mau;
            if (mau == 0) {
                cout << "Mẫu số phải khác 0" << endl;
            }
        } while (mau == 0);
    }
    void xuat() {
        cout << tu << "/" << mau << endl;
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
    cout << "==============================================================================" << endl;
    cout << "MSSV: 066206005044" << endl;
    cout << "Họ và tên: Hoàng Việt Quang" << endl;
    cout << "==============================================================================" << endl;
    phanso ps1, ps2;
    cout << "Nhập phân số thứ nhất: " << endl;
    ps1.nhap();
    cout << "Nhập phân số thứ hai: " << endl;
    ps2.nhap();
    cout << "Phân số thứ nhất: ";
    ps1.xuat();
    cout << "Phân số thứ hai: ";
    ps2.xuat();
    phanso tong = ps1 + ps2;
    cout << "Tổng hai phân số: ";
    tong.xuat();
    cout << "Nhấn phím bất kỳ để thoát chương trình..." << endl;
    cin.get();
    return 0;
}