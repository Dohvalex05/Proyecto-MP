/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// FASE 2 PROYECTO MP(Modificado Fase 4)
//
// Fichero: Categorias.h
//
/***************************************************************************/
/***************************************************************************/

#ifndef CATEGORIAS
#define CATEGORIAS

#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Categoria.h"

class Categorias{

private:

	const int capacidad_inicial=20;

	int capacidad; //capacidad

	int usados; //espacio usado

	Categoria * datos; //puntero

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
	//Parametros: referencia a otro objeto Categorias
	//POST: Informacion se transfiere

	void CopiarDatos (const Categorias & otro);

	//Redimensiona un vector 
	//Parametros: nada
	//POST: Vector tiene mas capacidad

	void Redimensiona (void);

	//Funcion que aniade una casilla nueva
	//Parametros: el valor que se va a aniadir al vector
	//POST: nuevo valor aniadido al final

	void Aniade(const Categoria & valor);

	//Funcion que borra una casilla del vector diamico
	//Parametros: referencia al vector, y la casilla a eliminar
	//POST: casilla desaparece y las necesarias se mueven a la izquierda

	void Elimina(const int num_casilla);




public:

	//CONSTRUCTORES

	//Constructor sin argumentos
	//Parametros:nada
	//POST: usadas son 0 y capacidad capacidad_inicial, memoria reservada


	Categorias();

	//Constructor con argumentos
	//Parametros: numero de casillas a reservar
	//POST: usadas son 0 y capacidad num_casillas, memoria reservada


	Categorias(const int num_casillas);

	//Constructor de copia,inicializa vector copiando informacion
	//Parametros: Referencia a otro objeto Categorias
	//POST: Vector inicializado con informacion de otro

	Categorias(const Categorias & otro);

	//Constructor nuevo.
	//Parametros: referencia a string que contiene nombre de fichero
	//POST: Objeto construido a partir de informacion de fichero

	Categorias(string & nombre);

	//DESTRUCTOR

	//Destructor que acaba con la memoria reservada al acabar la ejecucion


	~Categorias();

	//METODOS GET
	//Serviran para extraer informacion de objeto Categorias

	int Usados() const;

	int Capacidad() const;

	bool EstaVacio() const;

	//FUNCIONES QUE MODIFICAN EL CONTENIDO

	//Funcion que deja un objeto Categorias vacio
	//Parametros:nada
	//POST: Vector vacio, usados a 0 y capacidad a 0

	void EliminaTodos();

	//Funcion que inserta valor en una casilla moviendo las demas a la derecha
	//Parametros: el valor a anadir, el numero de casilla
	//POST: se aniade ese valor a esa casilla moviendo las demas

	void Inserta(const Categoria & valor, const int num_casilla);

	//Funcion que reajusta vector
	//Parametros: nada
	//POST: la capacidad se reduce al numero de casillas usadas

	void Reajusta();

	//Sobrecargas de operadores


	//Copia profunda usando Operador de asignacion
	//Parametros:Referencia a otro objeto Categorias
	//POST: Se copia la informacion al implicito

	Categorias & operator = (const Categorias & otro);

	//Devuelvo valor usando operadores () y []
	//PARAMETROS: posicion de elemento Categoria
	//Devuelve: Ese elemento

	Categoria & operator() (const int num_casilla);

	Categoria & operator() (const int num_casilla) const;

	Categoria & operator[] (const int num_casilla);

	Categoria & operator[] (const int num_casilla) const;

	//Sobrecarga de == y !=
	//Parametros: Referencia a otro objeto Categorias(otro)
	//Iguales si comparten mismo numero casillas y mismo IdCategoria
	//Devuelve: True si son iguales y False si no lo son

	bool operator == (const Categorias & otro) const;

	//Devuelve: False si son iguales y True si no lo son

	bool operator != (const Categorias & otro) const;

	//Sobrecargas de operadores >,>=,<,>=
 	//Parametros: Referencia a otro objeto Categorias(otro)

	//Devuelve: True si el objeto es mayor al otro y False si no

	bool operator > (const Categorias & otro) const;

	//Devuelve: True si el objeto es mayor o igual al otro y False si no

	bool operator >= (const Categorias & otro) const;

	//Devuelve: True si el objeto es menor al otro y False si no

	bool operator < (const Categorias & otro) const;

	//Devuelve: True si el objeto es menor o igual al otro y False si no

	bool operator <= (const Categorias & otro) const;

	//Sobrecarga de *
 	//Parametros: Referencia a otro objeto Categorias(otro)
 	//Devuelve: nuevo objeto Categorias que contiene todos los datos comunes

	friend Categorias operator * (const Categorias & este,const Categorias & otro);

	//Sobrecarga de &&

