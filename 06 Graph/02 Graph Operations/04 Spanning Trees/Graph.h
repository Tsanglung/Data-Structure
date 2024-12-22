#ifndef GRAPH_H
#define GRAPH_H

class Graph {
protected:
	int n, e;	//�ثe�I���ƶq�A�䪺�ƶq
    bool *visited;
    virtual void DFS(const int v) = 0;
public:
    Graph(int vertices):n(vertices),e(0){};
	bool IsEmpty() const {return n == 0;}//�Y�L���I return true
	int NumberOfVertices() const {return n;}
	int NumberOfEdges() const {return e;}
	virtual void InsertVertex(int v) = 0;
	virtual void InsertEdge(int u, int v,int w) = 0;
	virtual int Degree(int u) const = 0;//���I u �� edges ?
	virtual bool ExistsEdge(int u, int v) const = 0;
	virtual void DeleteVertex(int v) = 0;
	virtual void DeleteEdge(int u, int v) = 0;
    virtual void DFS() = 0;
    virtual void Components() = 0;
    virtual void SpanningTree(int u) = 0;//�H�Y�I�}�l���i�}��
};	

#endif
