@echo off
echo Dang bien dich chuong trinh...

g++ -o program.exe main.cpp Bieuthuc.cpp BieuthucPS.cpp BieuthucPT.cpp BieuthucCong.cpp BieuthucTru.cpp BieuthucNhan.cpp Fraction.cpp Dethi.cpp

if %errorlevel% neq 0 (
    echo Loi bien dich! Vui long kiem tra lai code.
    pause
    exit /b %errorlevel%
)

echo Bien dich thanh cong!
echo.
echo Dang chay chuong trinh...
echo.

program.exe

pause 