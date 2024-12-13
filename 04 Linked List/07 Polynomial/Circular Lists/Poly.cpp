//Polynomial.cpp
#include "Poly.h"
 
Polynomial::Polynomial()    {   poly.head->data = {0, -1};     /* ��l�� polynomial*/}
Polynomial::Polynomial(const Polynomial &p) {   if (&p != NULL)     *this = p;  /*copy �غc�l*/}
Polynomial::~Polynomial()   {} //�Ѻc�l
Polynomial& Polynomial::operator+(const Polynomial& b) const
{   //�ק�ҥ�p.91 Program 2.8 �榡�A�h�����[�k
    Polynomial *newPoly = new Polynomial;//�Ы� newPoly ����
    Term item;

    ChainNode<Term> *aPos = poly.head->link, 
                                    *bPos = b.poly.head->link;
    while (aPos != poly.head && bPos != b.poly.head) {
        if (aPos->data.exp == bPos->data.exp) 
        {   //���ƬۦP�A�Y�Ƭۥ[
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
    {   //add �ѤU�� terms 
        item = {aPos->data.coef, aPos->data.exp}; 
        newPoly->poly.InsertBack(item);
    }
    for (; bPos != b.poly.head; bPos = bPos->link) 
    {   //add �ѤU�� terms 
        item = {bPos->data.coef, bPos->data.exp};
        newPoly->poly.InsertBack(item);
    }
    return *newPoly;//�^�ǥ[�k���G
}

Polynomial& Polynomial::operator-(const Polynomial& b) const
{
    Polynomial *newPoly = new Polynomial;
    Term item;

    ChainNode<Term> *aPos = poly.head->link, 
                                    *bPos = b.poly.head->link;
    while (aPos != poly.head && bPos != b.poly.head) {
        if (aPos->data.exp == bPos->data.exp) 
        {    //���ƬۦP�A�Y�Ƭ۴�
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
    Polynomial *newPoly = new Polynomial;//�x�snew �h���������� 
    ChainNode<Term> *bPos = b.poly.head->link;//���o�h���� b ��head
    
    while (bPos != b.poly.head) 
    {   // ���X�h���� b ���C�Ӹ`�I
        ChainNode<Term> *currentNode = poly.head->link; // ���V Polynomial ���󪺲Ĥ@�Ӹ`�I������ cur
        Polynomial *temp = new Polynomial;
        for (; currentNode != poly.head; currentNode = currentNode->link)
        {   //�q�Ĥ@�Ӹ`�I�}�l�A���� cur ���V Polynomial ����head node����
            //�C�����N��N cur ���V�U�@�Ӹ`�I�C
            Term item;
            item.coef = currentNode->data.coef * bPos->data.coef; // �Y�Ƭۭ�
            item.exp = currentNode->data.exp +  bPos->data.exp; // ���Ƭۥ[
            temp->poly.InsertBack(item);
        }
        *newPoly = *newPoly + *temp;
        bPos = bPos->link; // ���V�U�@�� node
        delete temp;   
    }
    return *newPoly;
}

const Polynomial& Polynomial::operator=(const Polynomial& b)
{
    //�N��J Polynomial ���󪺶��ث������ثe�� Polynomial ����C
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