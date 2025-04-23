# Hướng dẫn từng bước - Bài tập về tính đa hình trong C++

## Đề bài
Yêu cầu:
1. Hiện thực Lớp Shape, Rectangle, và Triangle
2. Chạy thử và giải thích kết quả xuất ra màn hình
3. Chỉnh sửa để kết quả xuất ra là diện tích của các hình thuộc lớp con tương ứng

## Bước 1: Hiểu mã nguồn ban đầu

```cpp
#include<iostream>
using namespace std;

class Shape{
protected:
    int width, height;
public:
    Shape(int a = 0, int b = 0){
        width = a;
        height = b;
    }
    
    int area(){
        cout << "Parent class area :" << endl;
        return 0;
    }
};

class Rectangle: public Shape{
public:
    Rectangle(int a = 0, int b = 0): Shape(a, b){}
    
    int area(){
        cout << "Rectangle class area :" << endl;
        return (width * height);
    }
};

class Triangle: public Shape{
public:
    Triangle(int a = 0, int b = 0): Shape(a, b){}
    
    int area(){
        cout << "Triangle class area :" << endl;
        return (width * height / 2);
    }
};

int main(){
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);
    
    // store the address of Rectangle
    shape = &rec;
    // call rectangle area.
    shape->area();
    
    // store the address of Triangle
    shape = &tri;
    // call triangle area.
    shape->area();
    
    return 0;
}
```

## Bước 2: Biên dịch và chạy chương trình

### Cách biên dịch:
1. Mở terminal hoặc command prompt
2. Lưu mã nguồn vào file `shape.cpp`
3. Biên dịch với g++: `g++ shape.cpp -o shape`
4. Chạy chương trình: `./shape` (trên Linux/Mac) hoặc `shape.exe` (trên Windows)

### Kết quả khi chạy:
```
Parent class area :
Parent class area :
```

## Bước 3: Phân tích kết quả ban đầu

Quan sát kết quả, ta thấy:
- Thay vì hiển thị "Rectangle class area :" và "Triangle class area :", chương trình luôn hiển thị "Parent class area :"
- Phương thức `area()` của lớp cơ sở `Shape` được gọi, không phải phương thức của lớp con

### Lý do:
- Trong C++, khi khai báo một phương thức trong lớp cơ sở mà không có từ khóa `virtual`, việc gọi phương thức thông qua con trỏ của lớp cơ sở sẽ luôn gọi phương thức của lớp cơ sở, không phụ thuộc vào kiểu thực của đối tượng
- Đây gọi là liên kết tĩnh (static binding)

## Bước 4: Sửa lỗi để hiển thị đúng diện tích

### Cách sửa:
1. Thêm từ khóa `virtual` vào phương thức `area()` trong lớp cơ sở `Shape`
2. Sửa hàm `main()` để hiển thị giá trị diện tích được trả về

### Mã nguồn sau khi sửa:
```cpp
#include<iostream>
using namespace std;

class Shape{
protected:
    int width, height;
public:
    Shape(int a = 0, int b = 0){
        width = a;
        height = b;
    }
    
    virtual int area(){  // Thêm từ khóa virtual ở đây
        cout << "Parent class area :" << endl;
        return 0;
    }
};

class Rectangle: public Shape{
public:
    Rectangle(int a = 0, int b = 0): Shape(a, b){}
    
    int area(){
        cout << "Rectangle class area :" << endl;
        return (width * height);
    }
};

class Triangle: public Shape{
public:
    Triangle(int a = 0, int b = 0): Shape(a, b){}
    
    int area(){
        cout << "Triangle class area :" << endl;
        return (width * height / 2);
    }
};

int main(){
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);
    
    // store the address of Rectangle
    shape = &rec;
    // call rectangle area and print the result
    cout << "Area: " << shape->area() << endl;
    
    // store the address of Triangle
    shape = &tri;
    // call triangle area and print the result
    cout << "Area: " << shape->area() << endl;
    
    return 0;
}
```

## Bước 5: Biên dịch và chạy lại chương trình

### Kết quả mới sau khi sửa:
```
Rectangle class area :
Area: 70
Triangle class area :
Area: 25
```

## Bước 6: Giải thích chi tiết

### 1. Vấn đề trong phiên bản gốc:
- Phương thức `area()` trong lớp `Shape` không được khai báo là `virtual`
- Khi sử dụng con trỏ của lớp cơ sở (`Shape*`) để gọi phương thức, C++ sử dụng liên kết tĩnh
- Liên kết tĩnh dựa vào kiểu của con trỏ (`Shape*`), không phải kiểu thực của đối tượng (`Rectangle` hoặc `Triangle`)
- Do đó, luôn gọi phương thức `area()` của lớp `Shape`

### 2. Giải pháp:
- Thêm từ khóa `virtual` vào phương thức `area()` trong lớp `Shape`
- Điều này kích hoạt cơ chế liên kết động (dynamic binding)
- Liên kết động xác định phương thức sẽ gọi dựa trên kiểu thực của đối tượng tại thời điểm chạy
- Khi con trỏ `shape` trỏ đến đối tượng `Rectangle`, phương thức `area()` của `Rectangle` được gọi
- Khi con trỏ `shape` trỏ đến đối tượng `Triangle`, phương thức `area()` của `Triangle` được gọi

### 3. Diện tích được tính toán:
- Hình chữ nhật: width × height = 10 × 7 = 70
- Hình tam giác: (width × height) / 2 = (10 × 5) / 2 = 25

### 4. Cách C++ thực hiện đa hình:
- C++ sử dụng bảng phương thức ảo (virtual method table - VMT) để triển khai đa hình
- Từ khóa `virtual` chỉ dẫn trình biên dịch tạo một VMT cho lớp
- Khi gọi phương thức thông qua con trỏ lớp cơ sở, C++ tra cứu VMT để tìm phương thức thích hợp cần gọi

## Bước 7: Cải tiến thêm (không bắt buộc)

Để làm cho code tốt hơn, ta có thể:

1. Sử dụng hàm hủy ảo trong lớp cơ sở:
```cpp
virtual ~Shape() {}
```

2. Sử dụng từ khóa `override` trong các lớp con (C++11 trở lên):
```cpp
int area() override {
    cout << "Rectangle class area :" << endl;
    return (width * height);
}
```

3. Sử dụng lớp trừu tượng cho `Shape`:
```cpp
virtual int area() = 0; // Phương thức thuần ảo
```

## Kết luận

Qua bài tập này, chúng ta đã học:
1. Cách tạo lớp cơ sở và lớp dẫn xuất
2. Sự khác biệt giữa liên kết tĩnh và liên kết động
3. Cách triển khai tính đa hình trong C++ bằng từ khóa `virtual`
4. Cách ghi đè phương thức từ lớp cơ sở trong lớp dẫn xuất 