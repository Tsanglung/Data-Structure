#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// 提取數字的第 d 位 (從 0 開始)
int digit(int number, int d, int r) {return (number / static_cast<int>(pow(r, d))) % r;}

template<class T>
int RadixSort(T *a, int *link, const int d, const int r, const int n) {
    int e[r], f[r];
    int first = 1;

    // 初始化link
    for (int i = 1; i < n; i++) link[i] = i + 1;
    link[n] = 0;

    // 從最低位開始排序
    for (int i = 0; i < d; i++) 
    {
        fill(f, f + r, 0);

        // 將元素分配到基數bucket中
        for (int current = first; current; current = link[current]) 
        {
            int k = digit(a[current], i, r);
            if (f[k] == 0) f[k] = current;
            else link[e[k]] = current;
            e[k] = current;
        }

        // 重新組合list
        int j;
        for (j = 0; !f[j]; j++);
        first = f[j];
        int last = e[j];
        for (int k = j + 1; k < r; k++) 
            if (f[k]) 
            {
                link[last] = f[k];
                last = e[k];
            }
        link[last] = 0;
    }
    return first;
}

void RadixSorted(int *a, int *link, int first) 
{
    while (first != 0) 
    {
        cout << a[first] << " ";
        first = link[first];
    }
    cout << endl;
}

int main() {
    int *Input = new int[11];
    int *link = new int[11];

    Input[1] = 179;
    Input[2] = 208;
    Input[3] = 306;
    Input[4] = 93;
    Input[5] = 859;
    Input[6] = 984;
    Input[7] = 55;
    Input[8] = 9;
    Input[9] = 271;
    Input[10] = 33;

    int first = RadixSort(Input, link, 3, 10, 10);
    RadixSorted(Input, link, first);

    delete[] Input;
    delete[] link;

    return 0;
}