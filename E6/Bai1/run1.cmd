@echo off
chcp 65001 > nul

g++ Bai1.cpp -o Bai1.exe
if %errorlevel% neq 0 (
    echo Biên dịch thất bại!
    pause
)
Bai1.exe
exit
