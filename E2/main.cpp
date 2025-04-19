#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <cstdio>
#include <locale>
#include <codecvt>
#include <vector>
using namespace std;

class cauhoiTN {
private:
    string noidung;
    string dapanA;
    string dapanB;
    char dapandung;

public:
    cauhoiTN() {
        noidung = "";
        dapanA = "";
        dapanB = "";
        dapandung = ' ';
    }

    void nhap() {
        cin.ignore(1, '\n');
        cout << "Nhập nội dung câu hỏi: ";
        getline(cin, noidung);
        cout << "Nhập đáp án A: ";
        getline(cin, dapanA);
        cout << "Nhập đáp án B: ";
        getline(cin, dapanB);
        cout << "Nhập đáp án đúng (A/B): ";
        cin >> dapandung;
        dapandung = toupper(dapandung);

        while (dapandung != 'A' && dapandung != 'B') {
            cout << "Đáp án đúng phải là A hoặc B. Nhập lại: ";
            cin >> dapandung;
            dapandung = toupper(dapandung);
        }
    }

    void docfile(ifstream& f) {
        getline(f, noidung);
        getline(f, dapanA);
        getline(f, dapanB);
        string temp;
        getline(f, temp);
        if (!temp.empty())
            dapandung = temp[0];
    }

    void ghifile(ofstream& f) {
        f << noidung << endl;
        f << dapanA << endl;
        f << dapanB << endl;
        f << dapandung << endl;
    }

    bool kiemtra() {
        xuat(false);
        cout << "Nhập câu trả lời của bạn (A/B): ";
        char traloi;
        cin >> traloi;
        traloi = toupper(traloi);

        while (traloi != 'A' && traloi != 'B') {
            cout << "Câu trả lời phải là A hoặc B. Nhập lại: ";
            cin >> traloi;
            traloi = toupper(traloi);
        }
        cout << (traloi == dapandung ? "Đúng!" : "Sai!") << endl;
        return traloi == dapandung;
    }

    void xuat(bool showAnswer = true) {
        cout << "Câu hỏi: " << noidung << endl;
        cout << "A. " << dapanA << endl;
        cout << "B. " << dapanB << endl;
        if (showAnswer)
            cout << "Đáp án đúng: " << dapandung << endl;
    }

    void xoakhoangtrangthua() {
        noidung = trimString(noidung);
        dapanA = trimString(dapanA);
        dapanB = trimString(dapanB);
    }

    string toLower(const string& s) const {
        string result = s;
        for (size_t i = 0; i < result.length(); i++) {
            result[i] = tolower(result[i]);
        }
        return result;
    }

    string trimString(const string& s) const {
        string result = s;

        size_t start = 0;
        while (start < result.length() && isspace(result[start])) {
            start++;
        }

        size_t end = result.length();
        while (end > start && isspace(result[end - 1])) {
            end--;
        }

        result = result.substr(start, end - start);

        string finalresult;
        bool lastwasspace = false;

        for (size_t i = 0; i < result.length(); i++) {
            if (isspace(result[i])) {
                if (!lastwasspace) {
                    finalresult += ' ';
                    lastwasspace = true;
                }
            }
            else {
                finalresult += result[i];
                lastwasspace = false;
            }
        }

        return finalresult;
    }

    friend bool giongnhau(cauhoiTN cau1, cauhoiTN cau2);
};

bool giongnhau(cauhoiTN cau1, cauhoiTN cau2) {
    string q1 = cau1.toLower(cau1.noidung);
    string q2 = cau2.toLower(cau2.noidung);

    return (q1 == q2);
}

