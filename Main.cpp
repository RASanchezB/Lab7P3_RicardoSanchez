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
//Metodos que se necesitan para los archivos
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
										listaU = Contratar(listaU,Ingreso);
										dynamic_cast<Administrador*>(Ingreso)->setContratados(dynamic_cast<Administrador*>(Ingreso)->getContratados() + 1);
									}
									break;
									case 2:{
										listaU = Despedir(listaU,Ingreso);
									}
									break;
									case 3:{
										string SB = SueldoBajo(listaU);
										cout<<"Los empleados de menor sueldo son: "<<SB<<endl;
									}
									break;
									case 4:{
										string Platillo;
										int pos;
										for (size_t i = 0; i < listaU.size(); i++) {
											if(dynamic_cast<Mesero*>(listaU.at(i))){
												cout<<i<<". "<<listaU.at(i)->getNombre()<<endl;
											}
										}
										cout<<"Ingrese el numero del mesero al cual le desea agregar el platillo"<<endl;
										cin>>pos;
										cout<<"Escriba como desea identificar el platillo: "<<endl;
										cin>>Platillo;
										Mesero* Nuevo = dynamic_cast<Mesero*>(listaU.at(pos));
										Nuevo->getLista().push_back(Platillo);
									}
									break;
									case 5:{
										string SM = "";
										SM = SueldoAlto(listaU);
										cout<<"Los miembros del personal con los salarios mas altos son: "<<SM<<endl;
									}
									break;
									case 6:{
										double SalarioP;
										SalarioP = SueldoProm(listaU);
										cout<<"Es salario promedio entre todos los miembros del personal es: "<<SalarioP<<endl;
									}
									break;
									default:{}break;
								}

							}else if(dynamic_cast<Mesero*>(Ingreso)){
								int opcionM = 0;
								cout<<"Menu Mesero"<<endl
								<<"1)Dejar un plato"<<endl
								<<"2)Dejar todos los platos"<<endl
								<<"Ingrese la opcion que desea: "<<endl;
								cin>>opcionM;
								switch (opcionM) {
									case 1:{
										vector<string>PlatillosA;
										int PlatoE = 0;
										PlatillosA = dynamic_cast<Mesero*>(Ingreso)->getLista();
										for (size_t i = 0; i < PlatillosA.size(); i++) {
											cout<<i<<". "<<PlatillosA.at(i)<<endl;
										}
										cout<<"Ingrese el numero del platillo que desea entregar"<<endl;
										cin>>PlatoE;
										PlatillosA.erase(PlatillosA.begin()+PlatoE);
									}break;
									case 2:{
										vector<string> PlatillosA;
										PlatillosA = dynamic_cast<Mesero*>(Ingreso)->getLista();
										for (size_t i = 0; i < PlatillosA.size(); i++) {
											PlatillosA.erase(PlatillosA.begin()+i);
										}
									}break;
									default:{}break;
								}
							}else if(dynamic_cast<Cliente*>(Ingreso)){
								double RatingP = 0;
								int contador = 0;
								for (size_t i = 0; i < listaU.size(); i++) {
									if(dynamic_cast<Cliente*>(listaU.at(i))){
										Cliente* temp = dynamic_cast<Cliente*>(listaU.at(i));
										RatingP+=temp->getRating();
										contador++;
									}
								}
								cout<<"El rating promedio del restaurante es de: "<<(RatingP/contador)<<endl;
							}else if(dynamic_cast<Lavaplatos*>(Ingreso)){
								int opcionL = 0;
								cout<<"Menu Lavaplatos"<<endl
								<<"1)Renunciar"<<endl
								<<"2)Pedir Aumento"<<endl
								<<"Ingrese el numero de la opcion que desea: "<<endl;
								cin>>opcionL;
								switch (opcionL) {
									case 1:{
										Lavaplatos* Renunciara = dynamic_cast<Lavaplatos*>(Ingreso);
										if(Renunciara->getMotivacion()<=25){
											for (size_t i = 0; i < listaU.size(); i++) {
												Usuario* R = dynamic_cast<Lavaplatos*>(listaU.at(i));
												if(dynamic_cast<Lavaplatos*>(listaU.at(i)) && Ingreso->getID() == R->getID()){
													listaU.erase(listaU.begin()+i);
												}
											}
										}else{
											cout<<"Todavia no se rinde y no renunciara"<<endl;
										}
									}break;
									case 2:{
										Lavaplatos* PAumento = dynamic_cast<Lavaplatos*>(Ingreso);
										if(PAumento->getMotivacion() >= 100){
											double Aumento = 0;
											cout<<"Ingrese su nuevo salario"<<endl;
											cin>>Aumento;
											for (size_t i = 0; i < listaU.size(); i++) {
												Usuario* PA = dynamic_cast<Lavaplatos*>(listaU.at(i));
												if(dynamic_cast<Lavaplatos*>(listaU.at(i)) && Ingreso->getID() == PA->getID()){
													dynamic_cast<Personal*>(listaU.at(i))->setSueldo(Aumento);
												}
											}
										}
									}break;
									default:{}break;
								}
							}else if(dynamic_cast<Chef*>(Ingreso)){
								int opcionCH;
								cout<<"Menu del chef"<<endl
								<<"1)Gritar a un Lavaplatos"<<endl
								<<"2)Agradecer a un Lavaplatos"<<endl
								<<"Ingrese el numero de la opcion que desea: "<<endl;
								cin>>opcionCH;
								switch (opcionCH) {
									case 1:{
										int Cantidad = 0;
										for (size_t i = 0; i < listaU.size(); i++) {
											if(dynamic_cast<Lavaplatos*>(listaU.at(i))){
												cout<<i<<". "<<listaU.at(i)->getNombre()<<endl;
												Cantidad++;
											}
										}
										if(Cantidad > 0){
											int Pos;
											int Bajon;
											cout<<"Ingrese la posicion del Lavaplatos al cual gritar"<<endl;
											cin>>Pos;
											cout<<"Cuantos puntos de autoestima le rebajara"<<endl;
											cin>>Bajon;
											Lavaplatos* BajaAE = dynamic_cast<Lavaplatos*>(listaU.at(Pos));
											BajaAE->setMotivacion(BajaAE->getMotivacion()-Bajon);
										}else{
											cout<<"No hay Lavaplatos"<<endl;
										}
									}break;
									case 2:{
										int Cantidad = 0;
										for (size_t i = 0; i < listaU.size(); i++) {
											if(dynamic_cast<Lavaplatos*>(listaU.at(i))){
												cout<<i<<". "<<listaU.at(i)->getNombre()<<endl;
												Cantidad++;
											}
										}
										if(Cantidad > 0){
											int Pos;
											int Subir;
											cout<<"Ingrese la posicion del Lavaplatos al cual agradecer"<<endl;
											cin>>Pos;
											cout<<"Cuantos puntos de autoestima le aumentara"<<endl;
											cin>>Subir;
											Lavaplatos* SubirAE = dynamic_cast<Lavaplatos*>(listaU.at(Pos));
											SubirAE->setMotivacion(SubirAE->getMotivacion()+Subir);
										}else{
											cout<<"No hay Lavaplatos"<<endl;
										}
									}break;
									default:{}break;
								}

							}else{
								cout<<"Disculpe pero no se pudo meter a ninguna cuenta existente"<<endl;
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
			case 3:{//Escribir Archivo
				if(listaU.size() > 0){
					EscribirA(listaU);
					cout<<"Archivo escrito"<<endl;
				}else{
					cout<<"No se guardo nada ya que la lista esta vacia"<<endl;
				}
			}
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
double SueldoProm(vector<Usuario*>listaU){
	int promedio = 0;
	int cantidadP = 0;
	for (size_t i = 0; i < listaU.size(); i++) {
		if(dynamic_cast<Personal*>(listaU.at(i))){
			promedio+=dynamic_cast<Personal*>(listaU.at(i))->getSueldo();
			cantidadP++;
		}
	}
	return (promedio/cantidadP);
}
void EscribirA(vector<Usuario*> listaU){
	Usuario* Escribir;
	ofstream afile("Restaurante.txt");
	if(afile.is_open()){
		for (size_t i = 0; i < listaU.size(); i++) {
			Escribir = listaU.at(i);
			if(dynamic_cast<Administrador*>(Escribir)){
				string User,Pass,Nom,ID,NumT,Fecha;
				int Edad,Con,Des;
				double Salario;
				char Tipo = 'A';
				string Archivo = "";
				Administrador* A = dynamic_cast<Administrador*>(Escribir);
				User = A->getUsername();
				Pass = A->getPassword();
				Nom = A->getNombre();
				Edad = A->getEdad();
				ID=A->getID();
				NumT=A->getNumT();
				Fecha=A->getFecha();
				Salario=A->getSueldo();
				Con=A->getContratados();
				Des=A->getDespedidos();
				Archivo+=Tipo;
				Archivo+=", ";
				Archivo+=User;
				Archivo+=", ";
				Archivo+=Pass;
				Archivo+=", ";
				Archivo+=Nom;
				Archivo+=", ";
				Archivo+=Edad;
				Archivo+=", ";
				Archivo+=ID;
				Archivo+=", ";
				Archivo+=NumT;
				Archivo+=", ";
				Archivo+=Fecha;
				Archivo+=", ";
				Archivo+=Salario;
				Archivo+=", ";
				Archivo+=Con;
				Archivo+=", ";
				Archivo+=Des;
				Archivo+=";";
				afile<<Archivo;
			}else if(dynamic_cast<Chef*>(Escribir)){
				string User,Pass,Nom,ID,NumT,Fecha,Platillo;
				int Edad;
				double Salario;
				char Tipo = 'C';
				string Archivo = "";
				Chef* A = dynamic_cast<Chef*>(Escribir);
				User = A->getUsername();
				Pass = A->getPassword();
				Nom = A->getNombre();
				Edad = A->getEdad();
				ID=A->getID();
				NumT=A->getNumT();
				Fecha=A->getFecha();
				Salario=A->getSueldo();
				Platillo=A->getPlatillo();
				Archivo+=Tipo;
				Archivo+=", ";
				Archivo+=User;
				Archivo+=", ";
				Archivo+=Pass;
				Archivo+=", ";
				Archivo+=Nom;
				Archivo+=", ";
				Archivo+=Edad;
				Archivo+=", ";
				Archivo+=ID;
				Archivo+=", ";
				Archivo+=NumT;
				Archivo+=", ";
				Archivo+=Fecha;
				Archivo+=", ";
				Archivo+=Salario;
				Archivo+=", ";
				Archivo+=Platillo;
				Archivo+=";";
				afile<<Archivo;
			}else if(dynamic_cast<Lavaplatos*>(Escribir)){
				string User,Pass,Nom,ID,NumT,Fecha;
				int Edad,Mot;
				double Salario;
				char Tipo = 'L';
				string Archivo = "";
				Lavaplatos* A = dynamic_cast<Lavaplatos*>(Escribir);
				User = A->getUsername();
				Pass = A->getPassword();
				Nom = A->getNombre();
				Edad = A->getEdad();
				ID=A->getID();
				NumT=A->getNumT();
				Fecha=A->getFecha();
				Salario=A->getSueldo();
				Mot=A->getMotivacion();
				Archivo+=Tipo;
				Archivo+=", ";
				Archivo+=User;
				Archivo+=", ";
				Archivo+=Pass;
				Archivo+=", ";
				Archivo+=Nom;
				Archivo+=", ";
				Archivo+=Edad;
				Archivo+=", ";
				Archivo+=ID;
				Archivo+=", ";
				Archivo+=NumT;
				Archivo+=", ";
				Archivo+=Fecha;
				Archivo+=", ";
				Archivo+=Salario;
				Archivo+=", ";
				Archivo+=Mot;
				Archivo+=";";
				afile<<Archivo;
			}else if(dynamic_cast<Mesero*>(Escribir)){
				string User,Pass,Nom,ID,NumT,Fecha;
				int Edad;
				double Salario;
				char Tipo = 'C';
				string Archivo = "";
				Mesero* A = dynamic_cast<Mesero*>(Escribir);
				User = A->getUsername();
				Pass = A->getPassword();
				Nom = A->getNombre();
				Edad = A->getEdad();
				ID=A->getID();
				NumT=A->getNumT();
				Fecha=A->getFecha();
				Salario=A->getSueldo();
				Archivo+=Tipo;
				Archivo+=", ";
				Archivo+=User;
				Archivo+=", ";
				Archivo+=Pass;
				Archivo+=", ";
				Archivo+=Nom;
				Archivo+=", ";
				Archivo+=Edad;
				Archivo+=", ";
				Archivo+=ID;
				Archivo+=", ";
				Archivo+=NumT;
				Archivo+=", ";
				Archivo+=Fecha;
				Archivo+=", ";
				Archivo+=Salario;
				Archivo+=";";
				afile<<Archivo;
			}else if(dynamic_cast<Cliente*>(Escribir)){
				string User,Pass,Nom,ID,NumT,Fecha,Direccion;
				int Edad,Rating;
				char Tipo = 'O';
				string Archivo = "";
				Cliente* A = dynamic_cast<Cliente*>(Escribir);
				User = A->getUsername();
				Pass = A->getPassword();
				Nom = A->getNombre();
				Edad = A->getEdad();
				ID=A->getID();
				NumT=A->getNumT();
				Direccion=A->getDireccion();
				Rating=A->getRating();
				Archivo+=Tipo;
				Archivo+=", ";
				Archivo+=User;
				Archivo+=", ";
				Archivo+=Pass;
				Archivo+=", ";
				Archivo+=Nom;
				Archivo+=", ";
				Archivo+=Edad;
				Archivo+=", ";
				Archivo+=ID;
				Archivo+=", ";
				Archivo+=NumT;
				Archivo+=", ";
				Archivo+=Direccion;
				Archivo+=", ";
				Archivo+=Rating;
				Archivo+=";";
				afile<<Archivo;
			}
		}
		afile.close();
	}
}
vector<Usuario*> LeerA(){
	vector<Usuario*> v;
	fstream file("Restaurante.txt");
	if(file.is_open()){
		while(!file.eof()){
			string Linea,Tipo,User,Pass,Nom,ID,NumT,EdadT,Fecha,SalarioT;
			int Edad;
			double Salario;
			getline(file,Tipo,',');
			if(Tipo=="A"){
				string ConT,DesT;
				int Con,Des;
				getline(file,User,',');
				getline(file,Pass,',');
				getline(file,Nom,',');
				getline(file,EdadT,',');
				Edad = 0;
				getline(file,ID,',');
				getline(file,NumT,',');
				getline(file,Fecha,',');
				getline(file,SalarioT,',');
				Salario = 0;
				getline(file,ConT,',');
				Con = 0;
				getline(file,DesT,';');
				Des = 0;
				v.push_back(new Administrador(User,Pass,Nom,Edad,ID,NumT,Fecha,Salario,Con,Des));
			}else if(Tipo=="C"){
				string Platillo;
				getline(file,User,',');
				getline(file,Pass,',');
				getline(file,Nom,',');
				getline(file,EdadT,',');
				Edad = 0;
				getline(file,ID,',');
				getline(file,NumT,',');
				getline(file,Fecha,',');
				getline(file,SalarioT,',');
				Salario = 0;
				getline(file,Platillo,',');
				v.push_back(new Chef(User,Pass,Nom,Edad,ID,NumT,Fecha,Salario,Platillo));
			}else if(Tipo=="M"){
				getline(file,User,',');
				getline(file,Pass,',');
				getline(file,Nom,',');
				getline(file,EdadT,',');
				Edad = 0;
				getline(file,ID,',');
				getline(file,NumT,',');
				getline(file,Fecha,',');
				getline(file,SalarioT,',');
				Salario = 0;
				v.push_back(new Mesero(User,Pass,Nom,Edad,ID,NumT,Fecha,Salario));
			}else if(Tipo=="L"){
				string MotT;
				int Mot;
				getline(file,User,',');
				getline(file,Pass,',');
				getline(file,Nom,',');
				getline(file,EdadT,',');
				Edad = 0;
				getline(file,ID,',');
				getline(file,NumT,',');
				getline(file,Fecha,',');
				getline(file,SalarioT,',');
				Salario = 0;
				getline(file,MotT,',');
				Mot = 0;
				v.push_back(new Lavaplatos(User,Pass,Nom,Edad,ID,NumT,Fecha,Salario,Mot));
			}else if(Tipo=="O"){
				string Direccion,RatingT;
				int Rating;
				getline(file,User,',');
				getline(file,Pass,',');
				getline(file,Nom,',');
				getline(file,EdadT,',');
				Edad = 0;
				getline(file,ID,',');
				getline(file,NumT,',');
				getline(file,Fecha,',');
				getline(file,Direccion,',');
				getline(file,RatingT,',');
				Rating = 0;
				v.push_back(new Cliente(User,Pass,Nom,Edad,ID,NumT,Direccion,Rating));

			}
		}
		file.close();
		return v;
	}
}
