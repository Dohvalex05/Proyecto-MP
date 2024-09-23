/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// FASE 2 Proyecto MP(Modificado Fase 4)
//
// Fichero: Carreras.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include "Carreras.h"



using namespace std;

/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/

//CONSTRUCTORES

//Constructor sin argumentos
//Parametros:nada
//POST: usadas son 0 y capacidad capacidad_inicial, memoria reservada

Carreras::Carreras(){

	usados=0;

	ReservarMemoria(capacidad_inicial);

}

//Constructor con argumentos
//Parametros: numero de casillas a reservar
//POST: usadas son 0 y capacidad num_casillas, memoria reservada

Carreras::Carreras(const int num_casillas){

	usados=0;

	ReservarMemoria(num_casillas);

}

//Constructor de copia,inicializa vector copiando informacion
//Parametros: Referencia a otro objeto Carreras
//POST: Vector inicializado con informacion de otro

Carreras::Carreras(const Carreras & otro){

	ReservarMemoria(otro.capacidad);
	
	usados = otro.usados;
	
	CopiarDatos(otro);
}

//Constructor nuevo.
//Parametros: referencia a string que contiene nombre de fichero
//POST: Objeto construido a partir de informacion de fichero

Carreras::Carreras(string & nombre){

	ReservarMemoria(capacidad_inicial);

	LeerCarreras(nombre);

}

/***************************************************************************/
/***************************************************************************/

//DESTRUCTOR

//Destructor que acaba con la memoria reservada al acabar la ejecucion

Carreras::~Carreras(){
	LiberarMemoria();
}


/***************************************************************************/
/***************************************************************************/

//METODOS GET
//Serviran para extraer informacion de objeto Carreras

int Carreras::Usados() const{

	return usados;

}

int Carreras::Capacidad() const{

	return capacidad;

}

bool Carreras::EstaVacio() const{

	bool vacio=false;

	if (usados == 0){
		vacio = true;
	}

	return vacio;


}

/***************************************************************************/
/***************************************************************************/

//FUNCIONES QUE MODIFICAN EL CONTENIDO

//Funcion que deja un objeto Carreras vacio
//Parametros:nada
//POST: Vector vacio, usados a 0 y capacidad a 0

void Carreras::EliminaTodos(){

	LiberarMemoria();

}

//Funcion que inserta un valor en una casilla moviendo las demas a la derecha
//Parametros: el valor a anadir, el numero de casilla
//POST: se aniade ese valor a esa casilla moviendo las demas

