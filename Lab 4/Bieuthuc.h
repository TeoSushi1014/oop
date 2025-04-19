#pragma once
#include <iostream>
using namespace std;

class Bieuthuc {
protected:
	int a, b;
	char pheptoan;
	
	int random(int min, int max) {
		return min + rand() % (max - min + 1);
	}
	
public:
	Bieuthuc(int level = 1);
	virtual ~Bieuthuc() {}
	
	friend ostream& operator<<(ostream& out, Bieuthuc bt);
	virtual bool kiemtra(float traloi);
	virtual float giatri();
	
	char getPhepToan() const { return pheptoan; }
	int getA() const { return a; }
	int getB() const { return b; }
	
protected:
	void sinhSoNgauNhien(int level);
	void sinhPhepToanNgauNhien(int level);
};
