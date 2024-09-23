/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1(MODIFICACIONES FASE 4)
//
// Fichero: Fecha.cpp
//
/***************************************************************************/
/***************************************************************************/


#include "Fecha.h"

using namespace std;

//transforma un int en un mes especifico
//pide:nada
//devuelve:string correspondiente al mes

string Fecha::FormatMes(){
		string Mes;
	    if (mes == 1) {
	        Mes = "Ene";
	    }
	    if (mes == 2) {
	        Mes = "Feb";
	    }
	    if (mes == 3) {
	        Mes = "Mar";
	    }
	    if (mes == 4) {
	        Mes = "Abr";
	    }
	    if (mes == 5) {
	        Mes = "May";
	    }
	    if (mes == 6) {
	        Mes = "Jun";
	    }
	    if (mes == 7) {
	        Mes = "Jul";
	    }
	    if (mes == 8) {
	        Mes = "Ago";
	    }
	    if (mes == 9) {
	        Mes = "Sep";
	    }
	    if (mes == 10) {
	        Mes = "Oct";
	    }
	    if (mes == 11) {
	        Mes = "Nov";
	    }
	    if (mes == 12) {
	        Mes = "Dic";
	    }
	    return Mes;

}

//Funciones get
//Devuelven valores privados

int Fecha::GetDia(){
	return dia;
}

int Fecha::GetMes(){
	return mes;
}

int Fecha::GetAnio(){
	return anio;
}

//Funciones set
//Dan valor a elementos privados

void Fecha::SetDia(string sdia){
	dia=stoi(sdia);
}

void Fecha::SetMes(string smes){
	mes=stoi(smes);
}

void Fecha::SetAnio(string sanio){
	anio=stoi(sanio);
}

//muestra de forma bonita la fecha
//pide:nada
//devuelve:un string

string Fecha::ToString (void){

	string cadena=""; 

	cadena=cadena + FormatInt(dia,4,' ') + " ";

	cadena=cadena + FormatMes();

	cadena=cadena + FormatInt(anio,5,' ');

	return cadena;

}

//constructor fecha
//Uno sin variables que les asigna la fecha actual
//Otro con variables
//pide:string a leer y delimitador
//resultado:dia mes y anio reciben valores
//el string introducido no es el completo sino una parte
//el constructor externo se encarga de eso

//Constructor sin entrada
//La fecha de salida es la actual

Fecha::Fecha(){
	 
	//Creo variable t tipo time_t
	//Le asigno el tiempo actual

    time_t t = time(0);
    
    //Se convierte el tiempo a una estructura tm

    tm* tiempoactual = localtime(&t);

    //extrajo la parte dia y la guardo
    
    dia=((*tiempoactual).tm_mday);

    //lo mismo con mes(+1 porque los meses se guardan desde 0 a 11)

    mes=((*tiempoactual).tm_mon+1);

    //lo mismo con anio(+1900 porque empieza a registrar desde ahi)

    anio=((*tiempoactual).tm_year+1900);
}

Fecha::Fecha(string linea){

	//puntero que apunta al string para operar

	char * i=&(linea[0]);
	string sdia,smes,sanio;
	sdia ="";
	smes="";
	sanio="";

	//salto los espacios posibles inciales

	while(*i == ' '){
		i++;
	}

	//bucles while para atrapar los numeros de una fecha ej 02/03/2024
	//i++ entre ellos para saltar /

	while (*i != '/'){
		sdia = sdia + *i;
		i++;
	}
	SetDia(sdia);
	i++;
	while (*i != '/'){
		smes = smes + *i;
		i++;
	}
	SetMes(smes);
	i++;
	while (*i != '\0' && *i != ' '){
		sanio = sanio + *i;
		i++;
	}
	SetAnio(sanio);

}

//Sobrecarga de operadores >> y <<
//Parametros: referencia a flujo istream y ostream
//referencia a objeto Fecha

istream & operator >> (istream & in,Fecha & una_Fecha){

	string linea;

	getline(in,linea);

	//puntero que apunta al string para operar

	char * i=&(linea[0]);
	string sdia,smes,sanio;
	sdia ="";
	smes="";
	sanio="";

	//salto los espacios posibles inciales

	while(*i == ' '){
		i++;
	}

	//bucles while para atrapar los numeros de una fecha ej 02/03/2024
	//i++ entre ellos para saltar /

	while (*i != '/'){
		sdia = sdia + *i;
		i++;
	}
	una_Fecha.SetDia(sdia);
	i++;
	while (*i != '/'){
		smes = smes + *i;
		i++;
	}
	una_Fecha.SetMes(smes);
	i++;
	while (*i != '\0' && *i != ' '){
		sanio = sanio + *i;
		i++;
	}
	una_Fecha.SetAnio(sanio);

	return in;

}

ostream & operator << (ostream & out, Fecha & una_Fecha){

	out.setf(ios::fixed);		
	out.setf(ios::showpoint);

	ostringstream oss;

	const char delimitador='/';

	oss << setw(2) << setfill('0') <<una_Fecha.dia << delimitador 
	<< setw(2) << setfill('0') << una_Fecha.mes << delimitador
	<< setw(4) << setfill('0') << una_Fecha.anio;

	string final=oss.str();

	out << final;

	return(out);

}





	

