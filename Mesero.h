#ifndef MESERO_H
#define MESERO_H

#include <vector>
#include <string>
#include "Personal.h"

class Mesero: public Personal{
	private:
		vector<string> lista;
	public:
		Mesero();
		Mesero(string,string,string,int,string,string,string,double);
		void UnPlato();
		void Todos();
		vector<string> getLista();
		void setLista(vector<string>);
		virtual ~Mesero();
};
#endif
