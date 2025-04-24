# Hướng dẫn chi tiết: Ứng dụng Luyện Toán cho Trẻ

## 1. Giới thiệu

Đây là một ứng dụng C++ được thiết kế để giúp trẻ em luyện tập các phép tính toán học cơ bản như cộng, trừ và nhân. Chương trình sẽ tự động tăng độ khó dựa trên khả năng của người dùng.

### 1.1. Mục tiêu của dự án

- **Giáo dục**: Giúp trẻ em cải thiện kỹ năng tính toán cơ bản
- **Thích nghi**: Tự động điều chỉnh độ khó phù hợp với khả năng của người dùng
- **Đa dạng**: Cung cấp nhiều loại biểu thức khác nhau (số nguyên, phân số, biểu thức phức tạp)
- **Tương tác**: Giao diện console đơn giản nhưng hiệu quả

### 1.2. Tính năng chính

1. **Hệ thống cấp độ thích ứng**: Tăng/giảm cấp độ dựa trên kết quả người dùng
2. **Đa dạng phép tính**: Cộng, trừ, nhân với độ khó tăng dần
3. **Phân số**: Cấp độ cao sẽ có các phép tính với phân số
4. **Biểu thức phức tạp**: Biểu thức dạng (a op b) op (c op d)
5. **Hệ thống điểm**: Tính điểm dựa trên số câu trả lời đúng
6. **Giao diện tiếng Việt**: Hỗ trợ đầy đủ tiếng Việt để dễ sử dụng

## 2. Cấu trúc dự án

Dự án này được thiết kế theo mô hình lập trình hướng đối tượng (OOP) với cấu trúc kế thừa và đa hình rõ ràng.

### 2.1. Sơ đồ cấu trúc lớp

```
               ┌─────────┐
               │ Bieuthuc │
               └─────┬───┘
                     │
      ┌──────────────┼──────────────┐
      │              │              │
┌─────▼────┐   ┌─────▼────┐   ┌─────▼────┐
│BieuthucPS│   │BieuthucPT│   │ Các phép │
└──────────┘   └──────────┘   │ tính cơ  │
                              │   bản    │
                              └──────────┘
                                   │
                    ┌──────────────┼──────────────┐
                    │              │              │
              ┌─────▼────┐   ┌─────▼────┐   ┌─────▼────┐
              │BieuthucC │   │BieuthucT │   │BieuthucN │
              │   ong    │   │    ru    │   │   han    │
              └──────────┘   └──────────┘   └──────────┘


┌─────────┐
│Fraction │ ←── Sử dụng bởi BieuthucPS
└─────────┘
```

### 2.2. Vai trò chi tiết của từng lớp

- **Bieuthuc**: 
  - Lớp cơ sở (base class) cho tất cả các biểu thức
  - Định nghĩa các phương thức cơ bản: tạo biểu thức, kiểm tra đáp án, tính giá trị
  - Chứa thuộc tính chung: hai toán hạng (a, b) và phép toán

- **BieuthucCong / BieuthucTru / BieuthucNhan**: 
  - Các lớp con (derived classes) từ Bieuthuc
  - Mỗi lớp đại diện cho một phép tính cụ thể
  - Ghi đè (override) phương thức giatri() để thực hiện phép tính tương ứng

- **BieuthucPS (Biểu thức Phân số)**:
  - Lớp con từ Bieuthuc
  - Thay thế các toán hạng nguyên bằng các đối tượng Fraction
  - Thực hiện các phép tính với phân số

- **BieuthucPT (Biểu thức Phức tạp)**:
  - Lớp con từ Bieuthuc
  - Mở rộng với thêm hai toán hạng (c, d)
  - Tạo các biểu thức dạng (a op b) op (c op d)

- **Fraction**:
  - Lớp độc lập xử lý các phân số
  - Định nghĩa các phép tính (+, -, *) cho phân số
  - Hỗ trợ chuyển đổi sang dạng số thực

- **Dethi**:
  - Lớp quản lý tập hợp các câu hỏi
  - Tạo bộ đề thi với các biểu thức ở cấp độ khác nhau

### 2.3. Các file mã nguồn và chức năng

| File | Chức năng chi tiết |
|------|-------------------|
| **Bieuthuc.h** | Định nghĩa lớp cơ sở Bieuthuc |
| **Bieuthuc.cpp** | Cài đặt chi tiết lớp Bieuthuc |
| **BieuthucCong.h** | Định nghĩa lớp BieuthucCong |
| **BieuthucCong.cpp** | Cài đặt chi tiết lớp BieuthucCong |
| **BieuthucTru.h** | Định nghĩa lớp BieuthucTru |
| **BieuthucTru.cpp** | Cài đặt chi tiết lớp BieuthucTru |
| **BieuthucNhan.h** | Định nghĩa lớp BieuthucNhan |
| **BieuthucNhan.cpp** | Cài đặt chi tiết lớp BieuthucNhan |
| **BieuthucPS.h** | Định nghĩa lớp BieuthucPS (phân số) |
| **BieuthucPS.cpp** | Cài đặt chi tiết lớp BieuthucPS |
| **BieuthucPT.h** | Định nghĩa lớp BieuthucPT (phức tạp) |
| **BieuthucPT.cpp** | Cài đặt chi tiết lớp BieuthucPT |
| **Fraction.h** | Định nghĩa lớp Fraction (phân số) |
| **Fraction.cpp** | Cài đặt chi tiết lớp Fraction |
| **Dethi.h** | Định nghĩa lớp Dethi |
| **Dethi.cpp** | Cài đặt chi tiết lớp Dethi |
| **main.cpp** | Chứa hàm main() và giao diện người dùng |
| **run.cmd** | Script Windows để biên dịch và chạy chương trình |

### 2.4. Các khái niệm OOP được sử dụng

Dự án sử dụng nhiều khái niệm lập trình hướng đối tượng:

1. **Kế thừa (Inheritance)**:
   - BieuthucCong, BieuthucTru, BieuthucNhan, BieuthucPS và BieuthucPT kế thừa từ lớp Bieuthuc
   - Cho phép tái sử dụng code và mở rộng chức năng

2. **Đa hình (Polymorphism)**:
   - Ghi đè phương thức giatri() trong các lớp con
   - Cho phép xử lý các loại biểu thức khác nhau thông qua cùng một giao diện

3. **Nạp chồng toán tử (Operator Overloading)**:
   - Nạp chồng toán tử <<, +, -, * 
   - Cho phép sử dụng các toán tử quen thuộc với các đối tượng tự định nghĩa

4. **Đóng gói (Encapsulation)**:
   - Phân chia rõ ràng thuộc tính và phương thức public/protected/private
   - Bảo vệ dữ liệu và cung cấp giao diện sử dụng nhất quán

5. **Lớp bạn (Friend Class)**:
   - Sử dụng friend để cho phép toán tử << truy cập các thuộc tính private/protected
   - Giữ tính đóng gói nhưng vẫn cho phép các chức năng cần thiết

## 3. Phân tích chi tiết từng file

### 3.1. Lớp Bieuthuc (Bieuthuc.h và Bieuthuc.cpp)

