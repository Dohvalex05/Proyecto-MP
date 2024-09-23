/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1(MOFDIFICACIONES FASE 4)
//
// Fichero: Carrera.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef CARRERA
#define CARRERA

#include <iostream>
#include <string>
#include <cstring>
#include "Fecha.h"
#include "utils.h"
#include <sstream>
using namespace std;

class Carrera{

private:

	int IdCarrera;

	double Distancia;

	Fecha FechaCarrera;

	string Nombre;

public:

	
	//Funciones Set de Carrera, se usaran en el constructor
	//Parametros:string con texto
	//resultado:informacion guardada

	//Consta de bucle while para omitir espacios, y luego
	//otro bucle para atrapar la informacion hasta llegar a otro espacio o fin

	/*En todos hay un puntero dirigido al comienzo del string
	para poder operar sobre el usando cstring*/

	void setFechaCarrera(string linea);

	void setIdCarrera(string linea);

	void setDistancia(string linea);

	void setNombre(string linea);

	//Constructor
	//Parametros: string con informacion y delimitador o nada
	//Con bucles while voy guardando la informacion entre los delimitadores
	//resultado: todas las funciones menores recibiran la informacion requerida

	//Constructor que no recibe informacion
	//Le da valor inutil a a las variables

	Carrera();

	Carrera(string linea,const char delimitador);

	//FUNCIONES GET, se usan en el ToString
	//Uso Format de utils
	//resultado: se devuelve la informacion

	string GetNombre();

	string GetFechaCarrera();

	string GetIdCarrera();

	string GetDistancia();

	//Funcion que va a devolver todos los valores acumulados
	//resultado: todo se devuelve ordenado en forma de String

	string ToString();

	//Sobrecarga de operadores >> y <<
	//Parametros: referencia a flujo istream y ostream
	//			  referencia a objeto Carrera

	friend istream & operator >> (istream & in, Carrera & una_carrera);

	friend ostream & operator << (ostream & out, Carrera & una_carrera);


	
};

#endif