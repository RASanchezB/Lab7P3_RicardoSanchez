#include "Personal.h"
#include "Usuario.h"
#include "Chef.h"

Chef::Chef(){}
Chef::Chef(string pUsername, string pPassword, string pNombre, int pEdad, string pID, string pNumT, string pFecha, double pSueldo, string pPlatillo):Personal(pUsername,pPassword,pNombre,pEdad,pID,pNumT,pFecha,pSueldo){
	Platillo = pPlatillo;
}
string Chef::getPlatillo(){
	return Platillo;
}
void Chef::setPlatillo(string pPlatillo){
	Platillo = pPlatillo;
}
Chef::~Chef(){}