Lớp `Bieuthuc` là lớp cơ sở cho tất cả các loại biểu thức toán học trong chương trình. Lớp này định nghĩa cấu trúc chung và các phương thức cơ bản mà tất cả các biểu thức phải có.

#### 3.1.1. File Header (Bieuthuc.h)

```cpp
#pragma once            // Chỉ thị tiền xử lý để tránh include file nhiều lần
#include <iostream>     // Thư viện cho các thao tác vào/ra chuẩn
using namespace std;    // Sử dụng namespace std để không phải viết std:: trước mỗi lần dùng

class Bieuthuc
{
protected:              // Định nghĩa các thuộc tính protected để các lớp con có thể truy cập
    int a, b;           // Hai toán hạng của biểu thức, các lớp con có thể truy cập
    char pheptoan;      // Phép toán: '+', '-', '*' - các lớp con có thể truy cập
public:                 // Các phương thức public có thể được gọi từ bên ngoài
    Bieuthuc(int level);  // Constructor với tham số cấp độ khó
    
    // Toán tử << được định nghĩa là hàm bạn (friend function)
    // để có thể truy cập vào các thuộc tính protected/private của lớp
    friend ostream& operator<<(ostream& out, Bieuthuc bt);  
    
    bool kiemtra(float traloi);  // Kiểm tra đáp án nhập vào có đúng không
    float giatri();             // Tính giá trị biểu thức
};
```

**Giải thích chi tiết:**

1. **`#pragma once`**: 
   - Đây là chỉ thị tiền xử lý (preprocessor directive) giúp đảm bảo header file chỉ được include một lần
   - Giúp tránh lỗi định nghĩa hàm/lớp nhiều lần khi file header được include bởi nhiều file khác

2. **`#include <iostream>`**:
   - Include thư viện iostream cho các thao tác nhập xuất
   - Cung cấp các đối tượng như `cout`, `cin` và các toán tử như `<<`, `>>`

3. **`using namespace std;`**:
   - Cho phép sử dụng các thành phần trong namespace std mà không cần tiền tố `std::`
   - Ví dụ: dùng `cout` thay vì `std::cout`, `string` thay vì `std::string`

4. **Thuộc tính được đánh dấu `protected`**:
   - `protected` nghĩa là các thuộc tính này có thể:
     - Được truy cập bởi các phương thức của lớp hiện tại
     - Được truy cập bởi các phương thức của lớp con (kế thừa)
     - Không thể truy cập từ bên ngoài lớp
   - `a` và `b`: hai số nguyên đại diện cho toán hạng
   - `pheptoan`: ký tự đại diện cho phép tính (+, -, *)

5. **Phương thức `Bieuthuc(int level)`**:
   - Constructor với tham số level xác định cấp độ khó
   - Dùng để khởi tạo đối tượng `Bieuthuc` mới với cấp độ được chỉ định

6. **Phương thức `friend ostream& operator<<(...)`**:
   - Định nghĩa nạp chồng toán tử << để có thể xuất biểu thức ra màn hình
   - Từ khóa `friend` cho phép hàm này truy cập vào các thành phần private/protected
   - Cho phép sử dụng cú pháp: `cout << bieuthuc;`

7. **Phương thức `bool kiemtra(float traloi)`**:
   - Kiểm tra xem đáp án nhập vào có đúng không
   - Trả về `true` nếu đáp án đúng, `false` nếu sai

8. **Phương thức `float giatri()`**:
   - Tính giá trị biểu thức
   - Trả về kết quả dạng số thực

#### 3.1.2. File Cài đặt (Bieuthuc.cpp)

```cpp
#include "Bieuthuc.h"     // Include file header của lớp Bieuthuc
#include <cstdlib>        // Thư viện cho hàm rand(), srand()
#include <ctime>          // Thư viện cho hàm time()
#include <cmath>          // Thư viện cho hàm abs() - tính giá trị tuyệt đối

// Constructor tạo biểu thức với cấp độ nhất định
Bieuthuc::Bieuthuc(int level) {
    srand(time(NULL));    // Khởi tạo hạt giống ngẫu nhiên dựa trên thời gian hiện tại
    
    // Xác định giới hạn của số ngẫu nhiên dựa vào cấp độ
    // Nếu level <= 3, giới hạn là 10, ngược lại là 100
    int gioihanln = (level <= 3) ? 10 : 100;
    
    // Tạo ngẫu nhiên hai số a và b từ 1 đến gioihanln
    a = rand() % gioihanln + 1;   // Số ngẫu nhiên từ 1 đến gioihanln 
    b = rand() % gioihanln + 1;   // Số ngẫu nhiên từ 1 đến gioihanln
    
    // Chọn phép toán dựa vào cấp độ
    if (level == 1) {
        pheptoan = '+';           // Cấp độ 1: Chỉ phép cộng
    }
    else if (level == 2 || level == 4) {
        // Cấp độ 2, 4: Phép cộng hoặc trừ (ngẫu nhiên)
        pheptoan = (rand() % 2 == 0) ? '+' : '-';  
    }
    else {
        // Cấp độ khác: Cộng, trừ hoặc nhân (ngẫu nhiên)
        int op = rand() % 3;      // Số ngẫu nhiên 0, 1 hoặc 2
        switch (op) {
            case 0: pheptoan = '+'; break;  // op = 0: cộng
            case 1: pheptoan = '-'; break;  // op = 1: trừ
            case 2: pheptoan = '*'; break;  // op = 2: nhân
        }
    }
}

// Định nghĩa toán tử << để xuất biểu thức dạng "a op b"
ostream& operator<<(ostream& out, Bieuthuc bt) {
    out << bt.a << " " << bt.pheptoan << " " << bt.b;
    return out;  // Trả về tham chiếu để có thể nối nhiều toán tử <<
}

// Kiểm tra đáp án có đúng không (với sai số < 0.0001)
bool Bieuthuc::kiemtra(float traloi) {
    // So sánh với sai số do có thể tính toán số thực không chính xác tuyệt đối
    return abs(giatri() - traloi) < 0.0001;
}

// Tính giá trị biểu thức dựa vào phép toán
float Bieuthuc::giatri() {
    switch (pheptoan) {
        case '+': return a + b;  // Thực hiện phép cộng
        case '-': return a - b;  // Thực hiện phép trừ
        case '*': return a * b;  // Thực hiện phép nhân
        default: return 0;       // Mặc định trả về 0 nếu phép toán không hợp lệ
    }
}
```

**Phân tích chi tiết từng phần:**

1. **Include các thư viện:**
   - `#include "Bieuthuc.h"`: Include file header của lớp Bieuthuc
   - `#include <cstdlib>`: Cung cấp hàm `rand()` và `srand()` để tạo số ngẫu nhiên
   - `#include <ctime>`: Cung cấp hàm `time()` để lấy thời gian hiện tại làm hạt giống
   - `#include <cmath>`: Cung cấp hàm `abs()` để tính giá trị tuyệt đối

