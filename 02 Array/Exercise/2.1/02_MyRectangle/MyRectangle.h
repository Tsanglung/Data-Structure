#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include<iostream>
#include<string>
#include"Rectangle.h"
using namespace std;

class MyRectangle : public Rectangle{
    friend ostream& operator<<(ostream&, MyRectangle& ); // 重載輸出運算子
    friend istream& operator>>(istream&, MyRectangle& ); // 重載輸入運算子
public:
    MyRectangle(int , int , int , int , const string& ); // 建構函數
    ~MyRectangle(); // 解構函數

    // 成員函數
    string GetColor();            // 獲取顏色
    int GetArea();                // 計算面積
    int GetPerimeter();           // 計算周長

private:
    string color; // 顏色成員變數
};

#include"MyRectangle.cpp"
#endif