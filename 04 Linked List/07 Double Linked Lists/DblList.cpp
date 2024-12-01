#include <iostream>
using namespace std;
//Âù¦V³sµ²¦ê¦C
class DblList;

class DblListNode 
{
    friend class DblList;
    friend ostream &operator<<(ostream &os, const DblList &list);
    private:
        int data;
        DblListNode *left, *right;
    public:
        DblListNode(int value = 0) : data(value), left(nullptr), right(nullptr) {}
};

class DblList 
{
    friend ostream &operator<<(ostream &os, const DblList &list);
    public:
        DblList();
        DblListNode* getFirst() const;
        void Insert(DblListNode*, DblListNode*);
        void Delete(DblListNode*);
    private:
        DblListNode *first;  // points to head node
};

DblList::DblList() 
{
    first = new DblListNode();  // head node
    first->right = first;
    first->left = first;
}

DblListNode* DblList::getFirst() const {return first;}

void DblList::Insert(DblListNode *p, DblListNode *x)
{// insert p to right of x
    p->left = x; p->right = x->right;
    x->right->left = p; x->right = p;
}

void DblList::Delete(DblListNode *x)
{
    if (x == first) throw  "Deletion of head node not permitted";
    else 
    {
	    x->left->right = x->right;
	    x->right->left = x->left;
	    delete x;
    }
}

ostream &operator<<(ostream &os, const DblList &list) 
{
    DblListNode *current = list.first->right;
    while (current != list.first) {
        os << current->data << " ";
        current = current->right;
    }
    return os;
}

int main()
{
    DblList intlist;
    DblListNode *node1 = new DblListNode(1);
    DblListNode *node2 = new DblListNode(2);
    DblListNode *node3 = new DblListNode(3);
    intlist.Insert(node1, intlist.getFirst());
    intlist.Insert(node2, node1);
    intlist.Insert(node3, node2);

    cout << "DblList: " << intlist << endl;
    intlist.Delete(node2);
    cout << "After deleting node 2, DblList: " << intlist << endl;
}