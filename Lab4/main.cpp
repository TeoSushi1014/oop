#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include <fstream>
#include <vector>
#include "Bieuthuc.h"
#include "BieuthucPS.h"
#include "BieuthucPT.h"
#include "Dethi.h"
#include "BieuthucCong.h"
#include "BieuthucTru.h"
#include "BieuthucNhan.h"

using namespace std;

string taoline(int length, char character = '-') {
    return string(length, character);
}

string motatencapdo(int level);

void hienthitieude() {
    system("cls");
    cout << "=================================================\n";
    cout << "           CHƯƠNG TRÌNH LUYỆN TOÁN CHO TRẺ       \n";
    cout << "=================================================\n\n";
}

void luuketqua(const string& tennguoichoi, int tongdiem, int socautraloidung, int tongsocau) {
    ofstream file("ketqua.txt", ios::app);
    if (file.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);
        file << dt << "Người chơi: " << tennguoichoi << endl;
        file << "Tổng điểm: " << tongdiem << endl;
        file << "Số câu đúng: " << socautraloidung << "/" << tongsocau;
        file << " (" << fixed << setprecision(1) << (socautraloidung * 100.0 / tongsocau) << "%)" << endl;
        file << taoline(60, '-') << endl;
        file.close();
    }
}

void xemlichsu() {
    system("cls");
    ifstream file("ketqua.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Chưa có lịch sử chơi!" << endl;
    }
    cout << "\nNhấn phím bất kỳ để tiếp tục...";
    _getch();
}

void hienthihuongdan() {
    cout << "HƯỚNG DẪN:\n";
    cout << "- Trả lời đúng 3 câu liên tiếp để lên cấp độ cao hơn\n";
    cout << "- Trả lời sai sẽ bị giảm cấp độ\n";
    cout << "- Nhấn 'q' để thoát chương trình\n\n";
    cout << "CÁC CẤP ĐỘ:\n";
    for (int i = 1; i <= 4; i++) {
        cout << motatencapdo(i) << endl;
    }
    cout << "\nNhấn phím bất kỳ để bắt đầu...";
    _getch();
}

string motatencapdo(int level) {
    switch (level) {
        case 1:
            return "Cấp độ 1: Phép cộng với số từ 1-10";
        case 2:
            return "Cấp độ 2: Phép cộng, trừ với số từ 10-30";
        case 3:
            return "Cấp độ 3: Tất cả phép tính với số từ 10-50";
        default:
            return "Cấp độ 4: Tất cả phép tính với số từ 10-100";
    }
}

vector<Bieuthuc> taocauhoi(int level) {
    vector<Bieuthuc> cauhoi;
    
    int socaucong = 0, socautru = 0, socaunhan = 0;
    
    switch (level) {
        case 1: 
            socaucong = 3;
            break;
        case 2: 
            socaucong = 2;
            socautru = 1;
            break;
        case 3: 
            socaucong = socautru = socaunhan = 1;
            break;
        case 4: 
            socaucong = 2;
            socautru = 1;
            break;
        default: 
            socaucong = socautru = socaunhan = 1;
            break;
    }
    
    for (int i = 0; i < socaucong + socautru + socaunhan; i++) {
        cauhoi.push_back(Bieuthuc(level));
    }
    
    return cauhoi;
}

void hienthicauhoi(const vector<Bieuthuc>& cauhoi) {
    for (int i = 0; i < cauhoi.size(); i++) {
        cout << "Câu " << (i + 1) << ": " << cauhoi[i] << " = ?\n";
    }
}

int kiemtradapan(vector<Bieuthuc>& cauhoi) {
    int socaudung = 0;
    
    for (int i = 0; i < cauhoi.size(); i++) {
        cout << "Đáp án câu " << (i + 1) << ": ";
        float dapan;
        cin >> dapan;
        
        if (cauhoi[i].kiemtra(dapan)) {
            cout << ">> Đúng!\n";
            socaudung++;
        } else {
            cout << ">> Sai! Đáp án đúng là: " << cauhoi[i].giatri() << endl;
        }
    }
    
    return socaudung;
}

void hienThiThongTinSinhVien() {
    system("cls");
    cout << "==============================================\n";
    cout << "        THÔNG TIN SINH VIÊN                  \n";
    cout << "==============================================\n";
    cout << "Họ và tên: Hoàng Việt Quang\n";
    cout << "MSSV: 066206005044\n";
    cout << "GitHub: https://github.com/TeoSushi1014/oop\n";
    cout << "\nNhấn Enter để quay lại menu chính...";
    cin.ignore();
    cin.get();
}

void hienThiMenu() {
    cout << "==============================================\n";
    cout << "     CHƯƠNG TRÌNH ĐỐ VUI TOÁN HỌC\n";
    cout << "==============================================\n";
    cout << "Họ và tên: Hoàng Việt Quang\n";
    cout << "MSSV: 066206005044\n";
    cout << "GitHub: https://github.com/TeoSushi1014/oop\n";
    cout << "==============================================\n";
    cout << "1. Bắt đầu trò chơi\n";
    cout << "2. Xem hướng dẫn\n";
    cout << "3. Thoát\n";
    cout << "Lựa chọn của bạn: ";
}

