#pragma once
#ifndef _MATRIZ_INCIDENCIA_
#define _MATRIZ_INCIDENCIA_
#include <iostream>
#include <vector>
using namespace std;

class MatInci {
private:
	int size;
	int aristas;
	int** matriz;
	void init() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < aristas; j++) {
				matriz[i][j] = 0;
			}
		}
	}
public:
	MatInci();
	MatInci(int, int);
	void print();
	void addEdge(int, int);
	void adj(int);
	int outdegree(int);
	int indegree(int);
};

MatInci::MatInci()
{
	this->size = 0;
	this->aristas = 0;
	this->matriz = nullptr;
}
MatInci::MatInci(int size, int aristas)
{
	this->size = size;
	this->aristas = aristas;
	this->matriz = new int* [this->size];
	for (int i = 0; i < this->size; i++) {
		this->matriz[i] = new int[this->size];
	}
	this->init();
}

void MatInci::print() {
	cout << "MATRIZ INCIDENCIA" << endl;
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->aristas; j++) {
			cout << *(*(this->matriz + i) + j) << "\t ";
		}
		cout << endl;
	}
}

int ed_no = 0;
void MatInci::addEdge(int v1, int v2) {
	if (v1 > this->size || v2 > this->size) {
		cout << "El vertice no existe" << endl;
	}
	else {
		this->matriz[v1][ed_no] = -1;
		this->matriz[v2][ed_no] = 1;
		ed_no++;
	}
}

void MatInci::adj(int v) {//falta indicar etiquetas para mostrar correctamente los vertices adyacentes
	cout << "Lista de vertices adyacentes al vertice " << v << ": ";
	for (int i = 0; i < this->aristas; i++) {
		if (this->matriz[v][i] == -1|| this->matriz[v][i]==1) {
			cout << i << ",";
		}
	}
	cout << endl;
}

int MatInci::outdegree(int v) {
	int c = 0;
	for (int i = 0; i < this->aristas; i++) {
		if (this->matriz[v][i] == -1|| this->matriz[v][i] ==1) {
			c++;
		}
	}
	return c;
}

int MatInci::indegree(int v) {
	int cont = 0;
	for (int i = 0; i < this->aristas; i++) {
		if (this->matriz[v][i] == -1) {
			cont++;
		}
	}
	return cont;
}


#endif
