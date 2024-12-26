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
	int n, e;	//�ثe�I���ƶq�A�䪺�ƶq
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

class adjListWeightDirectedGraph : public Graph{//�F����C��ܪ����v�����V��
protected:
    vector<list<pair<int,int>>> vertices;//�����I�P���I�ҳs�����I�M�v���C��C���s�����I�A�x�s��pair���I�P�v��
    bool *visited;//�����O�_���X�L�`�I
    int num;//biconnected�n�p��DFN�PLOW���ܼ�
    vector<int> *dfn, *low;//biconnected�ݭn���ܼ�
    stack<pair<int, pair<int, int>>> s;	//biconnected�ݭn�����|
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