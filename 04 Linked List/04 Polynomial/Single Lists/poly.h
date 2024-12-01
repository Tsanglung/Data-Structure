#ifndef POLY_H
#define POLY_H

#include <iostream>
using namespace std;

class Polynomial;

#include "chain.h"

struct Term {
    int coef;
    int exp;
    Term Set(int c, int e) { coef = c; exp = e; return *this;}
};

istream& operator>>(istream&, Polynomial&); //輸入串流
ostream& operator<<(ostream&, const Polynomial&); //輸出串流
 
class Polynomial {
private:
    Chain<Term> poly;
public:
    Polynomial();
    Polynomial(const Polynomial&); //拷貝建構子
    ~Polynomial(); //解構子
    const Polynomial& operator=(const Polynomial&); //賦值運算子
    Polynomial operator+(const Polynomial&) const; //加法運算子
    friend istream& operator>>(istream&, Polynomial&); //輸入
    friend ostream& operator<<(ostream&, const Polynomial&); //輸出
};

#include "poly.cpp"
#endif // POLY_H
