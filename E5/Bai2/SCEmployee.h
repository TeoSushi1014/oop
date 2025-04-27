#pragma once
#include "CEmployee.h"

class SCEmployee : public CEmployee {
private:
    double luong_co_ban;

public:
    SCEmployee(const std::string& dau, const std::string& cuoi,
               double ds, double tl, double luong);
    
    void dat_luong_co_ban(double luong);
    double lay_luong_co_ban() const;
    
    virtual double thu_nhap() const;
    virtual void in() const;
};
