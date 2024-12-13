#include<iostream>
#include "Graph.h"
#include"Chain.h"
using namespace std;

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
                adjList[v].Insert(u);
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
    void DFS()
    {
        visited = new bool[n];
        fill(visited , visited + n , false);
        DFS(0);
        delete [] visited;
    }
    void DFS(const int v)
    {
        visited[v] = true;
        cout << v << " ";
        ChainNode* current = adjList[v].GetFirst();
        while (current != nullptr) 
        {
            int w = current->data;
            if (!visited[w])    DFS(w);
            current = current->link;
        }
    }
};

int main() {
    AdjLists AdjL(8);
    AdjL.InsertEdge(0,1);
    AdjL.InsertEdge(0,2);
    AdjL.InsertEdge(1,3);
    AdjL.InsertEdge(1,4);
    AdjL.InsertEdge(2,5);
    AdjL.InsertEdge(2,6);
    AdjL.InsertEdge(3,7);
    AdjL.InsertEdge(4,7);
    AdjL.InsertEdge(5,7);
    AdjL.InsertEdge(6,7);

    cout << "Graph adjacency lists:" << endl;
    AdjL.ShowGraph();

    cout << "Degree of vertex 0 : " << AdjL.Degree(0) << endl;
    cout << "DFS traversal:" << endl;
    AdjL.DFS();

    return 0;
}