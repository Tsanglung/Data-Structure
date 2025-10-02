#ifndef COMPLEX_H
#define COMPLEX_H
//Book p.93 Exercise 4.
//複數，加、減、乘、除
#include<iostream>
using namespace std;

class Complex{
    //(d), Overload << and >>
	friend istream& operator>>(istream& is, Complex& A);//overloading >>
	friend ostream& operator<<(ostream& os, Complex& A);//overloading <<
public:
	//(a), create 0 + 0i
	Complex();//建構子
	Complex(double a,double bi);	//copy
    ~Complex();
    Complex operator+(const Complex& s);//add
    Complex operator-(const Complex& s);//sub
    Complex operator*(const Complex& s);//mul
    Complex operator/(const Complex& s);//div
private:
	double a = 0, bi = 0; double den;
};

#include"Complex.cpp"
#endif