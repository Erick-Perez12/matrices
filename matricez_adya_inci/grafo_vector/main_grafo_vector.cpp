#include <iostream>
#include <vector>

using namespace std;

class grafo {
public:
    int vertice;
    vector<int> ** lista;

    grafo(int _vertice) {
        this->vertice = _vertice;
        this->lista = new vector<int>*[_vertice];
        for (int i = 0; i < _vertice; i++) {
            this->lista[i] = new vector<int>();
        }
    }
    void addEdge(int, int);
    void adj(int);
    int outdegree(int);
    int indegree(int);

};

void grafo::addEdge(int v, int w) {
    if (v > this->vertice) {
        cout << "error\n";
    }
    else this->lista[v]->push_back(w);
}

void grafo::adj(int v) {

    vector<int> A = *(this->lista[v]);
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << ", ";
    }

    for (int i = 0; i < this->vertice; i++) {
        if (i != v) {
            vector<int> B = *(this->lista[i]);
            for (int j = 0; j < B.size(); j++) {
                if (B[j] == v) cout << i << ",";
            }
        }
    }
}

int grafo::outdegree(int v) {
    int cont = 0;
    vector<int> A = *(this->lista[v]);
    for (int i = 0; i < A.size(); i++) {
        cont++;
    }

    for (int i = 0; i < this->vertice; i++) {
        if (i != v) {
            vector<int> B = *(this->lista[i]);
            for (int j = 0; j < B.size(); j++) {
                if (B[j] == v) cont++;
            }
        }
    }
    return cont;
}

int grafo::indegree(int v) {
    int cont = 0;
    for (int i = 0; i < this->vertice; i++) {
        if (i != v) {
            vector<int> B = *(this->lista[i]);
            for (int j = 0; j < B.size(); j++) {
                if (B[j] == v) cont++;
            }
        }
    }
    return cont;
}


int main() {
    grafo g1(4);
    g1.addEdge(2, 1);
    g1.addEdge(3, 5);
    g1.addEdge(1, 3);
    g1.adj(3);
    cout << "---> " << g1.lista[1]->back() << endl;
    cout << g1.outdegree(1) << endl;
    cout << g1.indegree(1) << endl;
    return 0;
}