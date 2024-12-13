//AvailableSpaceList.cpp
#include "ASL.h"

template<class Type>    ChainNode<Type>* Chain<Type>::av = NULL;       // ��l�� av

template<class Type>
Chain<Type>::Chain()
{   //�إߤ@�Ӧ�head node �� circular list
    head = last = GetNode();    // ���o header node
    head->link = head;          // �إ� circular
}
  
template<class Type> 
Chain<Type>::~Chain()
{  //�R��circluar list�A�ñNnode �s�W��i�ΪŶ�
    //�ҥ� P198 Program 4.17
    ChainNode<Type> *first = last->link;
    if (last) {
        last->link = av;    //last node �s���� av 
        av = first;  //list�� first node ���� av list �� front
        last = NULL;
    }
}

template<class Type>
ChainNode<Type>* Chain<Type>::GetNode()
{   //�q�i�ΪŶ����onode (�Ynode�s�b)
    //�Y�L�h�إ߷s��node
    //�ҥ� p.198 Program 4.15
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
{  //�ҥ� p.198 Program 4.16
    //���� x ���V���`�I
    x->link = av;
    av = x;
    x = 0;
}

template<class Type>
void Chain<Type>::DeleteFront()
{   //�Q��RetNode function������V��node
    ChainNode<Type> *x = head->link;
    head->link = x->link;
    RetNode(x);
}

template<class Type>
void Chain<Type>::InsertBack(Type &e)
{//�Ndata e ���s node ���J list �� tail�A�ҥ�P.192 Program 4.11
    ChainNode<Type> *x = GetNode();
    last->link = x;
    x->link = head;
    x->data = e;
    last = x;
}

template<class Type>
const Chain<Type>& Chain<Type>::operator=(const Chain<Type> &ch)
{
    //�N�`�I�q��J Chain ���� a �ƻs��ثe Chain ��H�A���N�ثe node�C
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