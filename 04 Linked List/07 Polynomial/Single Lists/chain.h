#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>

template<class T>
class Chain;
 
template<class T>
class ChainIterator;

#include "poly.h"

template<class T>
class ChainNode {
    friend class Chain<T>;
    friend class ChainIterator<T>;
    friend class Polynomial; // 讓 Polynomial 類可以訪問 ChainNode 的私有成員
public:
    ChainNode(T e = T(), ChainNode<T> *l = nullptr);
private:
    T data;
    ChainNode<T> *link;
};

template<class T>
class Chain {
    friend class ChainIterator<T>;
    friend class Polynomial; // 讓 Polynomial 類可以訪問 Chain 的私有成員
public:
    Chain();
    void InsertBack(const T& e);
    ChainIterator<T> begin() const;
    ChainIterator<T> end() const;
private:
    ChainNode<T> *first;
    ChainNode<T> *last;
};

template<class T>
class ChainIterator {
public:
    ChainIterator(ChainNode<T> *startNode = nullptr);
    T& operator *() const;
    T* operator->() const;
    ChainIterator& operator++();
    ChainIterator operator++(int);
    bool operator!=(const ChainIterator& right) const;
    bool operator==(const ChainIterator& right) const;
private:
    ChainNode<T> *current;
};

#include "chain.cpp"
#endif
