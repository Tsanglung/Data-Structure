//AvailableSpaceList.cpp
#include "ASL.h"

template<class Type>    ChainNode<Type>* Chain<Type>::av = NULL;       // 初始化 av

template<class Type>
Chain<Type>::Chain()
{   //建立一個有head node 的 circular list
    head = last = GetNode();    // 取得 header node
    head->link = head;          // 建立 circular
}
  
template<class Type> 
Chain<Type>::~Chain()
{  //刪除circluar list，並將node 新增到可用空間
    //課本 P198 Program 4.17
    ChainNode<Type> *first = last->link;
    if (last) {
        last->link = av;    //last node 連結到 av 
        av = first;  //list的 first node 成為 av list 的 front
        last = NULL;
    }
}

template<class Type>
ChainNode<Type>* Chain<Type>::GetNode()
{   //從可用空間取得node (若node存在)
    //若無則建立新的node
    //課本 p.198 Program 4.15
    ChainNode<Type> *x;
    if (av) {
        x = av;
        av = av->link;
    } else 
        x = new ChainNode<Type>;

    return x;
}

template<class Type>
void Chain<Type>::RetNode(ChainNode<Type>* &x)
{  //課本 p.198 Program 4.16
    //釋放 x 指向的節點
    x->link = av;
    av = x;
    x = 0;
}

template<class Type>
void Chain<Type>::DeleteFront()
{   //利用RetNode function釋放指向的node
    ChainNode<Type> *x = head->link;
    head->link = x->link;
    RetNode(x);
}

template<class Type>
void Chain<Type>::InsertBack(Type &e)
{//將data e 的新 node 插入 list 的 tail，課本P.192 Program 4.11
    ChainNode<Type> *x = GetNode();
    last->link = x;
    x->link = head;
    x->data = e;
    last = x;
}

template<class Type>
const Chain<Type>& Chain<Type>::operator=(const Chain<Type> &ch)
{
    //將節點從輸入 Chain 物件 a 複製到目前 Chain 對象，取代目前 node。
    ChainNode<Type> *chtemp;
    if (head->link != head) {      
        last->link = av;
        av = head->link;
    }
    head->link = head;
    last = head;
    chtemp = ch.head->link;
    while (chtemp != ch.head) {  
        InsertBack(chtemp->data);
        chtemp = chtemp->link;
    }
    return ch;
}