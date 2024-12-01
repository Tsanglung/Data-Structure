#include "chain.h"

template<class T>
ChainNode<T>::ChainNode(T e, ChainNode<T> *l) : data(e), link(l) {}

template<class T>
Chain<T>::Chain() : first(nullptr), last(nullptr) {}
 
template<class T>
void Chain<T>::InsertBack(const T& e) 
{
    ChainNode<T>* newNode = new ChainNode<T>(e);
    if (last) 
    {
        last->link = newNode;
        last = newNode;
    } 
    else first = last = newNode;
}

template<class T>
ChainIterator<T> Chain<T>::begin() const {return ChainIterator<T>(first);}

template<class T>
ChainIterator<T> Chain<T>::end() const {return ChainIterator<T>(nullptr);}

template<class T>
ChainIterator<T>::ChainIterator(ChainNode<T> *startNode) : current(startNode) {}

template<class T>
T &ChainIterator<T>::operator*() const {return current->data;}

template<class T>
T *ChainIterator<T>::operator->() const {return &current->data;}

template <class T>
ChainIterator<T> &ChainIterator<T>::operator++() 
{
    current = current->link;
    return *this;
}

template <class T>
ChainIterator<T> ChainIterator<T>::operator++(int) 
{
    ChainIterator<T> old = *this;
    current = current->link;
    return old;
}

template <class T>
bool ChainIterator<T>::operator!=(const ChainIterator<T>& right) const {return current != right.current;}

template <class T>
bool ChainIterator<T>::operator==(const ChainIterator<T>& right) const {return current == right.current;}