 	//Parametros: Referencias a dos objetos Categorias(este/otro)
 	//Devuelve: True si este contiene a otro y false si no

	friend bool operator && (const Categorias & este,const Categorias & otro);

	//Parametros: Referencias a un objeto Categorias y otro Categoria(este/otro)
	//Devuelve: True si este contiene a otro y false si no

	friend bool operator && (const Categorias & este,const Categoria & otro);

	//Parametros: Referencias a un objeto Categoria y otro Categorias(este/otro)
	//Devuelve: True si otro contiene a este y false si no

	friend bool operator && (const Categoria & este,const Categorias & otro);

	//Parametros: Referencias a un objeto Categorias 
	//y un int Numero de Categoria(este/NumCategoria)
	//Devuelve: true si Categorias contiene al dato Categoria cuyo campo
	//Categoria coincide con el int.

	friend bool operator && (const Categorias & este,int NumCategoria);

	//Devuelve: true si Categorias contiene al dato Categoria cuyo campo
	//Categoria coincide con el int.

	friend bool operator && (int NumCategoria,const Categorias & otro);

	//Sobrecarga de +

	//Parametros: Referencias a dos objetos Categorias(este,otro)
	//Devuelve: Nuevo objeto Categorias con suma(sin repeticion) de todos corredores
 
	friend Categorias operator + (const Categorias & este,const Categorias & otro);

	//Parametros: Referencias a un objeto Categorias y otro Categoria(este,otro)
	//Devuelve: Nuevo objeto Categorias con el nuevo objeto Categoria sumado

	friend Categorias operator + (const Categorias & este,const Categoria & otro);

	//Parametros: Referencias a un objeto Categoria y otro Categorias(este,otro)
	//Devuelve: Nuevo objeto Categorias con el nuevo objeto Categoria sumado

	friend Categorias operator + (const Categoria & este,const Categorias & otro);

	//Sobrecarga de +=

	//Parametros: Referencia a otro objeto Categorias(otro)
	//Devuelve: Objeto implicito sumado con el derecho

	Categorias & operator += (const Categorias & otro);

	//Parametros: Referencia a otro objeto Categoria(otro)
	//Devuelve: Objeto implicito sumado con el derecho

	Categorias & operator += (const Categoria & otro);

	//Sobrecarga de -

	//Parametros: Referencias a dos objetos Categorias(este,otro)
	//Devuelve: Nuevo objeto Categorias con elementos comunes con otro eliminados
 
	friend Categorias operator - (const Categorias & este,const Categorias & otro);

	//Parametros: Referencias a un objeto Categorias y otro Categoria(este,otro)
	//Devuelve: Nuevo objeto Categorias con el nuevo objeto Categoria restado

	friend Categorias operator - (const Categorias & este,const Categoria & otro);

	//Parametros: Referencias a un objeto Categoria y otro Categorias(este,otro)
	//Devuelve: Nuevo objeto Categorias con el nuevo objeto Categoria restado

	friend Categorias operator - (const Categorias & este,int NumCategoria);

	//Sobrecarga de -=

	//Parametros: Referencia a otro objeto Categorias(otro)
	//Devuelve: Objeto implicito se le resta el explicito otro

	Categorias & operator -= (const Categorias & otro);

	//Parametros: Referencia a otro objeto Categoria(otro)
	//Devuelve: Objeto implicito se le resta el explicito

	Categorias & operator -= (const Categoria & otro);

	//Parametros: Categoria de un corredor(NumCategoria)
	//Devuelve: Objeto implicito se le resta el explicito

	Categorias & operator -= (const int NumCategoria);

	//FUNCION TO STRING
	//Funcion que serializa informacion
	//Parametros: titulo que tendrá comienzo de ToString
	//Post: Muestra informacion de forma estructurada y facil de leer

	std::string ToString(const string titulo);

	//Sobrecarga de operadores << y >> para las clases coleccion
	//Parametros: referencia a objeto istream u ostream
	//			  referencia a objeto Categorias

	friend istream & operator >> (istream & in,Categorias & unas_Categorias);

	friend ostream & operator << (ostream & out,const Categorias & unas_Categorias);

	//FUNCIONES QUE GUARDAN O EXTRAEN INFORMACION EN FICHEROS

	//Funcion metodo de escritura
	//Parametros: referencia a string que contiene el nombre de un fichero
	//POST: informacion contenida en Categorias es guardada en un fichero
	//PRE: si el fichero no fuese del tipo especificado vector queda vacio

	void EscribirCategorias (const string & nombre) const;

	//Funcion metodo de lectura 
	//Parametros: referencia a string que contiene el nombre de un fichero
	//POST: informacion contenida en fichero es guardada en Categorias
	//PRE: si el fichero no fuese del tipo especificado vector queda vacio

	void LeerCategorias (const string & nombre);

};

#endif