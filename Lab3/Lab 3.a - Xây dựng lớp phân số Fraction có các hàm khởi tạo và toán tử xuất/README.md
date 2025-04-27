# Lab 3.a - Xây dựng lớp phân số Fraction có các hàm khởi tạo và toán tử xuất

## Yêu cầu:

Cài đặt hàm khởi tạo và toán tử chèn như sau:
- `Fraction(int num, int den)`: khởi tạo phân số num/den; lưu ý nếu giá trị không hợp lệ (ví dụ 5/0) thì phân số sẽ khởi tạo thành 0/1
- `Fraction(int random)`: khởi tạo phân số với giá trị ngẫu nhiên của tử và mẫu không vượt quá giá trị random
- `operator<<`: xuất phân số theo dạng num/den với đối tượng ostream

## Cấu trúc đã được cung cấp:

Lớp Fraction (Fraction.h):
```cpp
#pragma once
#include <iostream>
using namespace std;
class Fraction
{
private:
	// Tu so
	int numerator;
	// Mau so
	int denominator;
public:

};
```

Cài đặt phương thức (Fraction.cpp):
```cpp
#include "Fraction.h"
``` 