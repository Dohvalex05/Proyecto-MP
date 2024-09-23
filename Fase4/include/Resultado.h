/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1(MODIFICADA FASE 4)
//
// Fichero: Resultado.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef RESULTADO
#define RESULTADO

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Tiempo.h"
#include "utils.h"
using namespace std;

class Resultado{

private:

	int Posicion;

	int Dorsal;

	Tiempo TiempoCarrera;


public:

	//Funciones que dan valor a variables privadas

	void setPosicion(string linea);

	void setDorsal(string linea);

	void setTiempoCarrera(string linea);

	//Constructor que recibe o no string y da valores

	Resultado();

	Resultado(string linea,const char delimitador);

	//Devuelven estos valores

	string GetPosicion();

	string GetDorsal();

	string GetTiempoCarrera();

	string ToString();

	//Sobrecarga de operadores >> y <<
	//Parametros: referencia a flujo istream y ostream
	//			  referencia a objeto Resultado

	friend istream & operator >> (istream & in, Resultado & un_Resultado);

	friend ostream & operator << (ostream & out, Resultado & un_Resultado);

};

#endif