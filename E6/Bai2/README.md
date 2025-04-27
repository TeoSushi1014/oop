## Cau21.cpp - Đếm phần tử có phân biệt

```cpp
#include <iostream>           // Thư viện nhập/xuất chuẩn
#include <vector>             // Thư viện vector
#include <map>                // Thư viện map
using namespace std;          // Sử dụng không gian tên std

int main() {                  // Hàm main - điểm bắt đầu của chương trình
    vector<int> v;            // Khai báo vector v để lưu các số nguyên nhập vào
    int x;                    // Biến x để lưu giá trị nhập từ bàn phím
    
    while (true) {            // Vòng lặp vô hạn để nhập dữ liệu
        cin >> x;             // Nhập một số nguyên từ bàn phím
        if (x < 0) {          // Nếu số đó âm
            break;            // Thoát khỏi vòng lặp
        }
        v.push_back(x);       // Thêm số đó vào cuối vector v
    }
    
    map<int, int> m;          // Khai báo map m với key là số nguyên, value là số lần xuất hiện
    for (int i = 0; i < v.size(); i++) {   // Duyệt qua từng phần tử trong vector
        m[v[i]]++;            // Tăng số lần xuất hiện của phần tử đó trong map
    }
    
    cout << m.size() << endl; // In ra số lượng phần tử khác nhau (kích thước của map)
    
    return 0;                 // Kết thúc chương trình
}
```

## Cau22.cpp - Thống kê sự xuất hiện của các phần tử

```cpp
#include <iostream>           // Thư viện nhập/xuất chuẩn
#include <vector>             // Thư viện vector
#include <map>                // Thư viện map
using namespace std;          // Sử dụng không gian tên std

int main() {                  // Hàm main - điểm bắt đầu của chương trình
    vector<int> v;            // Khai báo vector v để lưu các số nguyên nhập vào
    int x;                    // Biến x để lưu giá trị nhập từ bàn phím
    
    while (true) {            // Vòng lặp vô hạn để nhập dữ liệu
        cin >> x;             // Nhập một số nguyên từ bàn phím
        if (x < 0) {          // Nếu số đó âm
            break;            // Thoát khỏi vòng lặp
        }
        v.push_back(x);       // Thêm số đó vào cuối vector v
    }
    
    map<int, int> m;          // Khai báo map m với key là số nguyên, value là số lần xuất hiện
    for (int i = 0; i < v.size(); i++) {   // Duyệt qua từng phần tử trong vector
        m[v[i]]++;            // Tăng số lần xuất hiện của phần tử đó trong map
    }
    
    // Duyệt qua map từ phần tử đầu tiên đến phần tử cuối cùng
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
        // In ra key (giá trị phần tử) và value (số lần xuất hiện), cách nhau một khoảng trắng
    }
    
    return 0;                 // Kết thúc chương trình
}
```

## Cau23.cpp - Liệt kê vị trí xuất hiện của các phần tử

```cpp
#include <iostream>           // Thư viện nhập/xuất chuẩn
#include <vector>             // Thư viện vector
#include <map>                // Thư viện map
using namespace std;          // Sử dụng không gian tên std

int main() {                  // Hàm main - điểm bắt đầu của chương trình
    vector<int> v;            // Khai báo vector v để lưu các số nguyên nhập vào
    int x;                    // Biến x để lưu giá trị nhập từ bàn phím
    
    while (true) {            // Vòng lặp vô hạn để nhập dữ liệu
        cin >> x;             // Nhập một số nguyên từ bàn phím
        if (x < 0) {          // Nếu số đó âm
            break;            // Thoát khỏi vòng lặp
        }
        v.push_back(x);       // Thêm số đó vào cuối vector v
    }
    
    map<int, vector<int>> m;  // Khai báo map m với key là số nguyên, value là vector chứa các vị trí
    for (int i = 0; i < v.size(); i++) {   // Duyệt qua từng phần tử trong vector
        m[v[i]].push_back(i); // Thêm vị trí i vào vector của phần tử v[i] trong map
    }
    
    // Duyệt qua map từ phần tử đầu tiên đến phần tử cuối cùng
    for (map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << " ";  // In ra key (giá trị phần tử)
        
        // Duyệt qua vector chứa các vị trí xuất hiện
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i] << " ";  // In ra vị trí, cách nhau một khoảng trắng
        }
        
        cout << endl;         // Xuống dòng để in phần tử tiếp theo
    }
    
    return 0;                 // Kết thúc chương trình
}
```

**Các biến thống nhất**:
   - `v`: Vector lưu các số nguyên nhập vào
   - `x`: Biến lưu giá trị nhập từ bàn phím
   - `m`: Map để xử lý dữ liệu (khác nhau về kiểu dữ liệu value)
   - `it`: Iterator để duyệt qua map
