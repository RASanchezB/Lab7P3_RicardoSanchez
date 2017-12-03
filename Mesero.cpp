#include "Personal.h"
#include "Mesero.h"
#include <iostream>
#include <vector>

using namespace std;

Mesero::Mesero(){}
Mesero::Mesero(string pUsername,string pPassword,string pNombre,int pEdad,string pID,string pNumT, string pFecha, double pSueldo):Personal(pUsername,pPassword,pNombre,pEdad,pID,pNumT,pFecha,pSueldo){

}
void Mesero::UnPlato(){
	int opcion = 0;
	cout<<"Lista de lo platillos por entregar: "<<endl;
	for(int i = 0; i < lista.size();i++){
		cout<<i<<lista.at(i)<<endl;
	}
	cout<<"Ingrese el numero del platillo que va a entregar: "<<endl;
	cin>>opcion;
	lista.erase(lista.begin()+opcion);
}
void Mesero::Todos(){
	for(int i = 0; i < lista.size(); i++){
		lista.erase(lista.begin()+i);
	}
	cout<<"Todos los platillos han sido entregado"<<endl;
}
vector<string> Mesero::getLista(){
	return lista;
}
void Mesero::setLista(vector<string> pLista){
	lista = pLista;
}
Mesero::~Mesero(){}
