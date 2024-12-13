#include<iostream>
#include"BinaryTree.h"
using namespace std;

int main()
{
    BinaryTreeNode<char> C8('A');
    BinaryTreeNode<char> C9('B');
    BinaryTreeNode<char> C7('C');
    BinaryTreeNode<char> C5('D');
    BinaryTreeNode<char> C3('E');
    BinaryTreeNode<char> C6('/',&C8,&C9);
    BinaryTreeNode<char> C4('*',&C6,&C7);
    BinaryTreeNode<char> C2('*',&C4,&C5);
    BinaryTreeNode<char> C1('+',&C2,&C3);
    BinaryTree<char> A(&C1);
    A.Inorder();
    cout<<endl;
    A.Preorder();
    cout<<endl;
    A.Postorder();
    cout<<endl;
    A.Levelorder();
    cout<<endl;
}