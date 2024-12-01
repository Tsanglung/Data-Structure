#include<iostream>
#include<fstream>
#include <algorithm> // 使用 fill 
using namespace std;
/*
定義:
(1)需具反身性 a = a
(2)需具對稱性 (a,b)=(b,a)
(3)需具備遞移性 a=b, b=c , a=c
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
    ENode **first = new ENode * [n]; //初始化 first
    bool *out = new bool [n];   //初始化 bool
    fill(first , first + n , nullptr); // 將整個 first 初始化為 nullptr
    fill(out , out + n, false); //整個 out 初始化為 false

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