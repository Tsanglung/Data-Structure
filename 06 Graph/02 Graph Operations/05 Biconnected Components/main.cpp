#include<iostream>
#include<stack>
#include "Graph.h"
#include "Chain.h"
using namespace std;

class AdjLists : public Graph
{
private:
    Chain *adjList;
    int num, *dfn, *low;
    stack<pair<int, int>> s;
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
    void Biconnected()
    {
        num = 1;
        dfn = new int [n];
        low = new int [n];
        fill(dfn , dfn + n, 0);
        fill(low, low + n, 0);
        Biconnected(0, - 1);
        delete [] dfn;
        delete [] low;
    }
    void Biconnected(const int u, const int v)
    {
        dfn[u] = low[u] = num++;
        for (ChainNode* wNode = adjList[u].GetFirst(); wNode != nullptr; wNode = wNode->link)
        {
            int w = wNode->data;
            if (w != v && dfn[w] < dfn[u])  s.push({u, w}); // edge(u, w)進入堆疊
            if (dfn[w] == 0) // w 還未被訪問
            { 
                Biconnected(w, u);
                low[u] = min(low[u], low[w]);
                if (low[w] >= dfn[u]) { // 找到一個雙連通
                    cout << "New Biconnected Component: ";
                    /*while (true) 
                    {
                        auto edge = s.top();
                        s.pop();
                        cout << "(" << edge.first << "," << edge.second << ") ";
                        if (edge.first == u && edge.second == w) break;
                    }*/
                    auto edge = s.top();
                    do {
                        edge = s.top();
                        s.pop();
                        cout << "(" << edge.first << "," << edge.second << ") ";
                    } while (!(edge.first == u && edge.second == w));
                    cout << endl;
                }
            }
            else if (w != v) low[u] = min(low[u], dfn[w]); // back edge
        }
    }
};

int main() {
    AdjLists AdjL(10);
    AdjL.InsertEdge(0,1);
    AdjL.InsertEdge(1,2);
    AdjL.InsertEdge(1,3);
    AdjL.InsertEdge(2,4);
    AdjL.InsertEdge(3,4);
    AdjL.InsertEdge(3,5);
    AdjL.InsertEdge(5,6);
    AdjL.InsertEdge(5,7);
    AdjL.InsertEdge(6,7);
    AdjL.InsertEdge(7,8);
    AdjL.InsertEdge(7,9);

    cout << "Graph adjacency lists:" << endl;
    AdjL.ShowGraph();

    cout << "Degree of vertex 0 : " << AdjL.Degree(0) << endl;
    cout << "G 的雙連通單元 : " << endl;
    AdjL.Biconnected();
    return 0;
}