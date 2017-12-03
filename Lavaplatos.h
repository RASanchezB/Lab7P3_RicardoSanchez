#ifndef LAVAPLATOS_H
#define LAVAPLATOS_H

#include "Personal.h"
#include <iostream>

class Lavaplatos:public Personal{
	private:
		int Motivacion;
	public:
		Lavaplatos();
		Lavaplatos(string,string,string,int,string,string,string,double,int);
		int getMotivacion();
		void setMotivacion(int);
		virtual ~Lavaplatos();
};
#endif
