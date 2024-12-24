#include"Graph.h"

adjListWeightUndirectedGraph::adjListWeightUndirectedGraph(int v)
{   //建構子
    e = 0; n = v;// edge = 0, vertice = v;
    vertices.resize(v , list<pair<int,int>>());//resize vector 的大小
    //若 vector 的大小 < v，新增額外的節點到 vector，初始化為list<pair<int,int>>()
    //創建空的 list，初始化新增的節點
}

adjListWeightUndirectedGraph::adjListWeightUndirectedGraph(adjListWeightUndirectedGraph &copy)
{   //copy 
    e = copy.e; n = copy.n;
    vertices.resize(copy.n, list<pair<int,int>>());
    for(int i = 0; i < copy.n; i++)//走訪每個節點
    {
        list<pair<int,int>>::iterator iter = copy.vertices[i].begin();
        for(;iter != copy.vertices[i].end(); iter++) this->vertices[i].push_back(*iter);
    }
}

void adjListWeightUndirectedGraph::InsertVertex(int v)
{
    if(v > vertices.size())
    {
        vertices.resize(v , list<pair<int,int>>());
        n = v;//更新節點數
    }
}

void adjListWeightUndirectedGraph::InsertEdge(int u, int v, int w)
{   //無向圖，多一次插入反向邊
    pair<int,int> temp(v , w);//temp(終點,權重)
    if(find(vertices[u].begin(), vertices[u].end(), temp) == vertices[u].end())
    {
        vertices[u].push_back(temp);//檢查 edge 是否存在節點 u 的 adjList 中，若否則新增 edge
        e++;//總 edge 數 + 1
    }
        
    pair<int,int> rtemp(u, w);//反向邊
    if(find(vertices[v].begin(), vertices[v].end(), rtemp) == vertices[v].end())
        vertices[v].push_back(rtemp);

}

void adjListWeightUndirectedGraph::InsertEdge(pair<int/*起點*/, pair<int/*終點*/, int/*權重*/>> edge)
{
    pair<int/*終點*/,int/*權重*/> temp(edge.second.first, edge.second.second);//權重
    if(find(vertices[edge.first].begin(), vertices[edge.first].end(), temp) == vertices[edge.first].end())
    {
        vertices[edge.first].push_back(temp);
        e++;//總 edge 數 + 1
    }

    pair<int,int> rtemp(edge.first, edge.second.second);
    if (find(vertices[edge.second.first].begin(), vertices[edge.second.first].end(), rtemp) == vertices[edge.second.first].end())
        vertices[edge.second.first].push_back(rtemp);
}

int adjListWeightUndirectedGraph::Degree(int u) const{return vertices[u].size();}//節點 u 的 Degree

bool adjListWeightUndirectedGraph::ExistsEdge(int u, int v) const
{   //檢查節點 u 和 v 是否存在 edge
    list<pair<int,int>>::const_iterator iter = vertices[u].begin();
    for(; iter != vertices[u].end(); iter++)
    {
        pair<int,int> temp = *iter;
        if(temp.first == v) return true;
    }
    return false;
}

void adjListWeightUndirectedGraph::DeleteVertex(int v)
{
    vertices[v] = list<pair<int,int>>(); //刪除節點 v 連結的 edge
    for(int i = 0; i < n; i++)
    {   //走訪每個點，與節點 v 有連結的 edge 全刪除
        list<pair<int,int>>::iterator iter = vertices[i].begin();
        for(;iter != vertices[i].end(); iter++)
        {
            pair<int,int> temp = *iter;
            if(temp.first == v) iter = vertices[i].erase(iter);
            //刪除當前 iter 指向的 edge，更新 iter 位置為刪除後的下一個 edge
        }
    }
    n--;//節點 - 1
}

void adjListWeightUndirectedGraph::DeleteEdge(int u, int v)
{
    list<pair<int,int>>::iterator iter = vertices[u].begin();
    //和 u 相連的所有 edge (pair<int(終點),int(權重)>)
    for(;iter != vertices[u].end(); iter++)
        if (iter->first == v) // 如果終點是 v
        {
            iter = vertices[u].erase(iter); // 刪除並獲取下一個有效迭代器
            e--; // 邊數 -1
        }
    //刪除反向邊
    iter = vertices[v].begin();
    for(;iter != vertices[v].end(); iter++)
        if (iter->first == u) // 如果終點是 v
            iter = vertices[v].erase(iter); // 刪除並獲取下一個有效迭代器

    
}

void adjListWeightUndirectedGraph::Kruskal()
{
    adjListWeightUndirectedGraph adjLUG = *this/*copy 當前的 graph*/, mcst(n)/*初始化為 n 個節點。儲存產生的 minimum-cost spanning tree*/;
    pair<int, pair<int,int>> lowestCostEdge;//儲存選擇的 lowest cost edge
    vector<int> set(n, 0);//用來記錄是否形成 cycle
    for(int i = 0; i < n; i++) set[i] = i;// 初始化每個節點的集合為其本身

    while(mcst.NumberOfEdges() < (n - 1) && adjLUG.e > 0)//spanning tree edge < (n-1) 且 graph 還有剩餘 edge
    {
        lowestCostEdge = pair<int,pair<int,int>>(0, pair<int,int>(0, INT_MAX));
        for(int i = 0;i < n; i++)//走訪所有節點
        {
            list<pair<int,int>>::iterator iter = adjLUG.vertices[i].begin();
            for(; iter != adjLUG.vertices[i].end(); iter++)
                if((*iter).second < lowestCostEdge.second.second)
                    lowestCostEdge = pair<int,pair<int,int>>(i, *iter);//更新最小邊
        }
        adjLUG.DeleteEdge(lowestCostEdge.first, lowestCostEdge.second.first);//刪除選擇的 edge
        if(set[lowestCostEdge.first] != set[lowestCostEdge.second.first])
        {   //檢查 cycle
            for(int i = 0; i < n; i++)
                if(set[i] == set[lowestCostEdge.second.first] && i != lowestCostEdge.second.first)
                    set[i] = set[lowestCostEdge.first];//合併 set
            set[lowestCostEdge.second.first] = set[lowestCostEdge.first];
            mcst.InsertEdge(lowestCostEdge);// Insert to minimum-cost spanning tree
        }
    }
    if(mcst.NumberOfEdges() < n - 1) cout << "no spanning tree" << endl;
    mcst.showGraph();
}

