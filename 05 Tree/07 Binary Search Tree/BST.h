#ifndef BST_H
#define BST_H

#include<iostream>
using namespace std;

template<class T>
struct BSTNode {
    T data;
    BSTNode<T> *left, *right;
    BSTNode(const T& item, BSTNode<T>* l = nullptr, BSTNode<T>* r = nullptr): data(item), left(l), right(r) {}
};

template<class T>
class BST
{
public:
    BST();
    void Insert(const T& item);
    void Delete(const T& item);
    bool Search(const T& item) const;
    void Inorder() const;
    void Preorder() const;
    void Postorder() const;
private:
    BSTNode<T>* root;
    BSTNode<T>* Insert(BSTNode<T>* node,const T& item);
    BSTNode<T>* Search(BSTNode<T>* node, const T& item) const;
    BSTNode<T>* Delete(BSTNode<T>* node, const T& item);
    BSTNode<T>* FindMin(BSTNode<T>* node) const;
    void Inorder(BSTNode<T>* node) const;
    void Preorder(BSTNode<T>* node) const;
    void Postorder(BSTNode<T>* node) const;
};

#include"BST.cpp"
#endif