#include<iostream>
#include<fstream>
#include <algorithm> // �ϥ� fill 
using namespace std;
/*
�w�q:
(1)�ݨ�Ϩ��� a = a
(2)�ݨ��٩� (a,b)=(b,a)
(3)�ݨ�ƻ����� a=b, b=c , a=c
*/
class ENode
{
    friend void Equivalence();
    public:
        ENode(int d = 0 , ENode *l = nullptr) {data = d; link = l;}
    private:
        int data;
        ENode *link;
};

void Equivalence()
{
    ifstream inFile("equiv.in",ios::in); // input file
    if(!inFile) throw "Can't open file.";
    int i , j , n;
    inFile >> n; // object number
    ENode **first = new ENode * [n]; //��l�� first
    bool *out = new bool [n];   //��l�� bool
    fill(first , first + n , nullptr); // �N��� first ��l�Ƭ� nullptr
    fill(out , out + n, false); //��� out ��l�Ƭ� false

    inFile >> i >> j; // equivalence pair
    while (inFile.good()) // check end of file
    {
        first[i] = new ENode(j, first[i]);
        first[j] = new ENode(i, first[j]);
        inFile >> i >> j;
    }

    for (int i = 0; i < n; i++)
    {// output
        if (!out[i])
        {
            cout << endl << "A new class: " << i;
            out[i] = true;
            ENode *x = first[i] , *top = nullptr;
            while (true)
            {//find rest
                while (x)
                {//process list
                    j = x->data;
                    if (!out[j])
                    {
                        cout << ", " << j;
                        out[j] = true;
                        ENode *y = x->link;
                        x->link = top;
                        top = x;
                        x = y;
                    }
                    else    x = x->link;
                }
                if (!top)   break;
                x = first[top->data];
                top = top->link;
            }
        }
    }

    for (int i = 0; i < n; i++) // delete
    {
        while (first[i])
        {
            ENode *delNode = first[i];
            first[i] = delNode->link;
            delete delNode;
        }
    }
    delete[] first;
    delete[] out;
}

int main()
{
    Equivalence();
    return 0;
}