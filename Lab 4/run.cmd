@echo off
chcp 65001 > nul
echo Biên dịch và chạy chương trình...

g++ -c main.cpp
g++ -c Dethi.cpp
g++ -c Bieuthuc.cpp
g++ -c BieuthucCong.cpp
g++ -c BieuthucTru.cpp
g++ -c BieuthucNhan.cpp
g++ -c Fraction.cpp
g++ -c BieuthucPS.cpp
g++ -c BieuthucPT.cpp

g++ -o main.exe main.o Dethi.o Bieuthuc.o BieuthucCong.o BieuthucTru.o BieuthucNhan.o Fraction.o BieuthucPS.o BieuthucPT.o

if %errorlevel% neq 0 (
    echo.
    echo Biên dịch thất bại! Kiểm tra lỗi và thử lại.
    echo.
    pause
    exit /b
)

del *.o

echo.
echo Biên dịch thành công!
echo.
echo Đang chạy chương trình...
echo.

main.exe

pause 