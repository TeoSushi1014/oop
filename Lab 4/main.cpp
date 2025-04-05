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

using namespace std;

string taoline(int length, char character = '-') {
    return string(length, character);
}

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

// Tạo một bộ câu hỏi cho một lượt chơi
vector<Bieuthuc> taocauhoi(int level) {
    vector<Bieuthuc> cauhoi;
    
    // Số lượng câu hỏi cho mỗi phép toán
    int socaucong = 0, socautru = 0, socaunhan = 0;
    
    switch (level) {
        case 1: // Chỉ phép cộng
            socaucong = 3;
            break;
        case 2: // Cộng và trừ
            socaucong = 2;
            socautru = 1;
            break;
        case 3: // Cộng, trừ và nhân
            socaucong = socautru = socaunhan = 1;
            break;
        case 4: // Cộng và trừ (số lớn)
            socaucong = 2;
            socautru = 1;
            break;
        default: // Tất cả (số lớn)
            socaucong = socautru = socaunhan = 1;
            break;
    }
    
    // Tạo các câu hỏi
    for (int i = 0; i < socaucong + socautru + socaunhan; i++) {
        cauhoi.push_back(Bieuthuc(level));
    }
    
    return cauhoi;
}

// Hiển thị một bộ câu hỏi
void hienthicauhoi(const vector<Bieuthuc>& cauhoi) {
    for (int i = 0; i < cauhoi.size(); i++) {
        cout << "Câu " << (i + 1) << ": " << cauhoi[i] << " = ?\n";
    }
}

// Kiểm tra đáp án và trả về số câu đúng
int kiemtradapan(const vector<Bieuthuc>& cauhoi) {
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

int main() {
    SetConsoleOutputCP(65001);
    srand(time(NULL));
    
    hienthitieude();
    hienthihuongdan();
    
    // Tạo đề thi mới
    Dethi dethi;
    char traloi[10];
    bool tieptuc = true;
    
    while (tieptuc) {
        hienthitieude();
        cout << motatencapdo(dethi.getLevel()) << endl;
        cout << "Số câu đúng: " << dethi.getSoCauDung() << "/" << dethi.getSoCau() << endl;
        cout << "Số câu đúng liên tiếp: " << dethi.getSoCauLienTiep() << endl << endl;
        
        // Hiển thị câu hỏi hiện tại
        dethi.hienThiCauHoi(dethi.getSoCauDung());
        
        // Nhận đáp án từ người dùng
        cin.getline(traloi, 10);
        
        // Kiểm tra nếu người dùng muốn thoát
        if (traloi[0] == 'q' || traloi[0] == 'Q') {
            tieptuc = false;
            continue;
        }
        
        // Kiểm tra đáp án
        float dapan = atof(traloi);
        bool ketqua = dethi.kiemTraDapAn(dethi.getSoCauDung() - 1, dapan);
        
        // Hiển thị kết quả
        cout << (ketqua ? "\nĐúng rồi!" : "\nSai rồi!") << endl;
        Sleep(1000);
        
        // Cập nhật cấp độ
        dethi.capNhatLevel();
        
        // Kiểm tra nếu đã hoàn thành tất cả câu hỏi
        if (dethi.getSoCauDung() == dethi.getSoCau()) {
            tieptuc = false;
        }
    }
    
    // Hiển thị kết quả cuối cùng
    hienthitieude();
    cout << "KẾT QUẢ CUỐI CÙNG:\n";
    cout << "Số câu đúng: " << dethi.getSoCauDung() << "/" << dethi.getSoCau() << endl;
    cout << "Cấp độ cao nhất đạt được: " << dethi.getLevel() << endl;
    
    // Lưu kết quả vào file
    dethi.luuKetQua("ketqua.txt");
    cout << "\nKết quả chi tiết đã được lưu vào file 'ketqua.txt'\n";
    
    cout << "\nNhấn phím bất kỳ để thoát...";
    _getch();
    return 0;
} 