#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
using namespace std;
//Book p.186 Program 4.6
template<class T>
class Chain;

template<class T>
class ChainNode
{
    friend class Chain<T>;
    private:
        T data;
        ChainNode<T> *link;
    public:
        ChainNode<T>(T element = T(), ChainNode<T> *next = 0):data(element) , link(next){}
};

template<class T>
class Chain
{
    private:
        ChainNode<T> *first;
    public:
        Chain():first(nullptr){}
        ChainNode<T> *GetNode(T);//���o node �p�G�s�b
        ChainNode<T> *Search(T n , bool beforeData = false);
        void Create(T);
        void Insert(T,ChainNode<T> *);//���J�b x ����A�p�G x �s�b
        void Delete(ChainNode<T> * , ChainNode<T> *); //�N x �R���Ay ����b x �e�@�Ӹ`�I
        void Output();
};

#include "Chain.cpp"
#endif