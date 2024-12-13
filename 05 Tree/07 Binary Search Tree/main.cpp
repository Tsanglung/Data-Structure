#include<iostream>
#include"BST.h"
using namespace std;

int main()
{
    BST<int> T1;
    T1.Insert(30);
    T1.Insert(40);
    T1.Insert(5);
    T1.Insert(2);
    T1.Insert(80);
    cout << "Inorder:";
    T1.Inorder();
    cout << endl;
    cout << "Preorder:";
    T1.Preorder();
    cout << endl;
    cout << "Postorder:";
    T1.Postorder();
    cout << endl;

    cout << "Search for 4: " << (T1.Search(2) ? "Found" : "Not Found") << endl;
    cout << "Search for 9: " << (T1.Search(9) ? "Found" : "Not Found") << endl;

    T1.Insert(35);
    cout << "Inorder:";
    T1.Inorder();
    cout << endl;
    cout << "Preorder:";
    T1.Preorder();
    cout << endl;
    cout << "Postorder:";
    T1.Postorder();
    cout << endl;

    T1.Delete(40);
    cout << "Inorder:";
    T1.Inorder();
    cout << endl;
    cout << "Preorder:";
    T1.Preorder();
    cout << endl;
    cout << "Postorder:";
    T1.Postorder();
    cout << endl;

}