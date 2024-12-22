#ifndef GRAPH_H
#define GRAPH_H

class Graph {
protected:
	int n, e;	//目前點的數量，邊的數量
    bool *visited;
	virtual void Biconnected(const int u, const int v) = 0;
public:
    Graph(int vertices):n(vertices),e(0){};
	bool IsEmpty() const {return n == 0;}//若無頂點 return true
	int NumberOfVertices() const {return n;}
	int NumberOfEdges() const {return e;}
	virtual void InsertVertex(int v) = 0;
	virtual void InsertEdge(int u, int v,int w) = 0;
	virtual int Degree(int u) const = 0;//頂點 u 的 edges ?
	virtual bool ExistsEdge(int u, int v) const = 0;
	virtual void DeleteVertex(int v) = 0;
	virtual void DeleteEdge(int u, int v) = 0;
    virtual void Biconnected() = 0;
};	

#endif
