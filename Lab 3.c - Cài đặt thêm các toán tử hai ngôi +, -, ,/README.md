# Lab 3.c - Cài đặt thêm các toán tử hai ngôi +, -, , 
 ```cpp
 /*
Cài đặt các toán tử hai toán hạng +, -, *, /
Thử nghiệm với hàm main sau:
*/
int main()
{
    char test_op = '+';
    cin >> test_op;
    Fraction f1(1,2), f2(2,3), f3(-1,1);
    switch (test_op) {
    case '+':
        cout << f1 << " + " << f2 << "=" << f1 + f2 << endl;
        cout << f1 << " + " << f3 << "=" << f1 + f3 << endl;
        break;
    case '-':
        cout << f1 << " - " << f2 << "=" << f1 - f2 << endl;
        cout << f1 << " - " << f3 << "=" << f1 - f3 << endl;
        break;
    case '*':
        cout << f1 << " * " << f2 << "=" << f1 * f2 << endl;
        cout << f1 << " * " << f3 << "=" << f1 * f3 << endl;
        break;
    case '/':
        cout << f1 << " / " << f2 << "=" << f1 / f2 << endl;
        cout << f1 << " / " << f3 << "=" << f1 / f3 << endl;
        break;
    }
    return 0;
}
```