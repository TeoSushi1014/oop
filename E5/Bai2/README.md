# Hướng dẫn chi tiết về codebase

Bài tập này triển khai hệ thống quản lý nhân viên với ba loại nhân viên khác nhau. Dưới đây là hướng dẫn chi tiết về từng file trong codebase.

## 1. Employee.h

File này chứa khai báo lớp cơ sở trừu tượng `Employee` mà tất cả các loại nhân viên khác sẽ kế thừa từ đó.

```cpp
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
    
    virtual double thu_nhap() const = 0;  // Phương thức ảo thuần túy
    virtual void in() const;
};
```

**Giải thích:**
- `#pragma once`: Chỉ thị tiền xử lý để đảm bảo file header chỉ được include một lần
- Lớp `Employee` có hai thuộc tính protected: `ten_dau` và `ten_cuoi`
- Constructor nhận tên đầu và tên cuối
- Các phương thức getter/setter cho các thuộc tính
- `thu_nhap()`: Phương thức ảo thuần túy (pure virtual) buộc các lớp con phải triển khai
- `in()`: Phương thức ảo hiển thị thông tin nhân viên

## 2. Employee.cpp

File này triển khai các phương thức của lớp `Employee`.

```cpp
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
```

**Giải thích:**
- Constructor khởi tạo tên đầu và tên cuối
- Các phương thức getter/setter được triển khai đơn giản
- Phương thức `in()` hiển thị thông tin nhân viên cơ bản

## 3. SEmployee.h

File này khai báo lớp `SEmployee` (Salaried Employee - nhân viên lương cố định) kế thừa từ lớp `Employee`.

```cpp
#pragma once
#include "Employee.h"

class SEmployee : public Employee {
private:
    double luong_tuan;

public:
    SEmployee(const std::string& dau, const std::string& cuoi, double luong);
    
    void dat_luong_tuan(double luong);
    double lay_luong_tuan() const;
    
    virtual double thu_nhap() const override;
    virtual void in() const override;
};
```

**Giải thích:**
- Lớp `SEmployee` kế thừa từ `Employee`
- Thêm thuộc tính `luong_tuan` - lương hàng tuần của nhân viên
- Constructor nhận tên đầu, tên cuối và lương tuần
- Các phương thức getter/setter cho thuộc tính lương tuần
- Ghi đè phương thức `thu_nhap()` và `in()`

## 4. SEmployee.cpp

File này triển khai các phương thức của lớp `SEmployee`.

```cpp
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
```

**Giải thích:**
- Constructor gọi constructor của lớp cha và khởi tạo `luong_tuan`
- Kiểm tra giá trị âm cho lương và đặt về 0 nếu âm
- Phương thức `thu_nhap()` trả về lương tuần
- Phương thức `in()` hiển thị thông tin nhân viên bao gồm cả lương tuần

## 5. CEmployee.h

File này khai báo lớp `CEmployee` (Commission Employee - nhân viên hoa hồng) kế thừa từ lớp `Employee`.

```cpp
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
    
    virtual double thu_nhap() const override;
    virtual void in() const override;
};
```

**Giải thích:**
- Lớp `CEmployee` kế thừa từ `Employee`
- Thêm thuộc tính `doanh_so` và `ti_le_hoa_hong`
- Constructor nhận tên đầu, tên cuối, doanh số và tỉ lệ hoa hồng
- Các phương thức getter/setter cho thuộc tính doanh số và tỉ lệ hoa hồng
- Ghi đè phương thức `thu_nhap()` và `in()`

## 6. CEmployee.cpp

File này triển khai các phương thức của lớp `CEmployee`.

```cpp
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
```

**Giải thích:**
- Constructor gọi constructor của lớp cha và khởi tạo `doanh_so` và `ti_le_hoa_hong`
- Kiểm tra giá trị âm cho doanh số và đặt về 0 nếu âm
- Kiểm tra tỉ lệ hoa hồng không âm và không quá 1.0
- Phương thức `thu_nhap()` tính thu nhập bằng doanh số * tỉ lệ hoa hồng
- Phương thức `in()` hiển thị thông tin nhân viên bao gồm doanh số và tỉ lệ hoa hồng

