#include "MinHeap.h"
using namespace std;

int main()
{
    int *Input = new int[11];
    Input[1] = 26;
    Input[2] = 5;
    Input[3] = 77;
    Input[4] = 1;
    Input[5] = 61;
    Input[6] = 11;
    Input[7] = 59;
    Input[8] = 15;
    Input[9] = 48;
    Input[10] = 19;

    cout << "Original array: " << endl;
    for (int i = 1; i <= 10; i++) 
        cout << Input[i] << " ";
    cout << endl;

    cout << endl;
    MinHeap<int>::HeapSort(Input , 10);
    cout << endl;

    cout << "Min Heap Sort array: " << endl;
    for(int i = 1; i <= 10; i++) 
        cout << Input[i] << " ";
    cout << endl;

    delete[] Input;
    return 0;
}
