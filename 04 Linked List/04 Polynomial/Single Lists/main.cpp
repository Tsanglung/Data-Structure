#include <iostream>
#include <fstream>
#include "poly.h"
using namespace std;

int main() {
    Polynomial A, B;
    //Ū�� .in �ɪ��h�����Y�ơB����
    ifstream inputFile("Poly.in", ios::in);
    if (!inputFile.is_open()) {
        cerr << "can't open file..." << endl;
        return 1;
    } 
    inputFile >> A;
    cout << "A(x) = " << A << endl;
    inputFile >> B;
    cout << "B(x) = " << B << endl;
    inputFile.close(); //�����ɮ�

    Polynomial C = A + B;
    cout << "C(x) = A(x) + B(x) = " << C << endl;

    return 0;
}