## 7. SCEmployee.h

File này khai báo lớp `SCEmployee` (Base-Salary-Plus-Commission Employee - nhân viên lương cơ bản + hoa hồng) kế thừa từ lớp `CEmployee`.

```cpp
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
    
    virtual double thu_nhap() const override;
    virtual void in() const override;
};
```

**Giải thích:**
- Lớp `SCEmployee` kế thừa từ `CEmployee` (không phải từ `Employee` trực tiếp)
- Thêm thuộc tính `luong_co_ban`
- Constructor nhận thông tin từ `CEmployee` cộng với lương cơ bản
- Các phương thức getter/setter cho thuộc tính lương cơ bản
- Ghi đè phương thức `thu_nhap()` và `in()`

## 8. SCEmployee.cpp

File này triển khai các phương thức của lớp `SCEmployee`.

```cpp
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
```

**Giải thích:**
- Constructor gọi constructor của lớp cha (`CEmployee`) và khởi tạo `luong_co_ban`
- Kiểm tra giá trị âm cho lương cơ bản và đặt về 0 nếu âm
- Phương thức `thu_nhap()` tính thu nhập bằng lương cơ bản + thu nhập từ hoa hồng
- Phương thức `in()` hiển thị thông tin nhân viên bao gồm cả thông tin từ `CEmployee` và lương cơ bản

## 9. main.cpp

File này chứa hàm main và các hàm bổ trợ để tạo dữ liệu ngẫu nhiên, in danh sách và sắp xếp theo yêu cầu.

```cpp
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
```

**Giải thích:**
- Sử dụng các thư viện cần thiết và include các header file đã định nghĩa
- Hàm `sinh_ten_ngau_nhien()` tạo chuỗi 2 ký tự ngẫu nhiên
- Hàm `so_ngau_nhien()` tạo số thực ngẫu nhiên trong khoảng [min, max]
- Hàm `in_danh_sach_nv()` hiển thị danh sách nhân viên
- Trong hàm `main()`:
  - Khởi tạo bộ sinh số ngẫu nhiên
  - Tạo vector chứa các con trỏ `Employee*`
  - Tạo 10 đối tượng cho mỗi loại nhân viên với dữ liệu ngẫu nhiên
  - In danh sách ban đầu
  - Sắp xếp danh sách theo thu nhập giảm dần
  - In danh sách đã sắp xếp
  - Giải phóng bộ nhớ

## Cách thực hiện của chương trình

1. Chương trình sẽ tạo 30 đối tượng nhân viên (10 đối tượng cho mỗi loại) với:
   - Tên gồm 2 ký tự ngẫu nhiên
   - Lương tuần ngẫu nhiên (500-2000) cho SEmployee
   - Doanh số ngẫu nhiên (1000-10000) và tỉ lệ hoa hồng ngẫu nhiên (0.05-0.3) cho CEmployee
   - Doanh số, tỉ lệ hoa hồng và lương cơ bản ngẫu nhiên (300-1000) cho SCEmployee

2. In danh sách chưa sắp xếp

3. Sắp xếp danh sách theo thu nhập giảm dần

4. In danh sách đã sắp xếp

5. Giải phóng bộ nhớ của các đối tượng

## Thiết kế hệ thống phân cấp

Hệ thống sử dụng tính kế thừa (inheritance) và đa hình (polymorphism) của OOP:

- `Employee` là lớp cơ sở trừu tượng (abstract base class)
- `SEmployee` kế thừa trực tiếp từ `Employee`
- `CEmployee` kế thừa trực tiếp từ `Employee`
- `SCEmployee` kế thừa từ `CEmployee` (vì nó mở rộng từ nhân viên hoa hồng) 