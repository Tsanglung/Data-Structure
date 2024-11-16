/*
二元搜尋 Binary Search
*/
#include<iostream>
using namespace std;
//遞迴版本
int R_BinarySearch(int *a,const int x,const int left, const int right )
{   //Book p.31 Program 1.11
    if(left <= right){ 
        int middle = ((left + right) / 2);
        if(x < a[middle]) return R_BinarySearch(a,x,left,middle - 1);
        else if(x > a[middle]) return R_BinarySearch(a,x,middle + 1,right);
        else return middle;
    }
    return -1; //not found
}
 
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
    int array[10];
    array[0] = 2;
    array[1] = 4;
    array[2] = 9;
    array[3] = 15;
    array[4] = 21;
    array[5] = 30;
    array[6] = 33;
    array[7] = 51;
    array[8] = 120;
    array[9] = 187;
    cout << 15 << " in position " << BinarySearch(array , 15 , 10) << endl;
    cout << 15 << " in position " << R_BinarySearch(array , 15 , 0 , 9) << endl;
}