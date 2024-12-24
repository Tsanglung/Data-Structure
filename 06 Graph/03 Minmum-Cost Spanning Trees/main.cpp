#include<iostream>
#include"Graph.h"
using namespace std;

int main()
{
    adjListWeightUndirectedGraph G1(7);
	G1.InsertEdge(0, 1, 28);
	G1.InsertEdge(0, 5, 10);
	G1.InsertEdge(1, 2, 16);
	G1.InsertEdge(1, 6, 14);
	G1.InsertEdge(2, 3, 12);
	G1.InsertEdge(3, 4, 22);
	G1.InsertEdge(3, 6, 18);
	G1.InsertEdge(4, 5, 25);
	G1.InsertEdge(4, 6, 24);
    
	cout << "G1 的最小消耗樹 (Kruskal's algorithm) : " << endl;
	G1.Kruskal();
    cout << "G1 的最小消耗樹 (Prim's algorithm) : " << endl;
    G1.Prim();
    cout << "G1 的最小消耗樹 (Sollin's algorithm) : " << endl;
    G1.Sollin();
}