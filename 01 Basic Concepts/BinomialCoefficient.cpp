#include<iostream>
using namespace std;

int call_count = 0;
int max_depth = 0;

//二項式係數 binomial coefficient
//Book p.33 Exercises 8.
int Binomial(int n,int m, int current_depth)
{   //recursive
    call_count++;
    if(current_depth > max_depth) max_depth = current_depth;

    if (m == 0 || m == n) return 1; 
    else return Binomial(n - 1, m, current_depth + 1) + Binomial(n - 1, m - 1, current_depth + 1);
}

int main()
{
    int m , n;
    cout << "Input n , m : ";
    cin >> n >> m;
    call_count = 0;
    max_depth = 0;
    cout<< "Binomial Coefficient(" << n << "," << m <<") = " << Binomial(n, m, 1) << endl; 
    cout << "Total function calls : " << call_count << endl;
    cout << "Max recursion depth : " << max_depth << endl; 
}
