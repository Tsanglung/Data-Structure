//��ܱƧǪk
/*
���b���ƧǧǦC�����̤p�]�j�^�����A
�s���ƧǧǦC���_�l��m�A�M��A
�A�q�Ѿl���ƧǤ������~��M��̤p�]�j�^�����A
�M����w�ƧǧǦC�������C
�H�������A����Ҧ��������Ƨǧ����C
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