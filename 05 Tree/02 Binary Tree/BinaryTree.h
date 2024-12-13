#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<iostream>
using namespace std;

template<class T> class BinaryTree;

template<class T>
class BinaryTreeNode
{
    friend class BinaryTree<T>;
    public:
        //constructor
        BinaryTreeNode<T>(T d,BinaryTreeNode<T>*l = NULL,BinaryTreeNode<T>*r = NULL):data(d),leftChild(l),rightChild(r){};
    private:
        T data;
        BinaryTreeNode<T> *leftChild;
        BinaryTreeNode<T> *rightChild;
};

template<class T>
class BinaryTree
{
    public:
        BinaryTree();//constructor
        BinaryTree(BinaryTreeNode<T>* node);//constructor
        BinaryTree(BinaryTree<T>& bt1,T& item,BinaryTree<T>& bt2);
        bool IsEmpty();
        bool Equal(BinaryTreeNode<T>*,BinaryTreeNode<T>*);
        bool operator==(const BinaryTree&) const;
        BinaryTree<T> LeftSubtree();
        BinaryTree<T> RightSubtree();
        T RootData();

        void Inorder();
        void Preorder();
        void Postorder();
        void Levelorder();
        void Visit(BinaryTreeNode<T>* item);
    private:
        BinaryTreeNode<T> *root;
        BinaryTreeNode<T> *Copy(BinaryTreeNode<T>*origNode);//copying BT
        void Inorder(BinaryTreeNode<T> *);
        void Preorder(BinaryTreeNode<T> *);
        void Postorder(BinaryTreeNode<T> *);
};

#include"BinaryTree.cpp"
#endif 