/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// FASE 2 Proyecto MP(Modificado Fase 4)
//
// Fichero: Resultados.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include "Resultados.h"



using namespace std;


/***************************************************************************/
/***************************************************************************/

//CONSTRUCTORES

//Constructor sin argumentos
//Parametros:nada
//POST: usadas son 0 y capacidad capacidad_inicial, memoria reservada

Resultados::Resultados(){

	usados=0;

	ReservarMemoria(capacidad_inicial);

}

//Constructor con argumentos
//Parametros: numero de casillas a reservar
//POST: usadas son 0 y capacidad num_casillas, memoria reservada

Resultados::Resultados(const int num_casillas){

	usados=0;

	ReservarMemoria(num_casillas);

}

//Constructor de copia,inicializa vector copiando informacion
//Parametros: Referencia a otro objeto Resultados
//POST: Vector inicializado con informacion de otro

Resultados::Resultados(const Resultados & otro){

	ReservarMemoria(otro.capacidad);
	
	usados = otro.usados;
	
	CopiarDatos(otro);
}

//Constructor nuevo.
//Parametros: referencia a string que contiene nombre de fichero
//POST: Objeto construido a partir de informacion de fichero

Resultados::Resultados(string & nombre){

	usados=0;

	ReservarMemoria(capacidad_inicial);

	LeerResultados(nombre);

}



/***************************************************************************/
/***************************************************************************/

//DESTRUCTOR

//Destructor que acaba con la memoria reservada al acabar la ejecucion

Resultados::~Resultados(){
	LiberarMemoria();
}


/***************************************************************************/
/***************************************************************************/

//METODOS GET
//Serviran para extraer informacion de objeto Resultados

int Resultados::Usados() const{

	return usados;

}

int Resultados::Capacidad() const{

	return capacidad;

}

bool Resultados::EstaVacio() const{

	bool vacio=false;

	if (usados == 0){
		vacio = true;
	}

	return vacio;


}

/***************************************************************************/
/***************************************************************************/

//FUNCIONES QUE MODIFICAN EL CONTENIDO

//Funcion que deja un objeto Resultados vacio
//Parametros:nada
//POST: Vector vacio, usados a 0 y capacidad a 0

void Resultados::EliminaTodos(){

	LiberarMemoria();

}

//Funcion que inserta un valor en una casilla moviendo las demas a la derecha
//Parametros: el valor a anadir, el numero de casilla
//POST: se aniade ese valor a esa casilla moviendo las demas

void Resultados::Inserta(const Resultado & valor, const int num_casilla) {

	//Si lo requiere se redimensiona

    if (usados >= capacidad) {

        Redimensiona();
    }

    //Todo desde num_casilla se mueve a la izquierda

    for(int i = usados; i > num_casilla-1; i--){
        datos[i] = datos[i-1];
    }

    //Aniado el valor en la ahora casilla libre

    datos[num_casilla-1] = valor;

    usados++;
}


//Funcion que reajusta vector
//Parametros: nada
//POST: la capacidad se reduce al numero de casillas usadas


void Resultados::Reajusta(){

	//Copio informacion en temporal y al original le cambio capacidad

	Resultados temporal(*this);

	LiberarMemoria();

	ReservarMemoria(temporal.usados);

	//Ahora copio informacion y elimino temporal

	CopiarDatos(temporal);

	temporal.LiberarMemoria();
	
}


/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
//Sobrecargas de operadores


//Copia profunda usando Operador de asignacion
//Parametros:Referencia a otro objeto Resultados
//POST: Se copia la informacion al implicito

Resultados & Resultados :: operator = (const Resultados & otro){

	LiberarMemoria();

	ReservarMemoria(otro.capacidad);

	usados=otro.usados;

	CopiarDatos(otro);

	return (*this);
}

//Devuelvo valor usando operadores () y []
//PARAMETROS: posicion de elemento Resultado
//Devuelve: Ese elemento

Resultado & Resultados::operator() (const int num_casilla){

	return(datos[num_casilla-1]);


}

Resultado & Resultados::operator() (const int num_casilla) const{

	return(datos[num_casilla-1]);


}
Resultado & Resultados::operator[] (const int num_casilla){

	return(datos[num_casilla-1]);



}

Resultado & Resultados::operator[] (const int num_casilla) const{

	return(datos[num_casilla-1]);


}

/***************************************************************************/
/***************************************************************************/