void adjListWeightUndirectedGraph::Prim()
{
    adjListWeightUndirectedGraph adjLUG = *this, mcst(n);
    pair<int, pair<int,int>> leastCostEdge;//儲存選擇的 least-cost edge
    vector<bool> TV(n, false);//紀錄走訪過的節點
    TV[0] = true;//起始點 0
    for(;mcst.NumberOfEdges() < (n-1); mcst.InsertEdge(leastCostEdge))
    {
        leastCostEdge = pair<int, pair<int,int>>(0, pair<int,int>(0,INT_MAX));
        for(int i = 0; i < n; i++)
            if(TV[i])//當節點 i 存在 TV 中，才考慮 i 的鄰邊
            {
                list<pair<int,int>>::iterator iter = adjLUG.vertices[i].begin();
                for(; iter != adjLUG.vertices[i].end(); iter++)
                    // 若 v 不在 TV 且 edge weight > 當前最小 edge
                    if(!TV[(*iter).first] && (*iter).second < leastCostEdge.second.second)
                        leastCostEdge = pair<int, pair<int,int>>(i, *iter);//更新最小邊
            }
        if(leastCostEdge.second.second == INT_MAX) break;// there is no such edge
        TV[leastCostEdge.second.first] = true;// add v to TV
    }
    if(mcst.NumberOfEdges() < n - 1) cout << "no spanning tree" << endl;
    mcst.showGraph();
}

void adjListWeightUndirectedGraph::Sollin() 
{
    adjListWeightUndirectedGraph adjLUG = *this, mcst(n); // 副本與 minimum-cost spanning trees
    vector<int> parent(n);  // 每個 node 的父節點
    vector<int> rank(n, 0); // 每個 node 的秩（高度）
    vector<int> nodeSet(n); // 用來記錄 node 的 connected component
    
    for (int i = 0; i < n; i++) 
    {   // 初始化
        parent[i] = i;
        nodeSet[i] = i;
    }

    while (mcst.NumberOfEdges() < n - 1) 
    {
        // 暫存每個 connented component 的最小邊
        vector<pair<int, pair<int, int>>> minEdges(n, {INT_MAX, {-1, -1}});
        // 找每個 connected component 的最小邊
        for (int u = 0; u < n; u++) 
        {
            list<pair<int, int>>::iterator iter = adjLUG.vertices[u].begin();
            for (; iter != adjLUG.vertices[u].end(); iter++) 
                if (nodeSet[u] != nodeSet[(*iter).first/*v*/] && (*iter).second/*weight*/ < minEdges[nodeSet[u]].first) 
                    minEdges[nodeSet[u]] = {(*iter).second, {u, (*iter).first}};
                    //若 u 和 v 不在同一個 connected component，且 v - u 的 weight 更小，更新最小邊
        }

        // 合併 connected component
        for (int i = 0; i < n; i++) 
        {
            if (minEdges[i].first != INT_MAX) 
                if (nodeSet[minEdges[i].second.first] != nodeSet[minEdges[i].second.second]) // 判斷 u 和 v 是否在同一 connected component 內
                {
                    mcst.InsertEdge(minEdges[i].second.first, minEdges[i].second.second, minEdges[i].first); // 將邊加入最小生成樹
                    // 按 rank 合併兩個 connected component        
                    if (rank[nodeSet[minEdges[i].second.first]] > rank[nodeSet[minEdges[i].second.second]]) 
                    {//若 u 的 connected component 的 rank > v 的 connected component rank，合併 v 的 connected component 給 u 的 connected component
                        for (int j = 0; j < n; j++) 
                            if (nodeSet[j] == nodeSet[minEdges[i].second.second]) 
                                nodeSet[j] = nodeSet[minEdges[i].second.first];     
                    } 
                    else if (rank[nodeSet[minEdges[i].second.first]] < rank[nodeSet[minEdges[i].second.second]]) 
                    {//若 v 的 rank > u 的 rank
                        for (int j = 0; j < n; j++) 
                            if (nodeSet[j] == nodeSet[minEdges[i].second.first]) 
                                nodeSet[j] = nodeSet[minEdges[i].second.second];
                    } 
                    else 
                    {// v rank == u rank
                        for (int j = 0; j < n; j++) 
                            if (nodeSet[j] == nodeSet[minEdges[i].second.second]) 
                                nodeSet[j] = nodeSet[minEdges[i].second.first];
                            
                        rank[nodeSet[minEdges[i].second.first]]++;
                    }
                }
        }
    }
    if (mcst.NumberOfEdges() < n - 1) cout << "no spanning tree" << endl;
    mcst.showGraph();
}

void adjListWeightUndirectedGraph::showGraph()
{	//將圖印出
	cout << "node: links (weight)" << endl;
	for (int i = 0; i < n; i++) 
	{
		cout << i << ": ";
		list<pair<int, int>>::iterator iter = vertices[i].begin();
		for (; iter != vertices[i].end(); iter++) 
		{
			pair<int, int> temp = *iter;
			cout << temp.first << '(' << temp.second << ')' << " ";
		}
		cout << endl;
	}
}
