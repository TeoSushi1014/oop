#ifndef RECTANGLE_H
#define RECTANGLE_H

class CRectangle {
private:
    int width;
    int height;
public:
    CRectangle();
    void setWidth(int w);
    void setHeight(int h);
    int getWidth();
    int getHeight();
    int area();
};

#endif