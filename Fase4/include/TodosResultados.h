/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// FASE 2 PROYECTO MP(Modificado Fase 3)
//
// Fichero: TodosResultados.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef TODOSRESULTADOS
#define TODOSRESULTADOS

#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Resultados.h"

class TodosResultados{

private:

	const int capacidad_inicial=20;

	int capacidad; //capacidad

	int usados; //espacio usado

	Resultados * datos; //puntero

	//FUNCIONES PRIVADAS

	//Reserva memoria para guardar el vector
	//Parametros: numero de casillas
	//PRE: num_casillas >= 0;

	void ReservarMemoria (const int num_casillas);

	//Elimina la memoria usada
	//Parametros:nada
	//POST: Numero de casillas usadas y capacidad son 0

	void LiberarMemoria (void);

	//Copia Datos de un lugar a otro
	//Parametros: referencia a otro objeto TodosResultados
	//POST: Informacion se transfiere

	void CopiarDatos (const TodosResultados & otro);

	//Redimensiona un vector 
	//Parametros: nada
	//POST: Vector tiene mas capacidad

	void Redimensiona (void);

	//Funcion que aniade una casilla nueva
	//Parametros: el valor que se va a aniadir al vector
	//POST: nuevo valor aniadido al final

	void Aniade(const Resultados & valor);

	//Funcion que borra una casilla del vector diamico
	//Parametros: referencia al vector, y la casilla a eliminar
	//POST: casilla desaparece y las necesarias se mueven a la izquierda

	void Elimina(const int num_casilla);


public:

	//CONSTRUCTORES

	//Constructor sin argumentos
	//Parametros:nada
	//POST: usadas son 0 y capacidad capacidad_inicial, memoria reservada

	TodosResultados();

	//Constructor con argumentos
	//Parametros: numero de casillas a reservar
	//POST: usadas son 0 y capacidad num_casillas, memoria reservada

	TodosResultados(const int num_casillas);

	//Constructor de copia,inicializa vector copiando informacion
	//Parametros: Referencia a otro objeto TodosResultados
	//POST: Vector inicializado con informacion de otro

	TodosResultados(const TodosResultados & otro);

	//DESTRUCTOR

	//Destructor que acaba con la memoria reservada al acabar la ejecucion

	~TodosResultados();

	//METODOS GET
	//Serviran para extraer informacion de objeto TodosResultados

	int Usados() const;

	int Capacidad() const;

	bool EstaVacio() const;

	//FUNCIONES QUE MODIFICAN EL CONTENIDO

	//Funcion que deja un objeto TodosResultados vacio
	//Parametros:nada
	//POST: Vector vacio, usados a 0 y capacidad a 0

	void EliminaTodos();

	//Funcion que inserta un valor en una
	// casilla moviendo las demas a la derecha
	//Parametros: el valor a anadir, el numero de casilla
	//POST: se aniade ese valor a esa casilla moviendo las demas

	void Inserta(const Resultados & valor, const int num_casilla);

	//Funcion que reajusta vector
	//Parametros: nada
	//POST: la capacidad se reduce al numero de casillas usadas

	void Reajusta();

	//copia Profunda usando operador de asignacion

	TodosResultados & operator = (const TodosResultados & otro);

	//Acceso a casilla usando operador ()[]

	Resultados & operator() (const int num_casilla);

	Resultados & operator() (const int num_casilla) const;

	Resultados & operator[] (const int num_casilla);

	Resultados & operator[] (const int num_casilla) const;

	//Unicos de TodosResultados

	Resultado & operator() (const int PosResultado,const int PosResult) const;

	Resultado & operator() (const int PosResultado,const int PosResult);

	//Sobrecarga de == y !=
	//Parametros: Referencia a otro objeto TodosResultados(otro)
	//Iguales si comparten mismo numero casillas y mismo Dorsal
	//Devuelve: True si son iguales y False si no lo son

	bool operator == (const TodosResultados & otro) const;

	//Devuelve: False si son iguales y True si no lo son

	bool operator != (const TodosResultados & otro) const;

	//Sobrecargas de operadores >,>=,<,>=
 	//Parametros: Referencia a otro objeto TodosResultados(otro)

	//Devuelve: True si el objeto es mayor al otro y False si no

	bool operator > (const TodosResultados & otro) const;

	//Devuelve: True si el objeto es mayor o igual al otro y False si no

	bool operator >= (const TodosResultados & otro) const;

	//Devuelve: True si el objeto es menor al otro y False si no

	bool operator < (const TodosResultados & otro) const;

	//Devuelve: True si el objeto es menor o igual al otro y False si no

	bool operator <= (const TodosResultados & otro) const;

	//Sobrecarga de *
 	//Parametros: Referencia a otro objeto TodosResultados(otro)
 	//Devuelve: nuevo objeto TodosResultados 
 	//que contiene todos los datos comunes

