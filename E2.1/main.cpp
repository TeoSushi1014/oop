#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <windows.h>
#include <cstring>
using namespace std;

class sinhvien {
private:
    string masv;
    string hoten;
    int sobuoivang;
    float diemth;
    float diemgk;

public:
    sinhvien() : masv(""), hoten(""), sobuoivang(0), diemth(0), diemgk(0) {}
    
    void nhap() {
        cin.ignore();
        cout << "MSSV: ";
        getline(cin, masv);
        masv.erase(remove(masv.begin(), masv.end(), ' '), masv.end());
        
        cout << "Họ tên: ";
        getline(cin, hoten);
        
        bool viethoa = true;
        for (size_t i = 0; i < hoten.length();) {
            if (isspace(hoten[i])) {
                viethoa = true;
                i++;
                continue;
            }
            
            if ((unsigned char)hoten[i] < 128) {
                if (viethoa) {
                    hoten[i] = toupper(hoten[i]);
                    viethoa = false;
                } else {
                    hoten[i] = tolower(hoten[i]);
                }
                i++;
                continue;
            }
            
            viethoa = false;
            unsigned char c = hoten[i];
            if ((c & 0xE0) == 0xC0) i += 2;
            else if ((c & 0xF0) == 0xE0) i += 3;
            else if ((c & 0xF8) == 0xF0) i += 4;
            else i++;
        }
        
        cout << "Số buổi vắng: ";
        cin >> sobuoivang;
        cout << "Điểm TH: ";
        cin >> diemth;
        cout << "Điểm GK: ";
        cin >> diemgk;
    }
    
    float tinhDiemQT() const {
        return sobuoivang <= 5 ? (10 - sobuoivang * 2) * 0.2 + diemth * 0.3 + diemgk * 0.5 : 0;
    }

    bool duDieuKienThi() const { return tinhDiemQT() >= 3.0; }
    
    string layHo() const {
        size_t pos = hoten.find_first_of(" ");
        return pos != string::npos ? hoten.substr(0, pos) : hoten;
    }

    string layTen() const {
        size_t pos = hoten.find_last_of(" ");
        return pos != string::npos ? hoten.substr(pos + 1) : hoten;
    }
    
    void xuat() const {
        cout << "----------------------------------------" << endl;
        cout << "MSSV: " << masv << endl;
        cout << "Họ tên: " << hoten << endl;
        cout << "Số buổi vắng: " << sobuoivang << endl;
        cout << "Điểm TH: " << fixed << setprecision(1) << diemth << endl;
        cout << "Điểm GK: " << fixed << setprecision(1) << diemgk << endl;
        cout << "Điểm QT: " << fixed << setprecision(1) << tinhDiemQT() << endl;
        cout << "Điều kiện thi: " << (duDieuKienThi() ? "Đủ điều kiện" : "Không đủ điều kiện") << endl;
    }
    
    void ghiFile(ofstream& f) const {
        f << masv << endl;
        f << hoten << endl;
        f << sobuoivang << endl;
        f << diemth << endl;
        f << diemgk << endl;
    }

    void docFile(ifstream& f) {
        getline(f, masv);
        getline(f, hoten);
        f >> sobuoivang >> diemth >> diemgk;
        f.ignore();
    }
};

