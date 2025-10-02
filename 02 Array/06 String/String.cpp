#include"String.h"
#include<string.h>
//初始化 *this to string init of length m
String::String(const char *init, int m):len(m)
{
    str = new char[m + 1];
    if(init) strncpy(str, init, m);
    str[m] = '\0';
    f = nullptr;
}
//若 *this 等於 t，return true
bool String::operator==(String t)
{
    if(len == t.len) return strcmp(str, t.str) == 0;
    else return false;
}
//若 *this 為空，則 return true
bool String::operator!(){return len == 0;}
//number of characters
int String::Length(){return len;}
// return a string whose elements are those of *this followed by those of t.
String String::Concat(String t)
{   //合併 *this、t
    char *concatStr = new char[len + t.len + 1];
    strcpy(concatStr, str);
    strcat(concatStr, t.str);
    return String(concatStr, len + t.len);
}
//return a string containing the j characters of *this at positions i, i+1,...
//i + j - 1 if these are valid positions of *this;otherwise,throw an exception.
String String::Substr(int i, int j)
{   //從 i 開始，length j 的子字串
    if(i < 0 || j < 0 || i + j > len) throw out_of_range("Invalid substring");
    char *subStr = new char[j + 1];
    strncpy(subStr, str + i, j);
    subStr[j] = '\0';
    return String(subStr, j);
}

int String::Find(String pat)
{   //program 2.16 Determine if pat is a substring of s.
    int posP = 0, posS = 0;
    int lengthP = pat.Length(), lengthS = Length();
    while((posP < lengthP) && (posS < lengthS))
        if(pat.str[posP] == str[posS]){
            posP++;posS++;
        }
        else
            if(posP == 0) posS++;
            else posP = pat.f[posP - 1] + 1;
    return (posP < lengthP) ? -1 : posS - lengthP;
}

void String::FailureFunction()
{
    int lengthP = Length();
    delete [] f;
    f = new int[lengthP];
    f[0] = -1;
    for(int j = 1; j < lengthP; j++)
    {
        int i = f[j - 1];
        while((*(str + j) != *(str + i + 1)) && (i >= 0)) i = f[i];
        if(*(str + j) == *(str + i + 1)) f[j] = i + 1;
        else f[j] = -1;
    }
}

char *String::GetStr() const{return str;}