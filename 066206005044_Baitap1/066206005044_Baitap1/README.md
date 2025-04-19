# Tài liệu hướng dẫn dự án 066206005044_Baitap1

## Tổng quan

Đây là bài tập 1 trong môn học lập trình hướng đối tượng, được thực hiện bởi:
- MSSV: 066206005044
- Họ và tên: Hoàng Việt Quang

Dự án này là một chương trình C++ đơn giản được phát triển trên Visual Studio, với mục đích làm quen với C++ và môi trường phát triển Visual Studio.

## Cấu trúc dự án

```
066206005044_Baitap1/
├── main.cpp           # File mã nguồn chính của chương trình
├── data.txt           # File dữ liệu đầu vào
├── 066206005044_Baitap1.vcxproj        # File cấu hình dự án Visual Studio
├── 066206005044_Baitap1.vcxproj.filters # File cấu hình bộ lọc dự án
└── 066206005044_Baitap1.vcxproj.user   # File cấu hình người dùng
```

## Chức năng của chương trình

Chương trình thực hiện các chức năng sau:

1. Hiển thị thông tin sinh viên (MSSV, họ tên)
2. Đọc dữ liệu từ file `data.txt`
3. Đếm tổng số dòng trong file
4. Tìm và đếm các dòng bắt đầu bằng dấu gạch ngang (`-`)
5. Hiển thị kết quả ra màn hình console

## Chi tiết cách hoạt động

### 1. Thiết lập môi trường

```cpp
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <windows.h>
#pragma execution_character_set("utf-8")

int main() {
    SetConsoleOutputCP(65001);
```

- Chương trình bắt đầu bằng việc import các thư viện cần thiết
- Sử dụng `#pragma execution_character_set("utf-8")` để hỗ trợ ký tự UTF-8
- Hàm `SetConsoleOutputCP(65001)` được sử dụng để cấu hình console hiển thị đúng các ký tự Unicode (UTF-8)

### 2. Hiển thị thông tin sinh viên

```cpp
std::cout << "======================================================================" << std::endl;
std::cout << "Bài tập 1. Làm quen với C++ và Visual Studio.Net/Visual Studio Code" << std::endl;
std::cout << "MSSV: 066206005044" << std::endl;
std::cout << "Họ và tên: Hoàng Việt Quang" << std::endl;
std::cout << "======================================================================" << std::endl;
```

- Hiển thị thông tin cơ bản về bài tập và sinh viên

### 3. Đọc file dữ liệu

```cpp
std::ifstream file("data.txt");
if (!file.is_open()) {
    std::cerr << "Không thể mở file hoặc file không tồn tại!" << std::endl;
    return 1;
}
```

- Mở file `data.txt` để đọc dữ liệu
- Kiểm tra xem file có mở thành công hay không, nếu không thì hiển thị thông báo lỗi và kết thúc chương trình

### 4. Xử lý dữ liệu

```cpp
std::string dong;
int tongsodong = 0;
int sodongbatdaubangdaugachngang = 0;
std::string cacdongbatdaubangdaugachngang[100];

while (std::getline(file, dong)) {
    tongsodong++;
    
    if (!dong.empty()) {
        // Xử lý BOM (Byte Order Mark) nếu có
        if (tongsodong == 1 && dong.size() >= 3) {
            if ((unsigned char)dong[0] == 0xEF && 
                (unsigned char)dong[1] == 0xBB && 
                (unsigned char)dong[2] == 0xBF) {
                dong.erase(0, 3);
            }
        }
        
        // Tìm dòng bắt đầu bằng dấu gạch ngang
        size_t vitrikytudautien = dong.find_first_not_of(" \t\r\n");
        if (vitrikytudautien != std::string::npos && dong[vitrikytudautien] == '-') {
            cacdongbatdaubangdaugachngang[sodongbatdaubangdaugachngang] = dong;
            sodongbatdaubangdaugachngang++;
        }
    }
}
```

- Đọc từng dòng trong file và đếm tổng số dòng
- Xử lý BOM (Byte Order Mark) nếu có ở đầu file
- Tìm các dòng bắt đầu bằng dấu gạch ngang (`-`) và lưu vào mảng

### 5. Hiển thị kết quả

```cpp
std::cout << "Có " << tongsodong << " dòng trong file data.txt" << std::endl;
std::cout << "Có " << sodongbatdaubangdaugachngang << " dòng bắt đầu bằng dấu gạch ngang:" << std::endl;
for (int i = 0; i < sodongbatdaubangdaugachngang; i++) {
    std::cout << cacdongbatdaubangdaugachngang[i] << std::endl;
}
if (sodongbatdaubangdaugachngang == 0) {
    std::cout << "Không có dòng nào bắt đầu bằng dấu gạch ngang" << std::endl;
}
```

- Hiển thị tổng số dòng trong file
- Hiển thị số dòng bắt đầu bằng dấu gạch ngang và nội dung của các dòng đó
- Nếu không có dòng nào bắt đầu bằng dấu gạch ngang, hiển thị thông báo tương ứng

### 6. Kết thúc chương trình

```cpp
file.close();
return 0;
```

- Đóng file sau khi xử lý xong
- Kết thúc chương trình với mã trả về 0 (thành công)

## Cách biên dịch và chạy chương trình

1. Mở dự án trong Visual Studio
2. Nhấn F5 hoặc chọn "Debug > Start Debugging" để biên dịch và chạy chương trình
3. Chương trình sẽ đọc file `data.txt` và hiển thị kết quả trên console

## Lưu ý

- File `data.txt` phải nằm cùng thư mục với file thực thi (hoặc trong thư mục làm việc hiện tại)
- Chương trình có xử lý BOM (Byte Order Mark) nếu file được lưu dưới định dạng UTF-8 with BOM
- Chương trình có thể xử lý tối đa 100 dòng bắt đầu bằng dấu gạch ngang

## Kết luận

Đây là một bài tập đơn giản để làm quen với C++ và Visual Studio, tập trung vào các kỹ năng cơ bản như:
- Đọc và xử lý file
- Xử lý chuỗi
- Sử dụng mảng
- Hiển thị kết quả ra console
- Xử lý ký tự Unicode 