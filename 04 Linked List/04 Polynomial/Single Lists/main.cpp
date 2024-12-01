#include <iostream>
#include <fstream>
#include "poly.h"
using namespace std;

int main() {
    Polynomial A, B;
    //讀取 .in 檔的多項式係數、指數
    ifstream inputFile("Poly.in", ios::in);
    if (!inputFile.is_open()) {
        cerr << "can't open file..." << endl;
        return 1;
    } 
    inputFile >> A;
    cout << "A(x) = " << A << endl;
    inputFile >> B;
    cout << "B(x) = " << B << endl;
    inputFile.close(); //關閉檔案

    Polynomial C = A + B;
    cout << "C(x) = A(x) + B(x) = " << C << endl;

    return 0;
}