//Sobrecarga de == y !=
//Parametros: Referencia a otro objeto Resultados(otro)
//Iguales si comparten mismo numero casillas y mismo Dorsal

//Devuelve: True si son iguales y False si no lo son

bool Resultados::operator == (const Resultados & otro) const{


 	bool iguales=true;

 	//me indica si sigo con el testeo

 	bool sigo=true;

 	if (usados != otro.usados) {
        iguales=false;  
    }

    //Si la primera comprobacion sale cierta el codigo no sigue

    if(iguales){

    	for(int i=0;i<usados && sigo;i++){
    		for(int j=0;j<otro.usados;j++){
	    		if (stoi(datos[i].GetDorsal()) != 
	    			stoi(otro.datos[j].GetDorsal())){
	    			iguales = false;
	    			sigo = false;
	    		}
    		}
    	}
    }

    return (iguales);

 }

 //Devuelve: False si son iguales y True si no lo son

 bool Resultados::operator != (const Resultados & otro) const{

 	return(!(*this == otro));
 	
 }

 //Sobrecargas de operadores >,>=,<,>=
 //Parametros: Referencia a otro objeto Resultados(otro)

 //Devuelve: True si el objeto es mayor al otro y False si no

 bool Resultados::operator > (const Resultados & otro) const{

 	bool mayor= true;

 	if (usados <= otro.usados){
 		mayor = false;
 	}

 	return mayor;
 }

 //Devuelve: True si el objeto es mayor o igual al otro y False si no

 bool Resultados::operator >= (const Resultados & otro) const{


 	bool mayorigual=true;

 	if (!(*this > otro) || !(*this == otro)){
 		mayorigual=false;
 	}

 	return mayorigual;
 }

 //Devuelve: True si el objeto es menor al otro y False si no

 bool Resultados::operator < (const Resultados & otro) const{

 	return(!(*this >= otro));

 }


 //Devuelve: True si el objeto es menor o igual al otro y False si no

 bool Resultados::operator <= (const Resultados & otro) const{

 	return(!(*this > otro));
 }

 //Sobrecarga de *
 //Parametros: Referencia a otro objeto Resultados(otro)
 //Devuelve: nuevo objeto Resultados que contiene todos los datos comunes

Resultados operator * (const Resultados & este,const Resultados & otro){

	Resultados nuevo;

	//Repaso que i valor de este coincida con j valor de otro
	//si coinciden se aniade

	for(int i=0;i<este.usados;i++){
		for(int j=0;j<otro.usados;j++){
			if (stoi(este.datos[i].GetDorsal()) == 
				stoi(otro.datos[i].GetDorsal()))
			{
				nuevo.Aniade(este.datos[i]);
			}
		}
	}

	return nuevo;

}

 //Sobrecarga de &&

 //Parametros: Referencias a dos objetos Resultados(este/otro)
 //Devuelve: True si este contiene a otro y false si no

bool operator && (const Resultados & este,const Resultados & otro){

	bool contiene=false;

	//Si el numero de elementos de otro coincide con el
	//numero de elementos de la interseccion entonces esta contenido

	if (este.Usados() >= otro.Usados()){

		if(otro.Usados() == (este * otro).Usados()){

			contiene=true;
		}

	}

	return contiene;

}

//Parametros: Referencias a un objeto Resultados y otro Resultado(este/otro)
//Devuelve: True si este contiene a otro y false si no

bool operator && (const Resultados & este,const Resultado & otro){

	bool contiene=false;

	Resultados Hotro;

	Hotro.Aniade(otro);

	if(este && Hotro){
		contiene=true;
	}

	return contiene;

}

//Parametros: Referencias a un objeto Resultado y otro Resultados(este/otro)
//Devuelve: True si otro contiene a este y false si no

bool operator && (const Resultado & este,const Resultados & otro){

	return(otro && este);

}

//Parametros: Referencias a un objeto Resultados 
//y un int Numero de Dorsal(este/NumDorsal)
//Devuelve: true si Resultados contiene al dato Resultado cuyo campo
//Dorsal coincide con el int.

bool operator && (const Resultados & este,int NumDorsal){

	bool contiene=false;

	//Repasa todos los datos hasta encontrar al indicado

	for(int i=0;i<este.Usados() && !contiene;i++){
		if (stoi(este.datos[i].GetDorsal()) == NumDorsal){
			contiene = true;
		}
	}

	return contiene;

}

//Devuelve: true si Resultados contiene al dato Resultado cuyo campo
//Dorsal coincide con el int.

