#include "MyRectangle.h"
#include <iostream>
using namespace std;

int main() {
    // ���� MyRectangle ���\��
    MyRectangle r1(0, 0, 10, 20, "Red"); // ��l�Ưx��

    // ��X�x�Ϊ��ݩ�
    cout << r1 << endl;

    // �p�⭱�n�M�P��
    cout << "Area: " << r1.GetArea() << endl;
    cout << "Perimeter: " << r1.GetPerimeter() << endl;

    // �q��J�Ыطs���x��
    MyRectangle newR;
    cin >> newR;
    cout << "New Rectangle: " << newR << endl;

    return 0;
}