2. **Constructor `Bieuthuc::Bieuthuc(int level)`:**
   - Đây là hàm tạo (constructor) của lớp, được gọi khi tạo đối tượng mới
   - `srand(time(NULL))`: Đặt hạt giống ngẫu nhiên dựa trên thời gian hiện tại
     - Đảm bảo mỗi lần chạy chương trình sẽ cho các số ngẫu nhiên khác nhau
   - `int gioihanln = (level <= 3) ? 10 : 100;`: Câu lệnh điều kiện ba ngôi
     - Nếu level <= 3 thì giới hạn là 10, ngược lại là 100
   - Phát sinh ngẫu nhiên hai số a và b từ 1 đến giới hạn:
     - `rand() % gioihanln + 1`: Số ngẫu nhiên từ 1 đến gioihanln
     - `%` là toán tử lấy phần dư, ví dụ 15 % 10 = 5
     - `+1` để dịch khoảng từ [0, gioihanln-1] thành [1, gioihanln]
   - Lựa chọn phép toán phù hợp với cấp độ:
     - Cấp độ 1: Chỉ phép cộng (+)
     - Cấp độ 2, 4: Phép cộng (+) hoặc trừ (-)
     - Cấp độ khác: Phép cộng (+), trừ (-) hoặc nhân (*)

3. **Nạp chồng toán tử `operator<<`:**
   - Định nghĩa cách hiển thị một đối tượng Bieuthuc
   - Kết quả hiển thị: `a pheptoan b` (ví dụ: "5 + 3")
   - Trả về tham chiếu `ostream&` để cho phép nối nhiều toán tử << (`cout << bt1 << bt2 << endl;`)

4. **Phương thức `kiemtra(float traloi)`**:
   - So sánh đáp án nhập vào với giá trị thực của biểu thức
   - Sử dụng sai số 0.0001 khi so sánh số thực (rất quan trọng vì phép tính số thực có thể có sai số nhỏ)

5. **Phương thức `giatri()`:**
   - Tính giá trị thực của biểu thức dựa vào phép toán
   - Sử dụng cấu trúc `switch-case` để xử lý các phép toán khác nhau
   - Trường hợp mặc định (default) trả về 0 để tránh lỗi nếu phép toán không hợp lệ

**Ứng dụng thực tế của lớp Bieuthuc:**
- Là nền tảng cho tất cả các loại biểu thức toán học trong chương trình
- Cho phép tạo các biểu thức ngẫu nhiên với độ khó tăng dần
- Cung cấp phương thức chuẩn để kiểm tra kết quả và tính giá trị
- Làm cơ sở cho việc mở rộng thêm các loại biểu thức phức tạp hơn

### 3.2. Lớp Fraction (Fraction.h và Fraction.cpp)

Lớp `Fraction` được thiết kế để biểu diễn và thao tác với phân số. Lớp này là nền tảng cho các biểu thức phân số phức tạp hơn trong ứng dụng.

#### 3.2.1. File Header (Fraction.h)

```cpp
#pragma once                 // Tránh include file nhiều lần
#include <iostream>          // Thư viện nhập xuất chuẩn
using namespace std;

class Fraction {
private:                    // Thuộc tính private - chỉ truy cập được từ bên trong lớp
    int tu, mau;            // Tử số và mẫu số của phân số
public:
    // Constructor với tham số mặc định: t=0, m=1
    // -> Tạo phân số 0/1 nếu không có tham số
    Fraction(int t = 0, int m = 1);  
    
    // Toán tử xuất - hàm bạn để truy cập thuộc tính private
    friend ostream& operator<<(ostream& out, const Fraction& f);  
    
    // Phương thức tính giá trị thực của phân số
    float giatri() const;   // const: đảm bảo không thay đổi đối tượng
    
    // Nạp chồng các toán tử +, -, * cho phân số
    Fraction operator+(const Fraction& other) const;  // Cộng hai phân số
    Fraction operator-(const Fraction& other) const;  // Trừ hai phân số
    Fraction operator*(const Fraction& other) const;  // Nhân hai phân số
};
```

**Giải thích chi tiết:**

1. **Khai báo thuộc tính `private`:**
   - `int tu, mau`: Biểu diễn tử số và mẫu số của phân số
   - `private` nghĩa là các thuộc tính này chỉ có thể truy cập được từ bên trong lớp
   - Đây là một ví dụ của tính đóng gói (encapsulation) - một nguyên tắc của OOP

2. **Constructor `Fraction(int t, int m)`:**
   - Cho phép tạo đối tượng Fraction với các giá trị mặc định
   - Trường hợp không có tham số: `Fraction f;` → tạo phân số 0/1
   - Trường hợp có một tham số: `Fraction f(5);` → tạo phân số 5/1
   - Trường hợp có hai tham số: `Fraction f(3, 4);` → tạo phân số 3/4

3. **Toán tử xuất `friend ostream& operator<<(...)`:**
   - Định nghĩa cách hiển thị một phân số khi sử dụng toán tử << 
   - Ví dụ: `cout << f;` sẽ hiển thị phân số f dưới dạng "tử/mẫu"
   - Từ khóa `friend` cho phép hàm này truy cập vào các thuộc tính private

4. **Phương thức `float giatri() const`:**
   - Chuyển đổi phân số thành số thực (tử/mẫu)
   - Từ khóa `const` chỉ định phương thức này không thay đổi đối tượng

5. **Các phương thức nạp chồng toán tử:**
   - `operator+`: Định nghĩa phép cộng hai phân số
   - `operator-`: Định nghĩa phép trừ hai phân số
   - `operator*`: Định nghĩa phép nhân hai phân số
   - Từ khóa `const` đảm bảo không thay đổi các đối tượng tham gia phép tính

#### 3.2.2. File Cài đặt (Fraction.cpp)

```cpp
#include "Fraction.h"     // Include file header Fraction.h

// Constructor tạo phân số
Fraction::Fraction(int t, int m) {
    tu = t;                 // Gán tử số
    mau = (m == 0) ? 1 : m; // Kiểm tra mẫu số = 0, nếu đúng thì gán = 1
}

// Định nghĩa toán tử << để xuất phân số
ostream& operator<<(ostream& out, const Fraction& f) {
    out << f.tu << "/" << f.mau;  // Hiển thị dạng "tử/mẫu"
    return out;             // Trả về tham chiếu để có thể nối chuỗi
}

// Tính giá trị phân số (dạng số thực)
float Fraction::giatri() const {
    return (float)tu / mau; // Ép kiểu tử số thành float để đảm bảo phép chia thực
}

// Toán tử cộng hai phân số
Fraction Fraction::operator+(const Fraction& other) const {
    // Công thức: a/b + c/d = (a*d + c*b)/(b*d)
    return Fraction(tu * other.mau + other.tu * mau, mau * other.mau);
}

// Toán tử trừ hai phân số
Fraction Fraction::operator-(const Fraction& other) const {
    // Công thức: a/b - c/d = (a*d - c*b)/(b*d)
    return Fraction(tu * other.mau - other.tu * mau, mau * other.mau);
}

// Toán tử nhân hai phân số
Fraction Fraction::operator*(const Fraction& other) const {
    // Công thức: a/b * c/d = (a*c)/(b*d)
    return Fraction(tu * other.tu, mau * other.mau);
}
```

**Phân tích chi tiết từng phần:**

