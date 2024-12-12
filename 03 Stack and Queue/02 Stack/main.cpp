#include<iostream>
#include"Stack.h"

int main()
{
    Stack<int>  A;
    Stack<char> B;
    Stack<string>C;
    for(int i = 0;i < 12;i++)
        A.Push(i);
    A.Output();
    A.Pop();
    A.Output();
} 
    