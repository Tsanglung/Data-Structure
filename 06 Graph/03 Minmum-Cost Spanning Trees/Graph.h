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

class adjListWeightUndirectedGraph : public Graph 
{//有權重的無向圖
protected:
    vector<list<pair<int,int>>> vertices;
    //vector<list<pair<節點,權重>>> vector 每個元素對應的節點
    //list<pair<節點,權重>>用list儲存每個節點的 adjacency List
    bool *visit; //紀錄是否走訪過節點
    int num; //biconnected component 計算 dfn、low的變數
    vector<int> *dfn/*depth-first number : 表示節點被走訪的次序*/, *low/*lowest depth-first number : 能通過 back edge 或 child tree's edge 回到最早走訪的節點*/;
    //vector<int> *dfn, *low; 每個節點都有對應的 dfn、low 值
    stack<pair<int, pair<int, int>>> s;// trace DFS 時被走訪的 edge，分辨 biconnected component
    //pair<起點, pair<終點,權重>>>
public:
    adjListWeightUndirectedGraph(int v = 1);//建構子
    adjListWeightUndirectedGraph(adjListWeightUndirectedGraph& l);//copy 建構子
    void InsertVertex(int v);
    void InsertEdge(int u,int v, int w = 1);
    void InsertEdge(pair<int ,pair<int,int>> edge);
    int Degree(int u) const;
    bool ExistsEdge(int u, int v) const;
    void DeleteVertex(int v);
    void DeleteEdge(int u,int v);
    void Kruskal();//Kruskal's algorithm
    void Prim(); //Prim's algorithm
    void Sollin();//Sollin's algorithm
    void showGraph();
};

#include"MCST.cpp"//Minimum-Cost Spanning Trees
#endif
