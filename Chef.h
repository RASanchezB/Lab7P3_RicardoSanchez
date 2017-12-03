#ifndef CHEF_H
#define CHEF_H

#include <string>
#include <iostream>
#include "Personal.h"

using namespace std;

class Chef:public Personal{
	private:
		string Platillo;
	public:
		Chef();
		Chef(string,string,string,int,string,string,string,double,string);
		string getPlatillo();
		void setPlatillo(string);
		
		virtual ~Chef();
};
#endif
