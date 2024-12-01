#include"BST.h"

template <class T>
BST<T>::BST(){root = nullptr;}

template <class T>
void BST<T>::Insert(const T &item){root = Insert(root,item);}

template<class T>
void BST<T>::Delete(const T &item){root = Delete(root,item);}

template<class T>
bool BST<T>::Search(const T &item) const {return Search(root,item) != nullptr;}

template <class T>
BSTNode<T> *BST<T>::Insert(BSTNode<T> *node, const T &item)
{
    if(node == nullptr) return new BSTNode<T>(item);
    if(item < node->data) node->left = Insert(node->left,item);
    else if(item > node->data) node->right = Insert(node->right,item);
    return node;
}

template<class T>
BSTNode<T> *BST<T>::Delete(BSTNode<T> *node,const T &item)
{
    if(node == nullptr) return node;// no child node
    if(item < node->data) node->left = Delete(node->left,item);
    else if(item > node->data) node->right = Delete(node->right,item);
    else
    {//要刪除的 node 有兩個 child node 情況
        if(node->left && node->right)
        {
            BSTNode<T> *tmp = FindMin(node->right);//找右子樹最小節點為繼任者
            node->data = tmp->data;
            node->right = Delete(node->right,tmp->data);
        }
        else
        {
            BSTNode<T>* tmp = node;
            node = (node->left != nullptr) ? node->left : node->right;
            delete tmp;
        }
    }
    return node;
}

template <class T>
BSTNode<T> *BST<T>::FindMin(BSTNode<T> *node) const
{   //找最小值
    while (node->left != nullptr) node = node->left;
    return node;
}

template <class T>
BSTNode<T> *BST<T>::Search(BSTNode<T> *node, const T &item) const
{
    if(node == nullptr || node->data == item) return node;
    if(item < node->data) return Search(node->left , item);
    else return Search(node->right, item);
}

template <class T>
void BST<T>::Inorder() const{Inorder(root);}

template <class T>
void BST<T>::Preorder() const{Preorder(root);}

template <class T>
void BST<T>::Postorder() const{Postorder(root);}

template <class T>
void BST<T>::Inorder(BSTNode<T> *node) const
{
    if(node != nullptr)
    {
        Inorder(node->left);
        cout << node->data << " ";
        Inorder(node->right);
    }
}

template <class T>
void BST<T>::Preorder(BSTNode<T> *node) const
{
    if(node != nullptr)
    {
        cout << node->data << " ";
        Preorder(node->left);
        Preorder(node->right);
    }
}

template <class T>
void BST<T>::Postorder(BSTNode<T> *node) const
{
    if(node != nullptr)
    {
        Postorder(node->left);
        Postorder(node->right);
        cout << node->data << " ";
    }
}