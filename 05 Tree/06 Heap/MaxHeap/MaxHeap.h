#ifndef MAXHEAP_H
#define MAXHEAP_H

#include<iostream>
using namespace std;

template<class T>
class MaxHeap 
{
private:
    T *heap;
    int heapSize , capacity;
public:
    MaxHeap(int theCapacity = 10);
    void ChangeSize1D(T*& a, const int oldSize, const int newSize);
    void Push(const T& e);
    void Pop();
    bool IsEmpty() const { return heapSize == 0; }
    void Output() const;
};

#include "MaxHeap.cpp"
#endif