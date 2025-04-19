#include "Rectangle.h"

CRectangle::CRectangle() {
    width = 0;
    height = 0;
}

void CRectangle::setWidth(int w) {
    width = w;
}

void CRectangle::setHeight(int h) {
    height = h;
}

int CRectangle::getWidth() {
    return width;
}

int CRectangle::getHeight() {
    return height;
}

int CRectangle::area() {
    return width * height;
}