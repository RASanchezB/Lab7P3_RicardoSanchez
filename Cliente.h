#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include <iostream>
#include <string>

using namespace std;

class Cliente: public Usuario{
	private:
		string Direccion;
		int Rating;
	public:
		//constructor
		Cliente();
		Cliente(string,string,string,int,string,string,string,int);
		//Getters
		string getDireccion();
		int getRating();
		//Setters
		void setDireccion(string);
		void setRating(int);
		//Destructor
		virtual ~Cliente();
};
#endif
