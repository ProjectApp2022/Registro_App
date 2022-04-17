#include<iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Archivos.h"
using namespace std;
template <class T>
class Node {
public:
	T data;
	Node<T>* next;
};

template <class T>
class LinkedList
{
private:
	Archivos* archivo;
	T data;
	int tam;
public:
	Node<T>* first;
	Node<T>* last;
	ofstream Escritura;
	ifstream lectura;

	// Constructor:
	LinkedList<T>() {
		archivo = new Archivos;
		tam = 0;
		first = NULL;
		last = NULL;
	}

	// Metodos:

	// Devuelve el elemento de una posición dada:
	T get(int index) {

		if (index == 0) {                     //1
			return this->first->data;         //n^2
		}
		else {
			Node<T>* curr = this->first;      //n^2
			for (int i = 0; i < index; ++i) { //n^2+n+2
				curr = curr->next;
			}
			return curr->data;                //n^2
		}
	}
	//BigO 3n^2+n+3 ->>>> 3n^2
	int getSize() {
		return tam;
	}
	// Agrega un elemento al inicio de la lista:
	void buscarelement(ifstream& Escritura) {
		Node<T>* aux = first;                //1
		archivo->Buscarusuario(Escritura);   //n
		while (aux != NULL) {                //n
			cout << " " << aux->data;        //n^2
			aux = aux->next;                 //n^3
		}
		cout << endl;
	}
	//BigO
	void editelement(ifstream& Escritura) {
		Node<T>* aux = first;              //1
		archivo->Editarusuario(Escritura); //n
		while (aux != NULL) {              //n
			cout << " " << aux->data;     //n^2
			aux = aux->next;              //n^3
		}
		cout << endl;
	}
	//BigO n^3+n^2+2n+1 ->>> n^3
	void push(ofstream& Escritura) {
		Node<T>* aux = new Node<T>;         //1
		archivo->agregarUsuario(Escritura); //n
		aux->data = data;                   //n^3
		aux->next = first;                  //n^3
		first = aux;                        //n^2

		tam++;
	}
	//BigO 2n^3+n^3n+1 ->>> 2n^3

	// Agrega un elemento al final de la lista:
	void add(ifstream& Escritura) {
		archivo->agregarUsuario(Escritura);
		if (!first) { // Lista vacia	//1
			first = new Node<T>;        //n*2
			first->data = data;         //n*3
			first->next = NULL;         //n*2
			last = first;               //n*2
		}
		else { // Lista con elementos
			if (last == first) {        //n*2
				last = new Node<T>;     //n*2
				last->data = data;      //n*3
				last->next = NULL;      //n*2
				first->next = last;     //n*3
			}
			else {
				Node<T>* aux = new Node<T>;//1
				aux->data = data;       //n*2
				aux->next = NULL;  //n*2
				last->next = aux; //n*3
				last = aux;  //n*2
			}
		}tam++;

	}
	//big O 4n^3+9n^2+2 ->>> 4n^3
	// Elimina un elemento de la lista:
	void deleteNode(ifstream& lectura) {
		archivo->ElimintarUsuario(lectura);
		if (first->data == data) {              //1+n^2
			first = first->next;                //n^3
		}
		else {
			Node<T>* aux = first;              //1
			while (aux->next != NULL) {        //n^2
				if (aux->next->data == data) { //n^3
					aux->next = aux->next->next;//n^3
				}
				else {
					aux = aux->next; //n^3
				}
			}
		}
		tam--;
	}
	//Big0 4n^3+2n^2+2
	// Imprimir lista
	void printList(ifstream& lectura) {
		archivo->verUsuarios(lectura); 
		Node<T>* aux = first;         //1
		while (aux != NULL) {         //n
			cout << " " << aux->data; //n^2
			aux = aux->next;          //n^3
		}
		cout << endl;
	}
	//BigO n^3+n^2+n+1
};
