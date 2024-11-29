#include <iostream>
using namespace std;
//�ƦC�զX Permutation 
//Book p.31 Example 1.5
void Permutations(char* a, const int k, const int size) 
{ 	//Program 1.12
	if (k == size - 1) 
	{  // ��X�ƦC�զX���G
		for (int i = 0; i < size; i++) cout << a[i] << " ";
		cout << endl;
	}
	else 
	{ 	// ���j
		for (int i = k; i < size; i++)   
		{	// ���� a[k] and a[i]
			char temp = a[k]; 
			a[k] = a[i]; 
			a[i] = temp;
			Permutations(a, k + 1, size); 
			// �A������ a[k] and a[i] 
			temp = a[k]; 
			a[k] = a[i]; 
			a[i] = temp;
		}
	} 
} 

int main()
{
	char b[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	Permutations(b, 0, 3);// a , b , c �ƦC�զX
	cout << endl;
	Permutations(b, 0, 5);//a ~ e �ƦC�զX
	cout << endl;
}
