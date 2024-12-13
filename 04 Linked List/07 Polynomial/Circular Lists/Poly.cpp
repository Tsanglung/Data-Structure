//Polynomial.cpp
#include "Poly.h"
 
Polynomial::Polynomial()    {   poly.head->data = {0, -1};     /* 初始化 polynomial*/}
Polynomial::Polynomial(const Polynomial &p) {   if (&p != NULL)     *this = p;  /*copy 建構子*/}
Polynomial::~Polynomial()   {} //解構子
Polynomial& Polynomial::operator+(const Polynomial& b) const
{   //修改課本p.91 Program 2.8 格式，多項式加法
    Polynomial *newPoly = new Polynomial;//創建 newPoly 物件
    Term item;

    ChainNode<Term> *aPos = poly.head->link, 
                                    *bPos = b.poly.head->link;
    while (aPos != poly.head && bPos != b.poly.head) {
        if (aPos->data.exp == bPos->data.exp) 
        {   //指數相同，係數相加
            float t = aPos->data.coef + bPos->data.coef;
            item = {t, aPos->data.exp};
            if (t) newPoly->poly.InsertBack(item);
            aPos = aPos->link;  bPos = bPos->link;
        }
        else if (aPos->data.exp > bPos->data.exp) 
        {
            item = {aPos->data.coef, aPos->data.exp};
            newPoly->poly.InsertBack(item);
            aPos = aPos->link;
        } 
        else if (aPos->data.exp < bPos->data.exp) 
        {
            item = {bPos->data.coef, bPos->data.exp};
            newPoly->poly.InsertBack(item);
            bPos = bPos->link;
        }
    }
    for (; aPos != poly.head; aPos = aPos->link) 
    {   //add 剩下的 terms 
        item = {aPos->data.coef, aPos->data.exp}; 
        newPoly->poly.InsertBack(item);
    }
    for (; bPos != b.poly.head; bPos = bPos->link) 
    {   //add 剩下的 terms 
        item = {bPos->data.coef, bPos->data.exp};
        newPoly->poly.InsertBack(item);
    }
    return *newPoly;//回傳加法結果
}

Polynomial& Polynomial::operator-(const Polynomial& b) const
{
    Polynomial *newPoly = new Polynomial;
    Term item;

    ChainNode<Term> *aPos = poly.head->link, 
                                    *bPos = b.poly.head->link;
    while (aPos != poly.head && bPos != b.poly.head) {
        if (aPos->data.exp == bPos->data.exp) 
        {    //指數相同，係數相減
            float t = aPos->data.coef - bPos->data.coef;
            item = {t, aPos->data.exp};
            if (t) newPoly->poly.InsertBack(item);
            aPos = aPos->link;  bPos = bPos->link;
        } 
        else if (aPos->data.exp > bPos->data.exp) 
        {
            item = {aPos->data.coef, aPos->data.exp};
            newPoly->poly.InsertBack(item);
            aPos = aPos->link;
        } 
        else if (aPos->data.exp < bPos->data.exp) 
        {
            item = {(-1) * (bPos->data.coef), bPos->data.exp};
            newPoly->poly.InsertBack(item);
            bPos = bPos->link;
        }
    }
    for (; aPos != poly.head; aPos = aPos->link) 
    {
        item = {aPos->data.coef, aPos->data.exp};
        newPoly->poly.InsertBack(item);
    }
    for (; bPos != b.poly.head; bPos = bPos->link) 
    {
        item = {(-1) * (bPos->data.coef), bPos->data.exp}; 
        newPoly->poly.InsertBack(item);
    }
    return *newPoly;
}

Polynomial& Polynomial::operator*(const Polynomial& b) const
{
    Polynomial *newPoly = new Polynomial;//儲存new 多項式的物件 
    ChainNode<Term> *bPos = b.poly.head->link;//取得多項式 b 的head
    
    while (bPos != b.poly.head) 
    {   // 走訪多項式 b 的每個節點
        ChainNode<Term> *currentNode = poly.head->link; // 指向 Polynomial 物件的第一個節點的指標 cur
        Polynomial *temp = new Polynomial;
        for (; currentNode != poly.head; currentNode = currentNode->link)
        {   //從第一個節點開始，直到 cur 指向 Polynomial 物件的head node為止
            //每次迭代後將 cur 指向下一個節點。
            Term item;
            item.coef = currentNode->data.coef * bPos->data.coef; // 係數相乘
            item.exp = currentNode->data.exp +  bPos->data.exp; // 指數相加
            temp->poly.InsertBack(item);
        }
        *newPoly = *newPoly + *temp;
        bPos = bPos->link; // 指向下一個 node
        delete temp;   
    }
    return *newPoly;
}

const Polynomial& Polynomial::operator=(const Polynomial& b)
{
    //將輸入 Polynomial 物件的項目指派給目前的 Polynomial 物件。
    poly = b.poly;  return *this;
}

float Polynomial::Evaluate(float x) const
{
    float ans = 0, power = 0;
    ChainNode<Term> *currentNode = poly.head->link;
    while (currentNode != poly.head) {
        power = 1;
        for (int i = 0; i < currentNode->data.exp; i++) power *= x;
        ans += currentNode->data.coef * power; 
        currentNode = currentNode->link;
    }
    return ans;
}

istream& operator>>(istream& is, Polynomial& a)
{
    int n;  Term item;
    is >> n;
    if (n > 0)
        while (a.poly.head->link != a.poly.head)    a.poly.DeleteFront();
    for (int i = 0; i < n; i++) {
        is >> item.coef >> item.exp;
        a.poly.InsertBack(item);
    }  
    return is;
}

ostream& operator<<(ostream& os, Polynomial& a)
{
    ChainNode<Term> *currrentNode = a.poly.head->link;

    while (currrentNode != a.poly.head) {
        os << ' ' << currrentNode->data.coef;
        if (currrentNode->data.exp > 1) os << "x^" << currrentNode->data.exp;
        else if (currrentNode->data.exp == 1)   os << 'x';
        os << ' ';
        currrentNode = currrentNode->link;
        if (currrentNode != a.poly.head && currrentNode->data.coef > 0) os << '+';
    }
    os << '\n'; return os;
}