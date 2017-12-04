#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <fstream>
//incluir las clases
#include "Usuario.h"
#include "Cliente.h"
#include "Personal.h"
#include "Administrador.h"
#include "Chef.h"
#include "Lavaplatos.h"
#include "Mesero.h"

using namespace std;

//metodos a usar
vector<Usuario*> Contratar(vector<Usuario*>,Usuario*);
vector<Usuario*> Despedir(vector<Usuario*>,Usuario*);
string SueldoBajo(vector<Usuario*>);
string SueldoAlto(vector<Usuario*>);
Mesero* PlatilloN(vector<Usuario*>,int);
double SueldoProm(vector<Usuario*>);
void EscribirA(vector<Usuario*>);
vector<Usuario*> LeerA();
//main
int main(){
	cout<<"Laboratorio 7 Programacion 3"<<endl;
	vector <Usuario*> listaU;
	Usuario* Ingreso;
	int opcion = 0;
	while(opcion != 4){
		cout<<"-----Menu-----"<<endl
		<<"1)Log In"<<endl
		<<"2)Crear Administrador"<<endl
		<<"3)Escribir Archivo"<<endl
		<<"4)salir"<<endl;
		cout<<"Ingrese el numero de la opcion que desea"<<endl;
		switch(opcion){
			case 1:{
				string User;
				string Pass;
				cout<<"Log In"<<endl;
				cout<<"Ingrese su nombre de usuario"<<endl;
				cin>>User;
				cout<<"Ingrese su contraseña"<<endl;
				cin>>Pass;
				for (size_t i = 0; i < listaU.size(); i++) {
					if(listaU.at(i)->getUsername()==User){
						if(listaU.at(i)->getPassword()==Pass){
							cout<<"Bienvenido "<<listaU.at(i)->getNombre()<<endl;
							Ingreso = listaU.at(i);
							if(dynamic_cast<Administrador*>(Ingreso)){
								int opcionA = 0;
								cout<<"---Menu de Admin---"<<endl
								<<"1)Contratar"<<endl
								<<"2)Despedir"<<endl
								<<"3)Personal con sueldo mas bajo"<<endl
								<<"4)Agregar platillo"<<endl
								<<"5)Personal con sueldo mas alto"<<endl
								<<"6)Salario promedio"<<endl
								<<"Ingrese la opcion que desea"<<endl;
								cin>>opcionA;
								switch(opcionA){//Menu del Administrador
									case 1:{

									}
										break;
									case 2:{}
										break;
									case 3:{}
										break;
									case 4:{}
										break;
									case 5:{}
										break;
									case 6:{}
										break;
									default:{}break;
								}

							}
						}
					}
				}
			}
				break;
			case 2:{
				string Nombre, Username, Password, ID, Fecha, NumT;
				int Edad;
				double Sueldo;
				bool Pasa = false;
				cout<<"Creando un Administrador"<<endl;
				cout<<"Ingrese su Nombre:"<<endl;
				cin>>Nombre;
				cout<<"Ingrese su nombre de usuario:"<<endl;
				cin>>Username;
				cout<<"Ingrese su Password:"<<endl;
				cin>>Password;
				cout<<"Ingrese su edad:"<<endl;
				cin>>Edad;
				cout<<"Ingrese su fecha de contratacion:"<<endl;
				cin>>Fecha;
				cout<<"Ingrese su numero de telefono:"<<endl;
				cin>>NumT;
				while(Pasa == false){
					cout<<"Ingrese su sueldo"<<endl;
					cin>>Sueldo;
					if(cin.fail()){
						cin.clear();
						cin.ignore();
					}else{
						Pasa = true;
					}
				}
				Usuario* PersonaN = new Administrador(Username,Password,Nombre,Edad,ID,NumT,Fecha,Sueldo,0,0);
				listaU.push_back(PersonaN);
}
				break;
			case 3:{}
				break;
			default:{}
				break;
		}
	}
	return 0;
}
vector<Usuario*> Contratar(vector<Usuario*> listaU, Usuario* Ingreso){
	string Username, Password, Nombre, ID, NumT;
	int Edad;
	cout<<endl;
	cout<<"Contratando"<<endl;
	cout<<"Ingrese el nombre"<<endl;
	cin>>Nombre;
	cout<<"Ingrese el nombre de Usuario"<<endl;
	cin>>Username;
	cout<<"Ingrese la contraseña"<<endl;
	cin>>Password;
	cout<<"Ingrese la edad"<<endl;
	cin>>Edad;
	cout<<"Ingrese el ID"<<endl;
	cin>>ID;
	cout<<"Ingrese el numero de telefono"<<endl;
	cin>>NumT;
	int opcionC = 0;
	cout<<endl;
	cout<<"Que tipo de trabajo hara el nuevo personal"<<endl
	<<"1)Cliente"<<endl
	<<"2)Administrador"<<endl
	<<"3)Chef"<<endl
	<<"4)Mesero"<<endl
	<<"5)Lavaplatos"<<endl
	<<"Elija la opcion que desea:"<<endl;
	cin>>opcionC;
	switch (opcionC) {
		case 1:{
			cout<<endl;
			cout<<"Agregando cliente"<<endl;
			string Direccion;
			int Rating;
			cout<<"Intrese la direccion"<<endl;
			cin>>Direccion;
			cout<<"Ingrese la calificacion que le dio al restaurante"<<endl;
			cin>>Rating;
			while(Rating < 1 || Rating > 5){
				cout<<"El numero ingresado no es valido. Ingrese otro:"<<endl;
				cin>>Rating;
			}
			listaU.push_back(new Cliente(Username,Password,Nombre,Edad,ID,NumT,Direccion,Rating));
		}
			break;
		case 2:{
			cout<<endl;
			cout<<"Agregando Administrador"<<endl;
			string Fecha;
			double Sueldo;
			cout<<"Ingrese la fecha en la que fue Contratado"<<endl;
			cin>>Fecha;
			cout<<"Ingrese el sueldo que gana"<<endl;
			cin>>Sueldo;
			listaU.push_back(new Administrador(Username,Password,Nombre,Edad,ID,NumT,Fecha,Sueldo,0,0));
		}
			break;
		case 3:{
			cout<<endl;
			cout<<"Agregando un chef"<<endl;
			string Fecha, Platillo;
			double Sueldo;
			cout<<"Ingrese la fecha en la que fue contratado"<<endl;
			cin>>Fecha;
			cout<<"Ingrese su platillo favorito"<<endl;
			cin>>Platillo;
			cout<<"Ingrese el sueldo"<<endl;
			cin>>Sueldo;
			listaU.push_back(new Chef(Username,Password,Nombre,Edad,ID,NumT,Fecha,Sueldo,Platillo));
		}
			break;
		case 4:{
			string Fecha;
			double Sueldo;
			cout<<endl;
			cout<<"Ingrese en que fecha fue Contratado"<<endl;
			cin>>Fecha;
			cout<<"Ingrese el sueldo"<<endl;
			cin>>Sueldo;
			listaU.push_back(new Mesero(Username,Password,Nombre,Edad,ID,NumT,Fecha,Sueldo));
		}
			break;
		case 5:{
			string Fecha;
			double Sueldo;
			cout<<endl;
			cout<<"Ingrese la fecha en la que fue contratado"<<endl;
			cin>>Fecha;
			cout<<"Ingrese el sueldo"<<endl;
			cin>>Sueldo;
			listaU.push_back(new Lavaplatos(Username,Password,Nombre,Edad,ID,NumT,Fecha,Sueldo,50));
		}
			break;
		default:{}break;
	}
	return listaU;
}
vector<Usuario*> Despedir(vector<Usuario*> listaU, Usuario* Ingreso){
	cout<<endl;
	cout<<"Despedir"<<endl;
	int eliminar;
	for (size_t i = 0; i < listaU.size(); i++) {
		if(dynamic_cast<Personal*>(listaU.at(i))){
			cout<<i<<". "<<listaU.at(i)->getNombre()<<endl;
		}
	}
	cout<<"Ingrese el numero que esta asignado al personal que desea despedir"<<endl;
	cin>>eliminar;
	listaU.erase(listaU.begin()+eliminar);
	dynamic_cast<Administrador*>(Ingreso)->setDespedidos(dynamic_cast<Administrador*>(Ingreso)->getDespedidos()+1);
	return listaU;
}
string SueldoBajo(vector<Usuario*> listaU){//DEBE SER EDITADO (INTRUCCIONES INCORRECTAS)
	vector<Usuario*> Sbajo;
	string pobrecillo = "";
	Personal* extra;
	double PagoBajo = 999999.99;
	for(int i = 0; listaU.size();i++){
		if(dynamic_cast<Personal*>(listaU.at(i))){
			extra = dynamic_cast<Personal*>(listaU.at(i));
			if(extra->getSueldo() < PagoBajo){
				Sbajo.push_back(extra);
				PagoBajo = extra->getSueldo();
			}
		}
	}
	for (size_t j = 0; j < Sbajo.size(); j++) {
		pobrecillo+=Sbajo.at(j)->getNombre();
		pobrecillo+=", ";
		delete Sbajo.at(j);
	}
	return pobrecillo;
}
string SueldoAlto(vector<Usuario*> listaU){//DEBE SER EDITADO (INTRUCCIONES INCORRECTAS)
	vector<Usuario*> SAlto;
	string Millonario = "";
	Personal* extra;
	double PagoAlto = 0;
	for (size_t i = 0; i < listaU.size(); i++) {
		if(dynamic_cast<Personal*>(listaU.at(i))){
			extra = dynamic_cast<Personal*>(listaU.at(i));
			if(extra->getSueldo() > PagoAlto){
				SAlto.push_back(extra);
				PagoAlto=extra->getSueldo();
			}
		}
	}
	for (size_t j = 0; j < SAlto.size(); j++) {
		Millonario+=SAlto.at(j)->getNombre();
		Millonario+=", ";
		delete SAlto.at(j);
	}
	return Millonario;
}
Mesero* PlatilloN(vector<Usuario*> listaU, int pos){
	Mesero* Elegido = dynamic_cast<Mesero*>(listaU.at(pos));
	return Elegido;
}
