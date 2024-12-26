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

void adjListWeightDirectedGraph::Topological()
{
    vector<int> count(n, 0); // 每個節點的 degree
    vector<int> ee(n, 0);      // 最早發生時間（Earliest Event Time）
    // 計算每個節點的 degree
    for (int i = 0; i < n; i++)
    {
        list<pair<int,int>>::iterator iter = vertices[i].begin();
        for (; iter != vertices[i].end(); iter++)
            count[(*iter).first]++;// 將每個鄰接節點的 degree 加 1
    }

    int top = -1; // 模擬 stack
    for (int i = 0; i < n; i++)
    {
        if (count[i] == 0)
        {   // no predecessor
            count[i] = top;// 將當前stack top的值儲存到節點的 count 中
            top = i; // 將degree 為 0 的節點加入 stack
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (top == -1)  throw "Network has a cycle"; // 如果 stack 為空，代表圖中存在循環
        else
        {
            int j = top; top = count[top]; // 從堆疊中取出節點
            cout << "Vertex : " << j << " deleted " << endl;

            // 遍歷當前節點的所有鄰接節點
            list<pair<int,int>>::iterator iter = vertices[j].begin();
            for (;iter != vertices[j].end(); iter++)
            {   // 如果鄰接節點的 Earliest Event Time 小於當前節點的 Earliest Event Time 加上權種，更新
                if (ee[(*iter).first/*鄰接節點*/] < ee[j] + (*iter).second/*權重*/)
                    ee[(*iter).first] = ee[j] + (*iter).second; // 更新 Earliest Event Time

                count[(*iter).first]--; // 減少鄰接節點的 degree
                if (count[(*iter).first] == 0)
                {
                    count[(*iter).first] = top;
                    top = (*iter).first; // 將新的 degree 為 0 的節點加入堆疊
                }
            }
        }
    }
    cout << "Earliest Event Times: ";// 輸出所有節點的 Earliest Event Times
    for (int i = 0; i < n; i++) cout << ee[i] << " ";
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