1. **Constructor `Fraction::Fraction(int t, int m)`:**
   - Khởi tạo phân số với tử số `t` và mẫu số `m`
   - Tử số được gán trực tiếp: `tu = t;`
   - Mẫu số được kiểm tra để tránh chia cho 0:
     - `mau = (m == 0) ? 1 : m;` - nếu m = 0, gán mẫu = 1, ngược lại giữ nguyên
   - Đây là xử lý lỗi đơn giản để tránh crash khi có mẫu số bằng 0

2. **Toán tử `operator<<`:**
   - Định nghĩa cách hiển thị phân số dạng "tử/mẫu"
   - Ví dụ: phân số 3/4 sẽ được hiển thị là "3/4"
   - `return out;` cho phép nối chuỗi toán tử như `cout << f1 << " + " << f2;`

3. **Phương thức `giatri()`:**
   - Tính giá trị số thực của phân số
   - `(float)tu` ép kiểu tử số thành float để đảm bảo kết quả là số thực

4. **Toán tử `operator+`:**
   - Cộng hai phân số theo công thức: a/b + c/d = (a*d + c*b)/(b*d)
   - `tu * other.mau`: Tử số của phân số thứ nhất nhân với mẫu số của phân số thứ hai
   - `other.tu * mau`: Tử số của phân số thứ hai nhân với mẫu số của phân số thứ nhất
   - `mau * other.mau`: Mẫu số của phân số kết quả là tích hai mẫu số
   - Trả về đối tượng Fraction mới chứa kết quả

5. **Toán tử `operator-`:**
   - Trừ hai phân số theo công thức: a/b - c/d = (a*d - c*b)/(b*d)
   - Tương tự phép cộng, chỉ thay dấu + bằng dấu -

6. **Toán tử `operator*`:**
   - Nhân hai phân số theo công thức: a/b * c/d = (a*c)/(b*d)
   - Tử số của phân số kết quả là tích hai tử số
   - Mẫu số của phân số kết quả là tích hai mẫu số

**Các điểm cần chú ý:**

1. **Không có rút gọn phân số:**
   - Lớp Fraction hiện không có cơ chế rút gọn phân số
   - Ví dụ: 2/4 sẽ không tự động chuyển thành 1/2
   - Một cải tiến có thể thêm là viết hàm tìm UCLN và rút gọn phân số

2. **Xử lý mẫu số bằng 0:**
   - Constructor đã xử lý trường hợp mẫu số bằng 0 bằng cách gán mặc định là 1
   - Tuy nhiên, sau các phép tính, mẫu số vẫn có thể bằng 0 nếu other.mau = 0

3. **Hiệu suất:**
   - Các phép tính hiện tại có thể dẫn đến phân số với tử và mẫu rất lớn
   - Trong ứng dụng thực tế, cần có cơ chế rút gọn phân số sau mỗi phép tính

**Ứng dụng thực tế của lớp Fraction:**
- Biểu diễn các phép tính phân số trong ứng dụng toán học
- Cơ sở cho lớp BieuthucPS xử lý các biểu thức phân số
- Cho phép hiển thị kết quả chính xác (dạng phân số) thay vì số thực gần đúng

### 3.3. Lớp BieuthucPS (BieuthucPS.h và BieuthucPS.cpp)

**BieuthucPS.h**:
```cpp
#pragma once
#include "Bieuthuc.h"
#include "Fraction.h"

class BieuthucPS : public Bieuthuc
{
protected:
    Fraction a, b;  // Hai phân số thay vì số nguyên
public:
    BieuthucPS(int level);  // Constructor
    friend ostream& operator<<(ostream& out, BieuthucPS bt);  // Toán tử xuất
    bool kiemtra(float traloi);  // Kiểm tra đáp án
    float giatri();  // Tính giá trị biểu thức
};
```

**BieuthucPS.cpp**:
```cpp
#include "BieuthucPS.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

// Constructor tạo biểu thức phân số
BieuthucPS::BieuthucPS(int level) : Bieuthuc(level) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
    
    int gioihanln = (level <= 3) ? 10 : 100;
    
    // Tạo hai phân số ngẫu nhiên
    a = Fraction(rand() % gioihanln + 1, rand() % gioihanln + 1);
    b = Fraction(rand() % gioihanln + 1, rand() % gioihanln + 1);
}

// Định nghĩa toán tử << để xuất biểu thức phân số
ostream& operator<<(ostream& out, BieuthucPS bt) {
    out << bt.a << " " << bt.pheptoan << " " << bt.b;
    return out;
}

// Kiểm tra đáp án có đúng không (sai số < 0.0001)
bool BieuthucPS::kiemtra(float traloi) {
    return fabs(giatri() - traloi) < 0.0001;
}

// Tính giá trị biểu thức phân số
float BieuthucPS::giatri() {
    switch (pheptoan) {
        case '+': return (a + b).giatri();
        case '-': return (a - b).giatri();
        case '*': return (a * b).giatri();
        default: return 0;
    }
}
```

### 3.4. Lớp BieuthucPT (BieuthucPT.h và BieuthucPT.cpp)

**BieuthucPT.h**:
```cpp
#pragma once
#include "Bieuthuc.h"

class BieuthucPT : public Bieuthuc
{
protected:
    int c, d;  // Thêm hai toán hạng c, d cho biểu thức phức tạp
public:
    BieuthucPT(int level);  // Constructor
    friend ostream& operator<<(ostream& out, BieuthucPT bt);  // Toán tử xuất
    bool kiemtra(float traloi);  // Kiểm tra đáp án
    float giatri();  // Tính giá trị biểu thức
};
```

**BieuthucPT.cpp**:
```cpp
#include "BieuthucPT.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

// Constructor tạo biểu thức phức tạp
BieuthucPT::BieuthucPT(int level) : Bieuthuc(level) {
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }
    
    int gioihanln = (level <= 3) ? 10 : 100;
    
    // Tạo 4 số ngẫu nhiên a, b, c, d
    a = rand() % gioihanln + 1;
    b = rand() % gioihanln + 1;
    c = rand() % gioihanln + 1;
    d = rand() % gioihanln + 1;
    
    // Chọn phép toán dựa vào cấp độ
    if (level == 1) {
        pheptoan = '+';  // Cấp độ 1: Chỉ phép cộng
    }
    else if (level == 2 || level == 4) {
        pheptoan = (rand() % 2 == 0) ? '+' : '-';  // Cấp độ 2, 4: Phép cộng hoặc trừ
    }
    else {
        // Cấp độ khác: Cộng, trừ hoặc nhân
        int op = rand() % 3;
        switch (op) {
            case 0: pheptoan = '+'; break;
            case 1: pheptoan = '-'; break;
            case 2: pheptoan = '*'; break;
        }
    }
}

// Định nghĩa toán tử << để xuất biểu thức phức tạp
ostream& operator<<(ostream& out, BieuthucPT bt) {
    out << "(" << bt.a << " " << bt.pheptoan << " " << bt.b << ") " 
        << bt.pheptoan << " "
        << "(" << bt.c << " " << bt.pheptoan << " " << bt.d << ")";
    return out;
}

// Kiểm tra đáp án có đúng không (sai số < 0.0001)
bool BieuthucPT::kiemtra(float traloi) {
    return fabs(giatri() - traloi) < 0.0001;
}

// Tính giá trị biểu thức phức tạp
float BieuthucPT::giatri() {
    float first, second;
    
    // Tính giá trị biểu thức con đầu tiên (a op b)
    switch (pheptoan) {
        case '+': first = a + b; break;
        case '-': first = a - b; break;
        case '*': first = a * b; break;
        default: first = 0;
    }
    
    // Tính giá trị biểu thức con thứ hai (c op d)
    switch (pheptoan) {
        case '+': second = c + d; break;
        case '-': second = c - d; break;
        case '*': second = c * d; break;
        default: second = 0;
    }
    
    // Tính giá trị biểu thức tổng: (a op b) op (c op d)
    switch (pheptoan) {
        case '+': return first + second;
        case '-': return first - second;
        case '*': return first * second;
        default: return 0;
    }
}
```

