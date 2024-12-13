#ifndef MINHEAP_H
#define MINHEAP_H

#include<iostream>
using namespace std;

template<class T>
class MinHeap 
{
private:
    T *heap;
    int heapSize , capacity;
public:
    MinHeap(int theCapacity = 10);
    void ChangeSize1D(T*& a, const int oldSize, const int newSize);
    void Push(const T& e);
    void Pop();
    bool IsEmpty() const { return heapSize == 0; }
    void Output() const;

    static void HeapSort(T *a , const int n);
    static void Adjust(T *a, const int root , const int n);
};

#include"MinHeap.cpp"
#endif