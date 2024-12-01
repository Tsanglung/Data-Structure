#include<iostream>
#include"MaxHeap.h"
using namespace std;

int main()
{
    MaxHeap<int> maxHeap(10);
    maxHeap.Push(20);
    maxHeap.Push(15);
    maxHeap.Push(2);
    maxHeap.Push(14);
    maxHeap.Push(10);

    cout << "Max Heap: ";
    maxHeap.Output();

    maxHeap.Pop();
    maxHeap.Output();
    maxHeap.Pop();
    maxHeap.Output();
    maxHeap.Pop();
    maxHeap.Output();
    maxHeap.Pop();
    maxHeap.Output();
    maxHeap.Pop();
    maxHeap.Output();

    return 0;
}