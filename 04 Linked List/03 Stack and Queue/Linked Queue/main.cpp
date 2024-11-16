#include<iostream>
#include"LinkedQueue.h"
using namespace std;

int main()
{
    LinkedQueue<int> A;
    cout<<A.IsEmpty()<<endl;
    for(int i = 0; i < 10;i++)
        A.Push(i);
    cout<<A<<endl;
    cout<<A.Front()<<endl;
    cout<<A.Rear()<<endl;
    A.Pop();
    cout<<A<<endl;
} 