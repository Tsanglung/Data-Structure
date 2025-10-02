#include<iostream>
#include"Rectangle.h"
using namespace std;

/*
exercise 1. overload operator < for class rectangle such the r < s if and only if the area of r is less than that of s.
*/

int main(){
    Rectangle r(1, 1, 3, 4);//����r
	Rectangle s(2, 4, 6, 8);//����s
	Rectangle* t = &s; //�� s �}��ȵ� t�A�q�L t �X�ݩΧ�� s ���󪺦���
    // use . to access members of class object.
    //use -> to access members of class object through pointers.
	if (r.GetHeight() * r.GetWidth() > t->GetHeight() * t->GetWidth())
		cout << r;
	else cout << s;

	if(r < s) cout << "Rectaegle r less than Rectangle s" << endl;
	else cout << "Rectaegle r > Rectangle s" << endl;
}