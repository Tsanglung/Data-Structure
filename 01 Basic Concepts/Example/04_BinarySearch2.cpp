/*
¤G¤¸·j´M Binary Search
*/
#include<iostream>
using namespace std;
//»¼°jª©¥»
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

int main(){
    int array[10] = {2,4,9,15,21,30,33,51,120,187};
    cout << 15 << " in position " << R_BinarySearch(array , 15 , 0 , 9) << endl;
}