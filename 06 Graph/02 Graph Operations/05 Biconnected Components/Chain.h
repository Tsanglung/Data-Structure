#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
using namespace std;

class Chain;
class ChainNode
{
    friend class Chain;
    public:
        int data;
        ChainNode *link;
        ChainNode(int element = 0, ChainNode *next = 0):data(element) , link(next){}
};

class Chain
{
    private:
        ChainNode *first;
    public:
        Chain():first(nullptr){}
        ChainNode *GetFirst() const;
        ChainNode *GetNode(int);//取得 node 如果存在
        ChainNode *Search(int n , bool beforeData = false);
        void Create(int);
        void Insert(int);//插入
        void Delete(int); 
        void Output();
        int Length() const;
};

#include "Chain.cpp"
#endif