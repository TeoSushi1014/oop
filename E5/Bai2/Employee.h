#pragma once
#include <string>

class Employee {
protected:
    std::string ten_dau;
    std::string ten_cuoi;

public:
    Employee(const std::string& dau, const std::string& cuoi);
    
    void dat_ten_dau(const std::string& dau);
    std::string lay_ten_dau() const;
    
    void dat_ten_cuoi(const std::string& cuoi);
    std::string lay_ten_cuoi() const;
    
    virtual double thu_nhap() const = 0;
    virtual void in() const;
};
