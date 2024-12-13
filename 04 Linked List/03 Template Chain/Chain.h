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
        ChainNode<T> *GetNode(T);//取得 node 如果存在
        ChainNode<T> *Search(T n , bool beforeData = false);
        void Create(T);
        void Insert(T,ChainNode<T> *);//插入在 x 之後，如果 x 存在
        void Delete(ChainNode<T> * , ChainNode<T> *); //將 x 刪除，y 接續在 x 前一個節點
        void Output();
};

#include "Chain.cpp"
#endif