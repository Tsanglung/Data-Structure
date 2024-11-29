#include <iostream>
using namespace std;
//排列組合 Permutation 
//Book p.31 Example 1.5
void Permutations(char* a, const int k, const int size) 
{ 	//Program 1.12
	if (k == size - 1) 
	{  // 輸出排列組合結果
		for (int i = 0; i < size; i++) cout << a[i] << " ";
		cout << endl;
	}
	else 
	{ 	// 遞迴
		for (int i = k; i < size; i++)   
		{	// 互換 a[k] and a[i]
			char temp = a[k]; 
			a[k] = a[i]; 
			a[i] = temp;
			Permutations(a, k + 1, size); 
			// 再次互換 a[k] and a[i] 
			temp = a[k]; 
			a[k] = a[i]; 
			a[i] = temp;
		}
	} 
} 

int main()
{
	char b[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	Permutations(b, 0, 3);// a , b , c 排列組合
	cout << endl;
	Permutations(b, 0, 5);//a ~ e 排列組合
	cout << endl;
}
