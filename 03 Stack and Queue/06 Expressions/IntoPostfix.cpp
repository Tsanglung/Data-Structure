#include"IntoPostfix.h"
Expressions::Expressions(string ex) : expression(ex), index(0){}

void Expressions::Postfix(Expressions e)//converting from infix to postfix form
{  //It is assumed that the last token(a token is either an operator, operand, or '#') in e is '#'. 
    //A function NextToken is used to get the next token from e. 
    index = 0;
    Stack<Token> stack(e.expression.size());//init
    stack.Push({END, "#"});
    for(Token x = NextToken(e); x.type != END; x = NextToken(e))
    {
        if(x.type == OPERAND) cout << x.value;
        else if( x.value == ")")
        {   //unstack until "("
            for(;stack.Top().value != "("; stack.Pop()) cout << stack.Top().value;
            stack.Pop();
        }
        else
        {  // x is an operator
            // isp : in-stack priority、icp : in-coming priority
            for(;isp(stack.Top()) <= icp(x); stack.Pop()) cout << stack.Top().value;
            stack.Push(x);
        }
    }
    for(;!stack.IsEmpty() && stack.Top().value != "#";cout<<stack.Top().value ,stack.Pop());//end, empty the stack
    stack.Pop();
    cout << endl;
}

Token Expressions::NextToken(Expressions e)
{
    if (index >= e.expression.size()) return {END, "#"};  // 如果讀取完所有字元，返回結束字元 #
    char c = e.expression[index++];
    if (c == '(' || c == ')') return {OPERATOR, string(1, c)};// 如果是括號，返回對應的 Token
    else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '!' || c == '=' || c == '<' || c == '>' || c == '&' || c == '|') 
    {
        string op(1, c);
        // 處理複合運算子
        if (index < e.expression.size()) 
        {
            char next = e.expression[index];
            if ((c == '<' || c == '>' || c == '=' || c == '!') && next == '=') {
                op += next;
                index++;
            } else if (c == '&' && next == '&') {
                op += next;
                index++;
            } else if (c == '|' && next == '|') {
                op += next;
                index++;
            }
        }
        // 檢查是否為一元運算元 -、!
        if ((op == "-" || op == "!") && (index == 1 || e.expression[index - 2] == '(' || 
             e.expression[index - 2] == '+' || e.expression[index - 2] == '-' || e.expression[index - 2] == '*' || e.expression[index - 2] == '/' || 
             e.expression[index - 2] == '%' || e.expression[index - 2] == '&' || e.expression[index - 2] == '|' || e.expression[index - 2] == '!')) 
            return {UNARY_MINUS, op}; // 一元運算子

        return {OPERATOR, op}; // 普通二元運算子
    }
    else return {OPERAND, string(1, c)}; // 運算元，返回對應的 Token
}

int Expressions::isp(Token t)
{   // isp : in-stack priority
    if(t.type == UNARY_MINUS) return 1;
    else if(t.value == "*" || t.value == "/" || t.value == "%") return 2;
    else if(t.value == "+" || t.value == "-") return 3;
    else if (t.value == "<" || t.value == "<=" || t.value == ">" || t.value == ">=") return 4;
    else if (t.value == "==" || t.value == "!=") return 5;
    else if (t.value == "&&") return 6;
    else if (t.value == "||") return 7;
    else if(t.value == "(" || t.value == "#") return 8;
    return -1;
}

int Expressions::icp(Token t)
{   //in-coming priority
    if(t.value == "(") return 0;
    else if(t.type == UNARY_MINUS) return 1;
    else if(t.value == "*" || t.value == "/" || t.value == "%") return 2;
    else if(t.value == "+" || t.value == "-") return 3;
    else if (t.value == "<" || t.value == "<=" || t.value == ">" || t.value == ">=") return 4;
    else if (t.value == "==" || t.value == "!=") return 5;
    else if (t.value == "&&") return 6;
    else if (t.value == "||") return 7;
    return -1;
}