#include "Graph.h"

adjListWeightUndirectedGraph::adjListWeightUndirectedGraph(int v) : adjListWeightDirectedGraph(v){}

void adjListWeightUndirectedGraph::InsertEdge(int u,int v,int w)
{
    adjListWeightDirectedGraph::InsertEdge(u ,v ,w);
    adjListWeightDirectedGraph::InsertEdge(v ,u ,w);//反邊
    e--;
}

void adjListWeightUndirectedGraph::InsertEdge(pair<int,pair<int,int>> edge)
{
    adjListWeightDirectedGraph::InsertEdge(edge);//正邊
    pair<int,pair<int,int>> temp = pair<int,pair<int,int>>(edge.second.first, pair<int,int>(edge.first, edge.second.second));
    adjListWeightDirectedGraph::InsertEdge(temp);//反邊
    e--;
}

void adjListWeightUndirectedGraph::DeleteEdge(int u,int v)
{
    adjListWeightDirectedGraph::DeleteEdge(u, v);
    adjListWeightDirectedGraph::DeleteEdge(v, u);
    e++;
}

void adjListWeightUndirectedGraph::showGraph()
{
    cout << "node : links" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << i << " : ";
        list<pair<int,int>>::iterator iter = vertices[i].begin();
        for(; iter != vertices[i].end(); iter++)
            cout << (*iter).first << " ";
        cout << endl;
    }
    cout << "---------------------------------------------------------" << endl;
}