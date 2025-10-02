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
    for (int i = 0; i < n; i++) // 初始化 square 為 0
        fill(square[i], square[i] + n, 0);
    square[0][(n - 1) / 2] = 1; // 第一列的中間為起始值 1

    // i, j 是當前座標
    int key = 2, i = 0, j = (n - 1) / 2;
    while (key <= n * n) // 把平面看成環狀的封閉體
    {                    // 上移和左移
        if (i - 1 < 0)
            k = n - 1;
        else
            k = i - 1;
        if (j - 1 < 0)
            l = n - 1;
        else
            l = j - 1;
        if (square[k][l])
            i = (i + 1) % n; // square occupied ,下移
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