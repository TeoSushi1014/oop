# Hướng dẫn chi tiết bài tập Templates trong C++

## Tổng quan
Bài tập này bao gồm hai phần chính:
1. **Bài 1**: Xây dựng template function để hoán vị hai biến
2. **Bài 2**: Xây dựng template class Point và thực hiện sắp xếp các điểm

## Bài 1: Template Function hoán vị (Bai1.cpp)

### Mô tả bài toán
Cài đặt hàm `hoanvi` dùng khuôn mẫu (template). Hàm này có thể hoán vị hai biến thuộc các kiểu dữ liệu khác nhau như int, float, char.

### Phân tích code

#### 1. Khai báo template function
```cpp
template <typename T>
void hoanvi(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
```

**Giải thích:**
- `template <typename T>` khai báo một template với tham số kiểu dữ liệu T
- `void hoanvi(T &a, T &b)` định nghĩa hàm hoán vị làm việc với hai tham số kiểu T
- Các tham số được truyền bằng tham chiếu (`&`) để thay đổi giá trị gốc của biến
- Thuật toán đơn giản: sử dụng biến tạm `temp` để lưu giá trị của a, sau đó gán giá trị của b cho a và cuối cùng gán giá trị tạm cho b

#### 2. Hàm main và kết quả
```cpp
int main() {
    int a = 2, b = 6;
    float c = 22.7, d = 10.14;
    char e = 'T', f = 'S';
    
    cout << "Truoc khi hoan vi:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "c = " << c << ", d = " << d << endl;
    cout << "e = " << e << ", f = " << f << endl;
    
    hoanvi(a, b);
    hoanvi(c, d);
    hoanvi(e, f);
    
    cout << "\nSau khi hoan vi:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "c = " << c << ", d = " << d << endl;
    cout << "e = " << e << ", f = " << f << endl;
    
    return 0;
}
```

**Giải thích:**
- Khởi tạo các cặp biến thuộc ba kiểu dữ liệu khác nhau (`int`, `float`, `char`)
- In ra giá trị các biến trước khi hoán vị
- Gọi hàm template `hoanvi()` với mỗi cặp biến
- In ra kết quả sau khi hoán vị để kiểm tra

### Cách biên dịch và chạy
Để biên dịch và chạy bài 1, có thể sử dụng file `run1.cmd` đã được cung cấp:
```bash
run1.cmd
```

Hoặc thực hiện thủ công:
```bash
g++ Bai1.cpp -o Bai1.exe
./Bai1.exe
```

### Kết quả
```
Truoc khi hoan vi:
a = 2, b = 6
c = 22.7, d = 10.14
e = T, f = S

Sau khi hoan vi:
a = 6, b = 2
c = 10.14, d = 22.7
e = S, f = T
```

## Bài 2: Template Class Point (Bai2.cpp)

### Mô tả bài toán
Cài đặt lớp Point có thành phần toạ độ x, y sử dụng template. Lớp Point có thể làm việc với x, y thuộc kiểu int, float hoặc double. Yêu cầu tính khoảng cách các điểm đến gốc tọa độ và sắp xếp các điểm theo thứ tự tăng dần khoảng cách.

### Phân tích code

#### 1. Khai báo template class Point
```cpp
template <typename T>
class Point {
private:
    T x;
    T y;

public:
    Point() : x(0), y(0) {}
    
    Point(T x1, T y1) : x(x1), y(y1) {}
    
    T getx() const {
        return x;
    }
    
    T gety() const {
        return y;
    }
    
    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
    
    double distance(const Point<T>& other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return sqrt(dx*dx + dy*dy);
    }
    
    double kc_o() const {
        Point<T> origin(0, 0);
        return distance(origin);
    }
};
```

**Giải thích:**
- `template <typename T>` khai báo một template class với tham số kiểu T
- **Thuộc tính**:
  - `x`, `y`: tọa độ điểm kiểu T (có thể là int, float, double)
- **Constructor**:
  - Constructor mặc định: khởi tạo điểm tại gốc tọa độ (0, 0)
  - Constructor với tham số: khởi tạo điểm với tọa độ cho trước
- **Phương thức**:
  - `getx()`, `gety()`: trả về tọa độ x, y
  - `print()`: in ra tọa độ điểm dưới dạng (x, y)
  - `distance()`: tính khoảng cách Euclid giữa hai điểm
  - `kc_o()`: tính khoảng cách từ điểm đến gốc tọa độ

#### 2. Hàm so sánh để sắp xếp
```cpp
bool ss(const Point<int>& a, const Point<int>& b) {
    return a.kc_o() < b.kc_o();
}
```

**Giải thích:**
- Hàm so sánh hai điểm dựa trên khoảng cách đến gốc tọa độ
- Trả về `true` nếu điểm a gần gốc tọa độ hơn điểm b
- Dùng làm tham số cho hàm `sort()` của thư viện chuẩn

#### 3. Hàm main và xử lý
```cpp
int main() {
    srand(time(0));
    
    vector<Point<int>> points;
    
    for (int i = 0; i < 20; i++) {
        int x = rand() % 100 - 50;
        int y = rand() % 100 - 50;
        points.push_back(Point<int>(x, y));
    }
    
    cout << "Danh sach 20 diem ngau nhien:" << endl;
    for (int i = 0; i < 20; i++) {
        points[i].print();
        cout << " - khoang cach den goc toa do: " << points[i].kc_o() << endl;
    }
    
    sort(points.begin(), points.end(), ss);
    
    cout << "\nDanh sach sau khi sap xep theo khoang cach den goc toa do tang dan:" << endl;
    for (int i = 0; i < 20; i++) {
        points[i].print();
        cout << " - khoang cach den goc toa do: " << points[i].kc_o() << endl;
    }
    
    return 0;
}
```

**Giải thích:**
- Khởi tạo bộ sinh số ngẫu nhiên với thời gian hiện tại
- Tạo vector `points` chứa 20 điểm Point<int>
- Mỗi điểm được tạo với tọa độ ngẫu nhiên trong khoảng [-50, 49]
- In danh sách các điểm và khoảng cách đến gốc tọa độ
- Sử dụng hàm `sort()` để sắp xếp các điểm theo khoảng cách đến gốc tọa độ tăng dần
- In lại danh sách sau khi sắp xếp

### Cách biên dịch và chạy
Để biên dịch và chạy bài 2, có thể sử dụng file `run2.cmd` đã được cung cấp:
```bash
run2.cmd
```

Hoặc thực hiện thủ công:
```bash
g++ Bai2.cpp -o Bai2.exe
./Bai2.exe
```

### Kết quả
```
Danh sach 20 diem ngau nhien:
(x1, y1) - khoang cach den goc toa do: d1
(x2, y2) - khoang cach den goc toa do: d2
...

Danh sach sau khi sap xep theo khoang cach den goc toa do tang dan:
(xa, ya) - khoang cach den goc toa do: da
(xb, yb) - khoang cach den goc toa do: db
...
```
Với x, y là các giá trị ngẫu nhiên và d là khoảng cách tương ứng đến gốc tọa độ. Danh sách sau khi sắp xếp sẽ có d tăng dần.

