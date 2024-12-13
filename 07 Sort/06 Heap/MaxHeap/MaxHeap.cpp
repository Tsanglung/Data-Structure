#include"MaxHeap.h"

template<class T>
MaxHeap<T>::MaxHeap(int theCapacity)
{
    capacity = theCapacity;
    heapSize = 0;
    heap = new T[capacity + 1];
}

template <class T>
void MaxHeap<T>::ChangeSize1D(T *&a, const int oldSize, const int newSize)
{
    T *temp = new T[newSize];
    int number = min(oldSize,newSize);
    copy(a , a + number , temp);
    delete [] a;
    a = temp;
}

template<class T>
void MaxHeap<T>::Push(const T& e)
{
    if(heapSize == capacity)
    {
        ChangeSize1D(heap,capacity,capacity * 2);
        capacity *= 2;
    }
    int currentNode = ++heapSize;
    while(currentNode != 1 && heap[currentNode / 2] < e)
    {
        heap[currentNode] = heap[currentNode / 2];
        currentNode /= 2;
    }
    heap[currentNode] = e;
}

template<class T>
void MaxHeap<T>::Pop()
{
    if(IsEmpty()) throw "Empty Heap";

    T lastE = heap[heapSize--];

    int currentNode = 1;
    int child = 2;
    while(child <= heapSize)
    {
        if(child < heapSize && heap[child] < heap[child + 1]) child++;
        if(lastE >= heap[child]) break;
        heap[currentNode] = heap[child];
        currentNode = child;
        child *= 2;
    }
    heap[currentNode] = lastE;
}

template <class T>
void MaxHeap<T>::Output() const
{
    for (int i = 1; i <= heapSize; ++i) cout << heap[i] << " ";
    cout << endl;
}

template<class T>
void MaxHeap<T>::Adjust(T *a, const int root, const int n)
{
    T e = a[root];
    int j;
    for (j = 2 * root; j <= n; j *= 2)
    {
        if (j < n && a[j] < a[j + 1]) j++;//j is max child of its parent
        if (e >= a[j]) break;
        a[j / 2] = a[j]; // move j-th record up the tree
    }
    a[j / 2] = e;

    // 輸出調整後的陣列狀態
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << endl;
}

template<class T>
void MaxHeap<T>::HeapSort(T *a, const int n)
{   //sort
    for (int i = n / 2; i >= 1; i--)
        Adjust(a, i, n);

    for (int i = n - 1; i >= 1; i--)
    {
        swap(a[1], a[i + 1]);//swap first and last of current heap
        Adjust(a, 1, i);    //heapify
    }
}