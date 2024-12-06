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

class Polynomial {//多項式運算
    friend istream& operator>>(istream&, Polynomial&); // overloading >>
    friend ostream& operator<<(ostream&, const Polynomial&); // overloading <<
public:
    Polynomial();
    Polynomial(int s, int f);
    ~Polynomial();

    Polynomial Add(const Polynomial& B);//加
    void NewTerm(float, int);

private:
    static Term* termArray;
    static int capacity;
    static int free ;//location of next free loaction in termArray
    int start, finish;
};

#include"Polynomial.cpp"
#endif