### 3.5. Các lớp biểu thức con đơn giản

**BieuthucCong.h**:
```cpp
#pragma once
#include "Bieuthuc.h"

class BieuthucCong : public Bieuthuc
{
public:
    BieuthucCong(int level);  // Constructor
    float giatri();  // Ghi đè phương thức tính giá trị
};
```

**BieuthucCong.cpp**:
```cpp
#include "BieuthucCong.h"
#include <cstdlib>
#include <ctime>

// Constructor chỉ định phép toán là cộng
BieuthucCong::BieuthucCong(int level) : Bieuthuc(level) {
    pheptoan = '+';
}

// Tính giá trị phép cộng
float BieuthucCong::giatri() {
    return a + b;
}
```

**BieuthucTru.h** và **BieuthucTru.cpp**, **BieuthucNhan.h** và **BieuthucNhan.cpp** có cấu trúc tương tự, chỉ khác phép toán.

### 3.6. Tệp main.cpp

File này chứa hàm main và các hàm phụ trợ để chạy trò chơi. Một số hàm quan trọng:

1. **taoline**: Tạo chuỗi các ký tự lặp lại
2. **hienThiMenu**: Hiển thị menu chính của chương trình
3. **hienThiHuongDan**: Hiển thị hướng dẫn chơi
4. **choiGame**: Xử lý lô-gic trò chơi chính
5. **main**: Điểm khởi đầu chương trình

```cpp
// Hàm main - điểm khởi đầu chương trình
int main() {
    // Đặt hạt giống cho bộ sinh số ngẫu nhiên
    srand(static_cast<unsigned int>(time(0)));
    
    // Cấu hình để hiển thị tiếng Việt
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    int luachon;
    do {
        system("cls");  // Xóa màn hình
        hienThiMenu();  // Hiển thị menu
        cin >> luachon;
        
        switch (luachon) {
            case 1:
                choiGame();  // Bắt đầu chơi game
                break;
                
            case 2:
                hienThiHuongDan();  // Hiển thị hướng dẫn
                break;
                
            case 3:
                cout << "\nCảm ơn bạn đã chơi! Tạm biệt.\n";  // Thoát
                break;
                
            default:
                cout << "\nLựa chọn không hợp lệ. Vui lòng thử lại.\n";
                cout << "Nhấn Enter để tiếp tục...";
                cin.ignore();
                cin.get();
        }
    } while (luachon != 3);  // Lặp lại cho đến khi người dùng chọn thoát
    
    return 0;
}
```

### 3.7. Tệp run.cmd

Đây là tệp script để biên dịch và chạy chương trình:

```cmd
@echo off
chcp 65001 > nul
echo Biên dịch và chạy chương trình...

g++ -c main.cpp
g++ -c Dethi.cpp
g++ -c Bieuthuc.cpp
g++ -c BieuthucCong.cpp
g++ -c BieuthucTru.cpp
g++ -c BieuthucNhan.cpp
g++ -c Fraction.cpp
g++ -c BieuthucPS.cpp
g++ -c BieuthucPT.cpp

g++ -o main.exe main.o Dethi.o Bieuthuc.o BieuthucCong.o BieuthucTru.o BieuthucNhan.o Fraction.o BieuthucPS.o BieuthucPT.o

if %errorlevel% neq 0 (
    echo.
    echo Biên dịch thất bại! Kiểm tra lỗi và thử lại.
    echo.
    pause
    exit /b
)

del *.o

echo.
echo Biên dịch thành công!
echo.
echo Đang chạy chương trình...
echo.

main.exe

pause
```

## 4. Cách chơi game

1. Chạy file `run.cmd` để biên dịch và khởi động chương trình.
2. Chọn tùy chọn "Bắt đầu trò chơi" từ menu chính.
3. Chương trình sẽ hiển thị câu hỏi toán học dựa trên cấp độ hiện tại.
4. Nhập đáp án của bạn.
5. Nếu trả lời đúng, bạn được cộng điểm và có thể lên cấp độ cao hơn sau khi trả lời đúng 3 câu liên tiếp.
6. Nếu trả lời sai, cấp độ có thể giảm.
7. Tiếp tục chơi hoặc quay lại menu chính.

## 5. Giải thích chi tiết về cấp độ khó

1. **Cấp độ 1**: Chỉ phép cộng, số từ 1-10
2. **Cấp độ 2**: Phép cộng và trừ, số từ 1-10 
3. **Cấp độ 3**: Phép cộng, trừ và nhân, số từ 1-10
4. **Cấp độ 4**: Phép cộng và trừ, số từ 10-100
5. **Cấp độ 5+**: Phép cộng, trừ và nhân, số từ 10-100
6. **Cấp độ cao hơn**: Thêm biểu thức phức tạp và phân số

## 6. Cài đặt và yêu cầu hệ thống

### 6.1. Yêu cầu hệ thống

1. **Hệ điều hành**: Windows (đã được kiểm tra trên Windows 10, 11)
2. **Trình biên dịch**: GCC (MinGW) 8.1.0 trở lên
3. **RAM**: Tối thiểu 512MB
4. **Không gian đĩa**: Khoảng 10MB cho chương trình và các file tạm
5. **Yêu cầu hiển thị**: Hỗ trợ UTF-8 để hiển thị tiếng Việt

### 6.2. Hướng dẫn cài đặt trình biên dịch MinGW

1. **Tải MinGW**:
   - Truy cập trang web: https://sourceforge.net/projects/mingw/
   - Tải xuống trình cài đặt MinGW

2. **Cài đặt MinGW**:
   - Chạy file cài đặt đã tải xuống
   - Chọn các gói cần thiết:
     - mingw32-base
     - mingw32-gcc-g++
     - mingw32-gcc-objc
   - Chọn "Installation" > "Apply Changes" để cài đặt

3. **Cấu hình biến môi trường PATH**:
   - Nhấp chuột phải vào "This PC" > "Properties" > "Advanced system settings"
   - Chọn "Environment Variables"
   - Trong phần "System variables", tìm biến "Path" và chọn "Edit"
   - Thêm đường dẫn đến thư mục bin của MinGW (thường là `C:\MinGW\bin`)
   - Nhấn "OK" để lưu thay đổi

4. **Kiểm tra cài đặt**:
   - Mở Command Prompt
   - Gõ lệnh: `g++ --version`
   - Nếu hiển thị phiên bản GCC, cài đặt đã thành công

### 6.3. Hướng dẫn biên dịch và chạy chương trình

