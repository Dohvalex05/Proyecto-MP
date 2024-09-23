/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// FASE 2 PROYECTO MP(Modificado Fase 4)
//
// Fichero: Corredores.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef CORREDORES
#define CORREDORES

#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include "Corredor.h"

class Corredores{

private:

	const int capacidad_inicial=20;

	int capacidad; //capacidad

	int usados; //espacio usado

	Corredor * datos; //puntero

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
	//Parametros: referencia a otro objeto Corredores
	//POST: Informacion se transfiere

	void CopiarDatos (const Corredores & otro);

	//Redimensiona un vector 
	//Parametros: nada
	//POST: Vector tiene mas capacidad

	void Redimensiona (void);

	//Funcion que aniade una casilla nueva
	//Parametros: el valor que se va a aniadir al vector
	//POST: nuevo valor aniadido al final

	void Aniade(const Corredor & valor);

	//Funcion que borra una casilla del vector diamico
	//Parametros: referencia al vector, y la casilla a eliminar
	//POST: casilla desaparece y las necesarias se mueven a la izquierda

	void Elimina(const int num_casilla);

public:

	//CONSTRUCTORES

	//Constructor sin argumentos
	//Parametros:nada
	//POST: usadas son 0 y capacidad capacidad_inicial, memoria reservada


	Corredores();

	//Constructor con argumentos
	//Parametros: numero de casillas a reservar
	//POST: usadas son 0 y capacidad num_casillas, memoria reservada


	Corredores(const int num_casillas);

	//Constructor de copia,inicializa vector copiando informacion
	//Parametros: Referencia a otro objeto Corredores
	//POST: Vector inicializado con informacion de otro

	Corredores(const Corredores & otro);

	//Constructor nuevo.
	//Parametros: referencia a string que contiene nombre de fichero
	//POST: Objeto construido a partir de informacion de fichero

	Corredores(string & nombre);

	//DESTRUCTOR

	//Destructor que acaba con la memoria reservada al acabar la ejecucion


	~Corredores();

	//METODOS GET
	//Serviran para extraer informacion de objeto Corredores

	int Usados() const;

	int Capacidad() const;

	bool EstaVacio() const;

	//FUNCIONES QUE MODIFICAN EL CONTENIDO

	//Funcion que deja un objeto Corredores vacio
	//Parametros:nada
	//POST: Vector vacio, usados a 0 y capacidad a 0

	void EliminaTodos();

	//Funcion que inserta valor en una casilla moviendo las demas a la derecha
	//Parametros: el valor a anadir, el numero de casilla
	//POST: se aniade ese valor a esa casilla moviendo las demas

	void Inserta(const Corredor & valor, const int num_casilla);

	//Funcion que reajusta vector
	//Parametros: nada
	//POST: la capacidad se reduce al numero de casillas usadas

	void Reajusta();

	//Sobrecargas de operadores


	//Copia profunda usando Operador de asignacion
	//Parametros:Referencia a otro objeto Corredores
	//POST: Se copia la informacion al implicito

	Corredores & operator = (const Corredores & otro);

	//Devuelvo valor usando operadores () y []
	//PARAMETROS: posicion de elemento Corredor
	//Devuelve: Ese elemento

	Corredor & operator() (const int num_casilla);

	Corredor & operator() (const int num_casilla) const;

	Corredor & operator[] (const int num_casilla);

	Corredor & operator[] (const int num_casilla) const;

	//Sobrecarga de == y !=
	//Parametros: Referencia a otro objeto Corredores(otro)
	//Iguales si comparten mismo numero casillas y mismo Dorsal
	//Devuelve: True si son iguales y False si no lo son

	bool operator == (const Corredores & otro) const;

	//Devuelve: False si son iguales y True si no lo son

	bool operator != (const Corredores & otro) const;

	//Sobrecargas de operadores >,>=,<,>=
 	//Parametros: Referencia a otro objeto Corredores(otro)

	//Devuelve: True si el objeto es mayor al otro y False si no

	bool operator > (const Corredores & otro) const;

	//Devuelve: True si el objeto es mayor o igual al otro y False si no

	bool operator >= (const Corredores & otro) const;

	//Devuelve: True si el objeto es menor al otro y False si no

	bool operator < (const Corredores & otro) const;

	//Devuelve: True si el objeto es menor o igual al otro y False si no

	bool operator <= (const Corredores & otro) const;

	//Sobrecarga de *
 	//Parametros: Referencia a otro objeto Corredores(otro)
 	//Devuelve: nuevo objeto Corredores que contiene todos los datos comunes

	friend Corredores operator * (const Corredores & este,const Corredores & otro);

	//Sobrecarga de &&

 	//Parametros: Referencias a dos objetos Corredores(este/otro)
 	//Devuelve: True si este contiene a otro y false si no

