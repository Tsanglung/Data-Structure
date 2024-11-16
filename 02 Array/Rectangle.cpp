#include <iostream>
using namespace std;
//Book p.75~77 Program 2.1、2.2、2.3
class Rectangle
{	//矩形
	friend ostream& operator<< (ostream& os, Rectangle& Rectabgle);
private:
	int x, y, h, w;

public:
	Rectangle(int x = 0, int y = 0, int height = 0, int width = 0) : x(x), y(y), h(height), w(width) { }//建構子 program 2.4 -> 2.5
	~Rectangle() {}	//解構子
	int GetH() { return h; };//高
	int GetW() { return w; };//寬
	bool operator==(const Rectangle& s)//overloading operator == program 2.6
	{	// 比較兩物件是否相等
		if (this == &s) return true;
		else if ((x == s.x) && (y == s.y) && (h == s.h) && (w == s.w))	return true;
		return false;
	}
};

ostream& operator<<(ostream& os, Rectangle& Rectabgle)//overloading operator <<
{	//program 2.7
	os << "Position(x , y) : (" << Rectabgle.x << " , " << Rectabgle.y << ") " << endl;
	os << "Height : " << Rectabgle.h << endl;
	os << "Width : " << Rectabgle.w << endl;
	return os;
}

int main()
{
	Rectangle r(1, 1, 3, 4);
	Rectangle s(2, 4, 6, 8);
	Rectangle* t = &s; //取 s 址賦值給 t，通過 t 訪問或更改 s 物件的成員

	if (r.GetH() * r.GetW() > t->GetH() * t->GetW())
		cout << r;
	else cout << s;
}
