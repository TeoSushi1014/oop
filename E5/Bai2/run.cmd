@echo off
chcp 65001 > nul
echo Đang biên dịch...

g++ CEmployee.cpp Employee.cpp SEmployee.cpp SCEmployee.cpp main.cpp -o main.exe

if %errorlevel% neq 0 (
    echo.
    echo Biên dịch thất bại! Kiểm tra lỗi và thử lại.
    echo.
    pause
    exit /b
)

echo.
echo Biên dịch thành công!
echo.
echo Đang chạy chương trình...
echo.

main.exe

pause 