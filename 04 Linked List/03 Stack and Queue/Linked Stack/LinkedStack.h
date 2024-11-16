#ifndef LinkedStack_H
#define LinkedStack_H

#include<iostream>
using namespace std;

template<class T>
class LinkedStack;

template<class T>
class StackNode
{
    template<class Type>
    friend ostream& operator<<(ostream& os,const LinkedStack<Type>& S);
    friend class LinkedStack<T>;
    private:
        T data;
        StackNode<T> *link;
        StackNode<T>(T d,StackNode<T> *l):data(d),link(l){};
}; 

template<class T>
class LinkedStack
{
    private:
        StackNode<T> *top;
    public:
        template<class Type>
        friend ostream& operator<<(ostream& os,const LinkedStack<Type>& S);
        LinkedStack();  //constructor
        bool IsEmpty() const;   //stack empty ? true | false
        T& Top()const;  //return top
        void Push(const T& e);  //push e into stack
        void Pop(); //delete top
};

#include"LinkedStack.cpp"
#endif