/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1(MODIFICACIONES FASE 4)
//
// Fichero: Corredor.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef CORREDOR
#define CORREDOR

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Fecha.h"
#include "utils.h"

using namespace std;

class Corredor{


private:

	int Dorsal;

	string DNI;

	string Nombre;

	string Apellidos;

	Fecha FechaNacimiento;

	char Sexo;

public:

	//Dan valor a variables privadas

	void setDorsal(string texto);

	void setDNI(string texto);

	void setNombre(string texto);

	void setApellidos(string texto);

	void setSexo(string texto);

	void setFechaNacimiento(string texto);

	//Constructor que recibe o no una string
	
	Corredor();

	Corredor(string linea,const char delimitador);

	//Devuelven los valores

	string GetDorsal();

	string GetDNI();

	string GetNombre();

	string GetApellidos();

	string GetFechaNacimiento();

	string GetSexo();

	string ToString();

	//Sobrecarga de operadores >> y <<
	//Parametros: referencia a flujo istream y ostream
	//			  referencia a objeto Corredor

	friend istream & operator >> (istream & in, Corredor & un_Corredor);

	friend ostream & operator << (ostream & out, Corredor & un_Corredor);

	

};


#endif
