#include<iostream>
#include<vector>
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

class AdjMatrix : public Graph
{
private:
    vector<vector<int>> adjMatrix;
public:
    //vector 建立 vertices * vertices 二維 0 陣列
    AdjMatrix(int vertices) : Graph(vertices){adjMatrix.resize(vertices,vector<int>(vertices,0));}
    void InsertVertex(int v)
    {   // 增加頂點數
        if(v >= n)
        {
            adjMatrix.resize(v + 1,vector<int>(v + 1, 0));
            n = v + 1;
        }
    }
    void InsertEdge(int u,int v,int w)
    {   
        if(u >= n || v >= n) return;
        if(adjMatrix[u][v] == 0) e++;
        adjMatrix[u][v] = w;
    }
    int Degree(int u) const
    {
        if(u >= n) return -1;//若所求頂點大於目前graph的頂點數，則無 degree
        int degree = 0;
        for(int v = 0;v < n;v++)
            if(adjMatrix[u][v] != 0)
                degree++;
        return degree;
    }
    bool ExistsEdge(int u,int v) const
    {   //頂點 u、v 是否存在 edge
        if(u >= n || v >= n) return false;
        return adjMatrix[u][v] != 0;
    }
    void DeleteVertex(int v)
    {
        if(v >= n) return;
        for(int u = 0;u < n;u++)
        {
            if(adjMatrix[u][v] != 0)
            {
                adjMatrix[u][v] = 0;
                e--;
            }
            if(adjMatrix[v][u] != 0)
            {
                adjMatrix[v][u] = 0;
                e--;
            }
        }
    }
    void DeleteEdge(int u,int v)
    {
        if(u >= n || v >= n || adjMatrix[u][v] == 0) return;
        adjMatrix[u][v] = 0;
        e--;
    }
    void ShowGraph() const
    {
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    AdjMatrix AdjM(7); // 8 * 8 matrix : 8個頂點
    AdjM.InsertEdge(0,1,1);
    AdjM.InsertEdge(0,2,1);
    AdjM.InsertEdge(1,0,1);
    AdjM.InsertEdge(1,3,1);
    AdjM.InsertEdge(2,1,1);
    AdjM.InsertEdge(2,3,1);
    AdjM.InsertEdge(3,1,1);
    AdjM.InsertEdge(3,2,1);
    AdjM.InsertEdge(4,5,1);
    AdjM.InsertEdge(5,4,1);
    AdjM.InsertEdge(5,6,1);
    AdjM.InsertEdge(6,5,1);
    AdjM.InsertEdge(6,7,1);
    AdjM.InsertEdge(7,6,1);
    cout << "Graph adjacency matrix:" << endl;
    AdjM.ShowGraph();

    cout << "Degree of Vertex 0 :" << AdjM.Degree(0) << endl;
    cout << "Does edge (1, 3) exist? " << (AdjM.ExistsEdge(1, 3) ? "Yes" : "No") << endl;
}