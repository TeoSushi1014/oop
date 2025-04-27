#include "Employee.h"
#include <iostream>

Employee::Employee(const std::string& dau, const std::string& cuoi)
    : ten_dau(dau), ten_cuoi(cuoi) {
}

void Employee::dat_ten_dau(const std::string& dau) {
    ten_dau = dau;
}

std::string Employee::lay_ten_dau() const {
    return ten_dau;
}

void Employee::dat_ten_cuoi(const std::string& cuoi) {
    ten_cuoi = cuoi;
}

std::string Employee::lay_ten_cuoi() const {
    return ten_cuoi;
}

void Employee::in() const {
    std::cout << "Nhan vien: " << ten_dau << " " << ten_cuoi;
} 