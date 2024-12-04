#include<iostream>
using namespace std;
//非遞迴 binomial coefficient
/*
公式:
           n!          
    -------------
    m! (n - m)!
*/
int Binomial(int n, int m)
{
    int nf = 1, mf = 1, n_mf = 1;
    for(int i = 1;i <= n; i++)
    {
        nf *= i; // n!
        if(i <= m) mf *= i; // m!
        if(i <= (n - m)) n_mf *= i; // (n - m)!
    }
    return nf / (mf * n_mf);// 公式 n! / (m! * (n - m)!)
}

int main()
{
    int m , n;
    cout << "Input n , m : ";
    cin >> n >> m;
    cout<< "Binomial Coefficient(" << n << "," << m <<") = " << Binomial(n, m) << endl; 
}