void taodethi() {
    string tenfile;
    cout << "Nhập tên file để lưu (không cần .TTN): ";
    cin >> tenfile;
    tenfile += ".TTN";

    wofstream fileOut(tenfile, ios::out | ios::binary);
    fileOut.imbue(locale(fileOut.getloc(), new codecvt_utf8<wchar_t>));

    if (!fileOut) {
        cout << "Không thể tạo file!" << endl;
        return;
    }

    fileOut.put(wchar_t(0xFEFF));
    fileOut.close();

    ofstream fileAppend(tenfile, ios::binary | ios::app);
    if (!fileAppend) {
        cout << "Không thể mở file để ghi!" << endl;
        return;
    }

    int socau;
    cout << "Nhập số câu hỏi: ";
    cin >> socau;

    cauhoiTN* dethi = new cauhoiTN[socau];
    int dem = 0;

    for (int i = 0; i < socau; i++) {
        cout << "\nNhập câu hỏi " << i + 1 << ":" << endl;
        cauhoiTN cauhoi;
        cauhoi.nhap();

        bool duplicate = false;
        for (int j = 0; j < dem; j++) {
            if (giongnhau(dethi[j], cauhoi)) {
                cout << "Câu hỏi này đã tồn tại! Vui lòng nhập lại." << endl;
                i--;
                duplicate = true;
                break;
            }
        }

        if (!duplicate) {
            dethi[dem] = cauhoi;
            dem++;
            cauhoi.ghifile(fileAppend);
        }
    }

    fileAppend.close();
    delete[] dethi;
    cout << "Đề thi đã được lưu vào file " << tenfile << endl;
}

void lambaithi(string tenfile) {
    wifstream fileIn(tenfile, ios::binary);
    fileIn.imbue(locale(fileIn.getloc(), new codecvt_utf8<wchar_t>));

    if (!fileIn) {
        cout << "Không thể mở file hoặc file không tồn tại!" << endl;
        return;
    }

    wchar_t bom = fileIn.get();
    if (bom != 0xFEFF) {
        fileIn.seekg(0);
    }

    fileIn.close();

    ifstream regularFileIn(tenfile);
    if (!regularFileIn) {
        cout << "Không thể mở file để đọc!" << endl;
        return;
    }

    const int MAX_QUESTIONS = 100;
    cauhoiTN* dethi = new cauhoiTN[MAX_QUESTIONS];
    int dem = 0;

    char possibleBOM[3];
    regularFileIn.read(possibleBOM, 3);
    if (!(possibleBOM[0] == (char)0xEF && possibleBOM[1] == (char)0xBB && possibleBOM[2] == (char)0xBF)) {
        regularFileIn.seekg(0);
    }

    while (!regularFileIn.eof() && dem < MAX_QUESTIONS) {
        dethi[dem].docfile(regularFileIn);
        if (!regularFileIn.eof()) {
            dem++;
        }
    }
    regularFileIn.close();

    if (dem == 0) {
        cout << "File không có câu hỏi nào!" << endl;
        delete[] dethi;
        return;
    }

    cout << "\n--- BẮT ĐẦU BÀI THI ---\n" << endl;
    int diemso = 0;
    for (int i = 0; i < dem; i++) {
        cout << "Câu " << i + 1 << ": ";
        if (dethi[i].kiemtra())
            diemso++;
        cout << endl;
    }

    cout << "Bạn đã hoàn thành bài thi!" << endl;
    cout << "Điểm số: " << diemso << "/" << dem << endl;

    delete[] dethi;
}

