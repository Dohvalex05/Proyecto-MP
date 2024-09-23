/***************************************************************************/
/***************************************************************************/
//
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1(MODIFICACIONES FASE 4)
//
// Fichero: Carrera.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "Carrera.h"


using namespace std;


//Funciones Set de Carrera, se usaran en el constructor
//Parametros:string con texto
//POST:informacion guardada


//Consta de bucle while para omitir espacios, y luego
//otro bucle para atrapar la informacion hasta llegar a otro espacio o fin

/*En todos hay un puntero dirigido al comienzo del string
para poder operar sobre el usando cstring*/

//Funcion que da valor a IdCarrera

void Carrera::setIdCarrera(string texto){
	string SidCarrera="";
	char * puntero = &texto[0];
	while(*puntero == ' '){
		puntero++;
	}
	while(*puntero != ' ' && *puntero != '\0'){
		SidCarrera = SidCarrera + *puntero;
		puntero++;
	}
	IdCarrera=stoi(SidCarrera);
}

//Funcion que da valor a Distancia

void Carrera::setDistancia(string texto){
	string Sdistancia="";
	char * puntero = &texto[0];
	while(*puntero == ' '){
		puntero++;
	}
	while(*puntero != ' ' && *puntero != '\0'){
		Sdistancia = Sdistancia + *puntero;
		puntero++;
	}
	Distancia=stod(Sdistancia);
}

//Funcion que da valor a FechaCarrera
//Manda la informacion al constructor de Fecha

void Carrera::setFechaCarrera(string texto){
	Fecha FechaTemp(texto);
	FechaCarrera=FechaTemp;
}

//Funcion que da valor a Nombre
//Como hay espacios entre letras lo planteo con for

void Carrera::setNombre(string texto){
	Nombre="";
	char * puntero = &texto[0];
	while(*puntero == ' '){
		puntero++;
	}
	for(int i=0;i<strlen(puntero);i++){
		Nombre=Nombre + *(puntero+i);
	}
}

//Constructor
//Parametros: string con informacion,y delimitador o nada
//Con bucles while voy guardando la informacion entre los delimitadores
//POST: todas las funciones menores recibiran la informacion requerida

Carrera::Carrera(){

	int IdCarrera=0;

	double Distancia=0.0;

	Fecha FechaCarrera=Fecha();

	string Nombre="";
 }


Carrera::Carrera(string linea,const char delimitador){

	//puntero a string, para operar con cstring

	char * pastring = &linea[0];
	string lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setIdCarrera(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setDistancia(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setFechaCarrera(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setNombre(lintemp);
	lintemp="";
	
}


//FUNCIONES GET, se usan en el ToString
//Uso Format de utils
//POST: se devuelve la informacion

//Devuelve Nombre

string Carrera::GetNombre(){
	string Nombrefinal=FormatString(Nombre,37,TipoAlineacion::Derecha,' ');
	return Nombrefinal;
}

//Devuelve IdCarrera

string Carrera::GetIdCarrera(){
	string IdFinal=FormatInt(IdCarrera,3,' ');
	return IdFinal;
}

//Devuelve FechaCarrera

string Carrera::GetFechaCarrera(){
	string FechaFinal=FechaCarrera.ToString();
	return FechaFinal;
}

//Devuelve Distancia

string Carrera::GetDistancia(){
	string DistanciaFinal=FormatDouble(Distancia,5,3,' ');
	return DistanciaFinal;
}


//Funcion que va a devolver todos los valores acumulados
//POST: todo se devuelve ordenado en forma de String

string Carrera::ToString(){

	string CarreraFinal="";

	CarreraFinal=CarreraFinal + GetIdCarrera() + ' ';
	CarreraFinal=CarreraFinal + GetNombre();
	CarreraFinal=CarreraFinal + GetDistancia() + " Km";
	CarreraFinal=CarreraFinal + GetFechaCarrera();

	return CarreraFinal;

}

//Sobrecarga de operadores >> y <<
//Parametros: referencia a flujo istream y ostream
//			  referencia a objeto Carrera

istream & operator >> (istream & in,Carrera & una_carrera){

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

	una_carrera.setIdCarrera(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	una_carrera.setDistancia(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	una_carrera.setFechaCarrera(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	una_carrera.setNombre(lintemp);
	lintemp="";

	return in;

}

ostream & operator << (ostream & out, Carrera & una_carrera){

	out.setf(ios::fixed);		// Notación de punto fijo para los reales
	out.setf(ios::showpoint);	// Mostrar siempre decimales

	ostringstream oss;

	const char delimitador='*';

	oss << una_carrera.IdCarrera << delimitador
	<< una_carrera.Distancia << delimitador 
	<< una_carrera.FechaCarrera << delimitador
	<< una_carrera.Nombre << delimitador;

	string final=oss.str();

	out << final;

	return(out);

}






