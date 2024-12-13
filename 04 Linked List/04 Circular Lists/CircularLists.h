#ifndef CIRCULARLISTS_H
#define CIRCULARLISTS_H

#include<iostream>

template<class T> class CircularList;//forward declaration

template<class T>
class ListNode 
{
    friend class CircularList<T>;
private:
    T data;
    ListNode<T> *link;
    ListNode(T element = T(), ListNode<T> *next = NULL) : data(element), link(next) {}
};

template<class T>
class CircularList 
{
private:
    ListNode<T> *last;
    static ListNode<T>* av; // Available list for recycling nodes
public:
    CircularList();
    ~CircularList();    // delete circular list
    ListNode<T> *GetNode(); // getting a node
    void RetNode(ListNode<T>*&);    //returning a node
    void InsertFront(const T&); // Insert front of a circular list
    void InsertBack(const T&);  // Insert back of a circular list
    void Output() const; // Function to Output the list
};

#include"CircularLists.cpp"
#endif