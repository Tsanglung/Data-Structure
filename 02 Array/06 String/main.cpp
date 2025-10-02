#include<iostream>
#include"String.h"
using namespace std;

int main()
{
    // ﹍て﹃
    String s1("hello", 5);
    String s2("world", 5);

    // 代刚单笲衡
    if (s1 == s2) cout << "s1 and s2 are equal." << endl;
    else cout << "s1 and s2 are not equal." << endl;
    // 代刚琌
    if (!s1) cout << "s1 is empty." << endl;
    else cout << "s1 is not empty." << endl;

    cout << "Length of s1: " << s1.Length() << endl;
    String s3 = s1.Concat(s2);// ㄖ
    cout << "Concatenated string: " << s3.GetStr() << endl;
   
    try { // 代刚﹃
        String sub = s3.Substr(0, 5);
        cout << "Substring of s3: " << sub.GetStr() << endl;
    } catch (const out_of_range &e) {
        cerr << e.what() << endl;
    }
    // ﹃琩т
    String pattern("world", 5);
    pattern.FailureFunction();
    int position = s3.Find(pattern);
    if (position != -1) cout << "Pattern found at position: " << position << endl;
    else cout << "Pattern not found." << endl;

    return 0;
}