bool operator && (int NumDorsal,const Resultados & otro){

	return(otro && NumDorsal);

}

//Sobrecarga de +

//Parametros: Referencias a dos objetos Resultados(este,otro)
//Devuelve: Nuevo objeto Resultados con suma(sin repeticion) de
//los dos objetos resultados
 
Resultados operator + (const Resultados & este,const Resultados & otro){

	Resultados nuevo(este);

	//Si este no contiene, entonces se aniade, se evita duplicados

	for(int i=0;i<otro.Usados();i++){

		if(!(este && otro.datos[i])){

			nuevo.Aniade(otro.datos[i]);

		}

	}

	return nuevo;

}

//Parametros: Referencias a un objeto Resultados y otro Resultado(este,otro)
//Devuelve: Nuevo objeto Resultados con el nuevo objeto Resultado sumado

Resultados operator + (const Resultados & este,const Resultado & otro){

	Resultados nuevo;

	nuevo.Aniade(otro);

	return(este + nuevo);

}

//Parametros: Referencias a un objeto Resultado y otro Resultados(este,otro)
//Devuelve: Nuevo objeto Resultados con el nuevo objeto Resultado sumado

Resultados operator + (const Resultado & este,const Resultados & otro){

	return(otro + este);

}


//Sobrecarga de +=

//Parametros: Referencia a otro objeto Resultados(otro)
//Devuelve: Objeto implicito sumado con el derecho

Resultados & Resultados::operator += (const Resultados & otro){

	*this = *this + otro;

	return (*this);

}

//Parametros: Referencia a otro objeto Resultado(otro)
//Devuelve: Objeto implicito sumado con el derecho

Resultados & Resultados::operator += (const Resultado & otro){

	*this = *this + otro;

	return (*this);

}

//Sobrecarga de -

//Parametros: Referencias a dos objetos Resultados(este,otro)
//Devuelve: Nuevo objeto Resultados con el nuevo objeto Resultados restado
 
Resultados operator - (const Resultados & este,const Resultados & otro){

	Resultados nuevo(este);

	//si lo contiene se elimina

	for(int i=0;i<otro.Usados();i++){

		if(este && otro.datos[i]){

			nuevo.Elimina(i);

		}

	}

	return nuevo;

}

//Parametros: Referencias a un objeto Resultados y otro Resultado(este,otro)
//Devuelve: Nuevo objeto Resultados con el nuevo objeto Resultado restado

Resultados operator - ( const Resultados & este,const Resultado & otro){

	Resultados nuevo;

	nuevo.Aniade(otro);

	return(este - nuevo);

}

//Parametros: Referencias a un objeto Resultado y otro Resultados(este,otro)
//Devuelve: Nuevo objeto Resultados con el nuevo objeto Resultado restado

Resultados operator - (const Resultados & este,int NumDorsal){

	bool sigue=true;

	Resultados nuevo(este);

	//Si lo contiene fuera

	for(int i=0;i<este.Usados() && sigue;i++){
		if (stoi(nuevo.datos[i].GetDorsal()) == NumDorsal){
			nuevo.Elimina(i);
			sigue=false;
		}
	}
	
	return nuevo;

}

//Sobrecarga de -=

//Parametros: Referencia a otro objeto Resultados(otro)
//Devuelve: Objeto implicito se le resta el explicito

Resultados & Resultados::operator -= (const Resultados & otro){

	*this = *this - otro;

	return (*this);

}

//Parametros: Referencia a otro objeto Resultado(otro)
//Devuelve: Objeto implicito se le resta el explicito

Resultados & Resultados::operator -= (const Resultado & otro){

	*this = *this - otro;

	return (*this);

}

//Parametros: Dorsal de un resultado(NumDorsal)
//Devuelve: Objeto implicito se le resta el explicito

Resultados & Resultados::operator -= (const int NumDorsal){

	*this = *this - NumDorsal;

	return (*this);

}

/***************************************************************************/
/***************************************************************************/

//FUNCION TO STRING
//Funcion que serializa informacion
//Parametros: titulo que tendrá comienzo de ToString
//Post: Muestra informacion de forma estructurada y facil de leer

string Resultados::ToString(const string titulo){

	string cad="";

	cad= cad + titulo + '\n';

	for(int i=0;i<usados;i++){

		cad= cad + datos[i].ToString() + '\n';
	}

	return cad;


}

/***************************************************************************/
/***************************************************************************/

//Sobrecarga de operadores << y >> para las clases coleccion
//Parametros: referencia a objeto istream u ostream
//			  referencia a objeto Resultados


