#include<iostream>
#include"CircularLists.h"
using namespace std;

int main() {
    CircularList<int> list;
    list.InsertFront(10);
    list.InsertFront(20);
    list.InsertFront(30);
    list.Output(); // Output: 30 20 10
    list.InsertBack(50);
    list.Output(); // Output: 30 20 10 50

    return 0;
}