void xoakhoangtrang() {
    string tenfile;
    cout << "Nhập tên file cần xử lý (không cần .TTN): ";
    cin >> tenfile;
    tenfile += ".TTN";

    ifstream fileIn(tenfile, ios::binary);

    if (!fileIn) {
        cout << "Không thể mở file!" << endl;
        return;
    }

    bool hasBOM = false;
    char possibleBOM[3];
    fileIn.read(possibleBOM, 3);
    if (possibleBOM[0] == (char)0xEF && possibleBOM[1] == (char)0xBB && possibleBOM[2] == (char)0xBF) {
        hasBOM = true;
    }
    else {
        fileIn.seekg(0);
    }

    const int MAX_QUESTIONS = 100;
    cauhoiTN* dethi = new cauhoiTN[MAX_QUESTIONS];
    int dem = 0;

    while (!fileIn.eof() && dem < MAX_QUESTIONS) {
        dethi[dem].docfile(fileIn);
        if (!fileIn.eof()) {
            dethi[dem].xoakhoangtrangthua();
            dem++;
        }
    }
    fileIn.close();

    ofstream fileOut(tenfile, ios::binary);
    if (!fileOut) {
        cout << "Không thể mở file để ghi!" << endl;
        delete[] dethi;
        return;
    }

    if (hasBOM) {
        fileOut.put((char)0xEF);
        fileOut.put((char)0xBB);
        fileOut.put((char)0xBF);
    }

    for (int i = 0; i < dem; i++) {
        dethi[i].ghifile(fileOut);
    }

    fileOut.close();
    delete[] dethi;
    cout << "Đã xóa khoảng trắng thừa trong file " << tenfile << endl;
}

vector<string> quetFilesTTN() {
    vector<string> danhSachFile;
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFileA("*.TTN", &findFileData);

    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            danhSachFile.push_back(findFileData.cFileName);
        } while (FindNextFileA(hFind, &findFileData) != 0);
        FindClose(hFind);
    }

    return danhSachFile;
}

void chonFile() {
    vector<string> danhSachFile = quetFilesTTN();
    
    if (danhSachFile.empty()) {
        cout << "Không tìm thấy file .TTN nào trong thư mục!" << endl;
        return;
    }

    cout << "\nDanh sách file .TTN trong thư mục:" << endl;
    for (size_t i = 0; i < danhSachFile.size(); i++) {
        cout << i + 1 << ". " << danhSachFile[i] << endl;
    }
    cout << danhSachFile.size() + 1 << ". Nhập tên file thủ công" << endl;

    int luachon;
    cout << "Chọn file: ";
    cin >> luachon;

    string tenfile;
    if (luachon >= 1 && luachon <= static_cast<int>(danhSachFile.size())) {
        tenfile = danhSachFile[luachon - 1];
        lambaithi(tenfile);
    } else if (luachon == danhSachFile.size() + 1) {
        cout << "Nhập tên file đề thi (không cần .TTN): ";
        cin >> tenfile;
        tenfile += ".TTN";
        lambaithi(tenfile);
    } else {
        cout << "Lựa chọn không hợp lệ!" << endl;
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    try {
        locale::global(locale(""));
    } catch (const runtime_error&) {
        locale::global(locale("C"));
    }

    int luachon;
    do {
        system("cls");
        cout << "==================================================================" << endl;
		cout << "Bài tập thực hành - Quản lý đề thi trắc nghiệm" << endl;
        cout << "MSSV: 066206005044" << endl;
        cout << "Họ và tên: Hoàng Việt Quang" << endl;
		cout << "==================================================================" << endl;
        cout << "1. Tạo đề thi trắc nghiệm mới" << endl;
        cout << "2. Làm bài thi" << endl;
        cout << "3. Xử lý file (xóa khoảng trắng thừa)" << endl;
		cout << "4. Source code (Github)" << endl;
        cout << "0. Thoát chương trình" << endl;
        cout << "Lựa chọn của bạn: ";
        cin >> luachon;

        switch (luachon) {
        case 1:
            taodethi();
            break;
        case 2:
            chonFile();
            break;
        case 3:
            xoakhoangtrang();
            break;
		case 4:
            system("start https://github.com/TeoSushi1014/oop/");
            cout << "Đang mở mã nguồn trên GitHub..." << endl;
            break;
        case 0:
            cout << "Cảm ơn bạn đã sử dụng chương trình!" << endl;
            break;
        default:
            cout << "Lựa chọn không hợp lệ!" << endl;
        }

        if (luachon != 0) {
            cout << "\nNhấn Enter để tiếp tục...";
            cin.ignore();
            cin.get();
        }
    } while (luachon != 0);

    return 0;
}
