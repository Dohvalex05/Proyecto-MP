/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// FASE 2 PROYECTO MP(Modificado Fase 4)
//
// Fichero: Carreras.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef CARRERAS
#define CARRERAS

#include <string>
#include <cstring>
#include <fstream>
#include "Carrera.h"

class Carreras{

private:

	const int capacidad_inicial=20;

	int capacidad; //capacidad

	int usados; //espacio usado

	Carrera * datos; //puntero

	//Funciones privadas

	//Pide memoria dinamica para guardar el vector
	//Parametros: numero de casillas
	//PRE: num_casillas >= 0;

	void ReservarMemoria (const int num_casillas);

	//Elimina la memoria usada
	//Parametros:nada
	//POST: Numero de casillas usadas y capacidad son 0

	void LiberarMemoria (void);

	//Copia Datos de un lugar a otro
	//Parametros: referencia a otro objeto Carreras
	//POST: Informacion se transfiere

	void CopiarDatos (const Carreras & otro);

	//Redimensiona un vector 
	//Parametros: nada
	//POST: Vector tiene mas capacidad

	void Redimensiona (void);

	//Funcion que aniade una casilla nueva
	//Parametros: el valor que se va a aniadir al vector
	//POST: nuevo valor aniadido al final

	void Aniade(const Carrera & valor);

	//Funcion que borra una casilla del vector diamico
	//Parametros: referencia al vector, y la casilla a eliminar
	//POST: casilla desaparece y las necesarias se mueven a la izquierda

	void Elimina(const int num_casilla);




public:

	//CONSTRUCTORES

	//Constructor sin argumentos
	//Parametros:nada
	//POST: usadas son 0 y capacidad capacidad_inicial, memoria reservada


	Carreras();

	//Constructor con argumentos
	//Parametros: numero de casillas a reservar
	//POST: usadas son 0 y capacidad num_casillas, memoria reservada


	Carreras(const int num_casillas);

	//Constructor de copia,inicializa vector copiando informacion
	//Parametros: Referencia a otro objeto Carreras
	//POST: Vector inicializado con informacion de otro

	Carreras(const Carreras & otro);

	//DESTRUCTOR

	//Destructor que acaba con la memoria reservada al acabar la ejecucion

	~Carreras();

	//Constructor nuevo.
	//Parametros: referencia a string que contiene nombre de fichero
	//POST: Objeto construido a partir de informacion de fichero

	Carreras(string & nombre);

	//CONSTRUCTOR NUEVO
	//Parametros: referencia a string que contiene el nombre de un fichero
	//POST: Construye un objeto C a partir de la información guardada en un
	//fichero de texto llamado nombre.
	//PRE: si el fichero no fuese del tipo especificado vector queda vacio

	Carreras(const string & nombre);

	//METODOS GET
	//Serviran para extraer informacion de objeto Carreras

	int Usados() const;

	int Capacidad() const;

	bool EstaVacio() const;

	//FUNCIONES QUE MODIFICAN EL CONTENIDO

	//Funcion que deja un objeto Carreras vacio
	//Parametros:nada
	//POST: Vector vacio, usados a 0 y capacidad a 0

	void EliminaTodos();

	//Funcion que inserta valor en una casilla moviendo las demas a la derecha
	//Parametros: el valor a anadir, el numero de casilla
	//POST: se aniade ese valor a esa casilla moviendo las demas

	void Inserta(const Carrera & valor, const int num_casilla);

	//Funcion que reajusta vector
	//Parametros: nada
	//POST: la capacidad se reduce al numero de casillas usadas

	void Reajusta();

	//Sobrecargas de operadores


	//Copia profunda usando Operador de asignacion
	//Parametros:Referencia a otro objeto Carreras
	//POST: Se copia la informacion al implicito

	Carreras & operator = (const Carreras & otro);

	//Devuelvo valor usando operadores () y []
	//PARAMETROS: posicion de elemento Carrera
	//Devuelve: Ese elemento

	Carrera & operator() (const int num_casilla);

	Carrera & operator() (const int num_casilla) const;

	Carrera & operator[] (const int num_casilla);

	Carrera & operator[] (const int num_casilla) const;

	//Sobrecarga de == y !=
	//Parametros: Referencia a otro objeto Carreras(otro)
	//Iguales si comparten mismo numero casillas y mismo IdCarrera
	//Devuelve: True si son iguales y False si no lo son

	bool operator == (const Carreras & otro) const;

	//Devuelve: False si son iguales y True si no lo son

	bool operator != (const Carreras & otro) const;

	//Sobrecargas de operadores >,>=,<,>=
 	//Parametros: Referencia a otro objeto Carreras(otro)

	//Devuelve: True si el objeto es mayor al otro y False si no

	bool operator > (const Carreras & otro) const;

	//Devuelve: True si el objeto es mayor o igual al otro y False si no

	bool operator >= (const Carreras & otro) const;

	//Devuelve: True si el objeto es menor al otro y False si no

	bool operator < (const Carreras & otro) const;

	//Devuelve: True si el objeto es menor o igual al otro y False si no

	bool operator <= (const Carreras & otro) const;

