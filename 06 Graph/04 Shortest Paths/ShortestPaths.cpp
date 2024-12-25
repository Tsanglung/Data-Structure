#include<iostream>
#include "Graph.h"
using namespace std;

int main()
{
    adjListWeightDirectedGraph G1(6);
    G1.InsertEdge(0,1,50);
    G1.InsertEdge(0,2,45);
    G1.InsertEdge(0,3,10);
    G1.InsertEdge(1,2,10);
    G1.InsertEdge(1,3,15);
    G1.InsertEdge(2,4,30);
    G1.InsertEdge(3,0,20);
    G1.InsertEdge(3,4,15);
    G1.InsertEdge(4,1,20);
    G1.InsertEdge(4,2,35);
    G1.InsertEdge(5,4,3);
    cout << "G1 有權重有向圖 : " << endl;
    G1.showGraph();
    cout << "G1 的最短路徑 (Dijkstra's algorithm) : " << endl;
    G1.Dijkstra(6,0);

    adjListWeightDirectedGraph G2(7);
    G2.InsertEdge(0,1,6);
    G2.InsertEdge(0,2,5);
    G2.InsertEdge(0,3,5);
    G2.InsertEdge(1,4,-1);
    G2.InsertEdge(2,1,-2);
    G2.InsertEdge(2,4,1);
    G2.InsertEdge(3,2,-2);
    G2.InsertEdge(3,5,-1);
    G2.InsertEdge(4,6,3);
    G2.InsertEdge(5,6,3);
    cout << "G2 有權重有向圖 : " << endl;
    G2.showGraph();
    cout << "G2 的最短路徑 (Bellman-Ford algorithm) : " << endl;
    G2.BellmanFord(7,0);

    adjListWeightDirectedGraph G3(3);
    G3.InsertEdge(0,1,4);
    G3.InsertEdge(0,2,11);
    G3.InsertEdge(1,2,2);
    G3.InsertEdge(1,0,6);
    G3.InsertEdge(2,0,3);
    cout << "G3 有權重有向圖 : " << endl;
    G3.showGraph();
    cout << "G3 的最短路徑 (Floyd-Warshall algorithm) : " << endl;
    G3.FloydWarshall(3);
}
