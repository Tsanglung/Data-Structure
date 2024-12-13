#include"LinkedQueue.h"

template<class T>
LinkedQueue<T>::LinkedQueue() {front = rear = NULL;}

template<class T>
inline bool LinkedQueue<T>::IsEmpty() const{ return front == NULL;}

template<class T>
inline T& LinkedQueue<T>::Front() const {return front->data;}

template<class T>
inline T&LinkedQueue<T>::Rear() const {return rear->data;}

template<class T>
void LinkedQueue<T>::Push(const T& e)
{
    if(IsEmpty()) front = rear = new QueueNode<T>(e,0);
    else rear = rear->link = new QueueNode<T>(e,0);
}
 
template<class T>
void LinkedQueue<T>::Pop()
{
    QueueNode<T> *delNode = front;
    front = front->link;
    delete delNode;
}

template<class T>
ostream& operator<<(ostream& os,const LinkedQueue<T>& Q)
{
    QueueNode<T>* currentNode = Q.front;
    while (currentNode)
    {
        os<<currentNode->data<<" ";
        currentNode = currentNode->link;
    }
    return os;
}