/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// FASE 2 Proyecto MP(Modificado Fase 4)
//
// Fichero: Corredores.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include "Corredores.h"



using namespace std;


/***************************************************************************/
/***************************************************************************/

//CONSTRUCTORES

//Constructor sin argumentos
//Parametros:nada
//POST: usadas son 0 y capacidad capacidad_inicial, memoria reservada

Corredores::Corredores(){

	usados=0;

	ReservarMemoria(capacidad_inicial);

}

//Constructor con argumentos
//Parametros: numero de casillas a reservar
//POST: usadas son 0 y capacidad num_casillas, memoria reservada

Corredores::Corredores(const int num_casillas){

	usados=0;

	ReservarMemoria(num_casillas);

}

//Constructor de copia,inicializa vector copiando informacion
//Parametros: Referencia a otro objeto Corredores
//POST: Vector inicializado con informacion de otro

Corredores::Corredores(const Corredores & otro){

	ReservarMemoria(otro.capacidad);
	
	usados = otro.usados;
	
	CopiarDatos(otro);
}

//Constructor nuevo.
//Parametros: referencia a string que contiene nombre de fichero
//POST: Objeto construido a partir de informacion de fichero

Corredores::Corredores(string & nombre){

	ReservarMemoria(capacidad_inicial);

	LeerCorredores(nombre);

}

/***************************************************************************/
/***************************************************************************/

//DESTRUCTOR

//Destructor que acaba con la memoria reservada al acabar la ejecucion

Corredores::~Corredores(){
	LiberarMemoria();
}


/***************************************************************************/
/***************************************************************************/

//METODOS GET
//Serviran para extraer informacion de objeto Corredores

int Corredores::Usados() const{

	return usados;

}

int Corredores::Capacidad() const{

	return capacidad;

}

bool Corredores::EstaVacio() const{

	bool vacio=false;

	if (usados == 0){
		vacio = true;
	}

	return vacio;


}

/***************************************************************************/
/***************************************************************************/

//FUNCIONES QUE MODIFICAN EL CONTENIDO

//Funcion que deja un objeto Corredores vacio
//Parametros:nada
//POST: Vector vacio, usados a 0 y capacidad a 0

void Corredores::EliminaTodos(){

	LiberarMemoria();

}

//Funcion que inserta un valor en una casilla moviendo las demas a la derecha
//Parametros: el valor a anadir, el numero de casilla
//POST: se aniade ese valor a esa casilla moviendo las demas

