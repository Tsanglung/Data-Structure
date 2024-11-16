#include"Chain.h"

template<class T>
ChainNode<T> *Chain<T>::GetNode(T data)
{
    ChainNode<T>* current = first;
    while (current != nullptr && current->data != data) 
        current = current->link;
    return current;
}

template<class T>
ChainNode<T> *Chain<T>::Search(T n , bool beforeData)
{   //·j´M node n
    ChainNode<T> *currentNode, *beforeNode;
    currentNode = first;
    beforeNode = currentNode;

    while(currentNode->data != n)
    {
        beforeNode = currentNode;
        currentNode = currentNode->link;
        if(currentNode == NULL) return NULL;
    }
    if(beforeData) return beforeNode;

    return currentNode;
}

template <class T>
void Chain<T>::Create(T data){first = new ChainNode<T>(data,0);}

template<class T>
void Chain<T>::Insert(T newData,ChainNode<T> *x)
{
    if(first)   x->link = new ChainNode<T>(newData , x->link);
    else    first = new ChainNode<T>(newData);
}

template<class T>
void Chain<T>::Delete(ChainNode<T> *x, ChainNode<T> *y)
{   // delete x
    if(x == first) first = first->link;
    else y->link = x->link;
    delete x;
}

template<class T>
void Chain<T>::Output()
{
    ChainNode<T> *current = first;
    while(current != NULL)
    {   // ¿é¥X®æ¦¡: a1->a2->a3....
        cout << current->data;
        if(current->link != NULL) cout << "->";
        current = current->link;
    }
    cout << endl;
}