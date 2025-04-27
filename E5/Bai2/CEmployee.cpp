#include "CEmployee.h"
#include <iostream>

CEmployee::CEmployee(const std::string& dau, const std::string& cuoi, 
                     double ds, double tl)
    : Employee(dau, cuoi), doanh_so(ds), ti_le_hoa_hong(tl) {
    if (doanh_so < 0.0) {
        doanh_so = 0.0;
    }
    if (ti_le_hoa_hong < 0.0 || ti_le_hoa_hong > 1.0) {
        ti_le_hoa_hong = 0.0;
    }
}

void CEmployee::dat_doanh_so(double ds) {
    doanh_so = (ds < 0.0) ? 0.0 : ds;
}

double CEmployee::lay_doanh_so() const {
    return doanh_so;
}

void CEmployee::dat_ti_le_hoa_hong(double tl) {
    ti_le_hoa_hong = (tl < 0.0 || tl > 1.0) ? 0.0 : tl;
}

double CEmployee::lay_ti_le_hoa_hong() const {
    return ti_le_hoa_hong;
}

double CEmployee::thu_nhap() const {
    return lay_ti_le_hoa_hong() * lay_doanh_so();
}

void CEmployee::in() const {
    std::cout << "Nhan vien hoa hong: ";
    Employee::in();
    std::cout << "\nDoanh so: " << lay_doanh_so()
              << "\nTi le hoa hong: " << lay_ti_le_hoa_hong();
} 