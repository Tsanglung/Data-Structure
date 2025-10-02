#include<iostream>
using namespace std;

int count = 0; //counting statements

void Add(int (*a)[3], int (*b)[3], int (*c)[3], int m, int n)
{
    for(int i = 0; i < m;i++)
    {
        count++;
        for(int j = 0;j < n;j++)
        {
            count++;
            c[i][j] = a[i][j] + b[i][j];
            count++;
        }
        count++;
    }
}

int main()
{
    int a[2][3], b[2][3], c[2][3];
    a[0][0] = 1.3; a[0][1] = 2.43; a[0][2] = 3.1;
    a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;

    b[0][0] = -1.3; b[0][1] = -2.43; b[0][2] = -3.1;
    b[1][0] = -4; b[1][1] = -5; b[1][2] = -6;

    Add(a, b, c, 2, 3);
    cout << c[0][0] << "," << c[0][1] << "," << c[0][2] << endl;
   cout << c[1][0] << "," << c[1][1] << "," << c[1][2] << endl;
   cout << count << endl;
}