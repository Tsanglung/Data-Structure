#include<iostream>
#include"Graph.h"
using namespace std;

int main()
{
    adjListWeightDirectedGraph G1(6);
    G1.InsertEdge(0,1);
    G1.InsertEdge(0,2);
    G1.InsertEdge(0,3);
    G1.InsertEdge(1,4);
    G1.InsertEdge(2,4);
    G1.InsertEdge(2,5);
    G1.InsertEdge(3,4);
    G1.InsertEdge(3,5);
    cout << "G1 有權重有向圖 : " << endl;
    G1.showGraph();
    cout << "G1 Topologiacl Order : " << endl;
    G1.Topological();

    adjListWeightDirectedGraph G2(9);
    G2.InsertEdge(0,1,6);
    G2.InsertEdge(0,2,4);
    G2.InsertEdge(0,3,5);
    G2.InsertEdge(1,4,1);
    G2.InsertEdge(2,4,1);
    G2.InsertEdge(3,5,2);
    G2.InsertEdge(4,6,9);
    G2.InsertEdge(4,7,7);
    G2.InsertEdge(5,7,4);
    G2.InsertEdge(6,8,2);
    G2.InsertEdge(7,8,4);
    cout << "G2 有權重有向圖 : " << endl;
    G2.showGraph();
    cout << "G2 Topologiacl Order : " << endl;
    G2.Topological();

}