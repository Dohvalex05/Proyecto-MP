/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1
//
// Fichero: utils.h
//
/***************************************************************************/
/***************************************************************************/
#ifndef UTILS
#define UTILS

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cmath>
#include <ctype.h>
#include <iomanip>
using namespace std;

//Especifica que tipo de alineacion se quiere

enum class TipoAlineacion{Izquierda, Centro, Derecha};

//Pasa un int a string dandole un formato agradable

string FormatInt (int numero, int num_casillas, char relleno);

//Pasa double a string dando formato agradable

string FormatDouble (double numero,int num_casillas,int num_dec, char relleno);

//Da formato agradable a un string

string FormatString (string la_cadena, int num_casillas, \
TipoAlineacion alineacion, char relleno);

#endif