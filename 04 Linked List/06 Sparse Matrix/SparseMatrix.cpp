#include<iostream>
#include<fstream>
using namespace std;
struct Triple{int value, row, col;};
class Matrix; // forward declaration
class MatrixNode
{
    friend class Matrix;
    friend istream& operator>>(istream&, Matrix&); 
    friend ostream& operator<<(ostream&, Matrix&);
private:
    MatrixNode *down, *right; //���V�U�Ӧ�m
    bool head; //head
    union { 
	    MatrixNode *next;
	    Triple triple;
    };
    MatrixNode(bool, Triple*);  // constructor
};

MatrixNode::MatrixNode(bool b, Triple* t)
{
    head = b;
    if (b) {right = next = this;} // row/column head node
    else triple = *t;  // node for list
}

class Matrix {
    friend istream& operator>>(istream&, Matrix& m); //Ū��
    friend ostream& operator<<(ostream&, Matrix& m); //��X
private:
   MatrixNode *headnode;
public:
   ~Matrix();
};

istream& operator>>(istream& is,Matrix& matrix){
    Triple s;   int p;
    is >> s.row >> s.col >> s.value; // matrix �j�p�� value �ƶq
    if (s.row > s.col) p = s.row; else p = s.col;
    matrix.headnode = new MatrixNode(false, &s); // set head node
    if (p == 0) { matrix.headnode->right = matrix.headnode; return is;}
    MatrixNode **head = new MatrixNode *[p];
    for (int i = 0; i < p; i++)
	    head[i]  = new MatrixNode(true, 0);
    int currentRow = 0;MatrixNode *last = head[0];// last node
    for(int i = 0; i < s.value; i++){   // input
        Triple t;
        is >> t.row >> t.col >> t.value;
        if(t.row > currentRow){
            last->right = head[currentRow];
            currentRow = t.row;
            last = head[currentRow];
        }
        last = last -> right = new MatrixNode(false, &t);// link new node row list
        head[t.col] -> next = head[t.col] -> next -> down = last;   // link new node col list
    }
    last ->right = head[currentRow];
    for(int i = 0; i < s.col; i++)  head[i] -> next -> down =head[i];
    for(int i = 0; i < p - 1 ;i++)  head[i] -> next = head[i + 1];
    head[p - 1] -> next = matrix.headnode;
    matrix.headnode->right =  head[0];
    delete [] head;
    return is;
}

ostream& operator<<(ostream& os, Matrix& matrix) {
    if (!matrix.headnode) return os;    
    //���o matrix size
    int numRows = matrix.headnode->triple.row;
    int numCols = matrix.headnode->triple.col;
    // bool �]�w���Ǧ�m���D 0 ��
    bool** hasValue = new bool*[numRows];
    for (int i = 0; i < numRows; ++i) 
        hasValue[i] = new bool[numCols]{false};
    // ���X matrix�A�üаO���ȱo��m
    MatrixNode* head = matrix.headnode->right;
    while (head != matrix.headnode) {
        MatrixNode* current = head->right;
        while (current != head) {
            hasValue[current->triple.row][current->triple.col] = true;
            current = current->right;
        }
        head = head->next;
    }

    //��X�A�L�Ȧ�m�A�� 0
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            bool found = false;
            head = matrix.headnode->right;
            while (head != matrix.headnode) {
                MatrixNode* current = head->right;
                while (current != head) {
                    if (current->triple.row == i && current->triple.col == j) {
                        os << current->triple.value << " ";
                        found = true; //���ȡA�]�� true
                        break;
                    }
                    current = current->right;//��U�@�Ӧ�m
                }
                if (found) break;
                head = head->next;
            }
            if (!found) os << "0 ";//�L�ȡA�� 0
        }
        os << endl;
    }

    for (int i = 0; i < numRows; ++i) //�M�� bool �}�C
        delete[] hasValue[i];
    delete[] hasValue;
    return os;
}

MatrixNode *av = 0;

Matrix::~Matrix()
{   // Delete a sparse matrix
    if (!headnode) return; // no nodes
    MatrixNode *x = headnode->right, *y;
    headnode->right = av; av = headnode; // return headnode
    while (x != headnode) { // �M�� rows
	    y = x -> right;
	    x -> right = av;
	    av = y;
	    x = x -> next; // next row
    }
    headnode = 0;
}

int main(){
    ifstream inFile( "SparseMatrix.in", ios::in);
    Matrix m;
    inFile >> m;
    cout << m;
}