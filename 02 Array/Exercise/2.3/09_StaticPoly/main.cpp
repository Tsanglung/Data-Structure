#include<iostream>
#include"Polynomial.h"
using namespace std;

#include<iostream>
#include"Polynomial.h"
using namespace std;

int main() {
    Polynomial aPoly(0, 1);
    Polynomial bPoly(2, 5);
    cout << "Input Poly1 : " << endl;
    cin >> aPoly;
    cout << "Input Poly2 : " << endl;
    cin >> bPoly;
    Polynomial cPoly = aPoly.Add(bPoly);
    cout << "Sum of Polynomials:" << endl;
    cout<<cPoly<<endl;

    return 0;
}