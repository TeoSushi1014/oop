#include <iostream>
#include "Rectangle.h"
using namespace std;
int main() {
	CRectangle rect1, * rect2;
	//rect1.height=2;
	rect1.setHeight(3);
	rect1.setWidth(4);
	cout << "Height1: " << rect1.getHeight() << endl;
	cout << "Width1: " << rect1.getWidth() << endl;
	cout << "S1: " << rect1.area() << endl;
	cout << endl;

	rect2 = new CRectangle;
	rect2->setHeight(5);
	rect2->setWidth(4);
	cout << "Height2: " << rect2->getHeight() << endl;
	cout << "Width2: " << rect2->getWidth() << endl;
	cout << "S2: " << rect2->area() << endl;
	return 0;
}