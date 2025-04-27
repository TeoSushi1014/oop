#pragma once
#include "Employee.h"

class CEmployee : public Employee {
private:
    double doanh_so;
    double ti_le_hoa_hong;

public:
    CEmployee(const std::string& dau, const std::string& cuoi, 
              double ds, double tl);
    
    void dat_doanh_so(double ds);
    double lay_doanh_so() const;
    
    void dat_ti_le_hoa_hong(double tl);
    double lay_ti_le_hoa_hong() const;
    
    virtual double thu_nhap() const;
    virtual void in() const;
};

