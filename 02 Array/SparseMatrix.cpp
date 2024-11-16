//稀疏矩陣
#include<iostream>
using namespace std;

//Book p.98~107
template<class T> 
class SparseMatrix;//提前宣告

template<class T>
class MatrixTerm
{
    friend class SparseMatrix<T>;
private:
    int row , col;//存值
    T value;
};
template<class T>
class SparseMatrix
{
private:
    int rows , cols , terms ;//共幾列、幾行、幾個非零值
    MatrixTerm<T> *smArray; //指標陣列儲存
public:
    SparseMatrix(int r , int c , int t):rows(r),cols(c),terms(t){smArray = new MatrixTerm<T> [terms];}
    ~SparseMatrix() {delete[] smArray;}
    SparseMatrix Transpose();//轉置矩陣
    SparseMatrix Add(SparseMatrix b); //加
    SparseMatrix Mul(SparseMatrix b); //乘
    void init1(T *a);
    void init2(T *a);
    void init3(T *a);
    void Output();
};

template<class T>
SparseMatrix<T> SparseMatrix<T>::Transpose()
{   //Program 2.10
    SparseMatrix<T> b(cols , rows , terms);
    if(terms > 0)
    {
        int currentB = 0;
        for(int i = 0; i < cols; i++)// transpose by columns
            for(int j = 0; j < terms; j++) //find and move terms in column c
                if(smArray[j].col == i)
                {
                    b.smArray[currentB].row = i;
                    b.smArray[currentB].col = smArray[j].row;
                    b.smArray[currentB++].value = smArray[j].value;
                }
    }
    return b;
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::Add(SparseMatrix<T> b)
{
    SparseMatrix<T> d(rows, b.cols , terms + b.terms);
     int aPos = 0, bPos = 0, rPos = 0;

    while (aPos < terms && bPos < b.terms) {
        if (smArray[aPos].row < b.smArray[bPos].row || (smArray[aPos].row == b.smArray[bPos].row && smArray[aPos].col < b.smArray[bPos].col)) {
            d.smArray[rPos++] = smArray[aPos++];
        }
        else if (smArray[aPos].row > b.smArray[bPos].row || (smArray[aPos].row == b.smArray[bPos].row && smArray[aPos].col > b.smArray[bPos].col)) {
            d.smArray[rPos++] = b.smArray[bPos++];
        }
        else {
            d.smArray[rPos] = smArray[aPos];
            d.smArray[rPos++].value = smArray[aPos++].value + b.smArray[bPos++].value;
        }
    }

    while (aPos < terms) {
        d.smArray[rPos++] = smArray[aPos++];
    }
    while (bPos < b.terms) {
        d.smArray[rPos++] = b.smArray[bPos++];
    }

    d.terms = rPos;//加完後共幾個值
    return d;
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::Mul(SparseMatrix<T> b)
{
    SparseMatrix<T> bXpose = b.Transpose();
    SparseMatrix<T> d(rows,b.cols,terms * b.terms);
        int rPos = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < bXpose.rows; j++) {
            int sum = 0 , aPos = 0, bPos = 0;
            while (aPos < terms && smArray[aPos].row < i) aPos++;
            while (bPos < bXpose.terms && bXpose.smArray[bPos].row < j) bPos++;
            while (aPos < terms && bPos < bXpose.terms && smArray[aPos].row == i && bXpose.smArray[bPos].row == j) 
            {
                if (smArray[aPos].col == bXpose.smArray[bPos].col) 
                    sum += smArray[aPos++].value * bXpose.smArray[bPos++].value;
                else if (smArray[aPos].col < bXpose.smArray[bPos].col) aPos++;
                else bPos++;
            }
            if (sum != 0) {
                d.smArray[rPos].row = i;
                d.smArray[rPos].col = j;
                d.smArray[rPos++].value = sum;
            }
        }
    }
    d.terms = rPos;
    return d;
}

template <class T>
void SparseMatrix<T>::init1(T *a)
{
    smArray[0].row = 0; smArray[0].col = 0; smArray[0].value = a[0];
    smArray[1].row = 0; smArray[1].col = 3; smArray[1].value = a[1];
    smArray[2].row = 0; smArray[2].col = 5; smArray[2].value = a[2];
    smArray[3].row = 1; smArray[3].col = 1; smArray[3].value = a[3];
    smArray[4].row = 1; smArray[4].col = 2; smArray[4].value = a[4];
    smArray[5].row = 2; smArray[5].col = 3; smArray[5].value = a[5];
    smArray[6].row = 4; smArray[6].col = 0; smArray[6].value = a[6];
    smArray[7].row = 5; smArray[7].col = 2; smArray[7].value = a[7];
}

template<class T>
void SparseMatrix<T>::init2(T *a)
{
    smArray[0].row = 0; smArray[0].col = 0; smArray[0].value = a[0];
    smArray[1].row = 0; smArray[1].col = 2; smArray[1].value = a[1];
    smArray[2].row = 1; smArray[2].col = 5; smArray[2].value = a[2];
    smArray[3].row = 2; smArray[3].col = 3; smArray[3].value = a[3];
    smArray[4].row = 5; smArray[4].col = 2; smArray[4].value = a[4];
}

template<class T>
void SparseMatrix<T>::init3(T *a)
{
    smArray[0].row = 0; smArray[0].col = 0; smArray[0].value = a[0];
    smArray[1].row = 0; smArray[1].col = 5; smArray[1].value = a[1];
    smArray[2].row = 2; smArray[2].col = 3; smArray[2].value = a[2];
    smArray[3].row = 3; smArray[3].col = 1; smArray[3].value = a[3];
    smArray[4].row = 4; smArray[4].col = 2; smArray[4].value = a[4];
    smArray[5].row = 5; smArray[5].col = 3; smArray[5].value = a[5];
    smArray[5].row = 5; smArray[5].col = 5; smArray[5].value = a[6];
}

template<class T>
void SparseMatrix<T>::Output()
{
    cout << "row\t" << "col\t" << "value" << endl;
    for(int i = 0; i < terms; i++)
        cout << smArray[i].row << "\t" << smArray[i].col << "\t" << smArray[i].value << endl;
}

int main(){
    int array1[] = {15,22,-15,11,3,-6,91,28};
    int array2[] = {-27,82,109,47,9};
    char Carray1[] = {'a','d','e','g','h','o','p'};

    SparseMatrix<char> charSM1(6,6,6);
    charSM1.init3(Carray1);
    charSM1.Output();
    SparseMatrix<char> TransSM1= charSM1.Transpose();
    TransSM1.Output();
    
    SparseMatrix<int> intSM1(6,6,8) , intSM2(6,6,5);
    intSM1.init1(array1);
    intSM2.init2(array2);
    SparseMatrix<int> intSM3 = intSM1.Add(intSM2);
    intSM3.Output();
    SparseMatrix<int> intSM4 = intSM1.Mul(intSM3);
    intSM4.Output();
}