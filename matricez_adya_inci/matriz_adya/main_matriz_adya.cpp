#include <iostream>
#include <vector>
#include "Matrizadya.h"
using namespace std;

  int main() {
        matrizadyacencia m1(4);
        m1.addEdge(0, 1);
        m1.addEdge(2, 1);
        m1.addEdge(3, 2);
        m1.addEdge(1, 3);
        m1.addEdge(1, 2);
        m1.print();
        m1.adj(3);
        cout << "numero de vecinos del vertice: "<< m1.outdegree(3) << endl;
        cout << "numero de vecinos que apuntan al vertice: " << m1.indegree(3) << endl;
        m1.reverse();
    }