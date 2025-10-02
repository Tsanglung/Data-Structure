#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

class Rectangle{
    friend ostream& operator<< (ostream& os, Rectangle& Rectabgle);
public:
    Rectangle(int, int, int, int);//constructor
    ~Rectangle();//destructor
    int GetHeight();//return height
    int GetWidth();//return width
    bool operator==(const Rectangle& s);//overloading operator == program 2.6
    bool operator<(const Rectangle& s);
private:
    int xLow, yLow, height, width;//data member
};

#include"Rectangle.cpp"
#endif