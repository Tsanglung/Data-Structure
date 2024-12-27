#include<iostream>
#include<iomanip> //stew
using namespace std;

class ListSort{
public:
    int key, linka;
};

void ListSort1(ListSort *ls, const int n, int first)
{   // doubly linked list 的 sort 方式
    int *linkb = new int [n + 1];// backward links
    int prev = 0;//初始化 backward links = 0
    for(int current = first; current; current = ls[current].linka)
    {
        linkb[current] = prev;//當前 node 的 backward links
        prev = current;
    }
    
    for(int i = 1; i < n; i++)
    {   
        /*cout << setw(5) << "i    ";
        for(int i = 1; i <= n; i++) cout << setw(3) << "R" << i << ' ';*/
        if(first != i)
        {   // 如果當前節點不在正確位置，則執行交換
            if(ls[i].linka) linkb[ls[i].linka] = first;// 更新 backward link
            ls[linkb[i]].linka = first;
            swap(ls[first].key, ls[i].key);// key change
            swap(ls[first].linka, ls[i].linka);// linka change
            swap(linkb[first], linkb[i]);
        }
        first = ls[i].linka;// linka first position
        /*cout << endl << setw(5) << "key  " ;
        for(int i = 1; i <= n; i++) cout << setw(4) << key[i] << " ";
        cout << endl << "ls.linka" ;
        for(int i = 1; i <= n; i++) cout << setw(4) << ls.linka[i] << " ";
        cout << endl << "linkb" ;
        for(int i = 1; i <= n; i++) cout << setw(4) << linkb[i] << " ";
        cout << endl << endl;*/
    }
    cout << setw(5) << "i    ";
    for(int i = 1; i <= n; i++) cout << setw(3) << "R" << i << ' ';
    cout << endl << setw(5) << "key  " ;
    for(int i = 1; i <= n; i++) cout << setw(4) << ls[i].key << " ";
    cout << endl << "linka" ;
    for(int i = 1; i <= n; i++) cout << setw(4) << ls[i].linka << " ";
    cout << endl << "linkb" ;
    for(int i = 1; i <= n; i++) cout << setw(4) << linkb[i] << " ";
    cout << endl << endl;
    delete [] linkb;
}

void ListSort2(ListSort *ls, const int n, int first)
{   // single linked list
    for(int i = 1;i < n; i++)
    {   //找到正確的 i position，若 index > i 則 record in positions 1,2~,i-1
        while(first < i) first = ls[first].linka;
        int q = ls[first].linka;// next record in sorted order
        if(first != i)
        {
            ListSort temp = ls[i];
            ls[i] = ls[first];// 將目標節點移動到當前位置
            ls[first] = temp;// 將當前節點移動到目標位置
            ls[i].linka = first;
        }
        first = q;// linka first position
        cout << first << endl;
        cout << setw(5) << "i    ";
        for(int j = 1; j <= n; j++) cout << setw(3) << "R" << j << ' ';
        cout << endl << setw(5) << "key  " ;
        for(int j = 1; j <= n; j++) cout << setw(4) << ls[j].key << " ";
        cout << endl << "linka" ;
        for(int j = 1; j <= n; j++) cout << setw(4) << ls[j].linka << " ";
        cout << endl << endl;
    }
}

int main()
{
    ListSort *ls =  new ListSort [11];
    ls[1] = {26,9};
    ls[2] = {5,6};
    ls[3] = {77,0};
    ls[4] = {1,2};
    ls[5] = {61,3};
    ls[6] = {11,8};
    ls[7] = {59,5};
    ls[8] = {15,10};
    ls[9] = {48,7};
    ls[10] = {19,1};
    ListSort1(ls,10,4);
    ListSort *ls2 =  new ListSort [11];
    ls2[1] = {26,9};
    ls2[2] = {5,6};
    ls2[3] = {77,0};
    ls2[4] = {1,2};
    ls2[5] = {61,3};
    ls2[6] = {11,8};
    ls2[7] = {59,5};
    ls2[8] = {15,10};
    ls2[9] = {48,7};
    ls2[10] = {19,1};
    ListSort2(ls2,10,4);
    delete [] ls2;
    system("pause"); //確認程式執行完畢
    return 0;
}