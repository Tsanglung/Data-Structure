#include"ThreadBT.h"
#include"LinkedQueue.h"
using namespace std;

template<class T>
ThreadBT<T>::ThreadBT(){root = NULL;}

template <class T>
bool ThreadBT<T>::IsEmpty(){return root == NULL;}

template <class T>
void ThreadBT<T>::Init()
{
    ThreadBTNode<T> *A, *B, *C, *D, *E, *F, *G, *H, *I;
    root = new ThreadBTNode<T>(T(), nullptr, nullptr, true, true);
    root->leftChild = A = new ThreadBTNode<T>('A');
    root->leftThread = false;
    root->rightThread = true;
    root->rightChild = root;

    A->leftChild = B = new ThreadBTNode<T>('B');
    A->rightChild = C = new ThreadBTNode<T>('C');
    
    B->leftChild = D = new ThreadBTNode<T>('D');
    B->rightChild = E = new ThreadBTNode<T>('E', nullptr, nullptr, true, true);
    
    C->leftChild = F = new ThreadBTNode<T>('F', nullptr, nullptr, true, true);
    C->rightChild = G = new ThreadBTNode<T>('G', nullptr, nullptr, true, true);
    
    D->leftChild = H = new ThreadBTNode<T>('H', nullptr, nullptr, true, true);
    D->rightChild = I = new ThreadBTNode<T>('I', nullptr, nullptr, true, true);
    
    H->leftChild = root; H->rightChild = D;
    I->leftChild = D; I->rightChild = B;
    E->leftChild = B; E->rightChild = A;
    F->leftChild = A; F->rightChild = C;
    G->leftChild = C; G->rightChild = root;
}


template <class T>
void ThreadBT<T>::Inorder(){Inorder(root->leftChild);}

template <class T>
void ThreadBT<T>::Inorder(ThreadBTNode<T> *current)
{
    if (!current) return;

    while (current->leftThread == false)    current = current->leftChild;

    while (current != root)
    {
        Visit(current);
        if (current->rightThread)   current = current->rightChild;
        else
        {
            current = current->rightChild;
            while (current->leftThread == false)    current = current->leftChild;
        }
    }
}

template <class T>
void ThreadBT<T>::Preorder(){Preorder(root->leftChild);}

template <class T>
void ThreadBT<T>::Preorder(ThreadBTNode<T> *current)
{
    if (!current) return;

    while (current != root)
    {
        Visit(current);
        if (!current->leftThread)   current = current->leftChild;
        else if (!current->rightThread) current = current->rightChild;
        else
        {
            while (current != root && current->rightThread) current = current->rightChild;
            if (current != root)    current = current->rightChild;
        }
    }
}

template <class T>
void ThreadBT<T>::Postorder(){Postorder(root->leftChild);}

template <class T>
void ThreadBT<T>::Postorder(ThreadBTNode<T> *current)
{
    if (!current) return;

    if (!current->leftThread)   Postorder(current->leftChild);
    if (!current->rightThread)  Postorder(current->rightChild);
    Visit(current);
}

template <class T>
void ThreadBT<T>::Levelorder()
{
    if (!root) return;

    LinkedQueue<ThreadBTNode<T>*> q;
    q.Push(root->leftChild);
    while (!q.IsEmpty())
    {
        ThreadBTNode<T>* current = q.Front();
        q.Pop();
        Visit(current);
        if (!current->leftThread)
            q.Push(current->leftChild);
        if (!current->rightThread)
            q.Push(current->rightChild);
    }
}

template <class T>
void ThreadBT<T>::Visit(ThreadBTNode<T>* item){if (item)   cout << item->data << " ";}