void Carreras::Inserta(const Carrera & valor, const int num_casilla) {

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


void Carreras::Reajusta(){

	//Copio informacion en temporal y al original le cambio capacidad

	Carreras temporal(*this);

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
//Parametros:Referencia a otro objeto Carreras
//POST: Se copia la informacion al implicito

Carreras & Carreras :: operator = (const Carreras & otro){

	LiberarMemoria();

	ReservarMemoria(otro.capacidad);

	usados=otro.usados;

	CopiarDatos(otro);

	return (*this);
}

//Devuelvo valor usando operadores () y []
//PARAMETROS: posicion de elemento Carrera
//Devuelve: Ese elemento

Carrera & Carreras::operator() (const int num_casilla){

	return(datos[num_casilla-1]);


}

Carrera & Carreras::operator() (const int num_casilla) const{

	return(datos[num_casilla-1]);


}
Carrera & Carreras::operator[] (const int num_casilla){

	return(datos[num_casilla-1]);



}

Carrera & Carreras::operator[] (const int num_casilla) const{

	return(datos[num_casilla-1]);


}

/***************************************************************************/
/***************************************************************************/

//Sobrecarga de == y !=
//Parametros: Referencia a otro objeto Carreras(otro)
//Iguales si comparten mismo numero casillas y mismo IdCarrera

//Devuelve: True si son iguales y False si no lo son

bool Carreras::operator == (const Carreras & otro) const{


 	bool iguales=true;

 	//me indica si sigo con el testeo

 	bool sigo=true;

 	if (usados != otro.usados) {
        iguales=false;  
    }

    //Si la primera comprobacion sale cierta el codigo no sigue

    if(iguales){

    	for(int i=0;i<usados && sigo;i++){
    		if (stoi(datos[i].GetIdCarrera()) != 
    			stoi(otro.datos[i].GetIdCarrera())){
    			iguales = false;
    			sigo = false;
    		}
    	}
    }

    return (iguales);

 }

 //Devuelve: False si son iguales y True si no lo son

 bool Carreras::operator != (const Carreras & otro) const{

 	return(!(*this == otro));
 	
 }

 //Sobrecargas de operadores >,>=,<,>=
 //Parametros: Referencia a otro objeto Carreras(otro)

 //Devuelve: True si el objeto es mayor al otro y False si no

 bool Carreras::operator > (const Carreras & otro) const{

 	bool mayor= true;

 	if (usados <= otro.usados){
 		mayor = false;
 	}

 	return mayor;
 }

 //Devuelve: True si el objeto es mayor o igual al otro y False si no

 bool Carreras::operator >= (const Carreras & otro) const{


 	bool mayorigual=true;

 	if (!(*this > otro) || !(*this == otro)){
 		mayorigual=false;
 	}

 	return mayorigual;
 }

 //Devuelve: True si el objeto es menor al otro y False si no

 bool Carreras::operator < (const Carreras & otro) const{

 	return(!(*this >= otro));

 }


 //Devuelve: True si el objeto es menor o igual al otro y False si no

 bool Carreras::operator <= (const Carreras & otro) const{

 	return(!(*this > otro));
 }

 //Sobrecarga de *
 //Parametros: Referencia a otro objeto Carreras(otro)
 //Devuelve: nuevo objeto Carreras que contiene todos los datos comunes

Carreras operator * (const Carreras & este,const Carreras & otro){

	Carreras nuevo;

	//Repaso que i valor de este coincida con j valor de otro
	//si coinciden se aniade

	for(int i=0;i<este.usados;i++){
		for(int j=0;j<otro.usados;j++){
			if (stoi(este.datos[i].GetIdCarrera()) == 
				stoi(otro.datos[j].GetIdCarrera()))
			{
				nuevo.Aniade(este.datos[i]);
			}
		}
	}

	return nuevo;

}

 //Sobrecarga de &&

 //Parametros: Referencias a dos objetos Carreras(este/otro)
 //Devuelve: True si este contiene a otro y false si no

bool operator && (const Carreras & este,const Carreras & otro){

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

//Parametros: Referencias a un objeto Carreras y otro Carrera(este/otro)
//Devuelve: True si este contiene a otro y false si no

bool operator && (const Carreras & este,const Carrera & otro){

	bool contiene=false;

	Carreras Hotro;

	Hotro.Aniade(otro);

	if(este && Hotro){
		contiene=true;
	}

	return contiene;

}

//Parametros: Referencias a un objeto Carrera y otro Carreras(este/otro)
//Devuelve: True si otro contiene a este y false si no

bool operator && (const Carrera & este,const Carreras & otro){

	return(otro && este);

}

//Parametros: Referencias a un objeto Carreras 
//y un int Numero de IdCarrera(este/NumIdCarrera)
//Devuelve: true si Carreras contiene al dato Carrera cuyo campo
//IdCarrera coincide con el int.

bool operator && (const Carreras & este,int NumIdCarrera){

	bool contiene=false;

	//Repasa todos los datos hasta encontrar al indicado

	for(int i=0;i<este.Usados() && !contiene;i++){
		if (stoi(este.datos[i].GetIdCarrera()) == NumIdCarrera){
			contiene = true;
		}
	}

	return contiene;

}

//Devuelve: true si Carreras contiene al dato Carrera cuyo campo
//IdCarrera coincide con el int.

bool operator && (int NumIdCarrera,const Carreras & otro){

	return(otro && NumIdCarrera);

}

//Sobrecarga de +

//Parametros: Referencias a dos objetos Carreras(este,otro)
//Devuelve: Nuevo objeto Carreras con suma(sin repeticion) de todas carreras
 
Carreras operator + (const Carreras & este,const Carreras & otro){

	Carreras nuevo(este);

	//Si este no contiene, entonces se aniade, se evita duplicados

	for(int i=0;i<otro.Usados();i++){

		if(!(este && otro.datos[i])){

			nuevo.Aniade(otro.datos[i]);

		}

	}

	return nuevo;

}

//Parametros: Referencias a un objeto Carreras y otro Carrera(este,otro)
//Devuelve: Nuevo objeto Carreras con el nuevo objeto Carrera sumado

Carreras operator + (const Carreras & este,const Carrera & otro){

	Carreras nuevo;

	nuevo.Aniade(otro);

	return(este + nuevo);

}

//Parametros: Referencias a un objeto Carrera y otro Carreras(este,otro)
//Devuelve: Nuevo objeto Carreras con el nuevo objeto Carrera sumado

Carreras operator + (const Carrera & este,const Carreras & otro){

	return(otro + este);

}


//Sobrecarga de +=

//Parametros: Referencia a otro objeto Carreras(otro)
//Devuelve: Objeto implicito sumado con el derecho

Carreras & Carreras::operator += (const Carreras & otro){

	*this = *this + otro;

	return (*this);

}

//Parametros: Referencia a otro objeto Carrera(otro)
//Devuelve: Objeto implicito sumado con el derecho

Carreras & Carreras::operator += (const Carrera & otro){

	*this = *this + otro;

	return (*this);

}

//Sobrecarga de -

//Parametros: Referencias a dos objetos Carreras(este,otro)
//Devuelve: Nuevo objeto Carreras con elementos comunes eliminados
 
Carreras operator - (const Carreras & este,const Carreras & otro){

	Carreras nuevo(este);

	//si lo contiene se elimina

	for(int i=0;i<otro.Usados();i++){

		if(este && otro.datos[i]){

			nuevo.Elimina(i);

		}

	}

	return nuevo;

}

//Parametros: Referencias a un objeto Carreras y otro Carrera(este,otro)
//Devuelve: Nuevo objeto Carreras con el nuevo objeto Carrera restado

Carreras operator - ( const Carreras & este,const Carrera & otro){

	Carreras nuevo;

	nuevo.Aniade(otro);

	return(este - nuevo);

}

//Parametros: Referencias a un objeto Carrera y otro Carreras(este,otro)
//Devuelve: Nuevo objeto Carreras con el nuevo objeto Carrera restado

Carreras operator - (const Carreras & este,int NumIdCarrera){

	bool sigue=true;

	Carreras nuevo(este);

	//Si lo contiene fuera

	for(int i=0;i<este.Usados() && sigue;i++){
		if (stoi(nuevo.datos[i].GetIdCarrera()) == NumIdCarrera){
			nuevo.Elimina(i);
			sigue=false;
		}
	}
	
	return nuevo;

}

//Sobrecarga de -=

//Parametros: Referencia a otro objeto Carreras(otro)
//Devuelve: Objeto implicito se le resta el explicito

Carreras & Carreras::operator -= (const Carreras & otro){

	*this = *this - otro;

	return (*this);

}

//Parametros: Referencia a otro objeto Carrera(otro)
//Devuelve: Objeto implicito se le resta el explicito

Carreras & Carreras::operator -= (const Carrera & otro){

	*this = *this - otro;

	return (*this);

}

//Parametros: IdCarrera de una carrera(NumIdCarrera)
//Devuelve: Objeto implicito se le resta el explicito

Carreras & Carreras::operator -= (const int NumIdCarrera){

	*this = *this - NumIdCarrera;

	return (*this);

}

/***************************************************************************/
/***************************************************************************/

//FUNCION TO STRING
//Funcion que serializa informacion
//Parametros: titulo que tendrá comienzo de ToString
//Post: Muestra informacion de forma estructurada y facil de leer

string Carreras::ToString(const string titulo){

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
//			  referencia a objeto Carreras


istream & operator >> (istream & in,Carreras & unas_carreras){

	unas_carreras.LiberarMemoria();

	unas_carreras.ReservarMemoria (unas_carreras.capacidad_inicial);

	//Empiezo lectura

	string linea;

	getline(in,linea);

	while (!in.eof()) {
					
		Carrera una_carrera (linea,'*');

		// Añadir el dato "Carrera" leido a la colección 
		unas_carreras += una_carrera; // Operator += 

		// Leer la siguiente linea 
		getline(in, linea); 
			
	}

	return in;

}

ostream & operator << (ostream & out,const Carreras & unas_carreras){

	ostringstream oss;

	for(int i=1;i<=unas_carreras.Usados();i++){

		oss << unas_carreras[i] << endl;

	}

	string final=oss.str();

	out << final;

	return out;

}

//FUNCIONES QUE GUARDAN O EXTRAEN INFORMACION EN FICHEROS

//Funcion metodo de escritura
//Parametros: referencia a string que contiene el nombre de un fichero
//POST: informacion contenida en Carreras es guardada en un fichero
//PRE: si el fichero no fuese del tipo especificado vector queda vacio

void Carreras::EscribirCarreras (const string & nombre) const{

	if (usados != 0){

		ofstream fo(nombre);

		fo << "CARRERAS" << endl;

		fo << *this;

		fo.close();

	}


}

//Funcion metodo de lectura 
//Parametros: referencia a string que contiene el nombre de un fichero
//POST: informacion contenida en fichero es guardada en Carreras
//PRE: si el fichero no fuese del tipo especificado vector queda vacio

void Carreras::LeerCarreras (const string & nombre){

	ifstream fi(nombre);

	//Me salto la primera parte que contiene informacion no guardable

	string linea;

	getline(fi, linea);

	if(linea == "CARRERAS"){

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

void Carreras::ReservarMemoria (const int num_casillas){

	if(num_casillas < 0){

		capacidad = 1;

	}

	else{

	capacidad = num_casillas;

	}

	datos = new Carrera[capacidad];
}

//Elimina la memoria usada
//Parametros:nada
//POST: Numero de casillas usadas y capacidad son 0

void Carreras:: LiberarMemoria(){

	if (datos != nullptr && datos != 0){

		delete [] datos;

		usados=0;

		capacidad=0;

	}

}

//Copia Datos de un lugar a otro
//Parametros: referencia a otro objeto Carreras
//POST: Informacion se transfiere

void Carreras::CopiarDatos(const Carreras & otro){

	for(int i=0;i<otro.usados;i++){

		datos[i] = otro.datos[i];

	}

}


//Redimensiona un vector 
//Parametros: nada
//POST: Vector tiene mas capacidad


void Carreras::Redimensiona (void){

	//Objeto temporal copia
	
	Carreras copia(*this);
	
	LiberarMemoria();
	ReservarMemoria(copia.capacidad + capacidad_inicial);
	
	CopiarDatos(copia);

	usados=copia.usados;
}


//Funcion que borra una casilla del vector diamico
//Parametros: referencia al vector, y la casilla a eliminar
//POST: casilla desaparece y las necesarias se mueven a la izquierda

void Carreras::Elimina(const int num_casilla) {

	//todo desde num_casilla se mueve a la derecha

	for(int i=num_casilla-1;i<usados;i++){
	
		datos[i]= datos[i+1];
		
	}
    
    usados--;
}

//Funcion que aniade una casilla nueva
//Parametros: el valor que se va a aniadir al vector
//POST: nuevo valor aniadido al final

void Carreras::Aniade(const Carrera & nuevo){
	

	//Si lo requiere se redimensiona

	if(usados >= capacidad){
		Redimensiona(); 
	}

	//Se aniade valor

	datos[usados] = nuevo;
	usados++;
}

