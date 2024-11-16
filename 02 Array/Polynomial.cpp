#include <iostream>
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
public:
    Polynomial(int size = 0) : Size(size) {termArray = new Term[size];}
    ~Polynomial() {delete[] termArray;}
 
    friend istream& operator>>(istream& is, Polynomial& Poly); // overloading >>
    friend ostream& operator<<(ostream& os, const Polynomial& Poly); // overloading <<

    Polynomial Add(const Polynomial& B);//加
    void NewTerm(float, int);

private:
    Term* termArray;
    int Size;
    static int free ;
};

int Polynomial::free = 0;

istream& operator>>(istream& is, Polynomial& Poly) {
    for (int i = 0; i < Poly.Size; i++)
        is >> Poly.termArray[i].coef >> Poly.termArray[i].exp;
    return is;
}

ostream& operator<<(ostream& os, const Polynomial& Poly) {
   os << Poly.termArray[0].coef << "x^" << Poly.termArray[0].exp;
    for (int i = 1; i < Poly.free; i++)
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

void Polynomial::NewTerm(float c, int e) {
    termArray[free].coef = c;
    termArray[free].exp = e;
    free++;
}
//p.91
Polynomial Polynomial::Add(const Polynomial& B) {
    Polynomial C;
    int a = 0, b = 0;
    float c;

    while ((a < Size) && (b < B.Size)) {//比較指數，進行係數處理
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

    for (; a < Size; a++)
        C.NewTerm(termArray[a].coef, termArray[a].exp);
    for (; b < B.Size; b++)
        C.NewTerm(B.termArray[b].coef, B.termArray[b].exp);

    return C;
}

int main() {
    Polynomial aPoly(2);
    Polynomial bPoly(4);
    cout << "Input Poly1 : " << endl;
    cin >> aPoly;
    cout << "Input Poly2 : " << endl;
    cin >> bPoly;
    Polynomial cPoly = aPoly.Add(bPoly);
    cout << "Sum of Polynomials:" << endl;
    cout<<cPoly<<endl;

    return 0;
}