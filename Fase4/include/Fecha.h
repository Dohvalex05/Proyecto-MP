/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1(MODIFICACIONES FASE 4)
//
// Fichero: Fecha.h
//
/***************************************************************************/
/***************************************************************************/
#ifndef FECHA
#define FECHA

#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <iomanip>
#include "utils.h"

using namespace std;

class Fecha{

private:

	int dia;

	int mes;

	int anio;

public:

	//Funcion que transforma un mes en formato numerico a un formato de texto
	//ej: 01 == Ene

	string FormatMes();


	//Funciones get
	//Devuelven valores privados

	int GetDia();

	int GetMes();

	int GetAnio();

	//Funciones set
	//Dan valor a elementos privados

	void SetDia(string sdia);

	void SetMes(string smes);

	void SetAnio(string sanio);

	//muestra de forma bonita la fecha
	//pide:nada
	//devuelve:un string

	string ToString(void);

	//constructor fecha
	//Uno sin variables que les asigna la fecha actual
	//Otro con variables
	//pide:string a leer y delimitador
	//resultado:dia mes y anio reciben valores
	//el string introducido no es el completo sino una parte
	//el constructor externo se encarga de eso

	Fecha(string linea);

	//Constructor sin entrada
	//La fecha de salida es la actual

	Fecha();

	//Sobrecarga de operadores >> y <<
	//Parametros: referencia a flujo istream y ostream
	//referencia a objeto Fecha

	friend istream & operator >> (istream & in, Fecha & una_fecha);

	friend ostream & operator << (ostream & out, Fecha & una_fecha);


	
};

#endif