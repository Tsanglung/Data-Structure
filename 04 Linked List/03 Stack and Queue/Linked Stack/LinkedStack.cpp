#include"LinkedStack.h"
//Book p.200~201 Program 4.19~4.20
template<class T>
LinkedStack<T>::LinkedStack(){ top = NULL;}

template<class T>
inline bool LinkedStack<T>::IsEmpty() const{ return top == NULL;}

template<class T>
inline T&LinkedStack<T>::Top()const{ return top->data; }

template<class T>
void LinkedStack<T>::Push(const T& e){top = new StackNode<T>(e,top);}

template<class T>
void LinkedStack<T>::Pop()
{
    StackNode<T> *delNode = top;
    top = top->link;
    delete delNode;
}
 
template<class T>
ostream& operator<<(ostream& os,const LinkedStack<T>& s)
{
    StackNode<T>* currentNode = s.top;
    while(currentNode != NULL)
    {
        os<<currentNode->data<<" ";
        currentNode = currentNode->link;
    }
    return os;
}