#ifndef GRAPH_H
#define GRAPH_H

class Graph {
protected:
	int n, e;	//點的數量，邊的數量
    bool *visited;
    virtual void BFS(const int v) = 0;
public:
    Graph(int vertices):n(vertices),e(0){}
	bool IsEmpty() const {return n == 0;}
	int NumberOfVertices() const {return n;}
	int NumberOfEdges() const {return e;}
	virtual void InsertVertex(int v) = 0;
	virtual void InsertEdge(int u, int v,int w) = 0;
	virtual int Degree(int u) const = 0;
	virtual bool ExistsEdge(int u, int v) const = 0;
	virtual void DeleteVertex(int v) = 0;
	virtual void DeleteEdge(int u, int v) = 0;
    virtual void BFS() = 0;
};	

#endif