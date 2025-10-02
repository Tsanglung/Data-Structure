#include<iostream>
#include"Complex.h"
using namespace std;

int main() 
{
	Complex C1, C2(3,2), C3, C4;
	cin >> C3;//5 3
	cin >> C4;//0 0
	Complex C5 = C1 + C2;//3 2
	cout << C5;
	Complex C6 = C3 - C5;//2 1
	cout << C6;
	Complex C7 = C6 * C5;//4 7
	cout << C7;
	Complex C8 = C7 / C6;
	cout << C8;
}