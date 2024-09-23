/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1(MODIFICACIONES FASE 4)
//
// Fichero: Corredor.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "Corredor.h"

using namespace std;

//Funciones set

//En todas las funciones creo punteros a strings para operar con cstring

//Bucles while que omiten espacios

//Funcion para dar valor a Dorsal

void Corredor::setDorsal(string texto){

	string SDorsal="";
	char * puntero = &texto[0];
	while(*puntero == ' '){
		puntero++;
	}
	while(*puntero != ' ' && *puntero != '\0'){
		SDorsal= SDorsal + *puntero;
		puntero++;
	}
	Dorsal=stoi(SDorsal);

}

//Funcion para dar valor a la variable DNI

void Corredor::setDNI(string texto){
	
	DNI="";
	char * puntero = &texto[0];
	while(*puntero == ' '){
		puntero++;
	}
	for(int i=0;i<strlen(puntero);i++){
		DNI=DNI + *(puntero+i);
	}
}

//Funcion para dar valor a la variable Nombre

void Corredor::setNombre(string texto){
	
	Nombre="";
	char * puntero = &texto[0];
	while(*puntero == ' '){
		puntero++;
	}
	for(int i=0;i<strlen(puntero);i++){
		Nombre=Nombre + *(puntero+i);
	}
}

//Funcion para dar valor a la variable Apellidos

void Corredor::setApellidos(string texto){
	Apellidos="";
	char * puntero = &texto[0];
	while(*puntero == ' '){
		puntero++;
	}
	for(int i=0;i<strlen(puntero);i++){
		Apellidos=Apellidos + *(puntero+i);
	}
}
//Funcion para dar valor a la variable Sexo

void Corredor::setSexo(string texto){
	string SSexo="";
	char * puntero = &texto[0];
	while(*puntero == ' '){
		puntero++;
	}
	while(*puntero != ' ' && *puntero != '\0'){
		SSexo = SSexo + *puntero;
		puntero++;
	}
	Sexo=SSexo[0];
}

//Funcion para dar valor a la variable FechaNacimiento

void Corredor::setFechaNacimiento(string texto){
	Fecha FechaTemp(texto);
	FechaNacimiento=FechaTemp;
}

//CONSTRUCTOR
//Usa las funciones set
//Con bucles while selecicona la informacion entre los delimitadores

Corredor::Corredor(){
	Dorsal=0; 
	DNI=""; 
	Nombre="";
	Apellidos="";		
 	FechaNacimiento=Fecha();
 	Sexo=' ';
 }


Corredor::Corredor(string linea,const char delimitador){

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

	setDNI(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setNombre(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setApellidos(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setFechaNacimiento(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setSexo(lintemp);
	lintemp="";
	
}

//Funciones Get, estas se usaran en el ToString()
//Estas se usan para devolver los valores

//Funcion que devuelve Dorsal

string Corredor::GetDorsal(){
	string DorsalFinal=FormatInt(Dorsal,4,' ');
	return DorsalFinal;
}

//Funcion que devuelve DNI

string Corredor::GetDNI(){
	string DNIFinal=FormatString(DNI,12,TipoAlineacion::Derecha,' ');
	return DNIFinal;
}

//Funcion que devuelve Nombre

string Corredor::GetNombre(){
	string NombreFinal=FormatString(Nombre,14,TipoAlineacion::Derecha,' ');
	return NombreFinal;
}

//funcion que devuelve Apellidos

string Corredor::GetApellidos(){
	string ApellidosFinal=FormatString(Apellidos,20, \
		TipoAlineacion::Derecha,' ');
	return ApellidosFinal;
}

//Funcion que devuelve FechaNacimiento

string Corredor::GetFechaNacimiento(){
	string FechaFinal=FechaNacimiento.ToString();
	return FechaFinal;
}

//Funcion que devuelve Sexo

string Corredor::GetSexo(){
	string SSexo;
	if (Sexo == 'H'){
		SSexo=" HOMBRE";
	}
	if (Sexo == 'M'){
		SSexo=" MUJER ";
	}
	return SSexo;
}

//Funcion que va a devolver en forma de string todos los valores acumulados
//Usa las funciones Get

string Corredor::ToString(){

	string CorredorFinal="";

	CorredorFinal=CorredorFinal + GetDorsal() + ' ';
	CorredorFinal=CorredorFinal + GetApellidos();
	CorredorFinal=CorredorFinal + GetNombre();
	CorredorFinal=CorredorFinal + GetDNI();
	CorredorFinal=CorredorFinal + GetFechaNacimiento();
	CorredorFinal=CorredorFinal + GetSexo();

	return CorredorFinal;

}

//Sobrecarga de operadores >> y <<
//Parametros: referencia a flujo istream y ostream
//referencia a objeto Corredor

istream & operator >> (istream & in,Corredor & un_Corredor){

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

	un_Corredor.setDorsal(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	un_Corredor.setDNI(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	un_Corredor.setNombre(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	un_Corredor.setApellidos(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	un_Corredor.setFechaNacimiento(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	un_Corredor.setSexo(lintemp);
	lintemp="";
	

	return in;

}

ostream & operator << (ostream & out, Corredor & un_Corredor){

	out.setf(ios::fixed);		
	out.setf(ios::showpoint);

	ostringstream oss;

	const char delimitador='*';

	oss << un_Corredor.Dorsal << delimitador << un_Corredor.DNI 
	<< delimitador <<un_Corredor.Nombre << 
	delimitador << un_Corredor.Apellidos << delimitador << 
	un_Corredor.FechaNacimiento << delimitador <<
	un_Corredor.Sexo << delimitador;

	string final=oss.str();

	out << final;

	return(out);

}
