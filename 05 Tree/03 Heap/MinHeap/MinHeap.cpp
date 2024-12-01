#include"MinHeap.h"

template<class T>
MinHeap<T>::MinHeap(int theCapacity)
{
    capacity = theCapacity;
    heapSize = 0;
    heap = new T[capacity + 1];
}

template <class T>
void MinHeap<T>::ChangeSize1D(T *&a, const int oldSize, const int newSize)
{
    T *temp = new T[newSize];
    int number = min(oldSize,newSize);
    copy(a , a + number , temp);
    delete [] a;
    a = temp;
}

template<class T>
void MinHeap<T>::Push(const T& e)
{
    if(heapSize == capacity)
    {
        ChangeSize1D(heap,capacity,capacity * 2);
        capacity *= 2;
    }
    int currentNode = ++heapSize;
    while(currentNode != 1 && heap[currentNode / 2] > e)
    {
        heap[currentNode] = heap[currentNode / 2];
        currentNode /= 2;
    }
    heap[currentNode] = e;
}

template<class T>
void MinHeap<T>::Pop()
{
    if(IsEmpty()) throw "Empty Heap";

    T lastE = heap[heapSize--];

    int currentNode = 1;
    int child = 2;
    while(child <= heapSize)
    {
        if(child < heapSize && heap[child] > heap[child + 1]) child++;
        if(lastE <= heap[child]) break;
        heap[currentNode] = heap[child];
        currentNode = child;
        child *= 2;
    }
    heap[currentNode] = lastE;
}

template <class T>
void MinHeap<T>::Output() const
{
    for (int i = 1; i <= heapSize; ++i) cout << heap[i] << " ";
    cout << endl;
}