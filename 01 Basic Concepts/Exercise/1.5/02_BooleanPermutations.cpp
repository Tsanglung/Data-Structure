/*
given n Boolean variables x_1,x_2,...,x_n we wish to print all possible combinations of truth values they can assume. 
For insrance, if n = 2,there are four possibilties:t,t;t,f;f,t;f,f.
n 個 boolean 變數，會有 2^n - 1 種組合
ex. 00, 01, 10, 11, ....
*/
#include<iostream>
#include<math.h>
#include<string>
using namespace std;
string binary = "";
void BooleanPermutations(int n, int t){
    for(int i = 0; i <= t; i++){
        for(int j = n - 1;j >= 0; j--){
            binary += ((i >> j) & 1) ? '1' : '0';
        }
        cout << binary <<endl;
    }
}

int main(){
    int n;
    cout << "Give n Boolean variables : ";
    cin >> n;
    int total_possible = pow(2, n) - 1;
    BooleanPermutations(n, total_possible);
    //cout << binary.size();// n * 2^n
    for(int count = 1; count <= binary.size(); count++){
        if((count - 1) % n == 0) cout << '(';
        if(count % n != 0){
            if(binary[count - 1] == '0') cout << "false , ";
            else if(binary[count - 1] == '1') cout << "true , "; 
        }
        else if(count % n == 0){
            if(binary[count - 1] == '0') cout << "false)" << endl;
            else if(binary[count - 1] == '1') cout << "true)" << endl;
        }
    }
}