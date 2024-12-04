#include<iostream>
using namespace std;

int main()
{
    int n = 10, x = 0, count = 0;
    //test 1
    for(int i = 1;i <= n; i++)
    {
        count++; //for for i
        for(int j = 1;j <= i; j++)
        {   
            count++; //for for j
            for(int k = 1; k <= j;k++)
            {
                count++; //for for k
                x++;
                count++; //for assignment
            }
            count++; //for last time of for k
        }
        count++; //for last time of for j
    }
    count++; //for last time of for i
    cout << "Test 1 Triple loop counts : " << count << endl;

    x = 0, count = 0;
    // test 2
    int i = 1;
    count++; //for int i
    while(i <= n)
    {
        count++; //for while
        x++;
        count++; //for assignment x
        i++;
        count++; //for assignment i
    }
    count++;//for last time of while
    cout << "Test 2 Triple loop counts : " << count << endl;
}