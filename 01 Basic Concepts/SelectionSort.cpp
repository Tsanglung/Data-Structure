//選擇排序法
/*
先在未排序序列中找到最小（大）元素，
存放到排序序列的起始位置，然後，
再從剩餘未排序元素中繼續尋找最小（大）元素，
然後放到已排序序列的末尾。
以此類推，直到所有元素均排序完畢。
*/
#include<iostream>
using namespace std;
void SelectionSort(int *a, const int n)
{   //Book p.27 Program 1.8
    for(int i = 0; i < n; i++){
        int j = i;
        for(int k = i + 1; k < n; k++){
            if(a[k] < a[j]) j = k;
            swap(a[i] , a[j]);
        }
    }    
}

int main(){
    int array[100] , i;
    array[0] = 4;
    array[1] = 3;
    array[2] = 1;
    array[3] = 8;
    array[4] = 0;
    SelectionSort(array , 5);

    for(int i = 0; i < 4; i++)  cout << array[i] << "," ;
    cout << array[4] << endl;
}