#### 6.3.1. Sử dụng file script run.cmd

1. **Mở Command Prompt**:
   - Nhấn tổ hợp phím `Win + R`
   - Gõ `cmd` và nhấn Enter

2. **Di chuyển đến thư mục dự án**:
   ```batch
   cd đường_dẫn_đến_thư_mục_dự_án
   ```

3. **Chạy file script**:
   ```batch
   run.cmd
   ```

File `run.cmd` sẽ tự động biên dịch tất cả các file .cpp và tạo ra file thực thi `main.exe`.

#### 6.3.2. Biên dịch thủ công

Nếu không muốn sử dụng file script, bạn có thể biên dịch thủ công như sau:

1. **Biên dịch từng file .cpp thành file đối tượng .o**:
   ```batch
   g++ -c main.cpp
   g++ -c Dethi.cpp
   g++ -c Bieuthuc.cpp
   g++ -c BieuthucCong.cpp
   g++ -c BieuthucTru.cpp
   g++ -c BieuthucNhan.cpp
   g++ -c Fraction.cpp
   g++ -c BieuthucPS.cpp
   g++ -c BieuthucPT.cpp
   ```

2. **Liên kết các file đối tượng thành file thực thi**:
   ```batch
   g++ -o main.exe main.o Dethi.o Bieuthuc.o BieuthucCong.o BieuthucTru.o BieuthucNhan.o Fraction.o BieuthucPS.o BieuthucPT.o
   ```

3. **Xóa các file đối tượng tạm thời**:
   ```batch
   del *.o
   ```

4. **Chạy chương trình**:
   ```batch
   main.exe
   ```

### 6.4. Giải thích chi tiết file run.cmd

File `run.cmd` là script tự động hóa quá trình biên dịch và chạy chương trình. Dưới đây là phân tích chi tiết:

```batch
@echo off                  # Tắt hiển thị lệnh trong CMD 
chcp 65001 > nul           # Chuyển code page sang UTF-8 để hỗ trợ tiếng Việt, ">nul" ẩn output
echo Biên dịch và chạy chương trình...  # Hiển thị thông báo

# Biên dịch từng file .cpp thành file đối tượng .o
g++ -c main.cpp            # -c: chỉ biên dịch, không liên kết
g++ -c Dethi.cpp
g++ -c Bieuthuc.cpp
g++ -c BieuthucCong.cpp
g++ -c BieuthucTru.cpp
g++ -c BieuthucNhan.cpp
g++ -c Fraction.cpp
g++ -c BieuthucPS.cpp
g++ -c BieuthucPT.cpp

g++ -o main.exe main.o Dethi.o Bieuthuc.o BieuthucCong.o BieuthucTru.o BieuthucNhan.o Fraction.o BieuthucPS.o BieuthucPT.o

if %errorlevel% neq 0 (    # errorlevel: biến môi trường chứa mã lỗi của lệnh gần nhất
    echo.                   # In dòng trống
    echo Biên dịch thất bại! Kiểm tra lỗi và thử lại.
    echo.
    pause                   # Dừng màn hình để người dùng đọc thông báo
    exit /b                 # Thoát script với mã lỗi hiện tại
)

del *.o                    # Xóa tất cả file có đuôi .o

echo.                      # In dòng trống
echo Biên dịch thành công!
echo.
echo Đang chạy chương trình...
echo.

# Chạy chương trình đã biên dịch
main.exe

pause                      # Dừng màn hình sau khi chương trình kết thúc
```

## 7. Mở rộng ứng dụng

### 7.1. Thêm phép chia

Để thêm phép chia vào ứng dụng, bạn cần:

1. **Thêm phép chia vào lớp Bieuthuc:**

```cpp
// Trong Bieuthuc.h, thêm phép '/' vào các phép toán
protected:
    int a, b;
    char pheptoan; // +, -, *, /

// Trong Bieuthuc.cpp, sửa constructor để có thể chọn phép chia
Bieuthuc::Bieuthuc(int level) {
    // ...
    else {
        int op = rand() % 4;  // Thay đổi từ 3 thành 4
        switch (op) {
            case 0: pheptoan = '+'; break;
            case 1: pheptoan = '-'; break;
            case 2: pheptoan = '*'; break;
            case 3: pheptoan = '/'; break;  // Thêm phép chia
        }
    }
    
    // Đảm bảo phép chia không chia cho 0
    if (pheptoan == '/' && b == 0) b = 1;
}

// Trong phương thức giatri(), thêm phép chia
float Bieuthuc::giatri() {
    switch (pheptoan) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return (float)a / b;  // Chia với kết quả là số thực
        default: return 0;
    }
}
```

2. **Thêm phép chia vào lớp Fraction:**

```cpp
// Trong Fraction.h
Fraction operator/(const Fraction& other) const;  // Chia hai phân số

// Trong Fraction.cpp
Fraction Fraction::operator/(const Fraction& other) const {
    // Kiểm tra chia cho 0
    if (other.tu == 0) {
        return Fraction(0, 1);  // Trả về 0 nếu chia cho 0
    }
    // a/b ÷ c/d = (a*d)/(b*c)
    return Fraction(tu * other.mau, mau * other.tu);
}
```

3. **Cập nhật các lớp con:**
   - Tạo lớp `BieuthucChia` tương tự như `BieuthucCong`
   - Cập nhật `BieuthucPS` và `BieuthucPT` để hỗ trợ phép chia

### 7.2. Thêm giao diện đồ họa

Để thêm giao diện đồ họa, bạn có thể sử dụng một số thư viện như:

1. **SFML (Simple and Fast Multimedia Library)**:
   - Cài đặt SFML: https://www.sfml-dev.org/download.php
   - Tạo các class hiển thị đồ họa
   - Sử dụng sự kiện chuột và bàn phím thay vì nhập từ console

2. **Qt Framework**:
   - Cài đặt Qt: https://www.qt.io/download
   - Thiết kế giao diện với Qt Designer
   - Tích hợp logic hiện tại vào ứng dụng Qt

Ví dụ mẫu với SFML:

```cpp
#include <SFML/Graphics.hpp>
#include "Bieuthuc.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ứng dụng Luyện Toán");
    sf::Font font;
    font.loadFromFile("arial.ttf");
    
    Bieuthuc bt(1);
    
    sf::Text questionText;
    questionText.setFont(font);
    questionText.setString(sf::String("Tính: " + std::to_string(bt.getA()) + " " + bt.getPhepToan() + " " + std::to_string(bt.getB())));
    questionText.setPosition(300, 200);
    
    // Vòng lặp chính
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            
            // Xử lý sự kiện...
        }
        
        window.clear(sf::Color::White);
        window.draw(questionText);
        window.display();
    }
    
    return 0;
}
```

### 7.3. Lưu trạng thái và bảng xếp hạng

Để lưu trạng thái và bảng xếp hạng, bạn có thể:

1. **Tạo lớp `Player` để lưu thông tin người chơi:**

