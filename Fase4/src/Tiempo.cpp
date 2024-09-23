/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1(MODIFICACIONES FASE 4)
//
// Fichero: Tiempo.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "Tiempo.h"
using namespace std;

//Funciones get
//Dan valor a elementosw privados

int Tiempo::GetHoras(){
	return horas;
}

int Tiempo::GetMinutos(){
	return minutos;
}

int Tiempo::GetSegundos(){
	return segundos;
}

//Funciones set
//Dan valor a elementos privados

void Tiempo::SetHoras(string shoras){
	horas=stoi(shoras);
}

void Tiempo::SetMinutos(string sminutos){
	minutos=stoi(sminutos);
}

void Tiempo::SetSegundos(string ssegundos){
	segundos=stoi(ssegundos);
}

//Constructores de la clase Tiempo
//Estos reciben una entrada(o no), y dan valores a los elementos de Tiempo

//Constructor sin entrada
//El tiempo de salida es el tiempo actual

Tiempo::Tiempo(){

	//Creo variable t tipo time_t
	//Le asigno el tiempo actual

    time_t t = time(0);
    
    //Se convierte el tiempo a una estructura tm

    tm* tiempoactual = localtime(&t);

    //Extraigo las horas
    
    horas=((*tiempoactual).tm_hour);

    //Extraigo los minutos

    minutos=((*tiempoactual).tm_min);

    //Extraigo los segundos

    segundos=((*tiempoactual).tm_sec);
}

//Constructor con entrada
//Guarda los valores del string de entrada

Tiempo::Tiempo(string linea){

	//puntero que apunta al string para operar

	char * puntero=&(linea[0]);
	string shoras,sminutos,ssegundos;
	shoras ="";
	sminutos="";
	ssegundos="";

	//salto los espacios posibles inciales

	while(*puntero == ' '){
		puntero++;
	}

	//bucles while para atrapar los numeros de un Tiempo ej 00:33:10
	//puntero++ entre ellos para saltar :

	while (*puntero != ':'){
		shoras = shoras + *puntero;
		puntero++;
	}
	SetHoras(shoras);
	puntero++;
	while (*puntero != ':'){
		sminutos = sminutos +*puntero;
		puntero++;
	}
	SetMinutos(sminutos);
	puntero++;
	while (*puntero != '\0' && *puntero != ' '){
		ssegundos = ssegundos +*puntero;
		puntero++;
	}
	SetSegundos(ssegundos);

}

//ToString de Tiempo
//Devuelve toda la informacion obtenida en forma de string legible

string Tiempo::ToString (void){

	string cadena=""; 

	cadena = cadena + FormatString(" ",2,TipoAlineacion::Derecha,' ');

	cadena=cadena + FormatInt(horas,2,'0')+ ":";

	cadena=cadena + FormatInt(minutos,2,'0') + ":";

	cadena=cadena + FormatInt(segundos,2,'0') ;

	return cadena;
}


//Sobrecarga de operadores >> y <<
//Parametros: referencia a flujo istream y ostream
//referencia a objeto Tiempo

istream & operator >> (istream & in,Tiempo & uno_Tiempo){

	string linea;

	getline(in,linea);

	//puntero que apunta al string para operar

	char * puntero=&(linea[0]);
	string shoras,sminutos,ssegundos;
	shoras ="";
	sminutos="";
	ssegundos="";

	//salto los espacios posibles inciales

	while(*puntero == ' '){
		puntero++;
	}

	//bucles while para atrapar los numeros de un Tiempo ej 00:33:10
	//puntero++ entre ellos para saltar :

	while (*puntero != ':'){
		shoras = shoras + *puntero;
		puntero++;
	}
	uno_Tiempo.SetHoras(shoras);
	puntero++;
	while (*puntero != ':'){
		sminutos = sminutos +*puntero;
		puntero++;
	}
	uno_Tiempo.SetMinutos(sminutos);
	puntero++;
	while (*puntero != '\0' && *puntero != ' '){
		ssegundos = ssegundos +*puntero;
		puntero++;
	}
	uno_Tiempo.SetSegundos(ssegundos);


	return in;

}

ostream & operator << (ostream & out, Tiempo & uno_Tiempo){

	out.setf(ios::fixed);		
	out.setf(ios::showpoint);

	ostringstream oss;

	const char delimitador=':';

	oss << setw(2) << setfill('0') << uno_Tiempo.horas <<
	delimitador <<setw(2) << setfill('0') << uno_Tiempo.minutos <<
	delimitador << setw(2) << setfill('0') << uno_Tiempo.segundos;

	string final=oss.str();

	out << final;

	return(out);

}



