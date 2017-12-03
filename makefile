lab7:	Main.o Usuario.o Cliente.o Personal.o Chef.o Lavaplatos.o Administrador.o Mesero.o
	g++ Main.o Usuario.o Cliente.o Personal.o Administrador.o Chef.o Lavaplatos.o Mesero.o -o lab7

Main.o:	Usuario.h Cliente.h Personal.h Administrador.h Chef.h Lavaplatos.h Mesero.h Main.cpp 
	g++ -c Main.cpp

Usuario.o: Usuario.h Usuario.cpp
	g++ -c Usuario.cpp

Cliente.o: Cliente.h Cliente.cpp
	g++ -c Cliente.cpp

Personal.o:	Personal.h Personal.cpp
	g++ -c Personal.cpp

Chef.o:	Chef.h Chef.cpp
	g++ -c Chef.cpp

Lavaplatos.o:	Lavaplatos.h Lavaplatos.cpp
	g++ -c Lavaplatos.cpp

Administrador.o:	Administrador.h Administrador.cpp
	g++ -c Administrador.cpp

Mesero.o:	Mesero.h Mesero.cpp
	g++ -c Mesero.cpp

clear:
	rm *.p run
