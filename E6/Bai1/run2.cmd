@echo off
chcp 65001 > nul

g++ Bai2.cpp -o Bai2.exe
if %errorlevel% neq 0 (
    echo Biên dịch thất bại!
    pause
)
Bai2.exe
exit
