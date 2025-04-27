#include "SEmployee.h"
#include <iostream>

SEmployee::SEmployee(const std::string& dau, const std::string& cuoi, double luong)
    : Employee(dau, cuoi), luong_tuan(luong) {
    if (luong_tuan < 0.0) {
        luong_tuan = 0.0;
    }
}

void SEmployee::dat_luong_tuan(double luong) {
    luong_tuan = (luong < 0.0) ? 0.0 : luong;
}

double SEmployee::lay_luong_tuan() const {
    return luong_tuan;
}

double SEmployee::thu_nhap() const {
    return lay_luong_tuan();
}

void SEmployee::in() const {
    std::cout << "Nhan vien luong co dinh: ";
    Employee::in();
    std::cout << "\nLuong tuan: " << lay_luong_tuan();
} 