#include<iostream>
using namespace std;

// �X�֨�Ӥw�ƧǪ��l�ǦC
template<class T>
void Merge(T *initList, T *mergeList, const int l, const int m, const int n)
{
    int i1 = l, iResult = l, i2 = m + 1;
    // �N��Ӥl�ǦC�X�֦��@�Ӧ��ǧǦC
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
    // �N�Ѿl�������ƻs��resultList
    copy(initList + i1, initList + m + 1, mergeList + iResult);
    copy(initList + i2, initList + n + 1, mergeList + iResult);
}

// ���q�X��
template<class T>
void MergePass(T *initList, T *resultList, const int n, const int s)
{
    int i;
    // �N�Ʋդ����h�Ӭq�A�C�q���׬�s�A�i��X��
    for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
        Merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);
    // �B�z�Ѿl������
    if ((i + s - 1) < n) 
        Merge(initList, resultList, i, i + s - 1, n);
    else 
        copy(initList + i, initList + n + 1, resultList + i);
}

// �X�ֱƧ�
template<class T>
void MergeSort(T *a, const int n)
{
    T *tmpList = new T[n + 1];
    // l ��ܨC�q�����סA�C���j��N�q���ץ[��
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

    // ����X�ֱƧ�
    MergeSort(Input, 10);

    // ��X�Ƨǵ��G
    for (int i = 1; i < 10; i++) 
        cout << Input[i] << " ";
    cout << Input[10] << endl;

    delete[] Input;
}
