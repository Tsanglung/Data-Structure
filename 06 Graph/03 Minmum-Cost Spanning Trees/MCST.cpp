#include"Graph.h"

adjListWeightUndirectedGraph::adjListWeightUndirectedGraph(int v)
{   //�غc�l
    e = 0; n = v;// edge = 0, vertice = v;
    vertices.resize(v , list<pair<int,int>>());//resize vector ���j�p
    //�Y vector ���j�p < v�A�s�W�B�~���`�I�� vector�A��l�Ƭ�list<pair<int,int>>()
    //�ЫتŪ� list�A��l�Ʒs�W���`�I
}

adjListWeightUndirectedGraph::adjListWeightUndirectedGraph(adjListWeightUndirectedGraph &copy)
{   //copy 
    e = copy.e; n = copy.n;
    vertices.resize(copy.n, list<pair<int,int>>());
    for(int i = 0; i < copy.n; i++)//���X�C�Ӹ`�I
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
        n = v;//��s�`�I��
    }
}

void adjListWeightUndirectedGraph::InsertEdge(int u, int v, int w)
{   //�L�V�ϡA�h�@�����J�ϦV��
    pair<int,int> temp(v , w);//temp(���I,�v��)
    if(find(vertices[u].begin(), vertices[u].end(), temp) == vertices[u].end())
    {
        vertices[u].push_back(temp);//�ˬd edge �O�_�s�b�`�I u �� adjList ���A�Y�_�h�s�W edge
        e++;//�` edge �� + 1
    }
        
    pair<int,int> rtemp(u, w);//�ϦV��
    if(find(vertices[v].begin(), vertices[v].end(), rtemp) == vertices[v].end())
        vertices[v].push_back(rtemp);

}

void adjListWeightUndirectedGraph::InsertEdge(pair<int/*�_�I*/, pair<int/*���I*/, int/*�v��*/>> edge)
{
    pair<int/*���I*/,int/*�v��*/> temp(edge.second.first, edge.second.second);//�v��
    if(find(vertices[edge.first].begin(), vertices[edge.first].end(), temp) == vertices[edge.first].end())
    {
        vertices[edge.first].push_back(temp);
        e++;//�` edge �� + 1
    }

    pair<int,int> rtemp(edge.first, edge.second.second);
    if (find(vertices[edge.second.first].begin(), vertices[edge.second.first].end(), rtemp) == vertices[edge.second.first].end())
        vertices[edge.second.first].push_back(rtemp);
}

int adjListWeightUndirectedGraph::Degree(int u) const{return vertices[u].size();}//�`�I u �� Degree

bool adjListWeightUndirectedGraph::ExistsEdge(int u, int v) const
{   //�ˬd�`�I u �M v �O�_�s�b edge
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
    vertices[v] = list<pair<int,int>>(); //�R���`�I v �s���� edge
    for(int i = 0; i < n; i++)
    {   //���X�C���I�A�P�`�I v ���s���� edge ���R��
        list<pair<int,int>>::iterator iter = vertices[i].begin();
        for(;iter != vertices[i].end(); iter++)
        {
            pair<int,int> temp = *iter;
            if(temp.first == v) iter = vertices[i].erase(iter);
            //�R����e iter ���V�� edge�A��s iter ��m���R���᪺�U�@�� edge
        }
    }
    n--;//�`�I - 1
}

void adjListWeightUndirectedGraph::DeleteEdge(int u, int v)
{
    list<pair<int,int>>::iterator iter = vertices[u].begin();
    //�M u �۳s���Ҧ� edge (pair<int(���I),int(�v��)>)
    for(;iter != vertices[u].end(); iter++)
        if (iter->first == v) // �p�G���I�O v
        {
            iter = vertices[u].erase(iter); // �R��������U�@�Ӧ��ĭ��N��
            e--; // ��� -1
        }
    //�R���ϦV��
    iter = vertices[v].begin();
    for(;iter != vertices[v].end(); iter++)
        if (iter->first == u) // �p�G���I�O v
            iter = vertices[v].erase(iter); // �R��������U�@�Ӧ��ĭ��N��

    
}

