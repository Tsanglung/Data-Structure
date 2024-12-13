#ifndef INTOPOSTFIX_H
#define INTOPOSTFIX_H

#include<iostream>
#include"Stack.h"
using namespace std;

enum TokenType { UNARY_MINUS ,OPERAND, OPERATOR, END };//運算元、運算子、#
struct Token{
    TokenType type;
    string value;
};

class Expressions
{
public:
    Expressions(string);
    void Postfix(Expressions e);//converting from infix to postfix form
    Token NextToken(Expressions e);// get the next token
    int isp(Token);
    int icp(Token);
private:
    string expression;
    size_t index;
};

#include"IntoPostfix.cpp"
#include"Stack.cpp"
#endif