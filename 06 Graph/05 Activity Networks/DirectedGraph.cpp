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

void adjListWeightDirectedGraph::Topological()
{
    vector<int> count(n, 0); // �C�Ӹ`�I�� degree
    vector<int> ee(n, 0);      // �̦��o�ͮɶ��]Earliest Event Time�^
    // �p��C�Ӹ`�I�� degree
    for (int i = 0; i < n; i++)
    {
        list<pair<int,int>>::iterator iter = vertices[i].begin();
        for (; iter != vertices[i].end(); iter++)
            count[(*iter).first]++;// �N�C�ӾF���`�I�� degree �[ 1
    }

    int top = -1; // ���� stack
    for (int i = 0; i < n; i++)
    {
        if (count[i] == 0)
        {   // no predecessor
            count[i] = top;// �N��estack top�����x�s��`�I�� count ��
            top = i; // �Ndegree �� 0 ���`�I�[�J stack
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (top == -1)  throw "Network has a cycle"; // �p�G stack ���šA�N��Ϥ��s�b�`��
        else
        {
            int j = top; top = count[top]; // �q���|�����X�`�I
            cout << "Vertex : " << j << " deleted " << endl;

            // �M����e�`�I���Ҧ��F���`�I
            list<pair<int,int>>::iterator iter = vertices[j].begin();
            for (;iter != vertices[j].end(); iter++)
            {   // �p�G�F���`�I�� Earliest Event Time �p���e�`�I�� Earliest Event Time �[�W�v�ءA��s
                if (ee[(*iter).first/*�F���`�I*/] < ee[j] + (*iter).second/*�v��*/)
                    ee[(*iter).first] = ee[j] + (*iter).second; // ��s Earliest Event Time

                count[(*iter).first]--; // ��־F���`�I�� degree
                if (count[(*iter).first] == 0)
                {
                    count[(*iter).first] = top;
                    top = (*iter).first; // �N�s�� degree �� 0 ���`�I�[�J���|
                }
            }
        }
    }
    cout << "Earliest Event Times: ";// ��X�Ҧ��`�I�� Earliest Event Times
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
