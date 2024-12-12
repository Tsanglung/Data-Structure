//�ѹ����g�c���D(mazing problem)
// 1 : ����
// 0 : �i�H�������|
#include<iostream>
#include<fstream>
#include"Stack.h"
using namespace std;

struct offsets{int a , b;};//��ܤ�V������
enum directions{N,NE,E,SE,S,SW,W,NW};//�_�B��_�B��B��n�B�n�B�F�n�B�F�B�F�_
offsets moving[8];
struct items{int x , y , dir;};//���� position �M directions

ostream& operator<<(ostream& os, items& item)
{   //��X�g�c
   return os << item.x << "," << item.y << ","  << item.dir;
}

int maze[100][100]; // two dimensional array
int mark[100][100]; // ������F�� position

void Path(const int m, const int p)
{   //output a path (if any) in the maze
    // maze[0][i] = maze[m+1][i]
    ofstream outFile("stack.pos", ios::out);

    mark[1][1] = 1; //start at (1,1)
    Stack<items> stack(m * p);
    items temp;
    temp.x = 1,temp.y = 1,temp.dir = E;//set (x,y,dir) �_�I�B��V
    stack.Push(temp);
    while(!stack.IsEmpty())
    {
        temp = stack.Top();
        stack.Pop();
        int i = temp.x , j = temp.y , d = temp.dir;//��U�� position �M directions
        while(d < 8) // move forward
        {
            outFile << i << " " << j << " " << d << endl;
            int g = i + moving[d].a , h = j + moving[d].b;//if we are at position [i][j] in the maze and wish to find position [g][h] that is (�F�B��...?) of us
            if((g == m) && (h == p)) // ��F�X�f
            {   // ���| path
                stack.Output();
                cout << i << " " << j << endl;//last squares on the path
                cout << m << " " << p << endl;// exit position
                return;
            }
            if((!maze[g][h]) && (!mark[g][h]))// �p�G�s��m�i���B���X��
            {  
                mark[g][h] = 1;//�аO�w���L
                temp.x = i, temp.y = j, temp.dir = d + 1;//new position and direction
                stack.Push(temp);
                i = g , j = h , d = N;// new position and direction
            }
            else d++;// next direction
        }
    }
    cout << "No path in maze." << endl;
}

int main()
{
   ifstream inFile( "Maze.in", ios::in);

    moving[N].a = -1; moving[N].b = 0;
    moving[NE].a = -1; moving[NE].b = 1;
    moving[E].a = 0; moving[E].b = 1;
    moving[SE].a = 1; moving[SE].b = 1;
    moving[S].a = 1; moving[S].b = 0;
    moving[SW].a = 1; moving[SW].b = -1;
    moving[W].a =  0; moving[W].b = -1;
    moving[NW].a = -1; moving[NW].b = -1;

    char ch;
    for (int i = 0; i < 14; i++)// read maze
        for (int j = 0; j < 17; j++)
       {
	        if ( (!i) || (!j) || (i == 13) || (j == 16))  maze[i][j] = 1;
	        else {
	            inFile >> ch;
	            maze[i][j] = ch - '0';
	        }
	        mark[i][j] = 0;
       }
    for (int i = 0; i <= 13; i++)
    {
        for (int j = 0; j <= 16; j++)
	        cout << maze[i][j] << " ";
        cout << endl;
    }
    Path(12, 15);// exit(12,15)
}