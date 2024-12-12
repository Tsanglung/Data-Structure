#ifndef Queue_H
#define Queue_H

#include<iostream>
using namespace std;

template<class T>
class Queue
{
    private:
        T *queue;
        int front,rear,capacity;
    public:
        Queue(int QueueCapicaty = 10);
        bool IsEmpty() const;
        T& Front()const;
        T& Rear()const;
        void Push(const T& e); //insert rear
        void Pop(); //delete front
        void Output();
};
 

#include"Queue.cpp"
#endif