//Polynomial.h
#ifndef POLY_H
#define POLY_H

#include <iostream>
using namespace std;

/* 
HomeWork
課本p203 Program 4.23
定義 Polynomial class
*/
class Polynomial; 

#include "ASL.h" //AvailableSpaceList.h

typedef struct term {
    //定義Term的結構
    float coef; //coefficiten
    int exp;    //exponent
} Term; 

istream& operator>>(istream&, Polynomial&); //輸出串流
ostream& operator<<(ostream&, Polynomial&); //輸入串流

class Polynomial {
    public: 
        Polynomial();   //建構子
        /*(a)*/friend istream& operator>>(istream&, Polynomial&);  //input
        /*(b)*/friend ostream& operator<<(ostream&, Polynomial&);//output
        /*(c)*/Polynomial(const Polynomial&);  //copy 建構子
        /*(d)*/const Polynomial& operator=(const Polynomial&); //賦值運算子
        /*(e)*/~Polynomial();  //解構子
        /*(f)*/Polynomial& operator+(const Polynomial&) const; //加
        /*(g)*/Polynomial& operator-(const Polynomial&) const; //減
        /*(h)*/Polynomial& operator*(const Polynomial&) const; //乘
        /*(i)*/float Evaluate(float x) const;  //帶入 x 值，計算poly結果

    private:
        Chain<Term> poly;
};

#include "Poly.cpp"
#endif 