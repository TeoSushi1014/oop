#include <iostream>
#include <fstream>
#include "Fraction.h"
using namespace std;

int main() {
    string filename;
    cout << "Nhap ten file: ";
    cin >> filename;
    ifstream file(filename);
    if (!file) {
        cout << "Khong mo duoc file!\n";
        return 1;
    }
    int n;
    file >> n;
    if (n <= 0) {
        cout << "So luong phan so khong hop le!\n";
        return 1;
    }
    Fraction max, min, f;
    file >> max;
    min = max;
    for (int i = 1; i < n; i++) {
        file >> f;
        if (f > max) max = f;
        if (f < min) min = f;
    }
    cout << min << endl;
    cout << max << endl;
    file.close();
    return 0;
}
