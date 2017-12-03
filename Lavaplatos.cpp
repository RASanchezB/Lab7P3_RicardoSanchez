#include "Personal.h"
#include "Lavaplatos.h"

Lavaplatos::Lavaplatos(){

}
Lavaplatos::Lavaplatos(string pUsername, string pPassword,string pNombre, int pEdad,string pID, string pNumero, string pFecha, double pSueldo,int pMotivacion){
	Motivacion = pMotivacion;
}
int Lavaplatos::getMotivacion(){
	return Motivacion;
}
void Lavaplatos::setMotivacion(int pMotivacion){
	Motivacion = pMotivacion;
}
Lavaplatos::~Lavaplatos(){}
