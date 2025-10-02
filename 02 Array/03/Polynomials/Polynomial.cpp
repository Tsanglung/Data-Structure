#include"Polynomial.h"

Polynomial::Polynomial(int size = 10) : capacity(size) ,terms(0){termArray = new Term[size];}
Polynomial::~Polynomial() {delete[] termArray;}

void Polynomial::NewTerm(float c, int e) {
    if(terms == capacity)
    {
        capacity *= 2;
        Term *temp = new Term[capacity];
        copy(termArray, termArray + terms, temp);
        delete [] termArray;
        termArray = temp;
    }
    termArray[terms].coef = c;
    termArray[terms++].exp = e;
}

Polynomial Polynomial::Add(const Polynomial& B) {//p.91
    Polynomial C;
    int a = 0, b = 0;
    float c;

    while ((a < capacity) && (b < B.capacity)) {//比較指數，進行係數處理
        if (termArray[a].exp == B.termArray[b].exp) {
            c = termArray[a].coef + B.termArray[b].coef;
            if (c) C.NewTerm(c, termArray[a].exp);
            a++; b++;
        } else if (termArray[a].exp < B.termArray[b].exp) {
            C.NewTerm(B.termArray[b].coef, B.termArray[b].exp);
            b++;
        } else {
            C.NewTerm(termArray[a].coef, termArray[a].exp);
            a++;
        }
    }

    for (; a < capacity; a++)
        C.NewTerm(termArray[a].coef, termArray[a].exp);
    for (; b < B.capacity; b++)
        C.NewTerm(B.termArray[b].coef, B.termArray[b].exp);

    return C;
}

istream& operator>>(istream& is, Polynomial& Poly) {
    for (int i = 0; i < Poly.capacity; i++)
        is >> Poly.termArray[i].coef >> Poly.termArray[i].exp;
    return is;
}

ostream& operator<<(ostream& os, const Polynomial& Poly) {
   os << Poly.termArray[0].coef << "x^" << Poly.termArray[0].exp;
    for (int i = 1; i < Poly.terms; i++)
    {
         if(Poly.termArray[i].exp > 0){
            if(Poly.termArray[i].coef  > 0)
               os << "+" << Poly.termArray[i].coef << "x^" << Poly.termArray[i].exp;
            else 
               os << Poly.termArray[i].coef << "x^" << Poly.termArray[i].exp;
         }
         else {
            if(Poly.termArray[i].coef  > 0)
               os << "+" << Poly.termArray[i].coef ;
            else 
               os << Poly.termArray[i].coef ;
         }
    }
    return os;
}