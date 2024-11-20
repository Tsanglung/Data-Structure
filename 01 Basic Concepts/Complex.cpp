#include<iostream>
using namespace std;
//Book p.93 Exercise 4.
//複數，加、減、乘、除
class Complex
{
private:
	double a = 0, bi = 0; double den;
public:
	//(a), create 0 + 0i
	Complex() {}//建構子
	Complex(double a,double bi):a(a),bi(bi) {}	//copy

	//(d), Overload << and >>
	friend istream& operator>>(istream& is, Complex& A);//overloading >>
	friend ostream& operator<<(ostream& os, Complex& A);//overloading <<
	
	Complex operator+(const Complex& s) //(b), add
	{	// overload to add two complex numbers
		Complex Add;
		Add.a = a + s.a;
		Add.bi = bi + s.bi;
		Add.den = 1;
		return Add;
	}

	Complex operator-(const Complex& s) //sub
	{
		Complex Sub;
		Sub.a = a - s.a;
		Sub.bi = bi - s.bi;
		Sub.den = 1;
		return Sub;
	}

	Complex operator*(const Complex& s) //(c), mul
	{	// overload to multiply two complex numbers
		//(a+bi)*(s.a+s.bi)
		Complex Mul;
		Mul.a = a * s.a - bi * s.bi;
		Mul.bi = a * s.bi + s.a * bi;
		Mul.den = 1;
		return Mul;
	}

	Complex operator/(const Complex& s) //div
	{
		//(a+bi)/(s.a+s.bi)
		Complex Div;
		Div.a = a * s.a - bi * (-s.bi);
		Div.bi = a * (-s.bi) + s.a * bi;
		Div.den = s.a * s.a - s.bi * (-s.bi);
		return Div;
	}
};

istream& operator>>(istream& is, Complex& A)
{	// overload to read complex numbers
	is >> A.a >> A.bi;
	return is;
}

ostream& operator<<(ostream& os, Complex& A)
{	// overload to print complex numbers
	if (A.den == 1) 
	{
		if (A.bi < 0) 
			os << A.a << A.bi << 'i' << endl;
		else 
			os << A.a << '+' << A.bi << 'i' << endl; 
	}
	else
	{
		if (A.bi < 0) 
			os << '(' << A.a << A.bi << "i)/" << A.den << endl;
		else
			os << '(' <<  A.a << '+' << A.bi << "i)/" << A.den << endl; 
	}
	return os;
}

int main() 
{
	Complex C1, C2(3,2), C3, C4;
	cin >> C3;//5 3
	cin >> C4;//0 0
	Complex C5 = C1 + C2;//3 2
	cout << C5;
	Complex C6 = C3 - C5;//2 1
	cout << C6;
	Complex C7 = C6 * C5;//4 7
	cout << C7;
	Complex C8 = C7 / C6;
	cout << C8;
}
