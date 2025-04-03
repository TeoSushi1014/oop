# Đề Bài: Ứng Dụng Thi Trắc Nghiệm

## Mô Tả
Đề thi trắc nghiệm bao gồm nhiều câu hỏi trắc nghiệm; mỗi câu hỏi trắc nghiệm bao gồm các thành phần:
- Nội dung câu hỏi
- Nội dung đáp án A
- Nội dung đáp án B
- Đáp án đúng

## Chức Năng Ứng Dụng
- Tạo đề thi trắc nghiệm gồm nhiều câu, nhập từ bàn phím và lưu vào file (*.TTN)
- Đọc nội dung file *.TTN để cho thi
- Đọc một file TTN và xóa khoảng trống thừa ở các câu hỏi và trả lời, lưu đè lên file cũ

## Yêu Cầu
1. Tạo lớp `CauhoiTN` với các thuộc tính như yêu cầu, các phương thức bao gồm:
   - `nhap()`: nhập liệu từ bàn phím
   - `docfile(ifstream& f)`: đọc dữ liệu một câu hỏi từ file stream f
   - `ghifile(ofstream& f)`: ghi nội dung câu hỏi vào file stream f
   - `kiemtra()`: hiện câu hỏi, và cho người dùng nhập câu trả lời, kiểm tra câu trả lời có đúng đáp án không
   - `xuat()`: xuất câu hỏi ra màn hình (bao gồm đáp án đúng)

2. Xây dựng thực đơn (Menu) để người dùng có thể lựa chọn chức năng (bao gồm chức năng thoát chương trình)

3. Viết hàm `bool giongnhau(CauhoiTN cau1, CauhoiTN cau2)` với lớp `CauHoiTN` để kiểm tra hai câu hỏi có trùng nhau hay không (dùng từ khoá friend)