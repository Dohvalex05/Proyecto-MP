/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1(MODIFICADO FASE 4)
//
// Fichero: Categoria.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "Categoria.h"
using namespace std;

//Funciones set
//Sirven para dar valores a los elementos de Categoria

//En todos hay punteros que miran a los string para operar con ellos
//Y bucles while que guardan la informacion omitiendo los espacios 
//Si hay espacios entre letras uso un bucle for

//Funcion para dar valor a IdCategoria

void Categoria::setIdCategoria(string texto){
	string SidCategoria="";
	char * puntero = &texto[0];
	while(*puntero == ' '){
		puntero++;
	}
	while(*puntero != ' ' && *puntero != '\0'){
		SidCategoria = SidCategoria + *puntero;
		puntero++;
	}
	IdCategoria=stoi(SidCategoria);
}

//Funcion para dar valor a FechaInicial

void Categoria::setFechaInicial(string texto){
	Fecha FechaTemp(texto);
	FechaInicial=FechaTemp;
}

//Funcion para dar valor a FechaFinal

void Categoria::setFechaFinal(string texto){
	Fecha FechaTemp(texto);
	FechaFinal=FechaTemp;
}

//Funcion para dar valor a Sexo

void Categoria::setSexo(string texto){
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

//Funcion para dar valor a Denominacion

void Categoria::setDenominacion(string texto){
	Denominacion="";
	char * puntero = &texto[0];
	while(*puntero == ' '){
		puntero++;
	}
	for(int i=0;i<strlen(puntero);i++){
		Denominacion=Denominacion + *(puntero+i);
	}
}

//CONSTRUCTOR PRINCIPAL
//Usa las funciones Set
//Con bucles while va guardando la informacion entre los delimitadores

Categoria::Categoria(){

	IdCategoria=0;

	Denominacion="";

	char Sexo=' ';

	Fecha FechaInicial=Fecha();

	Fecha FechaFinal=Fecha();
	
}

Categoria::Categoria(string linea,const char delimitador){

	//puntero a string, para operar con cstring

	char * pastring = &linea[0];
	string lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setIdCategoria(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setDenominacion(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setSexo(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}


	setFechaInicial(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	setFechaFinal(lintemp);
	lintemp="";


}

//Funciones Get
//sirven para devolver los elementos de Categoria
//Usan Format de utils y los ToString de Fecha

//Devuelve IdCategoria

string Categoria::GetIdCategoria(){
	string IdFinal=FormatInt(IdCategoria,3,' ');
	return IdFinal;
}

//Devuelve FechaInicial

string Categoria::GetFechaInicial(){
	string FechaFinal=FechaInicial.ToString();
	return FechaFinal;
}

//Devuelve FechaFinal

string Categoria::GetFechaFinal(){
	string FechaFinalFinal=FechaFinal.ToString();
	return FechaFinalFinal;
}

//Devuelve Sexo

string Categoria::GetSexo(){
	string SSexo;
	if (Sexo == 'H'){
		SSexo=" HOMBRE";
	}
	if (Sexo == 'M'){
		SSexo=" MUJER ";
	}
	return SSexo;
}

//Devuelve Denominacion

string Categoria::GetDenominacion(){
	string DenominacionFinal=FormatString(Denominacion,10, \
		TipoAlineacion::Derecha,' ');
	return DenominacionFinal;
}

//Funcion ToString
//Usa las funciones Get
//resultado: Devuelve un string ordenado con Informacion

string Categoria::ToString(){

	string CategoriaFinal="";

	CategoriaFinal=CategoriaFinal + GetIdCategoria() + ' ';
	CategoriaFinal=CategoriaFinal + GetDenominacion();
	CategoriaFinal=CategoriaFinal + GetSexo() + " De";
	CategoriaFinal=CategoriaFinal + GetFechaInicial() + " a";
	CategoriaFinal=CategoriaFinal + GetFechaFinal();

	return CategoriaFinal;

}

//Sobrecarga de operadores >> y <<
//Parametros: referencia a flujo istream y ostream
//referencia a objeto Categoria

istream & operator >> (istream & in,Categoria & una_Categoria){

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

	una_Categoria.setIdCategoria(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	una_Categoria.setDenominacion(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	una_Categoria.setSexo(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}


	una_Categoria.setFechaInicial(lintemp);
	pastring++;
	lintemp="";

	while(*pastring != delimitador){

		lintemp = lintemp + *pastring;
		pastring++;

	}

	una_Categoria.setFechaFinal(lintemp);
	lintemp="";

	return in;

}

ostream & operator << (ostream & out, Categoria & una_Categoria){

	out.setf(ios::fixed);		
	out.setf(ios::showpoint);

	ostringstream oss;

	const char delimitador='*';

	oss << una_Categoria.IdCategoria << delimitador <<  
	una_Categoria.Denominacion << delimitador <<
	una_Categoria.Sexo << delimitador <<  una_Categoria.FechaInicial <<
	delimitador << una_Categoria.FechaFinal << delimitador <<
	una_Categoria.FechaFinal << delimitador;

	string final=oss.str();

	out << final;

	return(out);

}
