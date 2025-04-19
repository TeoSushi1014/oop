# Ứng Dụng Thi Trắc Nghiệm

Ứng dụng thi trắc nghiệm đơn giản cho phép người dùng tạo đề thi, làm bài thi và quản lý các file đề thi.

## Thông tin

- **MSSV**: 066206005044
- **Họ và tên**: Hoàng Việt Quang
- **Bài tập**: Bài tập 2 - Xây dựng ứng dụng thi trắc nghiệm

## Tính năng

Ứng dụng có các tính năng chính sau:

1. **Tạo đề thi trắc nghiệm mới**
   - Tạo file đề thi mới với định dạng .TTN
   - Nhập các câu hỏi trắc nghiệm với 2 lựa chọn (A và B)
   - Tự động kiểm tra và loại bỏ các câu hỏi trùng lặp

2. **Làm bài thi**
   - Mở file đề thi có sẵn
   - Trả lời các câu hỏi trắc nghiệm
   - Hiển thị kết quả và điểm số sau khi hoàn thành bài thi

3. **Xử lý file (xóa khoảng trắng thừa)**
   - Làm sạch file đề thi bằng cách xóa các khoảng trắng thừa
   - Chuẩn hóa định dạng file

4. **Xem mã nguồn trên GitHub**
   - Truy cập mã nguồn của ứng dụng trên GitHub

## Hướng dẫn sử dụng

### 1. Tạo đề thi trắc nghiệm mới

1. Chọn tùy chọn 1 từ menu chính
2. Nhập tên file để lưu đề thi (không cần nhập phần mở rộng .TTN)
3. Nhập số lượng câu hỏi bạn muốn tạo
4. Với mỗi câu hỏi:
   - Nhập nội dung câu hỏi
   - Nhập đáp án A
   - Nhập đáp án B
   - Nhập đáp án đúng (A hoặc B)
5. Hệ thống sẽ tự động kiểm tra và loại bỏ các câu hỏi trùng lặp
6. Đề thi sẽ được lưu vào file với định dạng .TTN

### 2. Làm bài thi

1. Chọn tùy chọn 2 từ menu chính
2. Nhập tên file đề thi (không cần nhập phần mở rộng .TTN)
3. Hệ thống sẽ hiển thị từng câu hỏi và các lựa chọn
4. Nhập câu trả lời của bạn (A hoặc B) cho mỗi câu hỏi
5. Sau khi hoàn thành, hệ thống sẽ hiển thị điểm số của bạn

### 3. Xử lý file (xóa khoảng trắng thừa)

1. Chọn tùy chọn 3 từ menu chính
2. Nhập tên file cần xử lý (không cần nhập phần mở rộng .TTN)
3. Hệ thống sẽ xóa các khoảng trắng thừa trong file và chuẩn hóa định dạng

### 4. Xem mã nguồn trên GitHub

1. Chọn tùy chọn 4 từ menu chính
2. Trình duyệt web sẽ mở trang GitHub chứa mã nguồn của ứng dụng

### 0. Thoát chương trình

- Chọn tùy chọn 0 để thoát khỏi ứng dụng

## Định dạng file .TTN

File đề thi (.TTN) có cấu trúc như sau:
- Mỗi câu hỏi gồm 4 dòng:
  - Dòng 1: Nội dung câu hỏi
  - Dòng 2: Đáp án A
  - Dòng 3: Đáp án B
  - Dòng 4: Đáp án đúng (A hoặc B)

## Yêu cầu hệ thống

- Hệ điều hành Windows
- Hỗ trợ Unicode và UTF-8

## Lưu ý

- Ứng dụng hỗ trợ tiếng Việt có dấu
- Các file đề thi được lưu ở định dạng UTF-8 với BOM
- Đảm bảo không đóng ứng dụng đột ngột khi đang tạo hoặc làm bài thi 