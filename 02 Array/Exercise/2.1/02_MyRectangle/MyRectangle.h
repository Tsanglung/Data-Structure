#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include<iostream>
#include<string>
#include"Rectangle.h"
using namespace std;

class MyRectangle : public Rectangle{
    friend ostream& operator<<(ostream&, MyRectangle& ); // ������X�B��l
    friend istream& operator>>(istream&, MyRectangle& ); // ������J�B��l
public:
    MyRectangle(int , int , int , int , const string& ); // �غc���
    ~MyRectangle(); // �Ѻc���

    // �������
    string GetColor();            // ����C��
    int GetArea();                // �p�⭱�n
    int GetPerimeter();           // �p��P��

private:
    string color; // �C�⦨���ܼ�
};

#include"MyRectangle.cpp"
#endif