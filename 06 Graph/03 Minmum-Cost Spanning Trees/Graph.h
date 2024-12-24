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

class adjListWeightUndirectedGraph : public Graph 
{//���v�����L�V��
protected:
    vector<list<pair<int,int>>> vertices;
    //vector<list<pair<�`�I,�v��>>> vector �C�Ӥ����������`�I
    //list<pair<�`�I,�v��>>��list�x�s�C�Ӹ`�I�� adjacency List
    bool *visit; //�����O�_���X�L�`�I
    int num; //biconnected component �p�� dfn�Blow���ܼ�
    vector<int> *dfn/*depth-first number : ��ܸ`�I�Q���X������*/, *low/*lowest depth-first number : ��q�L back edge �� child tree's edge �^��̦����X���`�I*/;
    //vector<int> *dfn, *low; �C�Ӹ`�I���������� dfn�Blow ��
    stack<pair<int, pair<int, int>>> s;// trace DFS �ɳQ���X�� edge�A���� biconnected component
    //pair<�_�I, pair<���I,�v��>>>
public:
    adjListWeightUndirectedGraph(int v = 1);//�غc�l
    adjListWeightUndirectedGraph(adjListWeightUndirectedGraph& l);//copy �غc�l
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
