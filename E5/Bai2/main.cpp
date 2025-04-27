#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Employee.h"
#include "SEmployee.h"
#include "CEmployee.h"
#include "SCEmployee.h"

std::string sinh_ten_ngau_nhien() {
    const char ki_tu[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string ket_qua;
    
    for (int i = 0; i < 2; i++) {
        int so_ngau_nhien = rand() % 26;
        ket_qua += ki_tu[so_ngau_nhien];
    }
    
    return ket_qua;
}

double so_ngau_nhien(double min, double max) {
    double ti_le = (double)rand() / RAND_MAX;
    return min + ti_le * (max - min);
}

void in_danh_sach_nv(const std::vector<Employee*>& ds_nv) {
    std::cout << "\n=== Danh sach nhan vien ===\n";
    for (const auto& nv : ds_nv) {
        nv->in();
        std::cout << "\nThu nhap: " << nv->thu_nhap() << "\n\n";
    }
}

int main() {
    srand(time(0));
    
    std::vector<Employee*> ds_nv;
    
    std::cout << "Dang tao 10 nhan vien luong co dinh...\n";
    for (int i = 0; i < 10; i++) {
        std::string ten_dau = sinh_ten_ngau_nhien();
        std::string ten_cuoi = sinh_ten_ngau_nhien();
        double luong_tuan = so_ngau_nhien(500.0, 2000.0);
        
        ds_nv.push_back(new SEmployee(ten_dau, ten_cuoi, luong_tuan));
    }
    
    std::cout << "Dang tao 10 nhan vien hoa hong...\n";
    for (int i = 0; i < 10; i++) {
        std::string ten_dau = sinh_ten_ngau_nhien();
        std::string ten_cuoi = sinh_ten_ngau_nhien();
        double doanh_so = so_ngau_nhien(1000.0, 10000.0);
        double ti_le_hh = so_ngau_nhien(0.05, 0.3);
        
        ds_nv.push_back(new CEmployee(ten_dau, ten_cuoi, doanh_so, ti_le_hh));
    }
    
    std::cout << "Dang tao 10 nhan vien luong co ban + hoa hong...\n";
    for (int i = 0; i < 10; i++) {
        std::string ten_dau = sinh_ten_ngau_nhien();
        std::string ten_cuoi = sinh_ten_ngau_nhien();
        double doanh_so = so_ngau_nhien(1000.0, 10000.0);
        double ti_le_hh = so_ngau_nhien(0.05, 0.3);
        double luong_cb = so_ngau_nhien(300.0, 1000.0);
        
        ds_nv.push_back(new SCEmployee(ten_dau, ten_cuoi, doanh_so, ti_le_hh, luong_cb));
    }
    
    std::cout << "\n*** Danh sach chua sap xep ***\n";
    in_danh_sach_nv(ds_nv);
    
    std::sort(ds_nv.begin(), ds_nv.end(), 
              [](const Employee* a, const Employee* b) {
                  return a->thu_nhap() > b->thu_nhap();
              });
    
    std::cout << "\n*** Danh sach da sap xep (theo thu nhap giam dan) ***\n";
    in_danh_sach_nv(ds_nv);
    
    for (auto nv : ds_nv) {
        delete nv;
    }
    
    return 0;
} 