#include<iostream>
#include <fstream>
#include <chrono>
#include"Poly.h"

using namespace std;
using namespace std::chrono;

void TestPerformance(const Polynomial& A, const Polynomial& B)
{
    Polynomial Eval;
    float in; 
    auto start1 = high_resolution_clock::now();
    Eval = A + B;
    cout << "A(x) + B(x) = " << Eval;
    cout << "x = ? ";
    cin >> in;
    cout << "Eval("<<in<<") = A("<<in<<") + B("<<in<<")= " << Eval.Evaluate(in) << endl;
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Add Time:: " << duration1.count() << " microseconds" << endl;

    auto start2 = high_resolution_clock::now();
    Eval = A - B;
    cout << "A(x) - B(x) = " << Eval;
    cout << "x = ? ";
    cin >> in;
    cout << "Eval("<<in<<") = A("<<in<<") - B("<<in<<")= " << Eval.Evaluate(in) << endl;
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Sub Time:: " << duration2.count() << " microseconds" << endl;

    auto start3 = high_resolution_clock::now();
    Eval = A * B;
    cout << "A(x) * B(x) = " << Eval;
    cout << "x = ? ";
    cin >> in;
    cout << "Eval("<<in<<") = A("<<in<<") * B("<<in<<")= " << Eval.Evaluate(in) << endl;
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Mul Time:: " << duration3.count() << " microseconds" << endl;
}

int main(void)
{  //����J����
    //�A��J�Y�� ���� \n
    Polynomial A, B;

    //Ū��.in�ɪ��h�����Y�ơB����
    ifstream inputFile("polynomials.in",ios::in);
    if (!inputFile.is_open()) {
        cerr << "can't open file..." << endl;
        return 1;
    }
    inputFile >> A;
    cout << "A(x) = " << A << endl;
    inputFile >> B;
    cout << "B(x) = " << B << endl;

    /*cout << "First polynomial A(x): ";//��J����
    cin >> A;//��J�h����
    cout << "A(x) = " << A << endl;
    Polynomial K(A);//copy �غc�l
    cout << "Copy Constructor A(x) : " << K;
    cout << "\nSecond polynomial B(x): ";//��J����
    cin >> B;//��J�h����
    cout << "B(x) = " << B << endl;
    cout<<endl;*/
    TestPerformance(A,B);
    inputFile.close();//�����ɮ�
    return 0;
}