#include<iostream>
#include"MinHeap.h"
using namespace std;

int main()
{
    MinHeap<int> MinHeap(10);
    MinHeap.Push(2);
    MinHeap.Push(7);
    MinHeap.Push(4);
    MinHeap.Push(10);
    MinHeap.Push(8);

    cout << "Min Heap: ";
    MinHeap.Output();

    MinHeap.Pop();
    MinHeap.Output();
    MinHeap.Pop();
    MinHeap.Output();
    MinHeap.Pop();
    MinHeap.Output();
    MinHeap.Pop();
    MinHeap.Output();
    MinHeap.Pop();
    MinHeap.Output();

    return 0;
}