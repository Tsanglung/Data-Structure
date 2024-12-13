#include <iostream>
using namespace std;

template<class T> class GenList;

template<class T>
class GenListNode
{
    friend class GenList<T>;
    private:
        GenListNode<T> *link;
        bool tag;
        union 
        {
            T data;
            GenListNode<T> *down;
            int ref;
        };
};

template<class T>
class GenList
{
    public:
        ~GenList();
        void Copy(const GenList<T>&);
        bool operator==(const GenList<T>&);
        bool Equal(GenListNode<T>*,GenListNode<T>*);
        int Depth();
        void Init();
    private:
        GenListNode<T> *first;
        GenListNode<T> *Copy(GenListNode<T>*);// copy a list
        int Depth(GenListNode<T>*);
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
    if(s && t && (s->tag == t->tag))
        if(s->tag) return Equal(s->down,t->down) && Equal(s->link,t->link);
        else return (s->data == t->data) && Equal(s->link,t->link);
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
        if(p->tag) q->down = Copy(p->down);
        else q->data = p->data;
        q->link = p->link;
    }
    return q;
}

template <class T>
int GenList<T>::Depth(GenListNode<T> *s)
{
    if(!s) return 0;
    GenListNode<T> *current = s;
    int m = 0;
    while(current)
    {
        if(current->tag)
        {
            int n = Depth(current->down);
            if(m < n) m = n;
        }
        current = current->link;
    }
    return m + 1;
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
