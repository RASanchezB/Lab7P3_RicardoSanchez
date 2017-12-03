#ifndef PERSONAL_H
#define PERSONAL_H

#include "Usuario.h"
#include <iostream>
#include <string>

using namespace std;

class Personal:public Usuario{
	private:
		string Fecha;
		double Sueldo;
	public:
		Personal();
		Personal(string,string,string,int,string,string,string,double);
		string getFecha();
		double getSueldo();
		void setFecha(string);
		void setSueldo(double);
		~Personal();
};
#endif
