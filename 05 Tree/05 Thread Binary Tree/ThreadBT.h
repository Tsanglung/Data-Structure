#ifndef THREADBT_H
#define THREADBT_H

#include<iostream>
using namespace std;

template<class T>class ThreadBT;
template<class T>
class ThreadBTNode
{
    friend class ThreadBT<T>;
public:
    ThreadBTNode<T>(T d,ThreadBTNode<T>*lC = NULL,ThreadBTNode<T>*rC = NULL,bool lT = false,bool rT = false):data(d),leftChild(lC),rightChild(rC),leftThread(lT),rightThread(rT){}
private:
    T data;
    ThreadBTNode<T> *leftChild;
    ThreadBTNode<T> *rightChild;
    bool leftThread,rightThread;
};

template<class T>
class ThreadBT
{
public:
    ThreadBT();
    bool IsEmpty();
    void Init();
        
    void Inorder();
    void Preorder();
    void Postorder();
    void Levelorder();
    void Visit(ThreadBTNode<T>* item);
private:
    ThreadBTNode<T> *root;
    void Inorder(ThreadBTNode<T> *);
    void Preorder(ThreadBTNode<T> *);
    void Postorder(ThreadBTNode<T> *);
};

#include "ThreadBT.cpp"
#endif