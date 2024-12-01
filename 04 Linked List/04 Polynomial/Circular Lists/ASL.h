//AvailableSpaceList.h
#ifndef ASL_H
#define ASL_H

#include <iostream>

/*
�w�q chains �� template
�ҥ� p.186 Program 4.6
*/
template<class Type>
class Chain; 

#include "Poly.h" //Polynomial.h
 
template<class Type> 
class ChainNode {
    friend class Chain<Type>;
    friend class Polynomial;
    friend ostream& operator<<(ostream&, Polynomial&);
    friend istream& operator>>(istream&, Polynomial&);
    private:
        Type data;
        ChainNode<Type> *link;
};

template<class Type>
class Chain {
    friend class Polynomial;
    public:
        Chain();    //�غc�l
        ~Chain();   //�Ѻc�l
        ChainNode<Type>* GetNode(); //���onode �ҥ� p.198 Program 4.15
        void RetNode(ChainNode<Type>* &); //����node �ҥ� p.198 Program 4.16
        void InsertBack(Type &);//���J list �b end�A�ҥ�P.192 Program 4.11
        void DeleteFront();
        const Chain<Type>& operator=(const Chain<Type>&);
        friend ostream& operator<<(ostream&, Polynomial&);
        friend istream& operator>>(istream&, Polynomial&);
    private:
        ChainNode<Type>* head; //haed node
        ChainNode<Type>* last; //last node
        static ChainNode<Type>* av;
};

#include "ASL.cpp"
#endif 