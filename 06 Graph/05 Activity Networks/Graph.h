#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<climits>
#include<algorithm>
#include<list>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Graph {
protected:
	int n, e;	//目前點的數量，邊的數量
public:
	bool IsEmpty() const {return n == 0;}
	int NumberOfVertices() const {return n;}
	int NumberOfEdges() const {return e;}
	virtual void InsertVertex(int v) = 0;
	virtual void InsertEdge(int u, int v,int w) = 0;
	virtual int Degree(int u) const = 0;
	virtual bool ExistsEdge(int u, int v) const = 0;
	virtual void DeleteVertex(int v) = 0;
	virtual void DeleteEdge(int u, int v) = 0;
};	

class adjListWeightDirectedGraph : public Graph{//鄰接串列表示的有權重有向圖
protected:
    vector<list<pair<int,int>>> vertices;//紀錄點與此點所連結的點和權重。串列為連結的點，儲存的pair為點與權重
    bool *visited;//紀錄是否走訪過節點
    int num;//biconnected要計算DFN與LOW的變數
    vector<int> *dfn, *low;//biconnected需要的變數
    stack<pair<int, pair<int, int>>> s;	//biconnected需要的堆疊
public:
    adjListWeightDirectedGraph(int v = 1);
    adjListWeightDirectedGraph(adjListWeightDirectedGraph& copy);
    void InsertVertex(int v);
    void InsertEdge(int u,int v,int w = 1);
    void InsertEdge(pair<int,pair<int,int>> edge);
    int Degree(int u) const;
    bool ExistsEdge(int u,int v) const;
    void DeleteVertex(int v);
    void DeleteEdge(int u,int v);
    void Topological();
    void showGraph();
};

#include "DirectedGraph.cpp"
#endif