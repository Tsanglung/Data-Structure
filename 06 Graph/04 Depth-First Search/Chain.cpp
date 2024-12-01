#include"Chain.h"

ChainNode *Chain::GetFirst() const{return first;}


ChainNode *Chain::GetNode(int data)
{
    ChainNode* current = first;
    while (current != nullptr && current->data != data) 
        current = current->link;
    return current;
}

ChainNode *Chain::Search(int n , bool beforeData)
{   //·j´M node n
    ChainNode *currentNode, *beforeNode;
    currentNode = first;
    beforeNode = currentNode;

    while(currentNode->data != n)
    {
        beforeNode = currentNode;
        currentNode = currentNode->link;
        if(currentNode == NULL) return NULL;
    }
    if(beforeData) return beforeNode;

    return currentNode;
}

void Chain::Create(int data){first = new ChainNode(data,0);}

void Chain::Insert(int newData)
{
    ChainNode *newNode = new ChainNode(newData);
    if (first == nullptr) first = newNode;
    else 
    {
        ChainNode *current = first;
        while (current->link != nullptr) 
            current = current->link;
        current->link = newNode;
    }
}

void Chain::Delete(int x)
{   // delete x
    ChainNode *pre = 0, *current;
    for(current = first;current && current->data != x;
    pre = current,current = current->link);
    if(current)
    {
        if(pre) pre->link = current->link;
        else first = first->link;
        delete current;
    }
}

void Chain::Output()
{
    ChainNode *current = first;
    while(current != NULL)
    {   // ¿é¥X®æ¦¡: a1->a2->a3....
        cout << current->data;
        if(current->link != NULL) cout << "->";
        current = current->link;
    }
    cout << endl;
}

int Chain::Length() const {
    int length = 0;
    ChainNode* current = first;
    while (current != nullptr) {
        length++;
        current = current->link;
    }
    return length;
}