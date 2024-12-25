#include "Graph.h"

adjListWeightDirectedGraph::adjListWeightDirectedGraph(int v)
{   //�غc�l
    e = 0; n = v;// edge = 0, vertice = v;
    vertices.resize(v , list<pair<int,int>>());//resize vector ���j�p
    //�Y vector ���j�p < v�A�s�W�B�~���`�I�� vector�A��l�Ƭ�list<pair<int,int>>()
    //�ЫتŪ� list�A��l�Ʒs�W���`�I
}

adjListWeightDirectedGraph::adjListWeightDirectedGraph(adjListWeightDirectedGraph &copy)
{   //�ƻs�غc�l
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

void adjListWeightDirectedGraph::InsertEdge(int u/*�_*/, int v/*��*/, int w/*�v��*/)
{  
    pair<int,int> temp(v, w);
    if(find(vertices[u].begin(), vertices[u].end(), temp) == vertices[u].end())
    {
        vertices[u].push_back(temp);
        e++;
    }
}

void adjListWeightDirectedGraph::InsertEdge(pair<int/*�_�I*/, pair<int/*���I*/, int/*�v��*/>> edge)
{   //�s�W��
	pair<int/*���I*/, int/*�v��*/> temp = edge.second;
    if(find(vertices[edge.first].begin(), vertices[edge.first].end(), temp) == vertices[edge.first].end())
    {   //���I�O�_�s���L�F
        vertices[edge.first].push_back(temp);//�٨S���ܼW�[
        e++;//�`��� ++
    }
}

int adjListWeightDirectedGraph::Degree(int u) const{return vertices[u].size();}

bool adjListWeightDirectedGraph::ExistsEdge(int u, int v) const
{   //�b���I���O�_�s�b��
    list<pair<int,int>>::const_iterator iter = vertices[u].begin();
    for(; iter != vertices[u].end(); iter++)
        if((*iter).first == v) return true;
    return false;
}

void adjListWeightDirectedGraph::DeleteVertex(int v)
{   //�N���I�ҳs������R��
    vertices[v] = list<pair<int,int>>();
    for(int i = 0; i < n; i++)
    {   //�N��L�s�����I����R��
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
    vector<int> dist(n, INT_MAX); //�̵u�Z��
    vector<bool> s(n, false);//�O�_�w�T�w�̵u�Z��
    vector<int> pathV(n, -1);//�������|
    dist[v] = 0;// �_�I�Z���]�� 0

    for (int i = 0; i < n - 1; i++) //�P�_ n - 1 paths 
    {   // ��ܥ��T�w�̵u�Z���B�Z���̤p���I
        int u = -1, preMax = -1;
        for (int j = 0; j < n; j++) 
            if (!s[j] && ((preMax == -1) || dist[j] < preMax)) 
            {
                preMax = dist[j];
                u = j;
            }

        s[u] = true; // u �T�w�� dist
        list<pair<int,int>>::iterator iter = vertices[u].begin();
        for (;iter != vertices[u].end(); iter++) // ��s�P u �۾F���I���Z��
            if (!s[(*iter).first/*�۾F�`�I*/] && dist[u] + (*iter).second/*�v��*/ < dist[(*iter).first]) 
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
        if (dist[i] == INT_MAX) cout << "��" << endl;
        else 
        {
            cout << dist[i] << " [Path: ";
            stack<int> path; // �Ω�s����|
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
    dist[v] = 0; // �_�I�Z���]�� 0

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
            if (dist[i] == INT_MAX) cout << "�� ";
            else cout << dist[i] << ' ';
        }
        cout << endl;
    }
}

void adjListWeightDirectedGraph::FloydWarshall(const int n)
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    // ��l�ƶZ���x�}�G�q�F����C�]�m�v��
    for (int i = 0; i < n; i++) 
    {
        dist[i][i] = 0;  /* �ۤv��ۤv���Z����0*/
        list<pair<int,int>>::iterator iter = vertices[i].begin();
        for (; iter != vertices[i].end(); iter++) 
            dist[i][(*iter).first] = (*iter).second;  // ���o�P�۾F�`�I���Z��
    }
    
    for (int k = 0; k < n; k++) // Floyd-Warshall �t��k
    {   // ��ܥثe�Z���x�}
        cout << "A^" << k - 1 << " | ";//(k - 1 = �g�L���`�I�s��)
        for(int num = 0; num < n; num++) cout << num << " ";
        cout << endl << "------------" << endl;
        for (int i = 0; i < n; i++) 
        {   //��X
            cout << i << "  | ";
            for (int j = 0; j < n; j++) 
            {
                if (dist[i][j] == INT_MAX) cout << " �� ";
                else cout << dist[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)  // �Y�g�Lk�����u�����|
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j];
    }
    
    // ��̲ܳ׵��G
    cout << "A^" << n - 1 << " | ";
    for(int num = 0; num < n; num++) cout << num << " ";
    cout << endl << "------------" << endl;
    for (int i = 0; i < n; i++) 
    {
        cout << i << "  | ";
        for (int j = 0; j < n; j++) 
        {
            if (dist[i][j] == INT_MAX) cout << " �� ";
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
