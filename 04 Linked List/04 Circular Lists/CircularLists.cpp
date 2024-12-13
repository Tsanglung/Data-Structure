#include "CircularLists.h"
using namespace std;

// Initialize the static member
template<class T>
ListNode<T>* CircularList<T>::av = NULL;

template <class T>
CircularList<T>::CircularList() { last = NULL; /*Initialize last to null*/}
//Book p.198 Program 4.17
template <class T>
CircularList<T>::~CircularList() 
{   //Delete all node
    if (last) 
    {
        ListNode<T> *current = last->link;
        last->link = av;
        while (current != last) 
        {
            ListNode<T> *temp = current;
            current = current->link;
            temp->link = av;
            av = temp;
        }
        av = last;
        last = NULL;
    }
}
//Book p.196 Program 4.14
template<class T>
void CircularList<T>::InsertFront(const T& e) {
    ListNode<T> *newNode = new ListNode<T>(e);
    if (last) 
    {
        newNode->link = last->link; // New node points to the first node
        last->link = newNode; // Last node points to the new node
    } 
    else 
    {
        last = newNode; // Only one node in the list
        newNode->link = newNode; // Point to itself to make it circular
    }
}

template<class T>
void CircularList<T>::InsertBack(const T& e) {
    ListNode<T> *newNode = new ListNode<T>(e);
    if (last) 
    {
        newNode->link = last->link; // New node points to the first node
        last->link = newNode; // Last node points to the new node
        last = newNode; // Update last to be the new node
    } 
    else 
    {
        last = newNode; // Only one node in the list
        newNode->link = newNode; // Point to itself to make it circular
    }
}
//Book p.198 Program 4.14
template<class T>
ListNode<T> *CircularList<T>::GetNode() {
    ListNode<T> *x;
    if (av) 
    {
        x = av;
        av = av->link;
    } 
    else x = new ListNode<T>;
    return x;
}
//Book p.198 Program 4.15
template<class T>
void CircularList<T>::RetNode(ListNode<T>*& x) 
{
    x->link = av;
    av = x;
    x = nullptr;
}

template<class T>
void CircularList<T>::Output() const 
{
    if (last) 
    {
        ListNode<T> *current = last->link;
        do 
        {
            cout << current->data << " ";
            current = current->link;
        } while (current != last->link);
        cout << endl;
    }
}
