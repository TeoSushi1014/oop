# Lab 3.d - Cài đặt thêm các toán tử so sánh
```cpp
/*
Cài đặt các toán tử hai toán hạng ==, !=, <, >/
Thử nghiệm với hàm main sau:
*/

int main()
{
    int test_op;
    cin >> test_op;
    switch (test_op) {
    case 1:
        cout << (Fraction(1, 2) == Fraction(1, 3)) << endl;
        cout << (Fraction(1, 2) == Fraction(2, 4)) << endl;
        break;
    case 2:
        cout << (Fraction(1, 2) != Fraction(1, 3)) << endl;
        cout << (Fraction(1, 2) != Fraction(2, 4)) << endl;
        break;
    case 3:
        cout << (Fraction(1, 2) > Fraction(1, 3)) << endl;
        cout << (Fraction(1, 2) > Fraction(2, 4)) << endl;
        break;
    case 4:
        cout << (Fraction(1, 2) < Fraction(1, 3)) << endl;
        cout << (Fraction(1, 2) < Fraction(2, 4)) << endl;
        break;
    }
    return 0;
}
```