void hienThiHuongDan() {
    system("cls");
    cout << "==============================================\n";
    cout << "     HƯỚNG DẪN CHƠI\n";
    cout << "==============================================\n";
    cout << "- Trả lời đúng các câu hỏi toán học.\n";
    cout << "- Cấp độ khó sẽ tăng sau khi trả lời đúng 3 câu liên tiếp.\n";
    cout << "- Cấp độ khó sẽ giảm nếu trả lời sai.\n";
    cout << "\nCÁC CẤP ĐỘ:\n";
    cout << "- Level 1: Chỉ phép cộng, 1 <= a, b <= 10\n";
    cout << "- Level 2: Có phép cộng và trừ, 1 <= a, b <= 10\n";
    cout << "- Level 3: Có phép cộng, trừ và nhân, 1 <= a, b <= 10\n";
    cout << "- Level 4: Có phép cộng và trừ, 10 <= a, b <= 100\n";
    cout << "- Level 5+: Có phép cộng, trừ và nhân, 10 <= a, b <= 100\n";
    cout << "- Level cao hơn sẽ có biểu thức phức tạp và phân số\n";
    cout << "\nNhấn Enter để quay lại menu chính...";
    cin.ignore();
    cin.get();
}

void choiGame() {
    system("cls");
    cout << "==============================================\n";
    cout << "     BẮT ĐẦU CHƠI\n";
    cout << "==============================================\n";
    
    int level = 1;
    int socau = 0;
    int socaudung = 0;
    int socaulientiep = 0;
    int diemso = 0;
    
    while (true) {
        system("cls");
        cout << "==============================================\n";
        cout << "     LEVEL: " << level << "     ĐIỂM: " << diemso << "\n";
        cout << "==============================================\n";
        
        Bieuthuc* bt = nullptr;
        
        int loaiBT = rand() % 100;
        
        if (level <= 3) {
            if (level == 1) {
                bt = new BieuthucCong(level);
            } else if (level == 2) {
                if (loaiBT < 50)
                    bt = new BieuthucCong(level);
                else
                    bt = new BieuthucTru(level);
            } else {
                if (loaiBT < 33)
                    bt = new BieuthucCong(level);
                else if (loaiBT < 66)
                    bt = new BieuthucTru(level);
                else
                    bt = new BieuthucNhan(level);
            }
        } else if (level <= 5) {
            if (level == 4) {
                if (loaiBT < 50)
                    bt = new BieuthucCong(level);
                else
                    bt = new BieuthucTru(level);
            } else {
                if (loaiBT < 33)
                    bt = new BieuthucCong(level);
                else if (loaiBT < 66)
                    bt = new BieuthucTru(level);
                else
                    bt = new BieuthucNhan(level);
            }
        } else if (level <= 7) {
            if (loaiBT < 60)
                bt = new BieuthucPT(level);
            else if (loaiBT < 80)
                bt = new BieuthucPS(level);
            else {
                if (loaiBT < 87)
                    bt = new BieuthucCong(level);
                else if (loaiBT < 94)
                    bt = new BieuthucTru(level);
                else
                    bt = new BieuthucNhan(level);
            }
        } else {
            if (loaiBT < 50)
                bt = new BieuthucPT(level);
            else if (loaiBT < 80)
                bt = new BieuthucPS(level);
            else {
                if (loaiBT < 87)
                    bt = new BieuthucCong(level);
                else if (loaiBT < 94)
                    bt = new BieuthucTru(level);
                else
                    bt = new BieuthucNhan(level);
            }
        }
        
        socau++;
        cout << "Câu hỏi #" << socau << ": ";
        cout << *bt << " = ? ";
        
        float traloi;
        cout << "\nNhập câu trả lời của bạn: ";
        cin >> traloi;
        
        if (bt->kiemtra(traloi)) {
            cout << "\nChính xác! +10 điểm\n";
            socaudung++;
            socaulientiep++;
            diemso += 10;
            
            if (socaulientiep >= 3) {
                socaulientiep = 0;
                if (level < 10) {
                    level++;
                    cout << "\nChúc mừng! Bạn đã lên cấp độ " << level << "!\n";
                }
            }
        } else {
            cout << "\nSai rồi! Đáp án đúng là: " << bt->giatri() << "\n";
            socaulientiep = 0;
            
            if (level > 1) {
                level--;
                cout << "Bạn đã xuống cấp độ " << level << ".\n";
            }
        }
        
        delete bt;
        
        cout << "\nBạn có muốn tiếp tục chơi không? (y/n): ";
        char tieptuc;
        cin >> tieptuc;
        
        if (tieptuc != 'y' && tieptuc != 'Y') {
            cout << "\n==============================================\n";
            cout << "     KẾT QUẢ\n";
            cout << "==============================================\n";
            cout << "Tổng số câu: " << socau << "\n";
            cout << "Số câu đúng: " << socaudung << "\n";
            cout << "Điểm số: " << diemso << "\n";
            cout << "Nhấn Enter để quay lại menu chính...";
            cin.ignore();
            cin.get();
            break;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    int luachon;
    do {
        system("cls");
        hienThiMenu();
        cin >> luachon;
        
        switch (luachon) {
            case 1:
                choiGame();
                break;
                
            case 2:
                hienThiHuongDan();
                break;
                
            case 3:
                cout << "\nCảm ơn bạn đã chơi! Tạm biệt.\n";
                break;
                
            default:
                cout << "\nLựa chọn không hợp lệ. Vui lòng thử lại.\n";
                cout << "Nhấn Enter để tiếp tục...";
                cin.ignore();
                cin.get();
        }
    } while (luachon != 3);
    
    return 0;
} 