#include<iostream>
using namespace std;
//Ackermann's function
//Book p.33 Exercises 10.
int Ackermann(int m,int n)
{   //recursive
    if(m == 0) return n + 1; 
    else if(n == 0) return Ackermann(m - 1, 1);
    else return Ackermann(m - 1, Ackermann(m, n - 1));
}
 
int main()
{
    int m , n;
    cout << "Input m , n : ";
    cin >> m >> n;
    cout<< "Ackermann(" << m << "," << n <<") = " << Ackermann(m , n) << endl; 
} 