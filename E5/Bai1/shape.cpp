#include<iostream>
using namespace std;

class Shape{
protected:
    int width, height;
public:
    Shape(int a = 0, int b = 0){
        width = a;
        height = b;
    }
    
    virtual int area(){
        cout << "Parent class area :" << endl;
        return 0;
    }
};

class Rectangle: public Shape{
public:
    Rectangle(int a = 0, int b = 0): Shape(a, b){}
    
    int area(){
        cout << "Rectangle class area :" << endl;
        return (width * height);
    }
};

class Triangle: public Shape{
public:
    Triangle(int a = 0, int b = 0): Shape(a, b){}
    
    int area(){
        cout << "Triangle class area :" << endl;
        return (width * height / 2);
    }
};

int main(){
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);
    
    // store the address of Rectangle
    shape = &rec;
    // call rectangle area.
    cout << shape->area() << endl;
    
    // store the address of Triangle
    shape = &tri;
    // call triangle area.
    cout << shape->area() << endl;
    
    return 0;
}

// // Giải thích
// Nhờ tính đa hình với phương thức ảo area(), khi gọi shape->area() sẽ tự động sử dụng phương thức của lớp con. Diện tích hình chữ nhật: 10×7=70, diện tích hình tam giác: 10×5÷2=25.