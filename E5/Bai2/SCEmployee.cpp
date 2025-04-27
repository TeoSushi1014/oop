#include "SCEmployee.h"
#include <iostream>

SCEmployee::SCEmployee(const std::string& dau, const std::string& cuoi,
                       double ds, double tl, double luong)
    : CEmployee(dau, cuoi, ds, tl), luong_co_ban(luong) {
    if (luong_co_ban < 0.0) {
        luong_co_ban = 0.0;
    }
}

void SCEmployee::dat_luong_co_ban(double luong) {
    luong_co_ban = (luong < 0.0) ? 0.0 : luong;
}

double SCEmployee::lay_luong_co_ban() const {
    return luong_co_ban;
}

double SCEmployee::thu_nhap() const {
    return lay_luong_co_ban() + CEmployee::thu_nhap();
}

void SCEmployee::in() const {
    std::cout << "Nhan vien luong co ban + hoa hong: ";
    CEmployee::in();
    std::cout << "\nLuong co ban: " << lay_luong_co_ban();
} 