#pragma once
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include <Windows.h>
//#include "Arreglo.h"
using namespace std;
class Archivos
{
public:
	void agregarUsuario(ofstream& archivo) {
		system("cls");
		cout << "Digite el nombre de la App en .txt: ";
		cin>>nameapp;
		archivo.open(nameapp.c_str(), ios::out | ios::app);
		cout << "Agregar el nombre del usuario" << endl;
		cin >> nombre;
		cout << "Agregar el apellido del usuario" << endl;
		cin >> apellido;
		cout << "Agregar Codigo: ";
		cin >> codigo;
		cout << "Agregar edad: ";
		cin >> edad;
		cout << "Agregar distrito de residencia: ";
		cin >> ruta;
		archivo << nombre << " " << apellido << " " << codigo << " " << edad << " " << ruta << "\n";
		archivo.close();
	}
	void verUsuarios(ifstream& archivo) {
		system("cls");
		cout << "Digite la App en .txt que desea visualizar: ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::in);
		cout << "\nUsuarios Registrados:" << endl;
		archivo >> nombre;
		while (!archivo.eof())
		{
			archivo >> apellido;
			archivo >> codigo;
			archivo >> edad;
			archivo >> ruta;
			cout << "Nombre-----:" << nombre << endl;
			cout << "Apellido---:" << apellido << endl;
			cout << "Codigo-----:" << codigo << endl;
			cout << "Edad-----:" << edad << endl;
			cout << "Ruta de desplazaciamiento-----:" << ruta << endl;
			cout << "****************************************************" << endl;
			archivo >> nombre;

		}

		archivo.close();
		system("pause");
	}
	void Buscarusuario(ifstream& archivo) {
		system("cls");
		cout << "Digite la App en .txt para buscar el usuario: ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::in);
		bool usuarioencontrado = false;
		cout << "Digite el codigo que desea buscar" << endl;
		cin >> codigoaux;
		archivo >> nombre;
		while (!archivo.eof() && !usuarioencontrado)
		{
			archivo >> apellido;
			archivo >> codigo;
			if (codigo == codigoaux)
			{
				cout << "Nombre-----:" << nombre << endl;
				cout << "Apellido---:" << apellido << endl;
				cout << "Codigo-----:" << codigo << endl;
				cout << "Edad-----:" << edad << endl;
				cout << "Ruta de desplazaciamiento-----:" << ruta << endl;
				cout << "****************************************************" << endl;
				usuarioencontrado = true;
			}
			archivo >> nombre;
		}
		archivo.close();
		if (!usuarioencontrado)
		{
			cout << "*****El usuario que desea encontrar no existe o no esta registrado*****" << endl;

		}
		system("pause");
	}
	void Editarusuario(ifstream& archivo) {
		system("cls");
		cout << "Digite la App en .txt para editar el nombre de usuario: ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::in);
		ofstream archivoaux("datosauxiliar.txt", ios::out);
		if (archivo.is_open())
		{
			cout << "\nDigite el DNI del usuario: ";
			cin >> codigoaux;
			archivo >> nombre;
			while (!archivo.eof())
			{
				archivo >> apellido;
				archivo >> codigo;
				if (codigo == codigoaux)
				{
					cout << "Digite el nuevo Nombre: " << endl;
					cin >> nombreaux;
					archivoaux << nombreaux << " " << apellido << " " << codigo <<edad <<" "<<ruta<< "\n";
				}
				else {
					archivoaux << nombre << " " << apellido << " " << codigo << edad << " " << ruta << "\n";
				}
				archivo >> nombre;
			}
			archivo.close();
			archivoaux.close();
		}
		remove(nameapp.c_str());
		rename("datosauxiliar.txt", nameapp.c_str());
	}
	void ElimintarUsuario(ifstream& archivo) {
		system("cls");
		cout << "Digite la App en .txt para eliminar el usuario: ";
		cin >> nameapp;
		archivo.open(nameapp.c_str(), ios::in);
		ofstream archivoaux("datosauxiliar.txt", ios::out);
		if (archivo.is_open())
		{
			cout << "\nDigite el DNI del usuario: ";
			cin >> codigoaux;
			archivo >> nombre;
			while (!archivo.eof())
			{
				archivo >> apellido;
				archivo >> codigo;
				if (codigo == codigoaux)
				{
					cout << "El usuario ha sido eliminado " << endl;
					system("pause");

				}
				else {
					archivoaux << nombre << " " << apellido << " " << codigo << edad << " " << ruta << "\n";
				}
				archivo >> nombre;
			}
			archivo.close();
			archivoaux.close();
		}
		remove(nameapp.c_str());
		rename("datosauxiliar.txt", nameapp.c_str());
	}
	void buscarpornombre() {

	}
private:

	string nombre, apellido, nombreaux, codigo, codigoaux, edad, ruta,nameapp;
};




