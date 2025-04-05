#pragma once
#include "Bieuthuc.h"
#include <vector>
#include <iostream>

using namespace std;
class Dethi {
private:
    vector<Bieuthuc> cauhoi; // danh sách các biểu thức
    vector<float> dapan; // danh sách đáp án của người dùng
    int socaudung; // số câu trả lời đúng
    int level; // cấp độ hiện tại
    int socaulientiep; // số câu trả lời đúng liên tiếp
    
public:
    Dethi(int n1 = 3, int n2 = 4, int n3 = 3); // tạo đề thi với số câu hỏi cho mỗi cấp độ
    
    // Các phương thức chính
    void taoCauHoi(int level, int socau); // tạo số câu hỏi cho một cấp độ
    void hienThiCauHoi(int stt); // hiển thị câu hỏi thứ stt
    bool kiemTraDapAn(int stt, float traloi); // kiểm tra đáp án câu thứ stt
    void capNhatLevel(); // cập nhật level dựa trên số câu đúng liên tiếp
    
    // Các getter
    int getSoCau() const { return cauhoi.size(); }
    int getSoCauDung() const { return socaudung; }
    int getLevel() const { return level; }
    int getSoCauLienTiep() const { return socaulientiep; }
    
    // Các phương thức hỗ trợ
    void luuKetQua(const string& tenfile); // lưu kết quả vào file
    void docKetQua(const string& tenfile); // đọc kết quả từ file
};