istream & operator >> (istream & in,Resultados & unos_Resultados){

	

	unos_Resultados.LiberarMemoria();

	unos_Resultados.ReservarMemoria(unos_Resultados.capacidad_inicial);

	string linea;

	getline(in, linea); // Lectura adelantada

	while (!in.eof()) {
					
		Resultado uno_Resultado (linea,'*');

		// Añadir el dato "Resultado" leido a la colección 
		unos_Resultados += uno_Resultado; // Operator += 

		// Leer la siguiente linea 
		getline(in, linea); 
		
	}

	return in;

}

ostream & operator << (ostream & out,const Resultados & unos_Resultados){

	ostringstream oss;

	for(int i=1;i<=unos_Resultados.Usados();i++){

		oss << unos_Resultados[i] << endl;
	}

	string final=oss.str();

	out << final;

	return out;

}

//FUNCIONES QUE GUARDAN O EXTRAEN INFORMACION EN FICHEROS

//Funcion metodo de escritura
//Parametros: referencia a string que contiene el nombre de un fichero
//POST: informacion contenida en Resultados es guardada en un fichero
//PRE: si el fichero no fuese del tipo especificado vector queda vacio

void Resultados::EscribirResultados (const string & nombre) const{

	if (usados != 0){

		ofstream fo(nombre);

		fo << "RESULTADOS" << endl;

		fo << *this;

		fo.close();

	}


}

//Funcion metodo de lectura 
//Parametros: referencia a string que contiene el nombre de un fichero
//POST: informacion contenida en fichero es guardada en Resultados
//PRE: si el fichero no fuese del tipo especificado vector queda vacio

void Resultados::LeerResultados (const string & nombre){

	ifstream fi(nombre);

	//Me salto la primera parte que contiene informacion no guardable

	string linea;

	getline(fi, linea);

	if(linea == "RESULTADOS"){

		getline(fi,linea);

		while(linea[0] == '#'){

			getline(fi,linea);

		}

		//evito enviar a fi >> *this la informacion incorrecta

		//ios::cur = marca posicion actual

		//linea.length()-1 = la long de la linea - 1 para retroceder una linea

		fi.seekg(-(linea.length() + 1), ios::cur);

		fi >> *this;

	}

	fi.close();

}







/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
//FUNCIONES PRIVADAS

//Pide memoria dinamica para guardar el vector
//Parametros: numero de casillas
//PRE: num_casillas >= 0;

void Resultados::ReservarMemoria (const int num_casillas){

	if(num_casillas < 0){

		capacidad = 1;

	}

	else{

	capacidad = num_casillas;

	}

	datos = new Resultado[capacidad];
}

//Elimina la memoria usada
//Parametros:nada
//POST: Numero de casillas usadas y capacidad son 0

void Resultados:: LiberarMemoria(){

	if (datos != nullptr && datos != 0){

		delete [] datos;

		usados=0;

		capacidad=0;

	}

}

//Copia Datos de un lugar a otro
//Parametros: referencia a otro objeto Resultados
//POST: Informacion se transfiere

void Resultados::CopiarDatos(const Resultados & otro){

	for(int i=0;i<otro.usados;i++){

		datos[i] = otro.datos[i];

	}

}


//Redimensiona un vector 
//Parametros: nada
//POST: Vector tiene mas capacidad


void Resultados::Redimensiona (void){

	//Objeto temporal copia
	
	Resultados copia(*this);
	
	LiberarMemoria();
	ReservarMemoria(copia.capacidad + capacidad_inicial);
	
	CopiarDatos(copia);

	usados=copia.usados;
}


//Funcion que borra una casilla del vector diamico
//Parametros: referencia al vector, y la casilla a eliminar
//POST: casilla desaparece y las necesarias se mueven a la izquierda

void Resultados::Elimina(const int num_casilla) {

	//todo desde num_casilla se mueve a la derecha

	for(int i=num_casilla-1;i<usados;i++){
	
		datos[i]= datos[i+1];
		
	}
    
    usados--;
}

//Funcion que aniade una casilla nueva
//Parametros: el valor que se va a aniadir al vector
//POST: nuevo valor aniadido al final

void Resultados::Aniade(const Resultado & nuevo){
	

	//Si lo requiere se redimensiona

	if(usados >= capacidad){
		Redimensiona(); 
	}

	//Se aniade valor

	datos[usados] = nuevo;
	usados++;
}
