#include<iostream>
using namespace std;

class AdjMulti;

class GraphEdge {
    friend class AdjMulti;
private:
    bool m;
    int vertex1, vertex2;
    GraphEdge* link1, * link2;
public:
    GraphEdge(int v1 = 0, int v2 = 0, GraphEdge* p1 = nullptr, GraphEdge* p2 = nullptr)
        : m(false), vertex1(v1), vertex2(v2), link1(p1), link2(p2) {}
};

typedef GraphEdge* EdgePtr;

class AdjMulti {
private:
    EdgePtr* HeadNodes;
    int n;
public:
    AdjMulti(const int vertices = 0);
    ~AdjMulti();
    void InsertEdge(int u, int v);
    void DeleteEdge(int u, int v);
    void ShowGraph() const;
};

AdjMulti::AdjMulti(const int vertices) : n(vertices) {
    HeadNodes = new EdgePtr[n];
    for (int i = 0; i < n; i++) HeadNodes[i] = nullptr;
}

AdjMulti::~AdjMulti() {
    for (int i = 0; i < n; i++) {
        EdgePtr current = HeadNodes[i];
        while (current != nullptr) {
            EdgePtr temp = current;
            current = (current->vertex1 == i) ? current->link1 : current->link2;
            delete temp;
        }
    }
    delete[] HeadNodes;
}

void AdjMulti::InsertEdge(int u, int v) {
    EdgePtr newEdge = new GraphEdge(u, v, HeadNodes[u], HeadNodes[v]);
    HeadNodes[u] = newEdge;
    HeadNodes[v] = newEdge;
}

void AdjMulti::DeleteEdge(int u, int v) {
    EdgePtr* current = &HeadNodes[u];
    while (*current != nullptr && ((*current)->vertex1 != v && (*current)->vertex2 != v)) {
        current = ((*current)->vertex1 == u) ? &(*current)->link1 : &(*current)->link2;
    }
    if (*current == nullptr) return;

    EdgePtr toDelete = *current;
    *current = ((*current)->vertex1 == u) ? (*current)->link1 : (*current)->link2;

    EdgePtr* otherCurrent = &HeadNodes[v];
    while (*otherCurrent != nullptr && ((*otherCurrent)->vertex1 != u && (*otherCurrent)->vertex2 != u)) {
        otherCurrent = ((*otherCurrent)->vertex1 == v) ? &(*otherCurrent)->link1 : &(*otherCurrent)->link2;
    }
    if (*otherCurrent != nullptr) {
        *otherCurrent = ((*otherCurrent)->vertex1 == v) ? (*otherCurrent)->link1 : (*otherCurrent)->link2;
    }
    delete toDelete;
}

void AdjMulti::ShowGraph() const {
    for (int i = 0; i < n; i++) {
        cout << "[" << i << "] -> ";
        EdgePtr current = HeadNodes[i];
        while (current != nullptr) {
            if (current->vertex1 == i)
                cout << current->vertex2 << " ";
            else
                cout << current->vertex1 << " ";
            current = (current->vertex1 == i) ? current->link1 : current->link2;
        }
        cout << endl;
    }
}

int main() {
    AdjMulti AdjMult(4);
    AdjMult.InsertEdge(0, 1);
    AdjMult.InsertEdge(0, 2);
    AdjMult.InsertEdge(0, 3);
    AdjMult.InsertEdge(1, 2);
    AdjMult.InsertEdge(1, 3);
    AdjMult.InsertEdge(2, 3);


    cout << "Graph adjacency multilists:" << endl;
    AdjMult.ShowGraph();

    AdjMult.DeleteEdge(1, 0);

    cout << "After deleting edge 1-0:" << endl;
    AdjMult.ShowGraph();

    return 0;
}
