#include "MyRectangle.h"
#include <iostream>
using namespace std;

int main() {
    // 測試 MyRectangle 的功能
    MyRectangle r1(0, 0, 10, 20, "Red"); // 初始化矩形

    // 輸出矩形的屬性
    cout << r1 << endl;

    // 計算面積和周長
    cout << "Area: " << r1.GetArea() << endl;
    cout << "Perimeter: " << r1.GetPerimeter() << endl;

    // 從輸入創建新的矩形
    MyRectangle newR;
    cin >> newR;
    cout << "New Rectangle: " << newR << endl;

    return 0;
}