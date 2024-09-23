/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1(MODIFICADO FASE 4)
//
// Fichero: CATEGORIA.h
//
/***************************************************************************/
/***************************************************************************/
#ifndef CATEGORIA
#define CATEGORIA

#include <iostream>
#include <string>
#include <cstring>
#include "Fecha.h"
#include "utils.h"
using namespace std;

class Categoria{

private:

	int IdCategoria;

	string Denominacion;

	char Sexo;

	Fecha FechaInicial;

	Fecha FechaFinal;

public:

	//Dan valor a las variables privadas

	void setIdCategoria(string Alberto);

	void setFechaInicial(string Contador);

	void setFechaFinal(string Tadeij);

	void setSexo(string Pogacar);

	void setDenominacion(string LeTourdeFrance);

	//Constructores que reciben string

	Categoria();

	Categoria(string linea,const char delimitador);

	//Devuelven esa informacion

	string GetIdCategoria();

	string GetFechaInicial();

	string GetFechaFinal();

	string GetSexo();

	string GetDenominacion();

	string ToString();

	//Sobrecarga de operadores >> y <<
	//Parametros: referencia a flujo istream y ostream
	//			  referencia a objeto Categoria

	friend istream & operator >> (istream & in, Categoria & una_Categoria);

	friend ostream & operator << (ostream & out, Categoria & una_Categoria);


};

#endif