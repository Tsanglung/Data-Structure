#include"BinaryTree.h"
#include"LinkedQueue.h"
template<class T>
BinaryTree<T>::BinaryTree(){root = NULL;}

template<class T>
BinaryTree<T>::BinaryTree(BinaryTreeNode<T>* node){ root  = node;}

template<class T>
BinaryTree<T>::BinaryTree(BinaryTree<T>& bt1,T& item,BinaryTree<T>& bt2){root = new BinaryTreeNode<T>(item,copy(bt1.root),copy(bt2.root));}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::Copy(BinaryTreeNode<T> *origNode)
{
    if (!origNode) return 0;
    return new BinaryTreeNode<T>(origNode->data,
                       Copy(origNode->leftChild),
                       Copy(origNode->rightChild));
}

template <class T>
bool BinaryTree<T>::Equal(BinaryTreeNode<T> *a, BinaryTreeNode<T> *b)
{
    if ((!a) && (!b)) return true;
    return (a && b
                && (a->data == b->data)
                && Equal(a->leftChild, b->leftChild)
                && Equal(a->rightChild, b->rightChild));
}


template<class T>
inline bool BinaryTree<T>::IsEmpty(){return root == NULL;}

template<class T>
BinaryTree<T> BinaryTree<T>::LeftSubtree()
{
    BinaryTree<T> *leftST;
    leftST.root = root->leftChild;
    return leftST;
}

template<class T>
BinaryTree<T> BinaryTree<T>::RightSubtree()
{
    BinaryTree<T> *rightST;
    rightST.root = root->rightChild;
    return rightST;
}

template<class T>
inline T BinaryTree<T>::RootData(){ return root->data;}

template<class T>
void BinaryTree<T>::Visit(BinaryTreeNode<T>* item) {cout<<item->data<<" ";}

template<class T>
void BinaryTree<T>::Inorder(){Inorder(root);}

template<class T>
void BinaryTree<T>::Inorder(BinaryTreeNode<T>* currentNode)
{
    if(currentNode)
    {
        Inorder(currentNode->leftChild);
        Visit(currentNode);
        Inorder(currentNode->rightChild);
    }
}

template<class T>
void BinaryTree<T>::Preorder(){Preorder(root);}

template<class T>
void BinaryTree<T>::Preorder(BinaryTreeNode<T> * currentNode)
{
    if(currentNode)
    {
        Visit(currentNode);
        Preorder(currentNode->leftChild);
        Preorder(currentNode->rightChild);
    }
}

template<class T>
void BinaryTree<T>::Postorder(){Postorder(root);}

template<class T>
void BinaryTree<T>::Postorder(BinaryTreeNode<T>* currentNode)
{
    if(currentNode)
    {
        Postorder(currentNode->leftChild);
        Postorder(currentNode->rightChild);
        Visit(currentNode);
    }
}

template<class T>
void BinaryTree<T>::Levelorder()
{
    LinkedQueue<BinaryTreeNode<T>*> q;
    BinaryTreeNode<T>* currentNode = root;
    while(currentNode)
    {
        Visit(currentNode);
        if(currentNode->leftChild) q.Push(currentNode->leftChild);
        if(currentNode->rightChild) q.Push(currentNode->rightChild);
        if(q.IsEmpty()) return;
        currentNode = q.Front();
        q.Pop();
    }
}

template <class T>
bool BinaryTree<T>::operator==(const BinaryTree& t) const{return Equal(root, t.root);}