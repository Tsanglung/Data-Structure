#include<iostream>
using namespace std;

template<class T>
class QuickSort
{
private:
    T Element;
public:
    void SetElement(T e){Element = e;}
    T GetElement() const {return Element;}
    void quicksort(QuickSort<T> *a , const int left , const int right);
};

template <class T>
void QuickSort<T>::quicksort(QuickSort<T> *a, const int left, const int right)
{
    if(left < right)
    {
        for(int m = 1; m <= 10;m++) cout << a[m].GetElement() << " ";
        cout << endl;

        int i = left , j = right + 1 ;
        T pivot = a[left].GetElement();
        do
        {
            do i++;while(a[i].GetElement() < pivot);
            do j--;while(a[j].GetElement() > pivot);

            if(i < j) 
            {
                T tmp = a[i].GetElement();
                a[i].SetElement(a[j].GetElement());
                a[j].SetElement(tmp);
            }
        }while(i < j);

        T tmp = a[left].GetElement();
        a[left].SetElement(a[j].GetElement());
        a[j].SetElement(tmp);

        quicksort(a , left , j - 1);
        quicksort(a , j + 1,right);
    }
}

int main()
{
    QuickSort<int> *Q = new QuickSort<int>[11];
    Q[1].SetElement(26);
    Q[2].SetElement(5);
    Q[3].SetElement(37);
    Q[4].SetElement(1);
    Q[5].SetElement(61);
    Q[6].SetElement(11);
    Q[7].SetElement(59);
    Q[8].SetElement(15);
    Q[9].SetElement(48);
    Q[10].SetElement(19);

    Q[0].quicksort(Q , 1 , 10);
    cout << endl;

    for(int i = 1; i < 10; i++) cout << Q[i].GetElement() << ",";
        cout << Q[10].GetElement() << endl;

    delete [] Q;
    return 0;
}
