#include "iostream"
#include "vector"
#include "Matriz_incidencia.h"
using namespace std;

int main() {
    MatInci m1(4,5);
    m1.addEdge(0, 1);
    m1.addEdge(0, 2);
    m1.addEdge(2, 1);
    m1.addEdge(1, 3);
    m1.addEdge(2, 3);
    
    m1.print();
   // m1.adj(0);
    cout<<"numero de vecinos del vertice: "<<m1.outdegree(1)<<endl;
    cout<<"nmero de vecinos que apuntan al vertice: "<<m1.indegree(1)<<endl;

}