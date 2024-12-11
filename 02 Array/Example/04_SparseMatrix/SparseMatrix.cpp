#include"SparseMatrix.h"

template<class T> //初始化
SparseMatrix<T>::SparseMatrix(int r, int c,int t):rows(r),cols(c),terms(t),capacity(t){smArray = new MatrixTerm<T>[capacity];}
template<class T> //釋放記憶體
SparseMatrix<T>::~SparseMatrix(){delete[] smArray;}

template <class T>
void SparseMatrix<T>::StoreSum(const int sum, const int r, const int c)
{   //program 2.12 // 儲存非零項
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
{   //program 2.13 // 確保newSize >= 非0項數
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
        int *rowSize = new int[cols](); // 每列的非零項數
        int *rowStart = new int[cols](); // 每列的起始位置
        fill(rowSize, rowSize + cols, 0); // 初始化
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
    SparseMatrix<T> d(rows, cols, 0); // 初始化結果矩陣
    d.capacity = terms + b.terms;    // 設置足夠的容量
    d.smArray = new MatrixTerm<T>[d.capacity];
    int aPos = 0, bPos = 0, rPos = 0; // 分別指向 A、B 和結果矩陣的位置
    // 遍歷兩個矩陣的元素
    while (aPos < terms && bPos < b.terms) {
        if (smArray[aPos].row < b.smArray[bPos].row ||
           (smArray[aPos].row == b.smArray[bPos].row && smArray[aPos].col < b.smArray[bPos].col)) {
            // A 的當前元素在 B 的當前元素之前
            d.smArray[rPos++] = smArray[aPos++];
        } else if (smArray[aPos].row > b.smArray[bPos].row ||
                  (smArray[aPos].row == b.smArray[bPos].row && smArray[aPos].col > b.smArray[bPos].col)) {
            // B 的當前元素在 A 的當前元素之前
            d.smArray[rPos++] = b.smArray[bPos++];
        } else {
            // A 和 B 的當前元素對應同一位置，計算和
            T sum = smArray[aPos].value + b.smArray[bPos].value;
            if (sum != 0) { // 確保非零元素被加入結果矩陣
                d.smArray[rPos].row = smArray[aPos].row;
                d.smArray[rPos].col = smArray[aPos].col;
                d.smArray[rPos].value = sum;
                rPos++;
            }
            aPos++;
            bPos++;
        }
    }
    // 將 A 矩陣剩餘的元素加入結果
    while (aPos < terms) {
        d.smArray[rPos++] = smArray[aPos++];
    }
    // 將 B 矩陣剩餘的元素加入結果
    while (bPos < b.terms) {
        d.smArray[rPos++] = b.smArray[bPos++];
    }
    // 更新結果矩陣的非零元素數
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
    { //產生 d 的 row currentRowA
        int currColB = bXpose.smArray[0].row;
        int currColIndex = 0;
        while(currColIndex <= b.terms)
        {   //*this 的 row 乘 b 的 col
            if(smArray[currRowIndex].row != currRowA)
            {   //end of row currRowA
                d.StoreSum(sum, currRowA, currColB);
                sum = 0;
                currRowIndex = currRowBegin;
                while(bXpose.smArray[currColIndex].row == currColB) currColIndex++;//下一行
                currColB = bXpose.smArray[currColIndex].row;
            }
            else if(bXpose.smArray[currColIndex].row != currColB)
            {   //end of col currColB
                d.StoreSum(sum, currRowA, currColB);
                sum = 0;
                currRowIndex = currRowBegin;//row currRowA * 下一行
                currColB = bXpose.smArray[currColIndex].row;
            }
            else
            {
                if(smArray[currRowIndex].col < bXpose.smArray[currColIndex].col) currRowIndex++;//下一列的非0項
                else if(smArray[currRowIndex].col == bXpose.smArray[currColIndex].col)
                { //加總
                    sum += smArray[currRowIndex].value * bXpose.smArray[currColIndex].value;
                    currRowIndex++;currColIndex++;
                }
                else currColIndex++;
            }
        }// end of while(currColIndex <= b.terms)
        while(smArray[currRowIndex].row == currRowA) currRowIndex++;//下一列
        currRowBegin = currRowIndex;
        currRowA = smArray[currRowIndex].row;
    }
    return d;
}

// 運算子重載：讀入矩陣
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

// 運算子重載：輸出矩陣
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