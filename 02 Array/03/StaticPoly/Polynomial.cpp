#include"Polynomial.h"

int Polynomial::capacity = 100;
Term* Polynomial::termArray = new Term[100];
int Polynomial::free = 0;

Polynomial::Polynomial(){}
Polynomial::Polynomial(int s,int f) : start(s), finish(f){}
Polynomial::~Polynomial(){}

void Polynomial::NewTerm(float c, int e) {
    if(free == capacity)
    {
        capacity *= 2;
        Term *temp = new Term[capacity];
        copy(termArray, termArray + free, temp);
        delete [] termArray;
        termArray = temp;
    }
    termArray[free].coef = c;
    termArray[free++].exp = e;
}

Polynomial Polynomial::Add(const Polynomial& B) {//p.91
    Polynomial C;
    int a = start, b = B.start; C.start = free;
    float c;

    while ((a <= finish) && (b <= B.finish)) {//比較指數，進行係數處理
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

    for (; a <= finish; a++)
        C.NewTerm(termArray[a].coef, termArray[a].exp);
    for (; b <= B.finish; b++)
        C.NewTerm(B.termArray[b].coef, B.termArray[b].exp);

    C.finish = free - 1;
    return C;
}

istream& operator>>(istream& is, Polynomial& Poly) {
    for (Poly.free = Poly.start; Poly.free <= Poly.finish; Poly.free++)
        is >> Poly.termArray[Poly.free].coef >> Poly.termArray[Poly.free].exp;
    return is;
}

ostream& operator<<(ostream& os, const Polynomial& Poly) {
    int i = Poly.start;
    i++;
    os << Poly.termArray[Poly.start].coef << "x^" << Poly.termArray[Poly.start].exp;
    for (; i < Poly.free; i++)
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