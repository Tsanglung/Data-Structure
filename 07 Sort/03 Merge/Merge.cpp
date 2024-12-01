#include<iostream>
using namespace std;

// 合併兩個已排序的子序列
template<class T>
void Merge(T *initList, T *mergeList, const int l, const int m, const int n)
{
    int i1 = l, iResult = l, i2 = m + 1;
    // 將兩個子序列合併成一個有序序列
    for (; i1 <= m && i2 <= n; iResult++)
    {
        if (initList[i1] <= initList[i2])
        {
            mergeList[iResult] = initList[i1];
            i1++;
        }
        else
        {
            mergeList[iResult] = initList[i2];
            i2++;
        }
    }
    // 將剩餘的元素複製到resultList
    copy(initList + i1, initList + m + 1, mergeList + iResult);
    copy(initList + i2, initList + n + 1, mergeList + iResult);
}

// 分段合併
template<class T>
void MergePass(T *initList, T *resultList, const int n, const int s)
{
    int i;
    // 將數組分成多個段，每段長度為s，進行合併
    for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
        Merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);
    // 處理剩餘的元素
    if ((i + s - 1) < n) 
        Merge(initList, resultList, i, i + s - 1, n);
    else 
        copy(initList + i, initList + n + 1, resultList + i);
}

// 合併排序
template<class T>
void MergeSort(T *a, const int n)
{
    T *tmpList = new T[n + 1];
    // l 表示每段的長度，每次迴圈將段長度加倍
    for (int l = 1; l < n; l *= 2)
    {
        MergePass(a, tmpList, n, l);
        MergePass(tmpList, a, n, l);
    }
    delete[] tmpList;
}

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

    // 執行合併排序
    MergeSort(Input, 10);

    // 輸出排序結果
    for (int i = 1; i < 10; i++) 
        cout << Input[i] << " ";
    cout << Input[10] << endl;

    delete[] Input;
}
