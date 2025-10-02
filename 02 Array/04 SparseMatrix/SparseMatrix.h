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
    int row, col; // 儲存行列位置
    T value;      // 非零值
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
    int rows, cols, terms, capacity;       // 矩陣行數、列數、非零值數量、陣列大小
    MatrixTerm<T> *smArray;      // 用於儲存非零值的陣列
};

#include"SparseMatrix.cpp"
#endif