/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1(MODIFICACIONES FASE 4)
//
// Fichero: Tiempo.h
//
/***************************************************************************/
/***************************************************************************/
#ifndef TIEMPO
#define TIEMPO

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include "utils.h"
using namespace std;

class Tiempo{

private:

	int horas;

	int minutos;

	int segundos;

public:

	//Funciones get
	//Dan valor a elementosw privados

	int GetHoras();

	int GetMinutos();

	int GetSegundos();

	//Funciones set
	//Dan valor a elementos privados

	void SetHoras(string shoras);

	void SetMinutos(string sminutos);

	void SetSegundos(string ssegungos);

	//Devuelve la informacion en formato string

	string ToString(void);

	//Constructores, reciben o no string y dan valores a variables

	Tiempo(string linea);

	//Devuelve hora actual

	Tiempo();

	//Sobrecarga de operadores >> y <<
	//Parametros: referencia a flujo istream y ostream
	//referencia a objeto Tiempo

	friend istream & operator >> (istream & in, Tiempo & uno_Tiempo);

	friend ostream & operator << (ostream & out, Tiempo & uno_Tiempo);
	
};

#endif