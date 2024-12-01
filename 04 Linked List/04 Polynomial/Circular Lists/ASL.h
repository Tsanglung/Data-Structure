//AvailableSpaceList.h
#ifndef ASL_H
#define ASL_H

#include <iostream>

/*
定義 chains 的 template
課本 p.186 Program 4.6
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
        Chain();    //建構子
        ~Chain();   //解構子
        ChainNode<Type>* GetNode(); //取得node 課本 p.198 Program 4.15
        void RetNode(ChainNode<Type>* &); //釋放node 課本 p.198 Program 4.16
        void InsertBack(Type &);//插入 list 在 end，課本P.192 Program 4.11
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