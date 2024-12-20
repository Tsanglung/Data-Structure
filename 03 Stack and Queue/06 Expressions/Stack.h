#ifndef Stack_H
#define Stack_H

#include<iostream>
using namespace std;

template<class T>
class Stack
{
    private:
        T *stack;   //array for stack elements
        int top;    //top ����
        int capacity;   //capacity of stack array
    public:
        Stack(int);  //constructor
        bool IsEmpty() const;   //stack empty ? true | false
        T& Top()const;  //return top
        void Push(const T&);  //push e into stack
        void Pop(); //delete top
        void Output();
};

#endif