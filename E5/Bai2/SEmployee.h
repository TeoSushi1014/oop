#pragma once
#include "Employee.h"

class SEmployee : public Employee {
private:
    double luong_tuan;

public:
    SEmployee(const std::string& dau, const std::string& cuoi, double luong);
    
    void dat_luong_tuan(double luong);
    double lay_luong_tuan() const;
    
    virtual double thu_nhap() const;
    virtual void in() const;
};
