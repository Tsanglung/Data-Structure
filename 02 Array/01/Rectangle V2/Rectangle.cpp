#include<iostream>
#include"Rectangle.h"
using namespace std;

Rectangle::Rectangle(int x = 0, int y = 0, int h = 0, int w = 0): xLow(x), yLow(y), height(h), width(w) {}
Rectangle::~Rectangle(){}

int Rectangle::GetHeight() {return height;}
int Rectangle::GetWidth(){return width;}

bool Rectangle::operator==(const Rectangle& s)//overloading operator == program 2.6
{	// 比較兩物件是否相等
	if (this == &s) return true;
	else if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width))	return true;
	return false;
}

bool Rectangle::operator<(const Rectangle& s)
{	//exercise 1.
	return (height * width) < (s.height * s.width);
}

ostream& operator<<(ostream& os, Rectangle& Rectangle)//overloading operator <<
{	//program 2.7
	os << "Position(x , y) : (" << Rectangle.xLow << " , " << Rectangle.yLow << ") " << endl;
	os << "Height : " << Rectangle.height << endl;
	os << "Width : " << Rectangle.width << endl;
	return os;
}