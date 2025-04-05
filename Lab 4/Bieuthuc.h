#pragma once
#include <iostream>
using namespace std;

class Bieuthuc {
protected:
	int a, b; // hai toán hạng
	char pheptoan; // ký tự đại diện phép toán {+, -, *}
	
	// Hàm sinh số ngẫu nhiên trong khoảng [min, max]
	int random(int min, int max) {
		return min + rand() % (max - min + 1);
	}
	
public:
	Bieuthuc(int level = 1); // sinh ngẫu nhiên biểu thức theo quy luật
	virtual ~Bieuthuc() {} // destructor ảo cho class cơ sở
	
	// Các phương thức chính
	friend ostream& operator<<(ostream& out, Bieuthuc bt); // xuất ra theo dạng a # b
	virtual bool kiemtra(float traloi); // kiểm tra đáp án
	virtual float giatri(); // tính giá trị biểu thức
	
	// Getter
	char getPhepToan() const { return pheptoan; }
	int getA() const { return a; }
	int getB() const { return b; }
	
protected:
	// Các hàm hỗ trợ sinh biểu thức theo level
	void sinhSoNgauNhien(int level);
	void sinhPhepToanNgauNhien(int level);
};
