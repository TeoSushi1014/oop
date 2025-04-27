#include <iostream>
using namespace std;

template <typename T>
void hoanvi(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 2, b = 6;
    float c = 22.7, d = 10.14;
    char e = 'T', f = 'S';
    
    cout << "Truoc khi hoan vi:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "c = " << c << ", d = " << d << endl;
    cout << "e = " << e << ", f = " << f << endl;
    
    hoanvi(a, b);
    hoanvi(c, d);
    hoanvi(e, f);
    
    cout << "\nSau khi hoan vi:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    cout << "c = " << c << ", d = " << d << endl;
    cout << "e = " << e << ", f = " << f << endl;
    
    return 0;
} 