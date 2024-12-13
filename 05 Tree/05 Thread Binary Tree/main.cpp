#include<iostream>
#include"ThreadBT.h"
using namespace std;

int main()
{
    ThreadBT<char> A;
    A.Init();

    A.Inorder();
    cout<<endl;
    A.Preorder();
    cout<<endl;
    A.Postorder();
    cout<<endl;
    A.Levelorder();
    cout<<endl;
}