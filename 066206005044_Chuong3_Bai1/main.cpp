#include <iostream>
#include "Rectangle.h"
#include <cstdio>
#include <windows.h>
using namespace std;
int main() {
    SetConsoleOutputCP(65001);
    cout << "=========================================================" << endl;
    cout << "MSSV: 066206005044" << endl;
    cout << "Họ và tên: Hoàng Việt Quang" << endl;
    cout << "Source code: https://github.com/TeoSushi1014/oop/tree/main/066206005044_Chuong3_Bai1" << endl;
    cout << "=========================================================" << endl;
    cout << endl;
    CRectangle rect1, *rect2;
    //rect1.height = 2;
    rect1.setHeight(3);
    rect1.setWidth(4);
    cout << "Height1: " << rect1.getHeight() << endl;
    cout << "Width1: " << rect1.getWidth() << endl;
    cout << "S1: " << rect1.area() << endl;
    cout << endl;

    rect2 = new CRectangle();
    rect2->setHeight(5);
    rect2->setWidth(4);
    cout << "Height2: " << rect2->getHeight() << endl;
    cout << "Width2: " << rect2->getWidth() << endl;
    cout << "S2: " << rect2->area() << endl;
    cout << endl;
    cout << "Nhấn phím Enter để tắt chương trình...";
    cin.get();
    return 0;
}