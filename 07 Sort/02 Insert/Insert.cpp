#include<iostream>
using namespace std;

template<class T>
class InsertSort
{
private:
    T Element;
public:
    void SetElement(T e);
    T GetElement() const;
    void Insert(T e, InsertSort<T> *a, int i);
    void InsertionSort(InsertSort<T> *a, const int n);
};

template <class T>
void InsertSort<T>::SetElement(T e){ Element = e; }

template <class T>
T InsertSort<T>::GetElement() const { return Element; }

template <class T>
void InsertSort<T>::Insert(T e, InsertSort<T> *a, int i)
{   // Insert e to the order sequence
    while(e < a[i].GetElement())
    {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1].SetElement(e);
}

template <class T>
void InsertSort<T>::InsertionSort(InsertSort<T> *a, const int n)
{   // Sort into nondecreasing order
    a[0].SetElement(-100); // 假設 -100 是一個很小的值
    for(int j = 2; j <= n; j++)
    {
        T temp = a[j].GetElement();
        Insert(temp, a, j - 1);
    }
}

int main()
{
    InsertSort<int> *I1 = new InsertSort<int>[6];
    I1[1].SetElement(5);
    I1[2].SetElement(4);
    I1[3].SetElement(3);
    I1[4].SetElement(2);
    I1[5].SetElement(1);

    I1[0].InsertionSort(I1, 5);  // Note: Using the first object to call InsertionSort

    for(int i = 1; i < 5; i++) cout << I1[i].GetElement() << ",";
    cout << I1[5].GetElement() << endl;

    delete[] I1;
    return 0;
}
