/*
二元搜尋 Binary Search
*/
#include<iostream>
using namespace std;
 
int BinarySearch(int *a,const int x,const int n)
{   //Book p.28 Program 1.10
    // 從排序過的 array 搜尋 x
    int left = 0,right = n - 1;
    while(left <= right){
        int middle = ((left + right) / 2);
        if(x < a[middle]) right = middle - 1;
        else if(x > a[middle]) left = middle + 1;
        else return middle;
    }
    return -1; //not found
}

int main(){
    int array[10] = {2,4,9,15,21,30,33,51,120,187};
    cout << 15 << " in position " << BinarySearch(array , 15 , 10) << endl;
}