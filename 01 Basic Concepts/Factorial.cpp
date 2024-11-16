#include<iostream>
using namespace std;
//Factorial function
//Book p.33 Exercisex 6.
int RFactorial(int n)//»¼°j¶¥­¼
{   //recursive
    if(n <= 1) return 1;
    else return n * RFactorial(n - 1);
} 
 
int Factorial(int n)
{   //iterative
    int F = 1;
    for(int i = n;i > 0;i--) F *= i;
    return F;
}

int main()
{
    int n;
    cin >> n;
    cout << n << "! = " << RFactorial(n) << endl;
    cout << n << "! = " << Factorial(n) << endl;
}