#include "Cliente.h"
#include <iostream>
#include <string>

using namespace std;

Cliente::Cliente(){}
Cliente::Cliente(string pUsername,string pPassword,string pNombre, int pEdad, string pID, string pNumT, string pDireccion, int pRating):Usuario(pUsername,pPassword,pNombre,pEdad,pID,pNumT){
	Direccion = pDireccion;
	Rating = pRating;
}
string Cliente::getDireccion(){
	return Direccion;
}
int Cliente::getRating(){
	return Rating;
}
void Cliente::setDireccion(string pDireccion){
	Direccion = pDireccion;
}
void Cliente::setRating(int pRating){
	Rating = pRating;
}
Cliente::~Cliente(){}
