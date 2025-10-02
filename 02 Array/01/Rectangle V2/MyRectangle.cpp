#include<iostream>
#include"MyRectangle.h"
using namespace std;

MyRectangle::MyRectangle(int x = 0, int y = 0, int h = 0, int w = 0, const string& c = "")
{
    xLow = x;yLow = y;
    height = h;width = w;
    color = c;
}
MyRectangle::~MyRectangle(){}

string MyRectangle::GetColor(){return color;}
int MyRectangle::GetArea(){return GetHeight() * GetWidth();}
int MyRectangle::GetPerimeter(){return (GetHeight() + GetWidth()) * 2;}

istream& operator>>(istream& is, MyRectangle& MyR)
{
    int xLow, yLow, height, width;
    string color;
    cout << "Input xLow, yLow, height, width, color : ";
    is >> xLow >> yLow >> height >> width >> color;
    MyR = MyRectangle(xLow, yLow, height, width, color);
    return is;
}
ostream& operator<<(ostream& os, MyRectangle& MyR)
{
     os << "MyRectangle(" << MyR.GetHeight() << ", " << MyR.GetWidth() << ", Color: " << MyR.GetColor() << ")";
    return os;
}
