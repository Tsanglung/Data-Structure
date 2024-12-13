#include<iostream>
#include"Chain.h"
using namespace std;

class Graph {
protected:
	int n, e;	//點的數量，邊的數量
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
};	

class AdjLists : public Graph
{
private:
    Chain *adjList;
public:
    AdjLists(int vertices):Graph(vertices){adjList = new Chain [n];}
    void InsertVertex(int v)
    {
        if (v >= n) 
        {
            Chain* newAdjList = new Chain[v + 1];
            for (int i = 0; i < n; i++) 
                newAdjList[i] = adjList[i];
        
            delete[] adjList;
            adjList = newAdjList;
            n = v + 1;
        }
    }

    void InsertEdge(int u, int v,int w = 0)
    {
        if (u < n && v < n) 
            if (!ExistsEdge(u, v)) 
            {
                adjList[u].Insert(v);
                e++;
            }
    }

    int Degree(int u) const
    {
        if (u < n) 
            return adjList[u].Length();
        return -1;
    }

    bool ExistsEdge(int u, int v) const
    {
        if (u < n) 
            return adjList[u].GetNode(v) != nullptr;
        return false;
    }

    void DeleteVertex(int v)
    {
        if (v < n) 
        {
            for (int i = 0; i < n; i++) 
                if (i != v && ExistsEdge(i, v)) 
                {
                    adjList[i].Delete(v);
                    e--;
                }
            adjList[v] = Chain(); // 清空頂點 v 的所有邊
        }
    }
    void DeleteEdge(int u, int v)
    {
        if (u < n && ExistsEdge(u, v)) 
        {
            adjList[u].Delete(v);
            e--;
        }
    }
    void ShowGraph() const
    {
        for (int i = 0; i < n; i++) 
        {
            cout << '[' << i << "] ->";
            adjList[i].Output();
        }
    }
};

int main() {
    AdjLists AdjL(8);
    AdjL.InsertEdge(0,1);
    AdjL.InsertEdge(0,2);
    AdjL.InsertEdge(1,3);
    AdjL.InsertEdge(1,0);
    AdjL.InsertEdge(2,3);
    AdjL.InsertEdge(2,0);
    AdjL.InsertEdge(3,2);
    AdjL.InsertEdge(3,1);
    AdjL.InsertEdge(4,5);
    AdjL.InsertEdge(5,6);
    AdjL.InsertEdge(5,4);
    AdjL.InsertEdge(6,7);
    AdjL.InsertEdge(6,5);
    AdjL.InsertEdge(7,6);

    cout << "Graph adjacency lists:" << endl;
    AdjL.ShowGraph();

    cout << "Degree of vertex 1 : " << AdjL.Degree(1) << endl;
    AdjL.DeleteEdge(6,5);

    cout << "Graph adjacency lists:" << endl;
    AdjL.ShowGraph();
    return 0;
}