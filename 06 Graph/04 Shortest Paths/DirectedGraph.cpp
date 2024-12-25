#include "Graph.h"

adjListWeightDirectedGraph::adjListWeightDirectedGraph(int v)
{   //建構子
    e = 0; n = v;// edge = 0, vertice = v;
    vertices.resize(v , list<pair<int,int>>());//resize vector 的大小
    //若 vector 的大小 < v，新增額外的節點到 vector，初始化為list<pair<int,int>>()
    //創建空的 list，初始化新增的節點
}

adjListWeightDirectedGraph::adjListWeightDirectedGraph(adjListWeightDirectedGraph &copy)
{   //複製建構子
    e = copy.e; n = copy.n;
    vertices.resize(copy.n, list<pair<int,int>>());
    for(int i = 0; i < copy.n; i++)
    {
        list<pair<int,int>>::iterator iter = copy.vertices[i].begin();
        for(; iter != copy.vertices[i].end(); iter++) this->vertices[i].push_back(*iter);
    }
}

void adjListWeightDirectedGraph::InsertVertex(int v)
{
    if(v > vertices.size())
    {
        vertices.resize(v, list<pair<int,int>>());
        n = v;
    }
}

void adjListWeightDirectedGraph::InsertEdge(int u/*起*/, int v/*終*/, int w/*權重*/)
{  
    pair<int,int> temp(v, w);
    if(find(vertices[u].begin(), vertices[u].end(), temp) == vertices[u].end())
    {
        vertices[u].push_back(temp);
        e++;
    }
}

void adjListWeightDirectedGraph::InsertEdge(pair<int/*起點*/, pair<int/*終點*/, int/*權重*/>> edge)
{   //新增邊
	pair<int/*終點*/, int/*權重*/> temp = edge.second;
    if(find(vertices[edge.first].begin(), vertices[edge.first].end(), temp) == vertices[edge.first].end())
    {   //此點是否連接過了
        vertices[edge.first].push_back(temp);//還沒的話增加
        e++;//總邊數 ++
    }
}

int adjListWeightDirectedGraph::Degree(int u) const{return vertices[u].size();}

bool adjListWeightDirectedGraph::ExistsEdge(int u, int v) const
{   //在兩點中是否存在邊
    list<pair<int,int>>::const_iterator iter = vertices[u].begin();
    for(; iter != vertices[u].end(); iter++)
        if((*iter).first == v) return true;
    return false;
}

void adjListWeightDirectedGraph::DeleteVertex(int v)
{   //將此點所連結的邊刪除
    vertices[v] = list<pair<int,int>>();
    for(int i = 0; i < n; i++)
    {   //將其他連結此點的邊刪除
        list<pair<int,int>>::iterator iter = vertices[i].begin();
        for(; iter != vertices[i].end(); iter)
            if((*iter).first == v) iter = vertices[i].erase(iter);
        e--;
    }
}

void adjListWeightDirectedGraph::DeleteEdge(int u, int v)
{
    list<pair<int,int>>::iterator iter = vertices[u].begin();
    for(; iter != vertices[u].end(); iter)
    {
        if((*iter).first == v)
        {
            vertices[u].remove(*iter);
            e--;
            break;
        }
    }
}

