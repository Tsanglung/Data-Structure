#include<iostream>
#include"LinkedStack.h"
using namespace std;

int main()
{
    LinkedStack<int> A;
    for(int i = 0; i < 10;i++)
        A.Push(i);
    cout<<A.Top()<<endl;;
    A.Pop();
    cout<<A.Top()<<endl;
    cout<<A<<endl;
} 