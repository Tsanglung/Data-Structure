#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<iostream>
using namespace std;

//Book p.90~92
class Polynomial; // forward declaration

class Term {
    friend class Polynomial;
public:
    float coef; // coefficient
    int exp; // exponent
};

class Polynomial {//�h�����B��
    friend istream& operator>>(istream&, Polynomial&); // overloading >>
    friend ostream& operator<<(ostream&, const Polynomial&); // overloading <<
public:
    Polynomial(int size);
    ~Polynomial();

    Polynomial Add(const Polynomial& B);//�[
    void NewTerm(float, int);

private:
    Term* termArray;
    int capacity;
    int terms ;
};

#include"Polynomial.cpp"
#endif