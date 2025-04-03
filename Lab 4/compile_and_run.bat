@echo off
chcp 65001 > nul
echo Đang biên dịch chương trình...

:: Dừng chương trình nếu đang chạy
taskkill /f /im main.exe >nul 2>&1

:: Thử xóa file cũ
del /f main.exe >nul 2>&1

:: Biên dịch với tên mới
g++ -o main.exe main.cpp Bieuthuc.cpp

if %ERRORLEVEL% neq 0 (
    echo Biên dịch thất bại!
    pause
    exit /b 1
)

echo Biên dịch thành công! Đang chạy chương trình...
cls
main.exe
pause 