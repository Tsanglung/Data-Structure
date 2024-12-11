#include<iostream>
#include <fstream>
#include"SparseMatrix.h"
using namespace std;

int main()
{
    SparseMatrix<int> A, B, C, D,E;
    ifstream inputFile("sm.in",ios::in);
    if (!inputFile.is_open()) {
        cerr << "can't open file..." << endl;
        return 1;
    }
    inputFile >> A;
    cout << "Sparse atrixM :" << endl << A << endl;
    SparseMatrix<int>AT = A.Transpose();
    cout << "Transpose Sparse Matrix :" << endl << AT << endl;
    AT.~SparseMatrix();
    inputFile >> B;
    C = A.Add(B);
    cout << "Sparse Matrix A + B : " << endl << C << endl;
    SparseMatrix<int> Mul_DE;
    inputFile >> D;
    inputFile >> E;
    Mul_DE = D.Multiply(E);
    cout << "Sparse Matrix D * E : " << endl << Mul_DE << endl; 
}