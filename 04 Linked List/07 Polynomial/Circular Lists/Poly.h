//Polynomial.h
#ifndef POLY_H
#define POLY_H

#include <iostream>
using namespace std;

/* 
HomeWork
�ҥ�p203 Program 4.23
�w�q Polynomial class
*/
class Polynomial; 

#include "ASL.h" //AvailableSpaceList.h

typedef struct term {
    //�w�qTerm�����c
    float coef; //coefficiten
    int exp;    //exponent
} Term; 

istream& operator>>(istream&, Polynomial&); //��X��y
ostream& operator<<(ostream&, Polynomial&); //��J��y

class Polynomial {
    public: 
        Polynomial();   //�غc�l
        /*(a)*/friend istream& operator>>(istream&, Polynomial&);  //input
        /*(b)*/friend ostream& operator<<(ostream&, Polynomial&);//output
        /*(c)*/Polynomial(const Polynomial&);  //copy �غc�l
        /*(d)*/const Polynomial& operator=(const Polynomial&); //��ȹB��l
        /*(e)*/~Polynomial();  //�Ѻc�l
        /*(f)*/Polynomial& operator+(const Polynomial&) const; //�[
        /*(g)*/Polynomial& operator-(const Polynomial&) const; //��
        /*(h)*/Polynomial& operator*(const Polynomial&) const; //��
        /*(i)*/float Evaluate(float x) const;  //�a�J x �ȡA�p��poly���G

    private:
        Chain<Term> poly;
};

#include "Poly.cpp"
#endif 