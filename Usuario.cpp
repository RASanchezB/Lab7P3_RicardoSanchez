#include "Usuario.h"
#include <iostream>

using namespace std;

Usuario::Usuario(){
}
Usuario::Usuario(string pUsername, string pPassword, string pNombre, int pEdad, string pID, string pNumT){
	Username = pUsername;
	Password = pPassword;
	Nombre = pNombre;
	Edad = pEdad;
	ID = pID;
	NumT = pNumT;
}
//Getters
string Usuario::getUsername(){
	return Username;
}
string Usuario::getPassword(){
	return Password;
}
string Usuario::getNombre(){
	return Nombre;
}
int Usuario::getEdad(){
	return Edad;
}
string Usuario::getID(){
	return ID;
}
string Usuario::getNumT(){
	return NumT;
}
//Setters
void Usuario::setUsername(string pUsername){
	Username = pUsername;
}
void Usuario::setPassword(string pPassword){
	Password = pPassword;
}
void Usuario::setNombre(string pNombre){
	Nombre = pNombre;
}
void Usuario::setEdad(int pEdad){
	Edad = pEdad;
}
void Usuario::setID(string pID){
	ID = pID;
}
void Usuario::setNumT(string pNumT){
	NumT = pNumT;
}
Usuario::~Usuario(){}
