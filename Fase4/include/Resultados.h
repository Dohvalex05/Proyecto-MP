/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// FASE 2 PROYECTO MP(Modificado Fase 4)
//
// Fichero: Resultados.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef RESULTADOS
#define RESULTADOS

#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Resultado.h"

class Resultados{

private:

	const int capacidad_inicial=20;

	int capacidad; //capacidad

	int usados; //espacio usado

	Resultado * datos; //puntero

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
	//Parametros: referencia a otro objeto Resultados
	//POST: Informacion se transfiere

	void CopiarDatos (const Resultados & otro);

	//Redimensiona un vector 
	//Parametros: nada
	//POST: Vector tiene mas capacidad

	void Redimensiona (void);

	//Funcion que aniade una casilla nueva
	//Parametros: el valor que se va a aniadir al vector
	//POST: nuevo valor aniadido al final

	void Aniade(const Resultado & valor);

	//Funcion que borra una casilla del vector diamico
	//Parametros: referencia al vector, y la casilla a eliminar
	//POST: casilla desaparece y las necesarias se mueven a la izquierda

	void Elimina(const int num_casilla);




public:

	//CONSTRUCTORES

	//Constructor sin argumentos
	//Parametros:nada
	//POST: usadas son 0 y capacidad capacidad_inicial, memoria reservada


	Resultados();

	//Constructor con argumentos
	//Parametros: numero de casillas a reservar
	//POST: usadas son 0 y capacidad num_casillas, memoria reservada


	Resultados(const int num_casillas);

	//Constructor de copia,inicializa vector copiando informacion
	//Parametros: Referencia a otro objeto Resultados
	//POST: Vector inicializado con informacion de otro

	Resultados(const Resultados & otro);

	//Constructor nuevo.
	//Parametros: referencia a string que contiene nombre de fichero
	//POST: Objeto construido a partir de informacion de fichero

	Resultados(string & nombre);

	//DESTRUCTOR

	//Destructor que acaba con la memoria reservada al acabar la ejecucion


	~Resultados();

	//METODOS GET
	//Serviran para extraer informacion de objeto Resultados

	int Usados() const;

	int Capacidad() const;

	bool EstaVacio() const;

	//FUNCIONES QUE MODIFICAN EL CONTENIDO

	//Funcion que deja un objeto Resultados vacio
	//Parametros:nada
	//POST: Vector vacio, usados a 0 y capacidad a 0

	void EliminaTodos();

	//Funcion que inserta valor en una casilla moviendo las demas a la derecha
	//Parametros: el valor a anadir, el numero de casilla
	//POST: se aniade ese valor a esa casilla moviendo las demas

	void Inserta(const Resultado & valor, const int num_casilla);

	//Funcion que reajusta vector
	//Parametros: nada
	//POST: la capacidad se reduce al numero de casillas usadas

	void Reajusta();

	//Sobrecargas de operadores


	//Copia profunda usando Operador de asignacion
	//Parametros:Referencia a otro objeto Resultados
	//POST: Se copia la informacion al implicito

	Resultados & operator = (const Resultados & otro);

	//Devuelvo valor usando operadores () y []
	//PARAMETROS: posicion de elemento Resultado
	//Devuelve: Ese elemento

	Resultado & operator() (const int num_casilla);

	Resultado & operator() (const int num_casilla) const;

	Resultado & operator[] (const int num_casilla);

	Resultado & operator[] (const int num_casilla) const;

	//Sobrecarga de == y !=
	//Parametros: Referencia a otro objeto Resultados(otro)
	//Iguales si comparten mismo numero casillas y mismo Dorsal
	//Devuelve: True si son iguales y False si no lo son

	bool operator == (const Resultados & otro) const;

	//Devuelve: False si son iguales y True si no lo son

	bool operator != (const Resultados & otro) const;

	//Sobrecargas de operadores >,>=,<,>=
 	//Parametros: Referencia a otro objeto Resultados(otro)

	//Devuelve: True si el objeto es mayor al otro y False si no

	bool operator > (const Resultados & otro) const;

	//Devuelve: True si el objeto es mayor o igual al otro y False si no

	bool operator >= (const Resultados & otro) const;

	//Devuelve: True si el objeto es menor al otro y False si no

	bool operator < (const Resultados & otro) const;

	//Devuelve: True si el objeto es menor o igual al otro y False si no

	bool operator <= (const Resultados & otro) const;

	//Sobrecarga de *
 	//Parametros: Referencia a otro objeto Resultados(otro)
 	//Devuelve: nuevo objeto Resultados que contiene todos los datos comunes

	friend Resultados operator * (const Resultados & este,const Resultados & otro);

	//Sobrecarga de &&

 	//Parametros: Referencias a dos objetos Resultados(este/otro)
 	//Devuelve: True si este contiene a otro y false si no

