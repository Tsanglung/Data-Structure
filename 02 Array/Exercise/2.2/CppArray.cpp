#include"CppArray.h"
#include<iostream>
using namespace std;

CppArray::CppArray(int size, float init):size(size)
{
    if(size <= 0) throw "size should > 0";
    data = new float[size];
    for(int i = 0;i < size; i++)
        data[i] = init;
}

CppArray::CppArray(const CppArray& cp2) : size(cp2.size)
{   //copy constructor
    data = new float[size];
    for (int i = 0; i < size; ++i)
        data[i] = cp2.data[i];
}

CppArray::~CppArray() {delete[] data;}

CppArray& CppArray::operator=(const CppArray& cp2) 
{   // cp1 = cp2
    if (this != &cp2) 
    {
        delete[] data;
        size = cp2.size;
        data = new float[size];
        for (int i = 0; i < size; ++i) 
            data[i] = cp2.data[i];
    }
    return *this;
}

float& CppArray::operator[](int i) 
{   //range-checking
    if (i < 0 || i >= size) throw "Index out of range.";
    return data[i];
}

int CppArray::GetSize(){return size;}

istream& operator>>(istream& is, CppArray& CA) 
{
    for (int i = 0; i < CA.size; ++i) 
        is >> CA.data[i];
    return is;
}

ostream& operator<<(ostream& os, const CppArray& CA) 
{
    os << "[";
    for (int i = 0; i < CA.size; ++i) 
    {
        os << CA.data[i];
        if (i < CA.size - 1) os << ", ";
    }
    os << "]";
    return os;
}