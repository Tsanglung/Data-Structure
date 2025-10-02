#ifndef STRING_H
#define STRING_H

#include<iostream>
using namespace std;

class String{
public:
    String(const char *,int);//��l�� string
    bool operator==(String);
    bool operator!();//�Ystring �� empty �h return ture
    int Length();//nomber of characters
    String Concat(String);
    String Substr(int,int);
    int Find(String);
    void FailureFunction();
    char *GetStr() const;
private:
    char *str;
    int len, *f;
};

#include"String.cpp"
#endif