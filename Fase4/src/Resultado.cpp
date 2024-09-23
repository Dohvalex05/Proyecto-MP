/***************************************************************************/
/***************************************************************************/
//
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1(MODIFICADA FASE 4)
//
// Fichero: Resultado.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "Resultado.h"

using namespace std;


//Funciones set
//Recibiran una parte del texto y de ahi daran valores a los elementos
//En todos hay un puntero dirigido al comienzo del string
//para poder operar sobre el con cstring

//Da valor al elemento Posicion

void Resultado::setPosicion(string texto){
	string SPosicion="";
	char * puntero = &texto[0];
	while(*puntero == ' '){
		puntero++;
	}
	while(*puntero != ' ' && *puntero != '\0'){
		SPosicion = SPosicion + *puntero;
		puntero++;
	}
	Posicion=stoi(SPosicion);
}

//Da valor al elemento Dorsal

void Resultado::setDorsal(string texto){
	string SDorsal="";
	char * puntero = &texto[0];
	while(*puntero == ' '){
		puntero++;
	}
	while(*puntero != ' ' && *puntero != '\0'){
		SDorsal = SDorsal + *puntero;
		puntero++;
	}
	Dorsal=stoi(SDorsal);
}

//Da valor a TiempoCarrera

void Resultado::setTiempoCarrera(string texto){
	Tiempo TiempoTemp(texto);
	TiempoCarrera=TiempoTemp;
}

//CONSTRUCTOR

//Usa las funciones set

//Bucles while que guardan informacion entre delimitadores

Resultado::Resultado(){

	Posicion=0;

	Dorsal=0;

	TiempoCarrera=Tiempo();

}

Resultado::Resultado(string linea,const char delimitador){

	//puntero a string, para operar con cstring

	char * pastring = &linea[0];
	string lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setDorsal(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setTiempoCarrera(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setPosicion(lintemp);
	lintemp="";
}

//Funciones Get
//Sirven para devolver los elementos

//Funcion para devolver posicion

string Resultado::GetPosicion(){

	string PosicionFinal=FormatInt(Posicion,3,' ');
	return PosicionFinal;

}

//Funcion para devolver Dorsal

string Resultado::GetDorsal(){

	string DorsalFinal=FormatInt(Dorsal,5,' ');
	return DorsalFinal;

}

//Funcion para deolver Tiempo de Carrera

string Resultado::GetTiempoCarrera(){
	string TiempoFinal=TiempoCarrera.ToString();
	return TiempoFinal;
}

//Funcion To String
//Esta funcion muestra en forma de string la informacion almacenada
//Usa las funciones Get

string Resultado::ToString(){

	string ResultadoFinal="";

	ResultadoFinal=ResultadoFinal + GetPosicion() + ".";
	ResultadoFinal=ResultadoFinal + GetDorsal();
	ResultadoFinal=ResultadoFinal + GetTiempoCarrera();

	return ResultadoFinal;

}

//Sobrecarga de operadores >> y <<
//Parametros: referencia a flujo istream y ostream
//referencia a objeto Resultado

istream & operator >> (istream & in,Resultado & un_Resultado){

	string linea;

	getline(in,linea);

	const char delimitador='*';

	//puntero a string, para operar con cstring

	char * pastring = &linea[0];
	string lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	un_Resultado.setDorsal(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	un_Resultado.setTiempoCarrera(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	un_Resultado.setPosicion(lintemp);
	lintemp="";

	return in;

}

ostream & operator << (ostream & out, Resultado & un_Resultado){

	out.setf(ios::fixed);		
	out.setf(ios::showpoint);

	ostringstream oss;

	const char delimitador='*';

	oss << un_Resultado.Dorsal << delimitador << 
	un_Resultado.TiempoCarrera << delimitador <<
	un_Resultado.Posicion << delimitador;

	string final=oss.str();

	out << final;

	return(out);

}

