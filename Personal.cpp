#include "Personal.h"
#include <iostream>
#include <string>

using namespace std;

Personal::Personal(){}
Personal::Personal(string pUsername,string pPassword,string pNombre, int pEdad, string pID,string pNumT,string pFecha,double pSueldo):Usuario(pUsername,pPassword,pNombre,pEdad,pID,pNumT){
	Fecha = pFecha;
	Sueldo = pSueldo;
}
string Personal::getFecha(){
	return Fecha;
}
double Personal::getSueldo(){
	return Sueldo;
}
void Personal::setFecha(string pFecha){
	Fecha = pFecha;
}
void Personal::setSueldo(double pSueldo){
	Sueldo = pSueldo;
}
Personal::~Personal(){}
