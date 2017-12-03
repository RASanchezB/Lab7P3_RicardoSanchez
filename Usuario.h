#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

using namespace std;
class Usuario{
	private:
		string Username;
		string Password;
		string Nombre;
		int Edad;
		string ID;
		string NumT;
	public:
		//constructor
		Usuario();
		Usuario(string,string,string,int,string,string);
		//Getters
		string getUsername();
		string getPassword();
		string getNombre();
		int getEdad();
		string getID();
		string getNumT();
		//Setters
		void setUsername(string);
		void setPassword(string);
		void setNombre(string);
		void setEdad(int);
		void setID(string);
		void setNumT(string);
		//Destructor
		virtual ~Usuario();
};
#endif
