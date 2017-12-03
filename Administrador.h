#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
#include "Personal.h"

using namespace std;

class Administrador:public Personal{
	private:
		int Contratados;
		int Despedidos;
	public:
		Administrador();
		Administrador(string,string,string,int,string,string,string,double,int,int);

		int getContratados();
		int getDespedidos();
		void setContratados(int);
		void setDespedidos(int);

};
#endif
