#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include <iostream>
using namespace std;

template <class T>
class SparseMatrix;

template <class T>
class MatrixTerm 
{
    friend class SparseMatrix<T>;
    template<class U>
    friend istream &operator>>(istream &is, SparseMatrix<U> &matrix);
    template<class U>
    friend ostream &operator<<(ostream &os, const SparseMatrix<U> &matrix);
private:
    int row, col; // �x�s��C��m
    T value;      // �D�s��
};

template <class T>
class SparseMatrix 
{
    template<class U>
    friend istream &operator>>(istream &is, SparseMatrix<U> &matrix);
    template<class U>
    friend ostream &operator<<(ostream &os, const SparseMatrix<U> &matrix);
public:
    SparseMatrix(int r = 0, int c = 0, int t = 0);
    ~SparseMatrix() ;
    SparseMatrix Transpose();
    SparseMatrix Add(SparseMatrix b);
    SparseMatrix Multiply(SparseMatrix b);
    void StoreSum(const int, const int ,const int);
    void ChangeSize1D(const int);
private:
    int rows, cols, terms, capacity;       // �x�}��ơB�C�ơB�D�s�ȼƶq�B�}�C�j�p
    MatrixTerm<T> *smArray;      // �Ω��x�s�D�s�Ȫ��}�C
};

#include"SparseMatrix.cpp"
#endif