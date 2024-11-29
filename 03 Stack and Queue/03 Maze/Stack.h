#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    T* stack;   // array for stack elements
    int top;    // top element
    int capacity;   // stack capacity
public:
    Stack(int stackCapacity = 10);
    ~Stack() { delete[] stack; }
    bool IsEmpty() const ;
    T& Top() const;
    void Push(const T& item);
    void Pop();
    void Output() const;
};

template<class T>
Stack<T>::Stack(int StackCapacity):capacity(StackCapacity)
{
    if(capacity < 1)    throw"Stack Capacity must be > 0";
    stack = new T[capacity];
    top = -1;
}

template<class T>
inline bool Stack<T>::IsEmpty() const{   return top == -1; }

template<class T>
inline T& Stack<T>::Top()const //top ¤¸¯À
{
    if(IsEmpty()) throw "Stack is empty";
    else return stack[top];
}

template<class T>
void Stack<T>::Push(const T& e) //insert to top
{
    if(top == capacity - 1) 
    {
        T *temp = new T[capacity*2];
        for(int i = 0; i < capacity;i++) temp[i] = stack [i];
        delete [] stack;
        stack = temp;
        capacity *= 2;
    }
    stack[++top] = e;
}

template<class T>
void Stack<T>::Pop() //delete top
{
    if(IsEmpty()) throw "Empty stack can not delete";
    stack[top--].~T();
}

template<class T>
void Stack<T>::Output() const
{
    cout << "top = " << top << endl;
    for (int i = 0; i <= top; i++)
        cout << i << ":" << stack[i] << endl;
}

#endif
