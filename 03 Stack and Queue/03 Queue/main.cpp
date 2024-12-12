#include<iostream>
#include"Queue.h"
using namespace std;

int main()
{
    Queue<int>  A;
    for(int i = 0;i < 12;i++)
        A.Push(i);
    A.Output();
    cout<<A.Front()<<" "<<A.Rear()<<endl;
    A.Pop();
    cout<<A.Front()<<" "<<A.Rear()<<endl;
    A.Output();
} 