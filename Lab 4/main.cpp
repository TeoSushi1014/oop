#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "Bieuthuc.h"
using namespace std;

string taoline(int length, char character = '-') {
    return string(length, character);
}

void hienthitieude(const string& title1, const string& title2 = "") {
    cout << taoline(60, '-') << endl;
    cout << title1 << endl;
    if (!title2.empty()) {
        cout << title2 << endl;
    }
    cout << taoline(60, '-') << endl;
}

void hienthitencapdo(int level) {
    string tencapdo = "";
    
    switch (level) {
        case 1: tencapdo = "DỄ"; break;
        case 2: tencapdo = "TRUNG BÌNH"; break;
        case 3: tencapdo = "KHÓ"; break;
        case 4: tencapdo = "RẤT KHÓ"; break;
        case 5: tencapdo = "ĐỊA NGỤC"; break;
    }
    
    cout << "CẤP ĐỘ " << level << ": " << tencapdo << endl;
    cout << taoline(30, '-') << endl;
}

void hienthiketqua(bool dung, float dapandung, int diemcong) {
    if (dung) {
        cout << ">> CHÍNH XÁC! (+" << diemcong << " điểm)" << endl;
    } else {
        cout << ">> SAI! Đáp án đúng: " << dapandung << endl;
    }
}

void hienthithongke(int tongdiem, int socautraloidung, int tongsocau) {
    double tile = (tongsocau > 0) ? (socautraloidung * 100.0 / tongsocau) : 0;
    cout << "Điểm: " << tongdiem << " | Đúng: " << socautraloidung << "/" << tongsocau;
    cout << " (" << fixed << setprecision(1) << tile << "%)" << endl;
}

void hienthihuongdan() {
    cout << endl << taoline(60, '-') << endl;
    cout << "Nhấn ENTER để tiếp tục | C: Đổi cấp độ | ESC: Thoát" << endl;
}

int main() {
    SetConsoleOutputCP(65001);
    
    system("cls");
    hienthitieude("Họ và tên: Hoàng Việt Quang", "MSSV: 066206005044");
    
    int tongdiem = 0;
    int socautraloidung = 0;
    int tongsocau = 0;
    int socaudunglientuc = 0;
    char phim;
    int level = 1;
    bool tieptuc = true;
    
    while (tieptuc) {
        cout << endl;
        hienthitencapdo(level);
        
        Bieuthuc bt(level);
        
        cout << "Câu " << tongsocau + 1 << ": " << bt << " = ";
        
        float dapan;
        cin >> dapan;
        
        bool ketqua = bt.kiemtra(dapan);
        if (ketqua) {
            tongdiem += level;
            socautraloidung++;
            socaudunglientuc++;
            
            if (socaudunglientuc >= 3 && level < 5) {
                level++;
                cout << "\n>> CHÚC MỪNG! Bạn đã trả lời đúng 3 câu liên tiếp. Lên cấp độ " << level << "!" << endl;
                socaudunglientuc = 0;
            }
        } else {
            socaudunglientuc = 0;
        }
        
        cout << endl;
        hienthiketqua(ketqua, bt.giatri(), level);
        cout << endl;
        
        tongsocau++;
        hienthithongke(tongdiem, socautraloidung, tongsocau);
        
        hienthihuongdan();
        
        phim = _getch();
        
        if (phim == 27) {
            tieptuc = false;
        }
        else if (phim == 'c' || phim == 'C') {
            cout << "\nChọn cấp độ (1-5): ";
            cin >> level;
            cin.ignore();
            
            if (level < 1) level = 1;
            if (level > 5) level = 5;
            
            socaudunglientuc = 0;
        }
        
        if (tieptuc) {
            system("cls");
            hienthitieude("Họ và tên: Hoàng Việt Quang", "MSSV: 066206005044");
        }
    }
    
    system("cls");
    hienthitieude("KẾT QUẢ CUỐI CÙNG", "Họ và tên: Hoàng Việt Quang - MSSV: 066206005044");
    
    cout << endl;
    cout << "Tổng số câu hỏi:    " << tongsocau << endl;
    cout << "Số câu trả lời đúng: " << socautraloidung << endl;
    
    double tilecuoi = (tongsocau > 0) ? (socautraloidung * 100.0 / tongsocau) : 0;
    cout << "Tỉ lệ chính xác:    " << fixed << setprecision(1) << tilecuoi << "%" << endl;
    cout << "Tổng điểm:          " << tongdiem << endl;
    
    cout << endl;
    cout << "Cảm ơn bạn đã tham gia!" << endl;
    
    return 0;
} 