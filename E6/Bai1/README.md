# Hướng dẫn chi tiết Bai1.cpp và Bai2.cpp

## Bài 1: Hàm hoán vị với khuôn mẫu

File: `Bai1.cpp`

### Yêu cầu
Cài đặt hàm hoán vị (hoanvi) sử dụng khuôn mẫu (template). Viết chương trình main() gọi hàm hoán vị với hai đối số thuộc các kiểu dữ liệu: nguyên, thực và ký tự.

### Giải thích mã nguồn

1. **Khai báo hàm hoán vị sử dụng khuôn mẫu**:
   ```cpp
   template <typename T>
   void hoanvi(T &a, T &b) {
       T temp = a;
       a = b;
       b = temp;
   }
   ```
   - Đây là khuôn mẫu hàm có thể hoạt động với bất kỳ kiểu dữ liệu nào
   - Tham số là hai tham chiếu đến biến cùng kiểu T
   - Sử dụng biến tạm để hoán đổi giá trị giữa hai biến

2. **Hàm main**:
   ```cpp
   int main() {
       int a = 2, b = 6;                // Biến kiểu nguyên
       float c = 22.7, d = 10.14;       // Biến kiểu thực
       char e = 'T', f = 'S';           // Biến kiểu ký tự
       
       // Hiển thị giá trị trước khi hoán vị
       cout << "Truoc khi hoan vi:" << endl;
       cout << "a = " << a << ", b = " << b << endl;
       cout << "c = " << c << ", d = " << d << endl;
       cout << "e = " << e << ", f = " << f << endl;
       
       // Gọi hàm hoán vị với các kiểu dữ liệu khác nhau
       hoanvi(a, b);      // Hoán vị kiểu int
       hoanvi(c, d);      // Hoán vị kiểu float
       hoanvi(e, f);      // Hoán vị kiểu char
       
       // Hiển thị kết quả sau khi hoán vị
       cout << "\nSau khi hoan vi:" << endl;
       cout << "a = " << a << ", b = " << b << endl;
       cout << "c = " << c << ", d = " << d << endl;
       cout << "e = " << e << ", f = " << f << endl;
       
       return 0;
   }
   ```
   - Tạo các cặp biến thuộc ba kiểu khác nhau: int, float, char
   - Hiển thị giá trị ban đầu
   - Gọi hàm `hoanvi` với mỗi cặp biến
   - Hiển thị kết quả sau khi hoán vị

### Cách biên dịch và chạy
```
g++ Bai1.cpp -o Bai1
./Bai1  # Trên Linux/Mac
Bai1.exe  # Trên Windows
```

## Bài 2: Lớp Point với khuôn mẫu

File: `Bai2.cpp`

### Yêu cầu
Cài đặt lớp Point có tọa độ x, y sử dụng khuôn mẫu. Lớp Point phải có thể hoạt động với x, y thuộc các kiểu: int, float và double. Viết phương thức distance để tính khoảng cách đến một Point khác. Viết hàm main() tạo ngẫu nhiên 20 Point<int> và sắp xếp chúng theo thứ tự tăng dần khoảng cách đến gốc tọa độ (0,0).

### Giải thích mã nguồn

1. **Khai báo lớp Point với khuôn mẫu**:
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
   - Lớp Point được định nghĩa với khuôn mẫu T
   - Hai thuộc tính tư x, y kiểu T
   - Các phương thức:
     - Constructor mặc định khởi tạo điểm (0,0)
     - Constructor với tham số x, y
     - Các hàm getter: getx(), gety()
     - Phương thức print() để hiển thị tọa độ điểm
     - Phương thức distance() tính khoảng cách đến điểm khác
     - Phương thức kc_o() tính khoảng cách đến gốc tọa độ (0,0)

2. **Hàm so sánh để sắp xếp**:
   ```cpp
   bool ss(const Point<int>& a, const Point<int>& b) {
       return a.kc_o() < b.kc_o();
   }
   ```
   - Hàm này dùng để so sánh hai Point dựa vào khoảng cách đến gốc tọa độ
   - Trả về true nếu khoảng cách của a đến gốc tọa độ nhỏ hơn khoảng cách của b

3. **Hàm main**:
   ```cpp
   int main() {
       srand(time(0));  // Khởi tạo seed cho hàm random
       
       vector<Point<int>> points;
       
       // Sinh ngẫu nhiên 20 điểm
       for (int i = 0; i < 20; i++) {
           int x = rand() % 100 - 50;  // Trong khoảng [-50, 49]
           int y = rand() % 100 - 50;
           points.push_back(Point<int>(x, y));
       }
       
       // Hiển thị danh sách ban đầu
       cout << "Danh sach 20 diem ngau nhien:" << endl;
       for (int i = 0; i < 20; i++) {
           points[i].print();
           cout << " - khoang cach den goc toa do: " << points[i].kc_o() << endl;
       }
       
       // Sắp xếp các điểm theo khoảng cách đến gốc tọa độ
       sort(points.begin(), points.end(), ss);
       
       // Hiển thị danh sách sau khi sắp xếp
       cout << "\nDanh sach sau khi sap xep theo khoang cach den goc toa do tang dan:" << endl;
       for (int i = 0; i < 20; i++) {
           points[i].print();
           cout << " - khoang cach den goc toa do: " << points[i].kc_o() << endl;
       }
       
       return 0;
   }
   ```
   - Khởi tạo seed ngẫu nhiên dựa trên thời gian hiện tại
   - Tạo vector để lưu 20 điểm Point<int>
   - Sinh ngẫu nhiên tọa độ x, y trong khoảng [-50, 49] cho 20 điểm
   - Hiển thị danh sách 20 điểm và khoảng cách đến gốc tọa độ
   - Sắp xếp các điểm theo khoảng cách đến gốc tọa độ tăng dần
   - Hiển thị danh sách sau khi sắp xếp

### Cách biên dịch và chạy
```
g++ Bai2.cpp -o Bai2
./Bai2  # Trên Linux/Mac
Bai2.exe  # Trên Windows
```

## Các khái niệm quan trọng

1. **Khuôn mẫu (Template)**:
   - Cho phép tạo hàm và lớp hoạt động với nhiều kiểu dữ liệu khác nhau
   - Syntax: `template <typename T>` hoặc `template <class T>`
   - Trình biên dịch sẽ tạo mã thực tế khi chúng được sử dụng với kiểu cụ thể

2. **Tính toán khoảng cách**:
   - Khoảng cách Euclid giữa hai điểm (x1, y1) và (x2, y2):
   - distance = sqrt((x2 - x1)² + (y2 - y1)²)

3. **Sắp xếp bằng std::sort**:
   - Hàm sort() trong thư viện algorithm
   - Cần một hàm so sánh (comparator) để xác định thứ tự sắp xếp
