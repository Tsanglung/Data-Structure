#ifndef CPPARRAY_H
#define CPPARRAY_H

#include<iostream>
using namespace std;

class CppArray{
    friend istream& operator>>(istream& is,CppArray& CA);
    friend ostream& operator<<(ostream& os, const CppArray& CA);
public:
    CppArray(int size, float initvalue);
    CppArray(const CppArray& cp2);
    ~CppArray();
    CppArray& operator= (const CppArray& cp2);
    float& operator[](int i);
    int GetSize();
private:
    int size;
    float *data;
};

#include"CppArray.cpp"
#endif