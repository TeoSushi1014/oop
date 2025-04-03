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

int main() {
    SetConsoleOutputCP(65001);
    
    system("cls");
    cout << taoline(60, '-') << endl;
    cout << "Họ và tên: Hoàng Việt Quang" << endl;
    cout << "MSSV: 066206005044" << endl;
    cout << "Github: https://github.com/TeoSushi1014/oop/tree/main/Lab%204" << endl;
    cout << taoline(60, '-') << endl;
    
    int tongdiem = 0;
    int socautraloidung = 0;
    int tongsocau = 0;
    int socaudunglientuc = 0;
    char phim;
    int level = 1;
    bool tieptuc = true;
    
    while (tieptuc) {
        cout << endl;
        
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
        if (ketqua) {
            cout << ">> CHÍNH XÁC! (+" << level << " điểm)" << endl;
        } else {
            cout << ">> SAI! Đáp án đúng: " << bt.giatri() << endl;
        }
        cout << endl;
        
        tongsocau++;
        
        double tile = (tongsocau > 0) ? (socautraloidung * 100.0 / tongsocau) : 0;
        cout << "Điểm: " << tongdiem << " | Đúng: " << socautraloidung << "/" << tongsocau;
        cout << " (" << fixed << setprecision(1) << tile << "%)" << endl;
        
        cout << endl << taoline(60, '-') << endl;
        cout << "Nhấn ENTER để tiếp tục | C: Đổi cấp độ | ESC: Thoát" << endl;
        
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
            cout << taoline(60, '-') << endl;
            cout << "Họ và tên: Hoàng Việt Quang" << endl;
            cout << "MSSV: 066206005044" << endl;
            cout << "Github: https://github.com/TeoSushi1014/oop/tree/main/Lab%204" << endl;
            cout << taoline(60, '-') << endl;
        }
    }
    
    system("cls");
    cout << taoline(60, '-') << endl;
    cout << "Họ và tên: Hoàng Việt Quang" << endl;
    cout << "MSSV: 066206005044" << endl;
    cout << "Github: https://github.com/TeoSushi1014/oop/tree/main/Lab%204" << endl;
    cout << endl;
    cout << taoline(60, '-') << endl;
    cout << "TỔNG KẾT" << endl;
    cout << taoline(60, '-') << endl;
    
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