#pragma once
#ifndef _MATRIZ_ADYACENCIA_
#define _MATRIZ_ADYACENCIA_
#include <iostream>
#include <vector>
using namespace std;

class matrizadyacencia {
private:
	int size;
	int **matriz;
	void init() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				matriz[i][j] = 0;
			}
		}
	}
public:
	matrizadyacencia();
	matrizadyacencia(int);
	void print();
	void addEdge(int, int);
	void adj(int);
	int outdegree(int);
	int indegree(int);
	void reverse();
};

matrizadyacencia::matrizadyacencia()
{
	this->size = 0;
	this->matriz = nullptr;
}

matrizadyacencia::matrizadyacencia(int size)
{
	this->size = size;
	this->matriz = new int* [this->size];
	for (int i = 0; i < this->size; i++) {
		this->matriz[i] = new int[this->size];
	}
	this->init();
}

void matrizadyacencia::print() {
	cout << "MATRIZ ADYACENCIA" << endl;
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			cout << *(*(this->matriz + i) + j) << "\t ";
		}
		cout<<endl;
	}
}
void matrizadyacencia::addEdge(int v1, int v2) {
	if (v1 > this->size || v2 > this->size) {
		cout << "El vertice no existe" << endl;
	}
	else {
		this->matriz[v1][v2] = 1;
		this->matriz[v2][v1] = 1;
	}
}
 void matrizadyacencia::adj(int v){
	 cout << "Lista de vertices adyacentes al vertice " << v <<": ";
	 for (int i = 0; i < this->size; i++) {
		 if (this->matriz[v][i] == 1) {
			 cout << i << ",";
		 }
	 }
	 cout << endl;
 }

 int matrizadyacencia::outdegree(int v) {
	 int c=0;
	 for (int i = 0; i < this->size; i++) {
		 if (this->matriz[v][i] == 1) {
			 c++;
		 }
	 }
	 return c;
 }

 int matrizadyacencia::indegree(int v) {
	 int cont=0;
	 for (int i = 0; i < this->size; i++) {
		 if (this->matriz[i][v] == 1) {
			 cont++;
		 }
	 }
	 return cont;
 }

 void matrizadyacencia::reverse() {
	 for (int i = 0; i < this->size; i++) {
		 for (int j = 0; j < this->size; j++) {
			 if (matriz[i][j] == 1) {
				 matriz[i][j] = 0;
			 }
			 else if (matriz[i][j] == 0) {
				 matriz[i][j] = 1;
			 }
		 }
	 }
	 this->print();
 }

#endif