#include <iostream>
#include <iterator>  //ostream_iterator
#include <algorithm> // copy
using namespace std;
// book p.56
/*
is an n * n matrix of integer 1 to n ^ 2 such the sum of every row, column, and diagonal is the same.
n is odd.
*/
void Magic(const int n)
{
    const int MaxSize = 51;
    int square[MaxSize][MaxSize], k, l;
    if ((n > MaxSize) || (n < 1))
        throw "n out of range";
    else if (!(n % 2))
        throw "n is not even";
    // Coxeter's rule
    for (int i = 0; i < n; i++) // ��l�� square �� 0
        fill(square[i], square[i] + n, 0);
    square[0][(n - 1) / 2] = 1; // �Ĥ@�C���������_�l�� 1

    // i, j �O��e�y��
    int key = 2, i = 0, j = (n - 1) / 2;
    while (key <= n * n) // �⥭���ݦ��������ʳ���
    {                    // �W���M����
        if (i - 1 < 0)
            k = n - 1;
        else
            k = i - 1;
        if (j - 1 < 0)
            l = n - 1;
        else
            l = j - 1;
        if (square[k][l])
            i = (i + 1) % n; // square occupied ,�U��
        else
        {
            i = k;
            j = l;
        }
        square[i][j] = key;
        key++;
    }
    cout << "magic square of size " << n << endl;
    for (int i = 0; i < n; i++)
    {
        copy(square[i], square[i] + n, ostream_iterator<int>(cout, " "));
        cout << endl;
    }
}

int main()
{
    cout << "Input odd number n : ";
    int n;
    cin >> n;
    Magic(n);
}