```cpp
class Player {
private:
    string name;
    int level;
    int score;
    int correctAnswers;
    int totalAnswers;
    
public:
    Player(string n) : name(n), level(1), score(0), correctAnswers(0), totalAnswers(0) {}
    
    void incrementScore(int points) { score += points; }
    void incrementCorrectAnswers() { correctAnswers++; totalAnswers++; }
    void incrementTotalAnswers() { totalAnswers++; }
    
    // Getters, setters và các phương thức khác
    
    // Lưu dữ liệu người chơi vào file
    void saveToFile() {
        ofstream file("players/" + name + ".dat");
        if (file.is_open()) {
            file << name << endl;
            file << level << endl;
            file << score << endl;
            file << correctAnswers << endl;
            file << totalAnswers << endl;
            file.close();
        }
    }
    
    // Tải dữ liệu người chơi từ file
    static Player loadFromFile(string name) {
        Player player(name);
        ifstream file("players/" + name + ".dat");
        if (file.is_open()) {
            string n;
            getline(file, n);
            file >> player.level;
            file >> player.score;
            file >> player.correctAnswers;
            file >> player.totalAnswers;
            file.close();
        }
        return player;
    }
};
```

2. **Tạo lớp `Leaderboard` để quản lý bảng xếp hạng:**

```cpp
class Leaderboard {
private:
    vector<Player> players;
    
public:
    void addPlayer(const Player& player) {
        players.push_back(player);
        sort(players.begin(), players.end(), 
            [](const Player& a, const Player& b) { return a.getScore() > b.getScore(); });
    }
    
    void displayLeaderboard() {
        cout << "===== BẢNG XẾP HẠNG =====" << endl;
        for (int i = 0; i < min(10, (int)players.size()); i++) {
            cout << (i+1) << ". " << players[i].getName() << ": " << players[i].getScore() << " điểm" << endl;
        }
    }
    
    void saveToFile() {
        ofstream file("leaderboard.dat");
        if (file.is_open()) {
            file << players.size() << endl;
            for (const auto& player : players) {
                file << player.getName() << endl;
                file << player.getScore() << endl;
            }
            file.close();
        }
    }
    
    void loadFromFile() {
        ifstream file("leaderboard.dat");
        if (file.is_open()) {
            int size;
            file >> size;
            file.ignore();
            
            for (int i = 0; i < size; i++) {
                string name;
                int score;
                getline(file, name);
                file >> score;
                file.ignore();
                
                Player player = Player::loadFromFile(name);
                players.push_back(player);
            }
            
            file.close();
        }
    }
};
```

### 7.4. Thêm chế độ kiểm tra thời gian

Để thêm chế độ kiểm tra thời gian, bạn có thể:

1. **Sử dụng thư viện `<chrono>` để đo thời gian:**

```cpp
#include <chrono>

// Trong hàm main() hoặc một hàm riêng
void timeTrialMode() {
    cout << "==== CHẾ ĐỘ KIỂM TRA THỜI GIAN ====" << endl;
    cout << "Trả lời càng nhiều câu càng tốt trong 60 giây!" << endl;
    
    int score = 0;
    int questionCount = 0;
    
    // Thời điểm bắt đầu
    auto startTime = chrono::steady_clock::now();
    
    // Thời gian chơi (60 giây)
    const int gameDuration = 60;
    
    while (true) {
        // Kiểm tra thời gian đã trôi qua
        auto currentTime = chrono::steady_clock::now();
        auto elapsedSeconds = chrono::duration_cast<chrono::seconds>(currentTime - startTime).count();
        
        // Nếu đã hết thời gian
        if (elapsedSeconds >= gameDuration) {
            break;
        }
        
        // Hiển thị thời gian còn lại
        cout << "Thời gian còn lại: " << (gameDuration - elapsedSeconds) << " giây" << endl;
        
        // Tạo câu hỏi ngẫu nhiên
        Bieuthuc bt(1 + rand() % 3);  // Cấp độ từ 1-3 ngẫu nhiên
        cout << "Câu hỏi #" << (questionCount + 1) << ": " << bt << " = ? ";
        
        float answer;
        cin >> answer;
        
        if (bt.kiemtra(answer)) {
            cout << "Đúng! +10 điểm" << endl;
            score += 10;
        } else {
            cout << "Sai! Đáp án đúng là: " << bt.giatri() << endl;
        }
        
        questionCount++;
    }
    
    cout << "==== KẾT THÚC ====" << endl;
    cout << "Số câu đã trả lời: " << questionCount << endl;
    cout << "Điểm số: " << score << endl;
}
```

## 8. Kết luận và kiến thức quan trọng

### 8.1. Các khái niệm OOP quan trọng trong dự án

1. **Kế thừa (Inheritance)**:
   - BieuthucCong, BieuthucTru, BieuthucNhan kế thừa từ Bieuthuc
   - Cho phép tái sử dụng code và chuyên biệt hóa từng loại biểu thức

2. **Đa hình (Polymorphism)**:
   - Các phương thức giatri() được ghi đè (override) trong các lớp con
   - Cùng một phương thức nhưng có hành vi khác nhau tùy thuộc vào loại đối tượng

3. **Nạp chồng toán tử (Operator Overloading)**:
   - << để xuất đối tượng
   - +, -, * để thực hiện phép tính với các đối tượng Fraction

4. **Đóng gói (Encapsulation)**:
   - Phân chia rõ ràng thuộc tính và phương thức public/protected/private
   - Bảo vệ dữ liệu và cung cấp giao diện sử dụng

5. **Lớp bạn (Friend Class)**:
   - Sử dụng friend để cho phép toán tử << truy cập các thuộc tính private/protected
   - Giữ tính đóng gói nhưng vẫn cho phép các chức năng cần thiết

### 8.2. Lợi ích của cấu trúc OOP trong dự án

1. **Dễ bảo trì và mở rộng**:
   - Thêm phép tính mới không ảnh hưởng đến code hiện có
   - Phân tách rõ ràng giữa các thành phần chức năng

2. **Tái sử dụng code**:
   - Lớp cơ sở Bieuthuc cung cấp nền tảng chung
   - Các lớp con chỉ triển khai phần khác biệt

3. **Mô hình hóa trực quan**:
   - Phản ánh mối quan hệ tự nhiên giữa các thành phần
   - Ví dụ: Cộng, Trừ, Nhân là các loại Biểu thức

### 8.3. Các kỹ thuật lập trình quan trọng

1. **Xử lý ngẫu nhiên**:
   - Sử dụng hàm rand() và srand() để tạo câu hỏi ngẫu nhiên
   - Đặt hạt giống (seed) khác nhau để tránh lặp lại

2. **Xử lý đầu vào/đầu ra**:
   - Sử dụng cin, cout cho giao diện console
   - Nạp chồng toán tử << để format dữ liệu

3. **Xử lý lỗi**:
   - Kiểm tra mẫu số = 0 trong phân số
   - Sử dụng sai số nhỏ khi so sánh số thực

4. **Quản lý bộ nhớ**:
   - Sử dụng con trỏ và cấp phát động trong chương trình chính
   - Giải phóng bộ nhớ sử dụng delete

### 8.4. Hướng phát triển trong tương lai

1. **Cải thiện thuật toán**:
   - Thêm hàm rút gọn phân số
   - Tối ưu hóa các phép tính toán

2. **Giao diện người dùng**:
   - Chuyển sang giao diện đồ họa với thư viện như SFML hoặc Qt
   - Thêm hiệu ứng âm thanh và hình ảnh

