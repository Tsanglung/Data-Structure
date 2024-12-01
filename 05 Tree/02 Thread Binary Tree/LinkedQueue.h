#ifndef LinkedQueue_H
#define LinkedQueue_H

#include<iostream>
using namespace std;

template<class T>
class LinkedQueue;

template<class T>
class QueueNode
{
    template<class Type>
    friend ostream& operator<<(ostream& os,const LinkedQueue<Type>& Q);
    friend class LinkedQueue<T>;
    private:
        T data;
        QueueNode<T> *link;
        QueueNode<T>(T d,QueueNode<T> *l):data(d),link(l){};
};

template<class T>
class LinkedQueue
{
    private:
        QueueNode<T> *front;
        QueueNode<T> *rear;
    public:
        template<class Type>
        friend ostream& operator<<(ostream& os,const LinkedQueue<Type>& S);
        LinkedQueue();  //constructor
        bool IsEmpty() const;   //stack empty ? true | false
        T& Front()const;
        T& Rear()const;
        void Push(const T& e);
        void Pop();
};

#include"LinkedQueue.cpp"
#endif