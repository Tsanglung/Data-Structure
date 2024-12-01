#include "poly.h"

Polynomial::Polynomial() {}
Polynomial::Polynomial(const Polynomial &p) {*this = p; /* 使用賦值運算子進行copy*/}
Polynomial::~Polynomial() {}
const Polynomial& Polynomial::operator=(const Polynomial& p) {if (this != &p) poly = p.poly; /*使用 Chain 類別的賦值運算子*/return *this;}

Polynomial Polynomial::operator+(const Polynomial& b) const 
{
    Term temp;
    ChainIterator<Term> ai = poly.begin(), bi = b.poly.begin();
    Polynomial c;
    while (ai != poly.end() && bi != b.poly.end()) 
    {
        if (ai->exp == bi->exp) 
        { 
            int sum = ai->coef + bi->coef;
            if (sum) c.poly.InsertBack(temp.Set(sum, ai->exp));
            ++ai; ++bi;
        } 
        else if (ai->exp < bi->exp) 
        {
            c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
            ++bi;
        } 
        else 
        {
            c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
            ++ai;
        }
    }

    while (ai != poly.end()) 
    {
        c.poly.InsertBack(temp.Set(ai->coef, ai->exp));
        ++ai;
    }
    while (bi != b.poly.end()) 
    {
        c.poly.InsertBack(temp.Set(bi->coef, bi->exp));
        ++bi;
    }

    return c;
}

istream& operator>>(istream& is, Polynomial& a) 
{
    int n;
    Term item;
    is >> n;
    for (int i = 0; i < n; i++) 
    {
        is >> item.coef >> item.exp;
        a.poly.InsertBack(item);
    }
    return is;
}

ostream& operator<<(ostream& os, const Polynomial& a) 
{
    ChainIterator<Term> currentNode = a.poly.begin();

    while (currentNode != a.poly.end()) 
    {
        os << currentNode->coef;
        if (currentNode->exp > 1) os << "x^" << currentNode->exp;
        else if (currentNode->exp == 1) os << "x";
        currentNode ++;
        if (currentNode != nullptr && currentNode->coef > 0) os << " + ";
    }
    os << '\n';
    return os;
}