	friend bool operator && (const Resultados & este,const Resultados & otro);

	//Parametros: Referencias a un objeto Resultados y otro Resultado(este/otro)
	//Devuelve: True si este contiene a otro y false si no

	friend bool operator && (const Resultados & este,const Resultado & otro);

	//Parametros: Referencias a un objeto Resultado y otro Resultados(este/otro)
	//Devuelve: True si otro contiene a este y false si no

	friend bool operator && (const Resultado & este,const Resultados & otro);

	//Parametros: Referencias a un objeto Resultados 
	//y un int Numero de Dorsal(este/NumDorsal)
	//Devuelve: true si Resultados contiene al dato Resultado cuyo campo
	//Dorsal coincide con el int.

	friend bool operator && (const Resultados & este,int NumDorsal);

	//Devuelve: true si Resultados contiene al dato Resultado cuyo campo
	//Dorsal coincide con el int.

	friend bool operator && (int NumDorsal,const Resultados & otro);

	//Sobrecarga de +

	//Parametros: Referencias a dos objetos Resultados(este,otro)
	//Devuelve: Nuevo objeto Resultados con suma(sin repeticion) de todos corredores
 
	friend Resultados operator + (const Resultados & este,const Resultados & otro);

	//Parametros: Referencias a un objeto Resultados y otro Resultado(este,otro)
	//Devuelve: Nuevo objeto Resultados con el nuevo objeto Resultado sumado

	friend Resultados operator + (const Resultados & este,const Resultado & otro);

	//Parametros: Referencias a un objeto Resultado y otro Resultados(este,otro)
	//Devuelve: Nuevo objeto Resultados con el nuevo objeto Resultado sumado

	friend Resultados operator + (const Resultado & este,const Resultados & otro);

	//Sobrecarga de +=

	//Parametros: Referencia a otro objeto Resultados(otro)
	//Devuelve: Objeto implicito sumado con el derecho

	Resultados & operator += (const Resultados & otro);

	//Parametros: Referencia a otro objeto Resultado(otro)
	//Devuelve: Objeto implicito sumado con el derecho

	Resultados & operator += (const Resultado & otro);

	//Sobrecarga de -

	//Parametros: Referencias a dos objetos Resultados(este,otro)
	//Devuelve: Nuevo objeto Resultados con el nuevo objeto Resultados restado
 
	friend Resultados operator - (const Resultados & este,const Resultados & otro);

	//Parametros: Referencias a un objeto Resultados y otro Resultado(este,otro)
	//Devuelve: Nuevo objeto Resultados con el nuevo objeto Resultado sumado

	friend Resultados operator - (const Resultados & este,const Resultado & otro);

	//Parametros: Referencias a un objeto Resultado y otro Resultados(este,otro)
	//Devuelve: Nuevo objeto Resultados con el nuevo objeto Resultado sumado

	friend Resultados operator - (const Resultados & este,int NumDorsal);

	//Sobrecarga de -=

	//Parametros: Referencia a otro objeto Resultados(otro)
	//Devuelve: Objeto implicito se le resta el explicito otro

	Resultados & operator -= (const Resultados & otro);

	//Parametros: Referencia a otro objeto Resultado(otro)
	//Devuelve: Objeto implicito se le resta el explicito

	Resultados & operator -= (const Resultado & otro);

	//Parametros: Dorsal de un corredor(NumDorsal)
	//Devuelve: Objeto implicito se le resta el explicito

	Resultados & operator -= (const int NumDorsal);

	//FUNCION TO STRING
	//Funcion que serializa informacion
	//Parametros: titulo que tendrá comienzo de ToString
	//Post: Muestra informacion de forma estructurada y facil de leer

	std::string ToString(const string titulo);


	//Sobrecarga de operadores << y >> para las clases coleccion
	//Parametros: referencia a objeto istream u ostream
	//			  referencia a objeto Resultados

	friend istream & operator >> (istream & in,Resultados & unos_Resultados);

	friend ostream & operator << (ostream & out,const Resultados & unos_Resultados);

	//FUNCIONES QUE GUARDAN O EXTRAEN INFORMACION EN FICHEROS

	//Funcion metodo de escritura
	//Parametros: referencia a string que contiene el nombre de un fichero
	//POST: informacion contenida en Resultados es guardada en un fichero
	//PRE: si el fichero no fuese del tipo especificado vector queda vacio

	void EscribirResultados (const string & nombre) const;

	//Funcion metodo de lectura 
	//Parametros: referencia a string que contiene el nombre de un fichero
	//POST: informacion contenida en fichero es guardada en Resultados
	//PRE: si el fichero no fuese del tipo especificado vector queda vacio

	void LeerResultados (const string & nombre);

};

#endif