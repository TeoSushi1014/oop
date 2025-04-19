@echo off
chcp 65001 > nul
g++ -o main main.cpp -std=c++11 -Wall -fexec-charset=UTF-8 -finput-charset=UTF-8

if %errorlevel% neq 0 (
    echo Lỗi rồi bạn ơi! Không thể biên dịch main.cpp
    echo Vui lòng kiểm tra lại mã nguồn hoặc cài đặt g++
    pause
    exit /b 1
)

echo Biên dịch thành công!
echo ======================================

main.exe

echo ======================================