	friend TodosResultados operator * (const TodosResultados & este,\
		const TodosResultados & otro);

	//Sobrecarga de &&

 	//Parametros: Referencias a dos objetos TodosResultados(este/otro)
 	//Devuelve: True si este contiene a otro y false si no

	friend bool operator && (const TodosResultados & este,\
		const TodosResultados & otro);

	//Parametros: Referencias a un objeto TodosResultados y
	// otro Resultado(este/otro)
	//Devuelve: True si este contiene a otro y false si no

	friend bool operator && (const TodosResultados & este,\
		const Resultados & otro);

	//Parametros: Referencias a un objeto Resultados y 
	//otro TodosResultados(este/otro)
	//Devuelve: True si otro contiene a este y false si no

	friend bool operator && (const Resultados & este,\
		const TodosResultados & otro);

	//Parametros: Referencias a un objeto TodosResultados 
	//y un int Numero de Dorsal(este/NumDorsal)
	//Devuelve: true si TodosResultados contiene al dato Resultados cuyo campo
	//Dorsal coincide con el int.

	friend bool operator && (const TodosResultados & este,int NumDorsal);

	//Devuelve: true si TodosResultados contiene al dato Resultados cuyo campo
	//Dorsal coincide con el int.

	friend bool operator && (int NumDorsal,const TodosResultados & otro);

	//Sobrecarga de +

	//Parametros: Referencias a dos objetos TodosResultados(este,otro)
	//Devuelve: Nuevo objeto TodosResultados con suma(sin repeticion) 
	//de todos resultados
 
	friend TodosResultados operator + (const TodosResultados & este,\
		const TodosResultados & otro);

	//Parametros: Referencias a un objeto TodosResultados y otro 
	//Resultado(este,otro)
	//Devuelve: Nuevo objeto TodosResultados con el 
	//nuevo objeto Resultados sumado

	friend TodosResultados operator + (const TodosResultados & este,\
		const Resultados & otro);

	//Parametros: Referencias a un objeto Resultados y otro 
	//TodosResultados(este,otro)
	//Devuelve: Nuevo objeto TodosResultados con el nuevo 
	//objeto Resultados sumado

	friend TodosResultados operator + (const Resultados & este,\
		const TodosResultados & otro);

	//Sobrecarga de +=

	//Parametros: Referencia a otro objeto TodosResultados(otro)
	//Devuelve: Objeto implicito sumado con el derecho

	TodosResultados & operator += (const TodosResultados & otro);

	//Parametros: Referencia a otro objeto Resultado(otro)
	//Devuelve: Objeto implicito sumado con el derecho

	TodosResultados & operator += (const Resultados & otro);

	//Sobrecarga de -

	//Parametros: Referencias a dos objetos TodosResultados(este,otro)
	//Devuelve: Nuevo objeto TodosResultados con elementos comunes 
	//a otro eliminados
 
	friend TodosResultados operator - (const TodosResultados & este,\
		const TodosResultados & otro);

	//Parametros: Referencias a un objeto TodosResultados 
	//y otro Resultado(este,otro)
	//Devuelve: Nuevo objeto TodosResultados con el 
	//nuevo objeto Resultados restado

	friend TodosResultados operator - (const TodosResultados & este,\
		const Resultados & otro);

	//Parametros: Referencias a un objeto Resultados y otro
	//TodosResultados(este,otro)
	//Devuelve: Nuevo objeto TodosResultados con el nuevo
	//objeto Resultados restado

	friend TodosResultados operator - (const TodosResultados & este,\
		int NumDorsal);

	//Sobrecarga de -=

	//Parametros: Referencia a otro objeto TodosResultados(otro)
	//Devuelve: Objeto implicito se le resta el explicito otro

	TodosResultados & operator -= (const TodosResultados & otro);

	//Parametros: Referencia a otro objeto Resultado(otro)
	//Devuelve: Objeto implicito se le resta el explicito

	TodosResultados & operator -= (const Resultados & otro);

	//Parametros: Dorsal de un corredor(NumDorsal)
	//Devuelve: Objeto implicito se le resta el explicito

	TodosResultados & operator -= (const int NumDorsal);

	//FUNCION TO STRING
	//Funcion que serializa informacion
	//Parametros: titulo que tendrá comienzo de ToString
	//Post: Muestra informacion de forma estructurada y facil de leer


	//Serializa la informacion

	std::string ToString(const string titulo);

	//Sobrecarga de operadores << y >> para las clases coleccion
	//Parametros: referencia a objeto istream u ostream
	//			  referencia a objeto TodosResultados

	friend istream & operator >> (istream & in,TodosResultados
	 							  & unos_TodosResultados);


	friend ostream & operator << (ostream & out,const TodosResultados
									 & unos_TodosResultados);


};

#endif