void Corredores::Inserta(const Corredor & valor, const int num_casilla) {

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


void Corredores::Reajusta(){

	//Copio informacion en temporal y al original le cambio capacidad

	Corredores temporal(*this);

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
//Parametros:Referencia a otro objeto Corredores
//POST: Se copia la informacion al implicito

Corredores & Corredores :: operator = (const Corredores & otro){

	LiberarMemoria();

	ReservarMemoria(otro.capacidad);

	usados=otro.usados;

	CopiarDatos(otro);

	return (*this);
}

//Devuelvo valor usando operadores () y []
//PARAMETROS: posicion de elemento Corredor
//Devuelve: Ese elemento

Corredor & Corredores::operator() (const int num_casilla){

	return(datos[num_casilla-1]);


}

Corredor & Corredores::operator() (const int num_casilla) const{

	return(datos[num_casilla-1]);


}
Corredor & Corredores::operator[] (const int num_casilla){

	return(datos[num_casilla-1]);



}

Corredor & Corredores::operator[] (const int num_casilla) const{

	return(datos[num_casilla-1]);


}

/***************************************************************************/
/***************************************************************************/

//Sobrecarga de == y !=
//Parametros: Referencia a otro objeto Corredores(otro)
//Iguales si comparten mismo numero casillas y mismo Dorsal

//Devuelve: True si son iguales y False si no lo son

bool Corredores::operator == (const Corredores & otro) const{


 	bool iguales=true;

 	//me indica si sigo con el testeo

 	bool sigo=true;

 	if (usados != otro.usados) {
        iguales=false;  
    }

    //Si la primera comprobacion sale cierta el codigo no sigue

    if(iguales){

    	for(int i=0;i<usados && sigo;i++){
    		if (stoi(datos[i].GetDorsal()) != 
    			stoi(otro.datos[i].GetDorsal())){
    			iguales = false;
    			sigo = false;
    		}
    	}
    }

    return (iguales);

 }

 //Devuelve: False si son iguales y True si no lo son

 bool Corredores::operator != (const Corredores & otro) const{

 	return(!(*this == otro));
 	
 }

 //Sobrecargas de operadores >,>=,<,>=
 //Parametros: Referencia a otro objeto Corredores(otro)

 //Devuelve: True si el objeto es mayor al otro y False si no

 bool Corredores::operator > (const Corredores & otro) const{

 	bool mayor= true;

 	if (usados <= otro.usados){
 		mayor = false;
 	}

 	return mayor;
 }

 //Devuelve: True si el objeto es mayor o igual al otro y False si no

 bool Corredores::operator >= (const Corredores & otro) const{


 	bool mayorigual=true;

 	if (!(*this > otro) || !(*this == otro)){
 		mayorigual=false;
 	}

 	return mayorigual;
 }

 //Devuelve: True si el objeto es menor al otro y False si no

 bool Corredores::operator < (const Corredores & otro) const{

 	return(!(*this >= otro));

 }


 //Devuelve: True si el objeto es menor o igual al otro y False si no

 bool Corredores::operator <= (const Corredores & otro) const{

 	return(!(*this > otro));
 }

 //Sobrecarga de *
 //Parametros: Referencia a otro objeto Corredores(otro)
 //Devuelve: nuevo objeto Corredores que contiene todos los datos comunes

Corredores operator * (const Corredores & este,const Corredores & otro){

	Corredores nuevo;

	//Repaso que i valor de este coincida con j valor de otro
	//si coinciden se aniade


	for(int i=0;i<este.usados;i++){
		for(int j=0;j<otro.usados;j++){
			if (stoi(este.datos[i].GetDorsal()) == 
				stoi(otro.datos[j].GetDorsal()))
			{
				nuevo.Aniade(este.datos[i]);
			}
		}
	}

	return nuevo;

}

 //Sobrecarga de &&

 //Parametros: Referencias a dos objetos Corredores(este/otro)
 //Devuelve: True si este contiene a otro y false si no

bool operator && (const Corredores & este,const Corredores & otro){

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

//Parametros: Referencias a un objeto Corredores y otro Corredor(este/otro)
//Devuelve: True si este contiene a otro y false si no

bool operator && (const Corredores & este,const Corredor & otro){

	bool contiene=false;

	Corredores Hotro;

	Hotro.Aniade(otro);

	if(este && Hotro){
		contiene=true;
	}

	return contiene;

}

//Parametros: Referencias a un objeto Corredor y otro Corredores(este/otro)
//Devuelve: True si otro contiene a este y false si no

bool operator && (const Corredor & este,const Corredores & otro){

	return(otro && este);

}

//Parametros: Referencias a un objeto Corredores 
//y un int Numero de dorsal(este/NumDorsal)
//Devuelve: true si Corredores contiene al dato Corredor cuyo campo
//Dorsal coincide con el int.

bool operator && (const Corredores & este,int NumDorsal){

	bool contiene=false;

	//Repasa todos los datos hasta encontrar al indicado

	for(int i=0;i<este.Usados() && !contiene;i++){
		if (stoi(este.datos[i].GetDorsal()) == NumDorsal){
			contiene = true;
		}
	}

	return contiene;

}

//Devuelve: true si Corredores contiene al dato Corredor cuyo campo
//Dorsal coincide con el int.

bool operator && (int NumDorsal,const Corredores & otro){

	return(otro && NumDorsal);

}

//Sobrecarga de +

//Parametros: Referencias a dos objetos Corredores(este,otro)
//Devuelve: Nuevo objeto Corredores con suma(sin repeticion)
// de los dos objetos corredores
 
Corredores operator + (const Corredores & este,const Corredores & otro){

	Corredores nuevo(este);

	//Si este no contiene, entonces se aniade, se evita duplicados

	for(int i=0;i<otro.Usados();i++){

		if(!(este && otro.datos[i])){

			nuevo.Aniade(otro.datos[i]);

		}

	}

	return nuevo;

}

//Parametros: Referencias a un objeto Corredores y otro Corredor(este,otro)
//Devuelve: Nuevo objeto Corredores con el nuevo objeto Corredor sumado

Corredores operator + (const Corredores & este,const Corredor & otro){

	Corredores nuevo;

	nuevo.Aniade(otro);

	return(este + nuevo);

}

//Parametros: Referencias a un objeto Corredor y otro Corredores(este,otro)
//Devuelve: Nuevo objeto Corredores con el nuevo objeto Corredor sumado

Corredores operator + (const Corredor & este,const Corredores & otro){

	return(otro + este);

}


//Sobrecarga de +=

//Parametros: Referencia a otro objeto Corredores(otro)
//Devuelve: Objeto implicito sumado con el derecho

Corredores & Corredores::operator += (const Corredores & otro){

	*this = *this + otro;

	return (*this);

}

//Parametros: Referencia a otro objeto Corredor(otro)
//Devuelve: Objeto implicito sumado con el derecho

Corredores & Corredores::operator += (const Corredor & otro){

	*this = *this + otro;

	return (*this);

}

//Sobrecarga de -

//Parametros: Referencias a dos objetos Corredores(este,otro)
//Devuelve: Nuevo objeto Corredores con elementos comunes eliminados
 
Corredores operator - (const Corredores & este,const Corredores & otro){

	Corredores nuevo(este);

	//si lo contiene se elimina

	for(int i=0;i<otro.Usados();i++){

		if(este && otro.datos[i]){

			nuevo.Elimina(i);

		}

	}

	return nuevo;

}

//Parametros: Referencias a un objeto Corredores y otro Corredor(este,otro)
//Devuelve: Nuevo objeto Corredores con el nuevo objeto Corredor sumado

Corredores operator - ( const Corredores & este,const Corredor & otro){

	Corredores nuevo;

	nuevo.Aniade(otro);

	return(este - nuevo);

}

//Parametros: Referencias a un objeto Corredor y otro Corredores(este,otro)
//Devuelve: Nuevo objeto Corredores con el nuevo objeto Corredor restado

Corredores operator - (const Corredores & este,int NumDorsal){

	bool sigue=true;

	Corredores nuevo(este);

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

//Parametros: Referencia a otro objeto Corredores(otro)
//Devuelve: Objeto implicito se le resta el explicito

Corredores & Corredores::operator -= (const Corredores & otro){

	*this = *this - otro;

	return (*this);

}

//Parametros: Referencia a otro objeto Corredor(otro)
//Devuelve: Objeto implicito se le resta el explicito

Corredores & Corredores::operator -= (const Corredor & otro){

	*this = *this - otro;

	return (*this);

}

//Parametros: Dorsal de un corredor(NumDorsal)
//Devuelve: Objeto implicito se le resta el explicito

Corredores & Corredores::operator -= (const int NumDorsal){

	*this = *this - NumDorsal;

	return (*this);

}

/***************************************************************************/
/***************************************************************************/

//FUNCION TO STRING
//Funcion que serializa informacion
//Parametros: titulo que tendrá comienzo de ToString
//Post: Muestra informacion de forma estructurada y facil de leer

string Corredores::ToString(const string titulo){

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
//			  referencia a objeto Corredores


istream & operator >> (istream & in,Corredores & unos_Corredores){

	unos_Corredores.LiberarMemoria();

	unos_Corredores.ReservarMemoria (unos_Corredores.capacidad_inicial);

	string linea;

	getline(in, linea); // Lectura adelantada

	while (!in.eof()) {
					
		Corredor un_Corredor (linea,'*');

		// Añadir el dato "Corredor" leido a la colección 
		unos_Corredores += un_Corredor; // Operator += 

		// Leer la siguiente linea 
		getline(in, linea); 
		
	}

	return in;

}

ostream & operator << (ostream & out,const Corredores & unos_Corredores){

	ostringstream oss;

	for(int i=1;i<=unos_Corredores.Usados();i++){

		oss << unos_Corredores[i] << endl;
	}

	string final=oss.str();

	out << final;

	return out;

}

//FUNCIONES QUE GUARDAN O EXTRAEN INFORMACION EN FICHEROS

//Funcion metodo de escritura
//Parametros: referencia a string que contiene el nombre de un fichero
//POST: informacion contenida en Corredores es guardada en un fichero
//PRE: si el fichero no fuese del tipo especificado vector queda vacio

void Corredores::EscribirCorredores (const string & nombre) const{

	if (usados != 0){

		ofstream fo(nombre);

		fo << "CORREDORES" << endl;

		fo << *this;

		fo.close();

	}


}


//Funcion metodo de lectura 
//Parametros: referencia a string que contiene el nombre de un fichero
//POST: informacion contenida en fichero es guardada en Corredores
//PRE: si el fichero no fuese del tipo especificado vector queda vacio

void Corredores::LeerCorredores (const string & nombre){

	ifstream fi(nombre);

	//Me salto la primera parte que contiene informacion no guardable

	string linea;

	getline(fi, linea);

	if(linea == "CORREDORES"){

		getline(fi,linea);

		while(linea[0] == '#'){

			getline(fi,linea);

		}

		//evito enviar a fi >> *this la informacion incorrecta

		//ios::cur = marca posicion actual

		//linea.length()-1 = la long de la linea -1 para retroceder una linea

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

void Corredores::ReservarMemoria (const int num_casillas){

	if(num_casillas < 0){

		capacidad = 1;

	}

	else{

	capacidad = num_casillas;

	}

	datos = new Corredor[capacidad];
}

//Elimina la memoria usada
//Parametros:nada
//POST: Numero de casillas usadas y capacidad son 0

void Corredores:: LiberarMemoria(){

	if (datos != nullptr && datos != 0){

		delete [] datos;

		usados=0;

		capacidad=0;

	}

}

//Copia Datos de un lugar a otro
//Parametros: referencia a otro objeto Corredores
//POST: Informacion se transfiere

void Corredores::CopiarDatos(const Corredores & otro){

	for(int i=0;i<otro.usados;i++){

		datos[i] = otro.datos[i];

	}

}


//Redimensiona un vector 
//Parametros: nada
//POST: Vector tiene mas capacidad


void Corredores::Redimensiona (void){

	//Objeto temporal copia
	
	Corredores copia(*this);
	
	LiberarMemoria();
	ReservarMemoria(copia.capacidad + capacidad_inicial);
	
	CopiarDatos(copia);

	usados=copia.usados;
}


//Funcion que borra una casilla del vector diamico
//Parametros: referencia al vector, y la casilla a eliminar
//POST: casilla desaparece y las necesarias se mueven a la izquierda

void Corredores::Elimina(const int num_casilla) {

	//todo desde num_casilla se mueve a la derecha

	for(int i=num_casilla-1;i<usados;i++){
	
		datos[i]= datos[i+1];
		
	}
    
    usados--;
}

//Funcion que aniade una casilla nueva
//Parametros: el valor que se va a aniadir al vector
//POST: nuevo valor aniadido al final

void Corredores::Aniade(const Corredor & nuevo){
	

	//Si lo requiere se redimensiona

	if(usados >= capacidad){
		Redimensiona(); 
	}

	//Se aniade valor

	datos[usados] = nuevo;
	usados++;
}
