#include "Shape.h"

#include<iostream>

#ifndef __Rect__
#define __Rect__
class Rect: public Shape {
private:
    int x, y, height, width;
public:
    Rect(string svgRect);
    ~Rect();

    bool checkValid(string svgObject);

    int getX();
    int getY();
    int getHeight();
    int getWidth();

    void setProperty(string property) throw(string);
    void setHeight(int height);
    void setWidth(int width);
    void setX(int x);
    void setY(int y);

    virtual void print(ostream& os);
};

#endif // __Rect__