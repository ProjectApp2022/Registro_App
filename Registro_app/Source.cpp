#include <iostream>
#include <fstream>
#include <conio.h>
#include"Archivos.h"
#include "Arreglo.h"
using namespace std;
template <class T>
void buscar(string nombre) {
	Archivos* buscarusuario = new Archivos;
	buscarusuario->buscarpornombre();
}
int menu() {
	int men;
	system("cls");
	cout << "<-----Bienvenido a la base de Datos de APPs----->" << endl;
	cout << "1.- Agregar Usuario" << endl;
	cout << "2,. Ver Usuarios" << endl;
	cout << "3,. Buscar Usuarios" << endl;
	cout << "4,. Editar Usuarios" << endl;
	cout << "5,. Eliminar Usuarios" << endl;
	cout << "6.- Salir" << endl;
	cout << "Opcion:";
	cin >> men;
	return men;
}
int main() {
	ofstream Escritura;
	ifstream lectura;
	LinkedList<Archivos*>archivo;
	int m;
	do
	{
		m = menu();
		switch (m)
		{
		case 1:archivo.push(Escritura); break;
		case 2:archivo.printList(lectura); break;
		case 3:archivo.buscarelement(lectura); break;
		case 4:archivo.editelement(lectura); break;
		case 5:archivo.deleteNode(lectura); break;
		}
	} while (m != 6);
	return 0;
}

////int main() {
////	ofstream Escritura;
////	ifstream lectura;
////	LinkedList<Archivos*>archivo;
////	int men;
////	do
////	{
////		system("cls");
////		cout << "<-----Bienvenido a la Base de Datos de las APP----->" << endl;
////		cout << "1.- Agregar Usuario" << endl;
////		cout << "2,. Ver Usuarios" << endl;
////		cout << "3,. Buscar Usuarios" << endl;
////		cout << "4,. Editar Usuarios" << endl;
////		cout << "5,. Eliminar Usuarios" << endl;
////		cout << "6.- Salir" << endl;
////		cout << "Opcion:";
////		cin >> men;
////		switch (men)
////		{
////
////		case 1:archivo.push(Escritura); break;
////		case 2:archivo.printList(lectura); break;
////		case 3:archivo.buscarelement(lectura); break;
////		case 4:archivo.editelement(lectura); break;
////		case 5:archivo.deleteNode(lectura); break;
////		}
////
////	} while (men != 6);
////	return 0;
////}