	//Sobrecarga de *
 	//Parametros: Referencia a otro objeto Carreras(otro)
 	//Devuelve: nuevo objeto Carreras que contiene todos los datos comunes

	friend Carreras operator * (const Carreras & este,const Carreras & otro);

	//Sobrecarga de &&

 	//Parametros: Referencias a dos objetos Carreras(este/otro)
 	//Devuelve: True si este contiene a otro y false si no

	friend bool operator && (const Carreras & este,const Carreras & otro);

	//Parametros: Referencias a un objeto Carreras y otro Carrera(este/otro)
	//Devuelve: True si este contiene a otro y false si no

	friend bool operator && (const Carreras & este,const Carrera & otro);

	//Parametros: Referencias a un objeto Carrera y otro Carreras(este/otro)
	//Devuelve: True si otro contiene a este y false si no

	friend bool operator && (const Carrera & este,const Carreras & otro);

	//Parametros: Referencias a un objeto Carreras 
	//y un int Numero de IdCarrera(este/NumIdCarrera)
	//Devuelve: true si Carreras contiene al dato Carrera cuyo campo
	//IdCarrera coincide con el int.

	friend bool operator && (const Carreras & este,int NumIdCarrera);

	//Devuelve: true si Carreras contiene al dato Carrera cuyo campo
	//IdCarrera coincide con el int.

	friend bool operator && (int NumIdCarrera,const Carreras & otro);

	//Sobrecarga de +

	//Parametros: Referencias a dos objetos Carreras(este,otro)
	//Devuelve: Nuevo objeto Carreras con suma(sin repeticion) de todos corredores
 
	friend Carreras operator + (const Carreras & este,const Carreras & otro);

	//Parametros: Referencias a un objeto Carreras y otro Carrera(este,otro)
	//Devuelve: Nuevo objeto Carreras con el nuevo objeto Carrera sumado

	friend Carreras operator + (const Carreras & este,const Carrera & otro);

	//Parametros: Referencias a un objeto Carrera y otro Carreras(este,otro)
	//Devuelve: Nuevo objeto Carreras con el nuevo objeto Carrera sumado

	friend Carreras operator + (const Carrera & este,const Carreras & otro);

	//Sobrecarga de +=

	//Parametros: Referencia a otro objeto Carreras(otro)
	//Devuelve: Objeto implicito sumado con el derecho

	Carreras & operator += (const Carreras & otro);

	//Parametros: Referencia a otro objeto Carrera(otro)
	//Devuelve: Objeto implicito sumado con el derecho

	Carreras & operator += (const Carrera & otro);

	//Sobrecarga de -

	//Parametros: Referencias a dos objetos Carreras(este,otro)
	//Devuelve: Nuevo objeto Carreras con elementos comunes con otro restados
 
	friend Carreras operator - (const Carreras & este,const Carreras & otro);

	//Parametros: Referencias a un objeto Carreras y otro Carrera(este,otro)
	//Devuelve: Nuevo objeto Carreras con el nuevo objeto Carrera restado

	friend Carreras operator - (const Carreras & este,const Carrera & otro);

	//Parametros: Referencias a un objeto Carrera y otro Carreras(este,otro)
	//Devuelve: Nuevo objeto Carreras con el nuevo objeto Carrera restado

	friend Carreras operator - (const Carreras & este,int NumIdCarrera);

	//Sobrecarga de -=

	//Parametros: Referencia a otro objeto Carreras(otro)
	//Devuelve: Objeto implicito se le resta el explicito otro

	Carreras & operator -= (const Carreras & otro);

	//Parametros: Referencia a otro objeto Carrera(otro)
	//Devuelve: Objeto implicito se le resta el explicito

	Carreras & operator -= (const Carrera & otro);

	//Parametros: IdCarrera de un corredor(NumIdCarrera)
	//Devuelve: Objeto implicito se le resta el explicito

	Carreras & operator -= (const int NumIdCarrera);

	//FUNCION TO STRING
	//Funcion que serializa informacion
	//Parametros: titulo que tendrá comienzo de ToString
	//Post: Muestra informacion de forma estructurada y facil de leer

	std::string ToString(const string titulo);

	//Sobrecarga de operadores << y >> para las clases coleccion
	//Parametros: referencia a objeto istream u ostream
	//			  referencia a objeto Carreras
	//POST:referencia a istream u ostream

	friend istream & operator >> (istream & in,Carreras & unas_carreras);

	friend ostream & operator << (ostream & out, const Carreras & unas_carreras);

	//FUNCIONES QUE GUARDAN O EXTRAEN INFORMACION EN FICHEROS

	//Funcion metodo de escritura
	//Parametros: referencia a string que contiene el nombre de un fichero
	//POST: informacion contenida en Carreras es guardada en un fichero
	//PRE: si el fichero no fuese del tipo especificado vector queda vacio

	void EscribirCarreras (const string & nombre) const;

	//Funcion metodo de lectura 
	//Parametros: referencia a string que contiene el nombre de un fichero
	//POST: informacion contenida en fichero es guardada en Carreras
	//PRE: si el fichero no fuese del tipo especificado vector queda vacio

	void LeerCarreras (const string & nombre);
};

#endif