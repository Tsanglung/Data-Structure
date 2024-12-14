#include <iostream>
using namespace std;

template<class T> class GenList;//前置宣告

template<class T>
class GenListNode
{
    friend class GenList<T>;// friend 存取 private
    private:
        GenListNode<T> *link;//pointer
        bool tag;// true : 指向 sublist。 false 指向 atomic data
        union 
        {
            T data;
            GenListNode<T> *down;// point to sublist
            int ref;//計數
        };
};

template<class T>
class GenList
{
    public:
        ~GenList();// release data
        void Copy(const GenList<T>&);
        bool operator==(const GenList<T>&);// two lists are identical
        bool Equal(GenListNode<T>*,GenListNode<T>*);//workhorse
        int Depth();//driver
        void Init();
    private:
        GenListNode<T> *first;
        GenListNode<T> *Copy(GenListNode<T>*);// copy a list
        int Depth(GenListNode<T>*);//workhorse
        void Delete(GenListNode<T>*);
        static GenListNode<T> *av;
};

template <class T>
GenListNode<T> *GenList<T>::av = nullptr;

template <class T>
GenList<T>::~GenList(){Delete(first); first = nullptr;}

template <class T>
void GenList<T>::Copy(const GenList<T> &l) { first = Copy(l.first); }

template <class T>
bool GenList<T>::operator==(const GenList<T> &l){return Equal(first,l.first);}

template <class T>
bool GenList<T>::Equal(GenListNode<T> *s, GenListNode<T> *t)
{
    if((!s) && (!t)) return true;
    if(s && t && (s->tag == t->tag))// node 存在且 tag 相同
        if(s->tag) return Equal(s->down,t->down) && Equal(s->link,t->link);//若是 sublist 遞迴判斷
        else return (s->data == t->data) && Equal(s->link,t->link);// 判斷 data 是否相等
    return false;
}

template <class T>
int GenList<T>::Depth(){return Depth(first);}

template<class T>
GenListNode<T> *GenList<T>::Copy(GenListNode<T> *p)
{
    GenListNode<T> *q = 0;
    if(p)
    {
        q = new GenListNode<T>;
        q->tag = p->tag;
        if(p->tag) q->down = Copy(p->down);// copy sublist
        else q->data = p->data; //copy data
        q->link = p->link; // copy link
    }
    return q;
}

template <class T>
int GenList<T>::Depth(GenListNode<T> *s)
{
    if(!s) return 0;
    GenListNode<T> *current = s;
    int m = 0;//最大 depth
    while(current)
    {
        if(current->tag)
        {   //若 sublists ， 遞迴
            int n = Depth(current->down);
            if(m < n) m = n;
        }
        current = current->link;
    }
    return m + 1;//包含當前 node 的 depth
}

template <class T>
void GenList<T>::Delete(GenListNode<T> *x)
{
    x->ref--;
    if(!x->ref)
    {
        GenListNode<T> *y = x;
        while(y->link) 
        {
            y = y->link;
            if(y->tag == 1) Delete(y->down);    
        }
        y->link = av;
        av = x;
    }
}

template<class T>
void GenList<T>::Init()
{
    GenListNode<T> *second, *third, *fourth;
    first = new GenListNode<T>;
    first->tag = false; first->data = 'b'; first->link =  second = new GenListNode<T>;
    second->tag = true; second->link = 0; second->down = third = new GenListNode<T>;
    third->tag = false; third->data = 'b'; third->link = fourth = new GenListNode<T>;
    fourth->tag = false; fourth->data = 'c'; fourth->link = 0;
}

int main()
{
    GenList<char> l;
    l.Init();
    GenList<char> m;
    m.Copy(l);
    if (l == m) cout << "equal" << endl;
    cout << "depth: " << l.Depth();
}
