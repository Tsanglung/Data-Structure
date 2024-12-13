#include<iostream>
#include"IntoPostfix.h"
using namespace std;

int main()
{
    Expressions in("((A*B)*C)");
    in.Postfix(in);
    Expressions in2("-A+B-C+D");
    in2.Postfix(in2);
    Expressions in3("A*-B+C");
    in3.Postfix(in3);
    Expressions in4("(A+B)*D+E/(F+A*D)+C");
    in4.Postfix(in4);
    Expressions in5("A&&B||C||!(E>F)");
    in5.Postfix(in5);
}