class quanlysinhvien {
private:
    vector<sinhvien> dssv;

public:
    void nhapDS() {
        int n;
        cout << "Số lượng sinh viên: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            cout << "\nSinh viên " << i + 1 << ":" << endl;
            sinhvien sv;
            sv.nhap();
            dssv.push_back(sv);
        }
    }

    void xuatDS() const {
        cout << "\n===== THÔNG TIN SINH VIÊN =====" << endl;
        for (const auto& sv : dssv) {
            sv.xuat();
        }
    }
    
    void ghiFile(const string& tenfile) const {
        ofstream fileout(tenfile);
        if (!fileout) {
            cout << "Không thể mở file để ghi!" << endl;
            return;
        }

        fileout << dssv.size() << endl;
        for (const auto& sv : dssv) {
            sv.ghiFile(fileout);
        }
        
        fileout.close();
        cout << "Đã lưu vào file " << tenfile << endl;
    }

    vector<string> quetThuMuc() {
        vector<string> danhSachFile;
        WIN32_FIND_DATA findFileData;
        HANDLE hFind = FindFirstFile("*", &findFileData);
        
        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                string fileName = findFileData.cFileName;
                if (fileName != "." && fileName != ".." && fileName != "main.cpp" && 
                    fileName != "program.exe" && fileName != "main.o")
                    danhSachFile.push_back(fileName);
            } while (FindNextFile(hFind, &findFileData) != 0);
            FindClose(hFind);
        }
        
        return danhSachFile;
    }

    void docFile(const string& tenfile) {
        vector<string> danhSachFile = quetThuMuc();
        
        if (!danhSachFile.empty()) {
            cout << "Danh sách các file:" << endl;
            for (size_t i = 0; i < danhSachFile.size(); i++) {
                cout << i + 1 << ". " << danhSachFile[i] << endl;
            }
            
            int luaChon;
            string tenFileMo;
            
            cout << "Chọn số (0 để nhập tên): ";
            cin >> luaChon;
            
            if (luaChon > 0 && luaChon <= (int)danhSachFile.size()) {
                tenFileMo = danhSachFile[luaChon - 1];
            } else {
                cout << "Tên file: ";
                cin >> tenFileMo;
            }
            
            ifstream filein(tenFileMo);
            if (!filein) {
                cout << "Không thể mở file!" << endl;
                return;
            }
            
            dssv.clear();
            int n;
            filein >> n;
            filein.ignore();
            
            for (int i = 0; i < n; i++) {
                sinhvien sv;
                sv.docFile(filein);
                dssv.push_back(sv);
            }
            
            filein.close();
            cout << "Đã đọc " << n << " sinh viên từ file " << tenFileMo << endl;
        } else {
            cout << "Không tìm thấy file nào trong thư mục!" << endl;
            cout << "Tên file: ";
            string tenFileMo;
            cin >> tenFileMo;
            
            ifstream filein(tenFileMo);
            if (!filein) {
                cout << "Không thể mở file!" << endl;
                return;
            }
            
            dssv.clear();
            int n;
            filein >> n;
            filein.ignore();
            
            for (int i = 0; i < n; i++) {
                sinhvien sv;
                sv.docFile(filein);
                dssv.push_back(sv);
            }
            
            filein.close();
            cout << "Đã đọc " << n << " sinh viên từ file " << tenFileMo << endl;
        }
    }
    
    void dsCoTheDuThi() const {
        cout << "\n=== DANH SÁCH SINH VIÊN ĐỦ ĐIỀU KIỆN DỰ THI ===" << endl;
        bool cosv = false;
        
        for (const auto& sv : dssv) {
            if (sv.duDieuKienThi()) {
                sv.xuat();
                cosv = true;
            }
        }
        
        if (!cosv) cout << "Không có sinh viên nào đủ điều kiện dự thi." << endl;
    }    
    
    void dsHoNguyen() const {
        cout << "\n=== DANH SÁCH SINH VIÊN CÓ HỌ NGUYEN/NGUYỄN ===" << endl;
        bool cosv = false;
        
        for (const auto& sv : dssv) {
            string ho = sv.layHo();
            string holower = ho;
            transform(holower.begin(), holower.end(), holower.begin(), ::tolower);
            
            if (holower.find("nguy") == 0) {
                sv.xuat();
                cosv = true;
            }
        }
        
        if (!cosv) cout << "Không có sinh viên nào có họ Nguyen/Nguyễn." << endl;
    }
    
    void dsCungTen() const {
        cout << "\n=== DANH SÁCH SINH VIÊN CÓ CÙNG TÊN ===" << endl;
        
        vector<string> dsten;
        vector<string> dstentrung;
        
        for (const auto& sv : dssv) {
            string ten = sv.layTen();
            dsten.push_back(ten);
        }
        
        for (size_t i = 0; i < dsten.size(); i++) {
            for (size_t j = i + 1; j < dsten.size(); j++) {
                if (dsten[i] == dsten[j] && 
                    find(dstentrung.begin(), dstentrung.end(), dsten[i]) == dstentrung.end()) {
                    dstentrung.push_back(dsten[i]);
                    break;
                }
            }
        }
        
        if (dstentrung.empty()) {
            cout << "Không có sinh viên nào có cùng tên với sinh viên khác." << endl;
            return;
        }
        
        for (const auto& sv : dssv) {
            string ten = sv.layTen();
            if (find(dstentrung.begin(), dstentrung.end(), ten) != dstentrung.end()) {
                sv.xuat();
            }
        }
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    system("chcp 65001 > nul");
    
    quanlysinhvien qlsv;
    int luachon;
    string tenfile;
    
    do {
        system("cls");
        cout << "===========================================\n";
        cout << "Xây dựng phần mềm quản lý điểm quá trình và xét điều kiện dự thi cho sinh viêni\n";
        cout << "MSSV: 066206005044\n";
        cout << "Họ và tên: Hoàng Việt Quang\n";
        cout << "===========================================\n";
        cout << "1. Nhập danh sách sinh viên\n";
        cout << "2. Xuất danh sách sinh viên\n";
        cout << "3. Ghi danh sách vào file\n";
        cout << "4. Đọc danh sách từ file\n";
        cout << "5. Danh sách sinh viên đủ điều kiện dự thi\n";
        cout << "6. Danh sách sinh viên có họ Nguyen\n";
        cout << "7. Danh sách sinh viên có cùng tên\n";
        cout << "8. Source code Github: https://github.com/TeoSushi1014/oop\n";
        cout << "0. Thoát\n";
        cout << "Lựa chọn: ";
        cin >> luachon;
        
        switch (luachon) {
        case 1: qlsv.nhapDS(); break;
        case 2: qlsv.xuatDS(); break;
        case 3:
            cout << "Tên file: ";
            cin >> tenfile;
            qlsv.ghiFile(tenfile);
            break;
        case 4:
            qlsv.docFile(tenfile);
            break;
        case 5: qlsv.dsCoTheDuThi(); break;
        case 6: qlsv.dsHoNguyen(); break;
        case 7: qlsv.dsCungTen(); break;
        case 8: 
            system("start https://github.com/TeoSushi1014/oop");
            cout << "Đang mở GitHub...\n";
            break;
        case 0: cout << "Cảm ơn đã sử dụng chương trình!\n"; break;
        default: cout << "Lựa chọn không hợp lệ!\n";
        }
        
        if (luachon != 0) {
            cout << "\nNhấn Enter để tiếp tục...";
            cin.ignore();
            cin.get();
        }
    } while (luachon != 0);
    
    return 0;
}
