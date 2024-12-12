#include"Queue.h"

template<class T>
Queue<T>::Queue(int QueueCapicaty):capacity(QueueCapicaty)
{
    queue = new T[capacity];
    front = rear = -1;
}

template<class T>
inline bool Queue<T>::IsEmpty()const {return front == rear;}

template<class T>
inline T& Queue<T>::Front() const {if(!IsEmpty()) return queue[(front + 1) % capacity];}

template<class T>
inline T& Queue<T>::Rear() const { if(!IsEmpty()) return queue[rear];}
 
template<class T>
void Queue<T>::Push(const T& e)
{
    if((rear + 1 )% capacity == front)
    {
        T *newQueue = new T[capacity * 2];
        int start = (front + 1) % capacity;
        if(start < 2 )
            copy(queue + start,queue + start +capacity -1,newQueue);
        else
        {
            copy(queue + start,queue + capacity,newQueue);
            copy(queue,queue + rear + 1,newQueue + capacity -start);
        }
        front = 2*capacity - 1;
        rear = capacity -2;
        capacity *= 2;
        delete [] queue;
        queue = newQueue;
    }
    queue[++rear] = e;
}

template<class T>
void Queue<T>::Pop()
{
    queue[++front].~T();
}

template<class T>
void Queue<T>::Output()
{
    for(int i = front + 1; i <= rear;i++)
        cout<<queue[i]<<" ";
    cout<<endl;
}