void adjListWeightDirectedGraph::Dijkstra(const int n, const int v) 
{
    vector<int> dist(n, INT_MAX); //最短距離
    vector<bool> s(n, false);//是否已確定最短距離
    vector<int> pathV(n, -1);//紀錄路徑
    dist[v] = 0;// 起點距離設為 0

    for (int i = 0; i < n - 1; i++) //判斷 n - 1 paths 
    {   // 選擇未確定最短距離且距離最小的點
        int u = -1, preMax = -1;
        for (int j = 0; j < n; j++) 
            if (!s[j] && ((preMax == -1) || dist[j] < preMax)) 
            {
                preMax = dist[j];
                u = j;
            }

        s[u] = true; // u 確定為 dist
        list<pair<int,int>>::iterator iter = vertices[u].begin();
        for (;iter != vertices[u].end(); iter++) // 更新與 u 相鄰的點的距離
            if (!s[(*iter).first/*相鄰節點*/] && dist[u] + (*iter).second/*權重*/ < dist[(*iter).first]) 
            {
                dist[(*iter).first] = dist[u] + (*iter).second;
                pathV[(*iter).first] = u;
            }
    }

    cout << "Strart vertex " << v << ":\n";
    for (int i = 0; i < n; i++) 
    {
        if(i == v) i++;
        cout << "Vertex " << i << ": ";
        if (dist[i] == INT_MAX) cout << "∞" << endl;
        else 
        {
            cout << dist[i] << " [Path: ";
            stack<int> path; // 用於存放路徑
            for (int at = i; at != -1; at = pathV[at]) path.push(at);
            while (!path.empty()) 
            {
                cout << path.top();
                path.pop();
                if (!path.empty()) cout << " -> ";
            }
            cout << "]" << endl;
        }
    }
}

void adjListWeightDirectedGraph::BellmanFord(const int n, const int v)
{
    cout << "  |    " << "dist^k[7]" << endl;
    cout << "k | ";
    for(int i = 0; i < n; i++) cout << i << ' ';
    cout << endl;
    vector<int> dist(n, INT_MAX);
    dist[v] = 0; // 起點距離設為 0

    for (int k = 1; k <= n - 1; k++) 
    {
        vector<int> tempDist = dist;
        for (int u = 0; u < n; u++) 
        {
            list<pair<int,int>>::iterator iter = vertices[u].begin();
            for(; iter != vertices[u].end(); iter++)
                if(dist[u] != INT_MAX && tempDist[(*iter).first] > dist[u] + (*iter).second)
                    tempDist[(*iter).first] = dist[u] + (*iter).second;
        }
        dist = tempDist;
        cout << k << " | ";
        for (int i = 0; i < n; i++) 
        {
            if (dist[i] == INT_MAX) cout << "∞ ";
            else cout << dist[i] << ' ';
        }
        cout << endl;
    }
}

void adjListWeightDirectedGraph::FloydWarshall(const int n)
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    // 初始化距離矩陣：從鄰接串列設置權重
    for (int i = 0; i < n; i++) 
    {
        dist[i][i] = 0;  /* 自己到自己的距離為0*/
        list<pair<int,int>>::iterator iter = vertices[i].begin();
        for (; iter != vertices[i].end(); iter++) 
            dist[i][(*iter).first] = (*iter).second;  // 取得與相鄰節點的距離
    }
    
    for (int k = 0; k < n; k++) // Floyd-Warshall 演算法
    {   // 顯示目前距離矩陣
        cout << "A^" << k - 1 << " | ";//(k - 1 = 經過的節點編號)
        for(int num = 0; num < n; num++) cout << num << " ";
        cout << endl << "------------" << endl;
        for (int i = 0; i < n; i++) 
        {   //輸出
            cout << i << "  | ";
            for (int j = 0; j < n; j++) 
            {
                if (dist[i][j] == INT_MAX) cout << " ∞ ";
                else cout << dist[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)  // 若經過k能找到更短的路徑
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j];
    }
    
    // 顯示最終結果
    cout << "A^" << n - 1 << " | ";
    for(int num = 0; num < n; num++) cout << num << " ";
    cout << endl << "------------" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << i << "  | ";
        for (int j = 0; j < n; j++) 
        {
            if (dist[i][j] == INT_MAX) cout << " ∞ ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void adjListWeightDirectedGraph::showGraph()
{
    cout << "node : links(weight)" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << i << " : ";
        list<pair<int,int>>::iterator iter = vertices[i].begin();
        for(; iter != vertices[i].end(); iter++)
            cout << (*iter).first << "(" << (*iter).second << ") ";
        cout << endl;
    }
    cout << "---------------------------------------------------------" << endl;
}
