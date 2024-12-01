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

istream& operator>>(istream&, Polynomial&); //��J��y
ostream& operator<<(ostream&, const Polynomial&); //��X��y
 
class Polynomial {
private:
    Chain<Term> poly;
public:
    Polynomial();
    Polynomial(const Polynomial&); //�����غc�l
    ~Polynomial(); //�Ѻc�l
    const Polynomial& operator=(const Polynomial&); //��ȹB��l
    Polynomial operator+(const Polynomial&) const; //�[�k�B��l
    friend istream& operator>>(istream&, Polynomial&); //��J
    friend ostream& operator<<(ostream&, const Polynomial&); //��X
};

#include "poly.cpp"
#endif // POLY_H