	friend bool operator && (const Corredores & este,const Corredores & otro);

	//Parametros: Referencias a un objeto Corredores y otro Corredor(este/otro)
	//Devuelve: True si este contiene a otro y false si no

	friend bool operator && (const Corredores & este,const Corredor & otro);

	//Parametros: Referencias a un objeto Corredor y otro Corredores(este/otro)
	//Devuelve: True si otro contiene a este y false si no

	friend bool operator && (const Corredor & este,const Corredores & otro);

	//Parametros: Referencias a un objeto Corredores 
	//y un int Numero de dorsal(este/NumDorsal)
	//Devuelve: true si Corredores contiene al dato Corredor cuyo campo
	//Dorsal coincide con el int.

	friend bool operator && (const Corredores & este,int NumDorsal);

	//Devuelve: true si Corredores contiene al dato Corredor cuyo campo
	//Dorsal coincide con el int.

	friend bool operator && (int NumDorsal,const Corredores & otro);

	//Sobrecarga de +

	//Parametros: Referencias a dos objetos Corredores(este,otro)
	//Devuelve: Nuevo objeto Corredores con suma(sin repeticion) de todos corredores
 
	friend Corredores operator + (const Corredores & este,const Corredores & otro);

	//Parametros: Referencias a un objeto Corredores y otro Corredor(este,otro)
	//Devuelve: Nuevo objeto Corredores con el nuevo objeto Corredor sumado

	friend Corredores operator + (const Corredores & este,const Corredor & otro);

	//Parametros: Referencias a un objeto Corredor y otro Corredores(este,otro)
	//Devuelve: Nuevo objeto Corredores con el nuevo objeto Corredor sumado

	friend Corredores operator + (const Corredor & este,const Corredores & otro);

	//Sobrecarga de +=

	//Parametros: Referencia a otro objeto Corredores(otro)
	//Devuelve: Objeto implicito sumado con el derecho

	Corredores & operator += (const Corredores & otro);

	//Parametros: Referencia a otro objeto Corredor(otro)
	//Devuelve: Objeto implicito sumado con el derecho

	Corredores & operator += (const Corredor & otro);

	//Sobrecarga de -

	//Parametros: Referencias a dos objetos Corredores(este,otro)
	//Devuelve: nuevo objeto Corredores con elementos comunes con otro restados
 
	friend Corredores operator - (const Corredores & este,const Corredores & otro);

	//Parametros: Referencias a un objeto Corredores y otro Corredor(este,otro)
	//Devuelve: Nuevo objeto Corredores con el nuevo objeto Corredor restado

	friend Corredores operator - (const Corredores & este,const Corredor & otro);

	//Parametros: Referencias a un objeto Corredor y otro Corredores(este,otro)
	//Devuelve: Nuevo objeto Corredores con el nuevo objeto Corredor restado

	friend Corredores operator - (const Corredores & este,int NumDorsal);

	//Sobrecarga de -=

	//Parametros: Referencia a otro objeto Corredores(otro)
	//Devuelve: Objeto implicito se le resta el explicito otro

	Corredores & operator -= (const Corredores & otro);

	//Parametros: Referencia a otro objeto Corredor(otro)
	//Devuelve: Objeto implicito se le resta el explicito

	Corredores & operator -= (const Corredor & otro);

	//Parametros: Dorsal de un corredor(NumDorsal)
	//Devuelve: Objeto implicito se le resta el explicito

	Corredores & operator -= (const int NumDorsal);

	//FUNCION TO STRING
	//Funcion que serializa informacion
	//Parametros: titulo que tendrá comienzo de ToString
	//Post: Muestra informacion de forma estructurada y facil de leer

	std::string ToString(const string titulo);

	//Sobrecarga de operadores << y >> para las clases coleccion
	//Parametros: referencia a objeto istream u ostream
	//			  referencia a objeto Corredores

	friend istream & operator >> (istream & in,Corredores & unos_Corredores);

	friend ostream & operator << (ostream & out,const Corredores & unos_Corredores);

	//FUNCIONES QUE GUARDAN O EXTRAEN INFORMACION EN FICHEROS

	//Funcion metodo de escritura
	//Parametros: referencia a string que contiene el nombre de un fichero
	//POST: informacion contenida en Corredores es guardada en un fichero
	//PRE: si el fichero no fuese del tipo especificado vector queda vacio

	void EscribirCorredores (const string & nombre) const;

	//Funcion metodo de lectura 
	//Parametros: referencia a string que contiene el nombre de un fichero
	//POST: informacion contenida en fichero es guardada en Corredores
	//PRE: si el fichero no fuese del tipo especificado vector queda vacio

	void LeerCorredores (const string & nombre);

};

#endif