void adjListWeightUndirectedGraph::Kruskal()
{
    adjListWeightUndirectedGraph adjLUG = *this/*copy ��e�� graph*/, mcst(n)/*��l�Ƭ� n �Ӹ`�I�C�x�s���ͪ� minimum-cost spanning tree*/;
    pair<int, pair<int,int>> lowestCostEdge;//�x�s��ܪ� lowest cost edge
    vector<int> set(n, 0);//�ΨӰO���O�_�Φ� cycle
    for(int i = 0; i < n; i++) set[i] = i;// ��l�ƨC�Ӹ`�I�����X���䥻��

    while(mcst.NumberOfEdges() < (n - 1) && adjLUG.e > 0)//spanning tree edge < (n-1) �B graph �٦��Ѿl edge
    {
        lowestCostEdge = pair<int,pair<int,int>>(0, pair<int,int>(0, INT_MAX));
        for(int i = 0;i < n; i++)//���X�Ҧ��`�I
        {
            list<pair<int,int>>::iterator iter = adjLUG.vertices[i].begin();
            for(; iter != adjLUG.vertices[i].end(); iter++)
                if((*iter).second < lowestCostEdge.second.second)
                    lowestCostEdge = pair<int,pair<int,int>>(i, *iter);//��s�̤p��
        }
        adjLUG.DeleteEdge(lowestCostEdge.first, lowestCostEdge.second.first);//�R����ܪ� edge
        if(set[lowestCostEdge.first] != set[lowestCostEdge.second.first])
        {   //�ˬd cycle
            for(int i = 0; i < n; i++)
                if(set[i] == set[lowestCostEdge.second.first] && i != lowestCostEdge.second.first)
                    set[i] = set[lowestCostEdge.first];//�X�� set
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
    pair<int, pair<int,int>> leastCostEdge;//�x�s��ܪ� least-cost edge
    vector<bool> TV(n, false);//�������X�L���`�I
    TV[0] = true;//�_�l�I 0
    for(;mcst.NumberOfEdges() < (n-1); mcst.InsertEdge(leastCostEdge))
    {
        leastCostEdge = pair<int, pair<int,int>>(0, pair<int,int>(0,INT_MAX));
        for(int i = 0; i < n; i++)
            if(TV[i])//��`�I i �s�b TV ���A�~�Ҽ{ i ���F��
            {
                list<pair<int,int>>::iterator iter = adjLUG.vertices[i].begin();
                for(; iter != adjLUG.vertices[i].end(); iter++)
                    // �Y v ���b TV �B edge weight > ��e�̤p edge
                    if(!TV[(*iter).first] && (*iter).second < leastCostEdge.second.second)
                        leastCostEdge = pair<int, pair<int,int>>(i, *iter);//��s�̤p��
            }
        if(leastCostEdge.second.second == INT_MAX) break;// there is no such edge
        TV[leastCostEdge.second.first] = true;// add v to TV
    }
    if(mcst.NumberOfEdges() < n - 1) cout << "no spanning tree" << endl;
    mcst.showGraph();
}

void adjListWeightUndirectedGraph::Sollin() 
{
    adjListWeightUndirectedGraph adjLUG = *this, mcst(n); // �ƥ��P minimum-cost spanning trees
    vector<int> parent(n);  // �C�� node �����`�I
    vector<int> rank(n, 0); // �C�� node �����]���ס^
    vector<int> nodeSet(n); // �ΨӰO�� node �� connected component
    
    for (int i = 0; i < n; i++) 
    {   // ��l��
        parent[i] = i;
        nodeSet[i] = i;
    }

    while (mcst.NumberOfEdges() < n - 1) 
    {
        // �Ȧs�C�� connented component ���̤p��
        vector<pair<int, pair<int, int>>> minEdges(n, {INT_MAX, {-1, -1}});
        // ��C�� connected component ���̤p��
        for (int u = 0; u < n; u++) 
        {
            list<pair<int, int>>::iterator iter = adjLUG.vertices[u].begin();
            for (; iter != adjLUG.vertices[u].end(); iter++) 
                if (nodeSet[u] != nodeSet[(*iter).first/*v*/] && (*iter).second/*weight*/ < minEdges[nodeSet[u]].first) 
                    minEdges[nodeSet[u]] = {(*iter).second, {u, (*iter).first}};
                    //�Y u �M v ���b�P�@�� connected component�A�B v - u �� weight ��p�A��s�̤p��
        }

        // �X�� connected component
        for (int i = 0; i < n; i++) 
        {
            if (minEdges[i].first != INT_MAX) 
                if (nodeSet[minEdges[i].second.first] != nodeSet[minEdges[i].second.second]) // �P�_ u �M v �O�_�b�P�@ connected component ��
                {
                    mcst.InsertEdge(minEdges[i].second.first, minEdges[i].second.second, minEdges[i].first); // �N��[�J�̤p�ͦ���
                    // �� rank �X�֨�� connected component        
                    if (rank[nodeSet[minEdges[i].second.first]] > rank[nodeSet[minEdges[i].second.second]]) 
                    {//�Y u �� connected component �� rank > v �� connected component rank�A�X�� v �� connected component �� u �� connected component
                        for (int j = 0; j < n; j++) 
                            if (nodeSet[j] == nodeSet[minEdges[i].second.second]) 
                                nodeSet[j] = nodeSet[minEdges[i].second.first];     
                    } 
                    else if (rank[nodeSet[minEdges[i].second.first]] < rank[nodeSet[minEdges[i].second.second]]) 
                    {//�Y v �� rank > u �� rank
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
{	//�N�ϦL�X
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