3. **Thêm tính năng mới**:
   - Hệ thống tài khoản người dùng
   - Lưu trữ dữ liệu với cơ sở dữ liệu
   - Chế độ nhiều người chơi

4. **Mở rộng các loại câu hỏi**:
   - Thêm các dạng toán học mới: căn bậc hai, luỹ thừa, logarit
   - Thêm câu hỏi hình học

Đây là một dự án C++ hướng đối tượng khá toàn diện, sử dụng nhiều khái niệm OOP như kế thừa, đa hình, nạp chồng toán tử. Dự án này rất phù hợp cho người học lập trình C++ và OOP, đồng thời cung cấp nền tảng tốt để phát triển thêm các tính năng nâng cao. 

## 9. Hướng dẫn chi tiết về luồng chạy chương trình

### 9.1. Khởi động và menu chính

Khi chương trình được khởi động, các bước sau sẽ diễn ra:

1. **Cấu hình môi trường**:
   ```cpp
   // Đặt hạt giống ngẫu nhiên
   srand(time(0));
   
   // Cấu hình để hiển thị tiếng Việt
   SetConsoleCP(65001);
   SetConsoleOutputCP(65001);
   ```
   - `srand(time(0))`: Đặt hạt giống cho bộ tạo số ngẫu nhiên dựa trên thời gian hiện tại
   - `SetConsoleCP/OutputCP`: Cấu hình console để hỗ trợ tiếng Việt với UTF-8

2. **Hiển thị menu chính**:
   ```cpp
   system("cls");  // Xóa màn hình
   hienThiMenu();  // Hiển thị menu chính
   ```
   
   Hàm `hienThiMenu()` hiển thị các tùy chọn:
   ```cpp
   void hienThiMenu() {
       cout << "==============================================\n";
       cout << "     CHƯƠNG TRÌNH ĐỐ VUI TOÁN HỌC\n";
       cout << "==============================================\n";
       cout << "Họ và tên: Hoàng Việt Quang\n";
       cout << "MSSV: 066206005044\n";
       cout << "GitHub: https://github.com/TeoSushi1014/oop\n";
       cout << "==============================================\n";
       cout << "1. Bắt đầu trò chơi\n";
       cout << "2. Xem hướng dẫn\n";
       cout << "3. Thoát\n";
       cout << "Lựa chọn của bạn: ";
   }
   ```

3. **Xử lý lựa chọn của người dùng**:
   ```cpp
   cin >> luachon;
   
   switch (luachon) {
       case 1:
           choiGame();  // Bắt đầu trò chơi
           break;
           
       case 2:
           hienThiHuongDan();  // Hiển thị hướng dẫn
           break;
           
       case 3:
           cout << "\nCảm ơn bạn đã chơi! Tạm biệt.\n";  // Thoát
           break;
           
       default:
           cout << "\nLựa chọn không hợp lệ. Vui lòng thử lại.\n";
           cout << "Nhấn Enter để tiếp tục...";
           cin.ignore();
           cin.get();
   }
   ```
   - Chương trình lặp lại vòng lặp menu cho đến khi người dùng chọn "Thoát" (tùy chọn 3)

### 9.2. Luồng chạy trong chế độ chơi game

Khi người dùng chọn "Bắt đầu trò chơi", hàm `choiGame()` được gọi và các bước sau sẽ diễn ra:

1. **Khởi tạo biến chơi game**:
   ```cpp
   void choiGame() {
       system("cls");
       cout << "==============================================\n";
       cout << "     BẮT ĐẦU CHƠI\n";
       cout << "==============================================\n";
       
       int level = 1;          // Cấp độ ban đầu = 1
       int socau = 0;          // Số câu đã chơi = 0
       int socaudung = 0;      // Số câu trả lời đúng = 0
       int socaulientiep = 0;  // Số câu đúng liên tiếp = 0
       int diemso = 0;         // Điểm số = 0
       // ...
   }
   ```

2. **Vòng lặp chơi game**:
   ```cpp
   while (true) {
       system("cls");
       cout << "==============================================\n";
       cout << "     LEVEL: " << level << "     ĐIỂM: " << diemso << "\n";
       cout << "==============================================\n";
       
       // Tạo biểu thức ngẫu nhiên dựa trên cấp độ hiện tại
       Bieuthuc* bt = nullptr;
       
       int loaiBT = rand() % 100;  // Chọn loại biểu thức ngẫu nhiên
       
       // Tạo biểu thức phù hợp với cấp độ
       if (level <= 3) {
           if (level == 1) {
               bt = new BieuthucCong(level);
           } else if (level == 2) {
               if (loaiBT < 50)
                   bt = new BieuthucCong(level);
               else
                   bt = new BieuthucTru(level);
           } else {
               if (loaiBT < 33)
                   bt = new BieuthucCong(level);
               else if (loaiBT < 66)
                   bt = new BieuthucTru(level);
               else
                   bt = new BieuthucNhan(level);
           }
       }
       // ... (xử lý các cấp độ khác)
       
       // Hiển thị câu hỏi
       socau++;
       cout << "Câu hỏi #" << socau << ": ";
       cout << *bt << " = ? ";
       
       // Đọc đáp án từ người dùng
       float traloi;
       cout << "\nNhập câu trả lời của bạn: ";
       cin >> traloi;
       
       // Kiểm tra đáp án
       if (bt->kiemtra(traloi)) {
           // Xử lý khi trả lời đúng
           cout << "\nChính xác! +10 điểm\n";
           socaudung++;
           socaulientiep++;
           diemso += 10;
           
           // Tăng cấp độ nếu đủ điều kiện
           if (socaulientiep >= 3) {
               socaulientiep = 0;
               if (level < 10) {
                   level++;
                   cout << "\nChúc mừng! Bạn đã lên cấp độ " << level << "!\n";
               }
           }
       } else {
           // Xử lý khi trả lời sai
           cout << "\nSai rồi! Đáp án đúng là: " << bt->giatri() << "\n";
           socaulientiep = 0;
           
           // Giảm cấp độ nếu cấp độ > 1
           if (level > 1) {
               level--;
               cout << "Bạn đã xuống cấp độ " << level << ".\n";
           }
       }
       
       // Giải phóng bộ nhớ
       delete bt;
       
       // Hỏi người dùng có muốn tiếp tục không
       cout << "\nBạn có muốn tiếp tục chơi không? (y/n): ";
       char tieptuc;
       cin >> tieptuc;
       
       if (tieptuc != 'y' && tieptuc != 'Y') {
           // Hiển thị kết quả cuối cùng
           cout << "\n==============================================\n";
           cout << "     KẾT QUẢ\n";
           cout << "==============================================\n";
           cout << "Tổng số câu: " << socau << "\n";
           cout << "Số câu đúng: " << socaudung << "\n";
           cout << "Điểm số: " << diemso << "\n";
           cout << "Nhấn Enter để quay lại menu chính...";
           cin.ignore();
           cin.get();
           break;
       }
   }
   ```

3. **Chi tiết quan trọng trong vòng lặp chơi game**:

   a. **Cơ chế tăng/giảm cấp độ**:
      - Đúng 3 câu liên tiếp: Tăng 1 cấp độ