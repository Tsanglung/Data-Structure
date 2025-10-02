#include<iostream>
#include"CppArray.h"
using namespace std;

int main()
{
    CppArray a1(5, 2.5);
    cout << "array 1 initialized : " << a1 << endl;
    cout << "array 1 size : " << a1.GetSize() << endl;
    a1[2] = 10.5;
    cout << "array 1 modifying index 2 : " << a1 << endl;

    try{
        cout << "accessing index 8 : " << a1[8] << endl; 
    }catch(const char *e){ 
        cout << e << endl;
    }

    CppArray a2 = a1; //copy
    cout << "array 2 copy of array 1 : " << a2 << endl;

    CppArray a3(3, 1.0);
    cout << "array 3 initialized: " << a3 << endl;
    a3 = a1;
    cout << "array 3 after assignment from array 1: " << a3 << endl;

    cout << "enter 5 values for array 1: " << endl;
    cin >> a1;
    cout << "array 1 after input: " << a1 << endl;
}