#include"SparseMatrix.h"

template<class T> //��l��
SparseMatrix<T>::SparseMatrix(int r, int c,int t):rows(r),cols(c),terms(t),capacity(t){smArray = new MatrixTerm<T>[capacity];}
template<class T> //����O����
SparseMatrix<T>::~SparseMatrix(){delete[] smArray;}

template <class T>
void SparseMatrix<T>::StoreSum(const int sum, const int r, const int c)
{   //program 2.12 // �x�s�D�s��
    if(sum != 0)
    {
        if(terms == capacity) ChangeSize1D(2 * capacity + 1);
        smArray[terms].row = r;
        smArray[terms].col = c;
        smArray[terms++].value = sum;
    }
}

template<class T>
void SparseMatrix<T>::ChangeSize1D(const int newSize)
{   //program 2.13 // �T�OnewSize >= �D0����
    if(newSize < terms) throw "New size must be >= number of terms";
    MatrixTerm<T> *temp = new MatrixTerm<T>[newSize];
    copy(smArray, smArray + terms, temp);
    delete [] smArray;
    smArray = temp;
    capacity = newSize;
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::Transpose()
{   //Program 2.10
    SparseMatrix<T> b(cols , rows , terms);
    if(terms > 0)
    {
        int *rowSize = new int[cols](); // �C�C���D�s����
        int *rowStart = new int[cols](); // �C�C���_�l��m
        fill(rowSize, rowSize + cols, 0); // ��l��
        for(int i = 0; i < terms; i++) rowSize[smArray[i].col]++;
        rowStart[0] = 0;//start of row i in b
        for(int i = 1; i < cols; i++) rowStart[i] = rowStart[i-1] + rowSize[i-1];
        for(int i = 0; i < terms; i++)
        { //copy from *this to b
            int j = rowStart[smArray[i].col];
            b.smArray[j].row = smArray[i].col;
            b.smArray[j].col = smArray[i].row;
            b.smArray[j].value = smArray[i].value;
            rowStart[smArray[i].col]++;
        }
        delete [] rowSize;
        delete [] rowStart;
    }
    return b;
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::Add(SparseMatrix<T> b)
{
    SparseMatrix<T> d(rows, cols, 0); // ��l�Ƶ��G�x�}
    d.capacity = terms + b.terms;    // �]�m�������e�q
    d.smArray = new MatrixTerm<T>[d.capacity];
    int aPos = 0, bPos = 0, rPos = 0; // ���O���V A�BB �M���G�x�}����m
    // �M����ӯx�}������
    while (aPos < terms && bPos < b.terms) {
        if (smArray[aPos].row < b.smArray[bPos].row ||
           (smArray[aPos].row == b.smArray[bPos].row && smArray[aPos].col < b.smArray[bPos].col)) {
            // A ����e�����b B ����e�������e
            d.smArray[rPos++] = smArray[aPos++];
        } else if (smArray[aPos].row > b.smArray[bPos].row ||
                  (smArray[aPos].row == b.smArray[bPos].row && smArray[aPos].col > b.smArray[bPos].col)) {
            // B ����e�����b A ����e�������e
            d.smArray[rPos++] = b.smArray[bPos++];
        } else {
            // A �M B ����e���������P�@��m�A�p��M
            T sum = smArray[aPos].value + b.smArray[bPos].value;
            if (sum != 0) { // �T�O�D�s�����Q�[�J���G�x�}
                d.smArray[rPos].row = smArray[aPos].row;
                d.smArray[rPos].col = smArray[aPos].col;
                d.smArray[rPos].value = sum;
                rPos++;
            }
            aPos++;
            bPos++;
        }
    }
    // �N A �x�}�Ѿl�������[�J���G
    while (aPos < terms) {
        d.smArray[rPos++] = smArray[aPos++];
    }
    // �N B �x�}�Ѿl�������[�J���G
    while (bPos < b.terms) {
        d.smArray[rPos++] = b.smArray[bPos++];
    }
    // ��s���G�x�}���D�s������
    d.terms = rPos;
    return d;
}

template<class T>
SparseMatrix<T> SparseMatrix<T>::Multiply(SparseMatrix<T> b)
{
    SparseMatrix<T> bXpose = b.Transpose();
    SparseMatrix<T> d(rows,b.cols,0);
    int currRowIndex = 0, currRowBegin = 0, currRowA = smArray[0].row;
    if(terms == capacity) ChangeSize1D(terms + 1);
    bXpose.ChangeSize1D(bXpose.terms + 1);
    smArray[terms].row = rows;
    bXpose.smArray[b.terms].row = b.cols;
    bXpose.smArray[b.terms].col = -1;
    int sum = 0;
    while(currRowIndex < terms)
    { //���� d �� row currentRowA
        int currColB = bXpose.smArray[0].row;
        int currColIndex = 0;
        while(currColIndex <= b.terms)
        {   //*this �� row �� b �� col
            if(smArray[currRowIndex].row != currRowA)
            {   //end of row currRowA
                d.StoreSum(sum, currRowA, currColB);
                sum = 0;
                currRowIndex = currRowBegin;
                while(bXpose.smArray[currColIndex].row == currColB) currColIndex++;//�U�@��
                currColB = bXpose.smArray[currColIndex].row;
            }
            else if(bXpose.smArray[currColIndex].row != currColB)
            {   //end of col currColB
                d.StoreSum(sum, currRowA, currColB);
                sum = 0;
                currRowIndex = currRowBegin;//row currRowA * �U�@��
                currColB = bXpose.smArray[currColIndex].row;
            }
            else
            {
                if(smArray[currRowIndex].col < bXpose.smArray[currColIndex].col) currRowIndex++;//�U�@�C���D0��
                else if(smArray[currRowIndex].col == bXpose.smArray[currColIndex].col)
                { //�[�`
                    sum += smArray[currRowIndex].value * bXpose.smArray[currColIndex].value;
                    currRowIndex++;currColIndex++;
                }
                else currColIndex++;
            }
        }// end of while(currColIndex <= b.terms)
        while(smArray[currRowIndex].row == currRowA) currRowIndex++;//�U�@�C
        currRowBegin = currRowIndex;
        currRowA = smArray[currRowIndex].row;
    }
    return d;
}

// �B��l�����GŪ�J�x�}
template <class T>
istream &operator>>(istream &is, SparseMatrix<T> &matrix) 
{
    is >> matrix.rows >> matrix.cols >> matrix.terms;
    delete[] matrix.smArray;
    matrix.capacity = max(matrix.terms, 1);
    matrix.smArray = new MatrixTerm<T>[matrix.capacity];
    for (int i = 0; i < matrix.terms; ++i)
        is >> matrix.smArray[i].row >> matrix.smArray[i].col >> matrix.smArray[i].value;
    return is;
}

// �B��l�����G��X�x�}
template <class T>
ostream &operator<<(ostream &os, const SparseMatrix<T> &matrix) 
{
    os << "row\tcol\tvalue\n";
    for (int i = 0; i < matrix.terms; ++i) {
        os << matrix.smArray[i].row << '\t'
           << matrix.smArray[i].col << '\t'
           << matrix.smArray[i].value << '\n';
    }
    return os;
}