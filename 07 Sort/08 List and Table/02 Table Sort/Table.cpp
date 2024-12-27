#include<iostream>
#include<iomanip> //stew
using namespace std;

class TableSort
{
public:
    int key;
};

void Table(TableSort *ts,const int n, int *t)
{   //index table sort
    for(int i = 1; i < n; i++)
    {   // ts[1:n] to correspond to the sequence a[t[1]],...a[t[n]]
        if(t[i] != i)
        {   //non-trivial cycle starting at i
            TableSort p = ts[i];
            int j = i;
            do{
                int k = t[j];
                ts[j] = ts[k]; 
                t[j] = j;
                j = k;
            }while(t[j] != i);
            ts[j] = p;// j  is position for record  p
            t[j] = j;
        }
    cout << setw(5) << "     ";
    for(int i = 1; i <= n; i++) cout << setw(3) << "R" << i << ' ';
    cout << endl << setw(5) << "key  " ;
    for(int i = 1; i <= n; i++) cout << setw(4) << ts[i].key << " ";
    cout << endl << setw(5) << "t    " ;
    for(int i = 1; i <= n; i++) cout << setw(4) << t[i] << " ";
    cout << endl << endl;
    }
}

int main()
{
    TableSort *ts = new TableSort [9];
    int *t = new int [9];
    ts[1] = {35}; t[1] = 3;
    ts[2] = {14}; t[2] = 2;
    ts[3] = {12}; t[3] = 8;
    ts[4] = {42}; t[4] = 5;
    ts[5] = {26}; t[5] = 7;
    ts[6] = {50}; t[6] = 1;
    ts[7] = {31}; t[7] = 4;
    ts[8] = {18}; t[8] = 6;

    Table(ts, 8, t);
}
