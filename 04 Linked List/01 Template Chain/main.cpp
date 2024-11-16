#include<iostream>
#include"Chain.h"
using namespace std;

int main()
{
    Chain<int> Chain1;
    Chain1.Create(0);
    Chain1.Output();

    int a , b;
    for(int i = 0; i < 5; i++)
    {
        cin >> a >> b;
        if(b != -1) Chain1.Insert(b , Chain1.Search(a));//搜尋 nodo，若有則插入 b 在 a 後
        else Chain1.Delete(Chain1.Search(a) , Chain1.Search(a , true)); //b = -1 則刪除 node，若 node 存在
        Chain1.Output();
    }

    Chain<string> Chain2;
    Chain2.Create("BAT");
    Chain2.Output();

    string s1,s2;
    for(int i = 0; i < 5; i++)
    {
        cin >> s1 >> s2;
        if(s2 != "D") Chain2.Insert(s2,Chain2.Search(s1));
        else Chain2.Delete(Chain2.Search(s1) , Chain2.Search(s1 , true));
        Chain2.Output();
    }
}