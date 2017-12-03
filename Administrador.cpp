#include "Personal.h"
#include "Administrador.h"

#include <iostream>
#include <string>

using namespace std;

Administrador::Administrador(){}
Administrador::Administrador(string pUsername,string pPassword,string pNombre, int pEdad, string pID, string pNumT, string pFecha,double pSueldo,int pContratados, int pDespedidos):Personal(pUsername,pPassword,pNombre,pEdad,pID,pNumT,pFecha,pSueldo){
	Contratados = pContratados;
	Despedidos = pDespedidos;
}
int Administrador::getContratados(){
	return Contratados;
}
int Administrador::getDespedidos(){
	return Despedidos;
}
void Administrador::setContratados(int pContratados){
	Contratados = pContratados;
}
void Administrador::setDespedidos(int pDespedidos){
	Despedidos = pDespedidos;
}
