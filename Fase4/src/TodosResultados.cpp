/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// FASE 2 Proyecto MP(Modificado Fase 4)
//
// Fichero: TodosResultados.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include "TodosResultados.h"
#include "Resultados.h"



using namespace std;


/***************************************************************************/
/***************************************************************************/

//CONSTRUCTORES

//Constructor sin argumentos
//Parametros:nada
//POST: usadas son 0 y capacidad capacidad_inicial, memoria reservada

TodosResultados::TodosResultados(){

	usados=0;

	ReservarMemoria(capacidad_inicial);

}

//Constructor con argumentos
//Parametros: numero de casillas a reservar
//POST: usadas son 0 y capacidad num_casillas, memoria reservada

TodosResultados::TodosResultados(const int num_casillas){

	usados=0;

	ReservarMemoria(num_casillas);

}

//Constructor de copia,inicializa vector copiando informacion
//Parametros: Referencia a otro objeto TodosResultados
//POST: Vector inicializado con informacion de otro

TodosResultados::TodosResultados(const TodosResultados & otro){

	ReservarMemoria(otro.capacidad);
	
	usados = otro.usados;
	
	CopiarDatos(otro);
}

/***************************************************************************/
/***************************************************************************/

//DESTRUCTOR

//Destructor que acaba con la memoria reservada al acabar la ejecucion

TodosResultados::~TodosResultados(){
	LiberarMemoria();
}


/***************************************************************************/
/***************************************************************************/

//METODOS GET
//Serviran para extraer informacion de objeto TodosResultados

int TodosResultados::Usados() const{

	return usados;

}

int TodosResultados::Capacidad() const{

	return capacidad;

}

bool TodosResultados::EstaVacio() const{

	bool vacio=false;

	if (usados == 0){
		vacio = true;
	}

	return vacio;


}

/***************************************************************************/
/***************************************************************************/

//FUNCIONES QUE MODIFICAN EL CONTENIDO

//Funcion que deja un objeto TodosResultados vacio
//Parametros:nada
//POST: Vector vacio, usados a 0 y capacidad a 0

void TodosResultados::EliminaTodos(){

	LiberarMemoria();

}


//Funcion que inserta un valor en una casilla moviendo las demas a la derecha
//Parametros: el valor a anadir, el numero de casilla
//POST: se aniade ese valor a esa casilla moviendo las demas

void TodosResultados::Inserta(const Resultados & valor, const int num_casilla)
{

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


void TodosResultados::Reajusta(){

	//Copio informacion en temporal y al original le cambio capacidad

	TodosResultados temporal(*this);

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
//Copia profunda usando Operador de asignacion

TodosResultados & TodosResultados :: operator = (const TodosResultados & otro)
{

	LiberarMemoria();

	ReservarMemoria(otro.capacidad);

	usados=otro.usados;

	CopiarDatos(otro);

	return (*this);
}

//Devuelvo valor usando operadores () y []

Resultados & TodosResultados::operator() (const int num_casilla){

	return(datos[num_casilla-1]);


}

Resultados & TodosResultados::operator() (const int num_casilla) const{

	return(datos[num_casilla-1]);


}
Resultados & TodosResultados::operator[] (const int num_casilla){

	return(datos[num_casilla-1]);



}

Resultados & TodosResultados::operator[] (const int num_casilla) const{

	return(datos[num_casilla-1]);


}

//Unicos de TodosResultados

Resultado & TodosResultados::operator() (const int PosResultado, \
										  const int PosResult) const{

	return(datos[PosResultado-1][PosResult]);

}

Resultado & TodosResultados::operator() (const int PosResultado,\
										  const int PosResult){

	return(datos[PosResultado-1][PosResult]);

}


/***************************************************************************/
/***************************************************************************/

//Sobrecarga de == y !=
//Parametros: Referencia a otro objeto TodosResultados(otro)
//Iguales si comparten mismo numero casillas y mismo Dorsal

//Devuelve: True si son iguales y False si no lo son

bool TodosResultados::operator == (const TodosResultados & otro) const{


 	bool iguales=true;

 	//me indica si sigo con el testeo

 	bool sigo=true;

 	if (usados != otro.usados) {
        iguales=false;  
    }

    //Si la primera comprobacion sale cierta el codigo no sigue

    if(iguales){

    	for(int i=0;i<usados && sigo;i++){
    		if (datos[i] != otro.datos[i]){
    			iguales = false;
    			sigo = false;
    		}
		}
	
    }

    return (iguales);

 }

 //Devuelve: False si son iguales y True si no lo son

 bool TodosResultados::operator != (const TodosResultados & otro) const{

 	return(!(*this == otro));
 	
 }

 //Sobrecargas de operadores >,>=,<,>=
 //Parametros: Referencia a otro objeto TodosResultados(otro)

 //Devuelve: True si el objeto es mayor al otro y False si no

 bool TodosResultados::operator > (const TodosResultados & otro) const{

 	bool mayor= true;

 	if (usados <= otro.usados){
 		mayor = false;
 	}

 	return mayor;
 }

 //Devuelve: True si el objeto es mayor o igual al otro y False si no

 bool TodosResultados::operator >= (const TodosResultados & otro) const{


 	bool mayorigual=true;

 	if (!(*this > otro) || !(*this == otro)){
 		mayorigual=false;
 	}

 	return mayorigual;
 }

 //Devuelve: True si el objeto es menor al otro y False si no

 bool TodosResultados::operator < (const TodosResultados & otro) const{

 	return(!(*this >= otro));

 }


 //Devuelve: True si el objeto es menor o igual al otro y False si no

 bool TodosResultados::operator <= (const TodosResultados & otro) const{

 	return(!(*this > otro));
 }

 //Sobrecarga de *
 //Parametros: Referencia a otro objeto TodosResultados(otro)
 //Devuelve: nuevo objeto TodosResultados que contiene todos los datos comunes

TodosResultados operator * (const TodosResultados & este, \
	const TodosResultados & otro){

	TodosResultados nuevo;

	//Repaso que i valor de este coincida con j valor de otro
	//si coinciden se aniade

	for(int i=0;i<este.usados;i++){
		for(int j=0;j<otro.usados;j++){
			if (este.datos[i] == otro.datos[j]){
				nuevo.Aniade(este.datos[i]);
			}
		}
	}
	
	

	return nuevo;

}

 //Sobrecarga de &&

 //Parametros: Referencias a dos objetos TodosResultados(este/otro)
 //Devuelve: True si este contiene a otro y false si no

bool operator && (const TodosResultados & este,const TodosResultados & otro){

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

//Parametros: Referencias a un objeto TodosResultados y 
//otro Resultados(este/otro)
//Devuelve: True si este contiene a otro y false si no

bool operator && (const TodosResultados & este,const Resultados & otro){

	bool contiene=false;

	TodosResultados Hotro;

	Hotro.Aniade(otro);

	if(este && Hotro){
		contiene=true;
	}

	return contiene;

}

//Parametros: Referencias a un objeto Resultados y otro 
//TodosResultados(este/otro)
//Devuelve: True si otro contiene a este y false si no

bool operator && (const Resultados & este,const TodosResultados & otro){

	return(otro && este);

}

//Parametros: Referencias a un objeto TodosResultados 
//y un int Numero de Dorsal(este/NumDorsal)
//Devuelve: true si TodosResultados contiene al dato Resultados cuyo campo
//Dorsal coincide con el int.

bool operator && (const TodosResultados & este,int NumDorsal){

	bool contiene=false;

	//Repasa todos los datos hasta encontrar al indicado

	for(int i=0;i<este.usados && !contiene;i++){
		for(int j=0;j<este.datos[i].Usados();j++){
			if (stoi(este.datos[i][j+1].GetDorsal()) == NumDorsal){
				contiene = true;
			}
		}
	}

	return contiene;

}

//Devuelve: true si TodosResultados contiene al dato Resultados cuyo campo
//Dorsal coincide con el int.

bool operator && (int NumDorsal,const TodosResultados & otro){

	return(otro && NumDorsal);

}

//Sobrecarga de +

//Parametros: Referencias a dos objetos TodosResultados(este,otro)
//Devuelve: Nuevo objeto TodosResultados con suma(sin repeticion)
//de todos resultados
 
TodosResultados operator + (const TodosResultados & este \
	,const TodosResultados & otro){

	TodosResultados nuevo(este);

	//Si este no contiene, entonces se aniade, se evita duplicados

	for(int i=0;i<otro.Usados();i++){

		if(!(este && otro.datos[i])){

			nuevo.Aniade(otro.datos[i]);
		}

	}

	

	return nuevo;

}

//Parametros: Referencias a un objeto TodosResultados y 
//otro Resultados(este,otro)
//Devuelve: Nuevo objeto TodosResultados con el nuevo objeto Resultados sumado

TodosResultados operator + (const TodosResultados & este, \
	const Resultados & otro){

	TodosResultados nuevo;

	nuevo.Aniade(otro);

	return(este + nuevo);

}

//Parametros: Referencias a un objeto Resultados y 
//otro TodosResultados(este,otro)
//Devuelve: Nuevo objeto TodosResultados con el nuevo objeto Resultados sumado

TodosResultados operator + (const Resultados & este, \
	const TodosResultados & otro){

	return(otro + este);

}


//Sobrecarga de +=

//Parametros: Referencia a otro objeto TodosResultados(otro)
//Devuelve: Objeto implicito sumado con el derecho

TodosResultados & TodosResultados::operator += (const TodosResultados & otro){

	*this = *this + otro;

	return (*this);

}

//Parametros: Referencia a otro objeto Resultado(otro)
//Devuelve: Objeto implicito sumado con el derecho

TodosResultados & TodosResultados::operator += (const Resultados & otro){

	*this = *this + otro;

	return (*this);

}

//Sobrecarga de -

//Parametros: Referencias a dos objetos TodosResultados(este,otro)
//Devuelve: Nuevo objeto TodosResultados con el 
//nuevo objeto TodosResultados restado
 
TodosResultados operator - (const TodosResultados & este, \
	const TodosResultados & otro){

	TodosResultados nuevo(este);

	//si lo contiene se elimina

	for(int i=0;i<otro.Usados();i++){

		if(este && otro.datos[i]){

			nuevo.Elimina(i);

		}

	}

	return nuevo;

}

//Parametros: Referencias a un objeto TodosResultados
// y otro Resultado(este,otro)
//Devuelve: Nuevo objeto TodosResultados
// con el nuevo objeto Resultados restado

TodosResultados operator - ( const TodosResultados & este, \
	const Resultados & otro){

	TodosResultados nuevo;

	nuevo.Aniade(otro);

	return(este - nuevo);

}

//Parametros: Referencias a un objeto Resultados y 
//otro TodosResultados(este,otro)
//Devuelve: Nuevo objeto TodosResultados con el 
//nuevo objeto Resultados restado

TodosResultados operator - (const TodosResultados & este,int NumDorsal){

	bool sigue=true;

	TodosResultados nuevo(este);

	//Si lo contiene fuera

	for(int i=0;i<este.Usados() && sigue;i++){
		for(int j=0; j<este.datos[i].Usados();j++){
			if (stoi(nuevo.datos[i][j+1].GetDorsal()) == NumDorsal){
				nuevo.datos[i] -= NumDorsal;
				sigue=false;
			}
		}
	}
	
	return nuevo;

}

//Sobrecarga de -=

//Parametros: Referencia a otro objeto TodosResultados(otro)
//Devuelve: Objeto implicito se le resta el explicito

TodosResultados & TodosResultados::operator -= (const TodosResultados & otro){

	*this = *this - otro;

	return (*this);

}

//Parametros: Referencia a otro objeto Resultado(otro)
//Devuelve: Objeto implicito se le resta el explicito

TodosResultados & TodosResultados::operator -= (const Resultados & otro){

	*this = *this - otro;

	return (*this);

}

//Parametros: Dorsal de un corredor(NumDorsal)
//Devuelve: Objeto implicito se le resta el explicito

TodosResultados & TodosResultados::operator -= (const int NumDorsal){

	*this = *this - NumDorsal;

	return (*this);

}



/***************************************************************************/
/***************************************************************************/

//FUNCION TO STRING
//Funcion que serializa informacion
//Parametros: titulo que tendrá comienzo de ToString
//Post: Muestra informacion de forma estructurada y facil de leer

string TodosResultados::ToString(const string titulo){

	string cad="";

	cad= cad + titulo + '\n';

	for(int i=0;i<usados;i++){

		string carrera="CARRERA " + to_string(i+1);

		cad = cad + FormatString(carrera,20,TipoAlineacion::Centro,'=') + '\n';

		cad= cad + datos[i].ToString("") + '\n';
	}

	return cad;


}

/***************************************************************************/
/***************************************************************************/

//Sobrecarga de operadores << y >> para las clases coleccion
//Parametros: referencia a objeto istream u ostream
//			  referencia a objeto TodosResultados


istream & operator >> (istream & in,TodosResultados & unos_TodosResultados){

	unos_TodosResultados.LiberarMemoria();

	unos_TodosResultados.ReservarMemoria(unos_TodosResultados.capacidad_inicial);

	Resultados unos_Resultados;

	in >> unos_Resultados;

	// Añadir el dato "Resultado" leido a la colección 
	// Operator += 

	unos_TodosResultados += unos_Resultados;

	return in;

}

ostream & operator << (ostream & out,const TodosResultados & unos_TodosResultados){

	ostringstream oss;

	for(int i=1;i<=unos_TodosResultados.Usados();i++){

		oss << unos_TodosResultados[i] << endl;

		cout << endl;
	}

	string final=oss.str();

	out << final;

	return out;

}

/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
/***************************************************************************/
//FUNCIONES PRIVADAS

//Parametros memoria para guardar el vector
//Parametros: numero de casillas
//PRE: num_casillas >= 0;

void TodosResultados::ReservarMemoria (const int num_casillas){

	capacidad = num_casillas;
	datos = new Resultados[capacidad];
}

//Elimina la memoria usada
//Parametros:nada
//POST: Numero de casillas usadas y capacidad son 0

void TodosResultados:: LiberarMemoria(){

	if (datos != nullptr && datos != 0){

		delete [] datos;

		usados=0;

		capacidad=0;

	}

}

//Copia Datos de un lugar a otro
//Parametros: referencia a otro objeto TodosResultados
//POST: Informacion se transfiere

void TodosResultados::CopiarDatos(const TodosResultados & otro){

	for(int i=0;i<otro.usados;i++){

		datos[i] = otro.datos[i];

	}

}


//Redimensiona un vector 
//Parametros: nada
//POST: Vector tiene mas capacidad


void TodosResultados::Redimensiona (void){
	
	TodosResultados copia(*this);
	
	LiberarMemoria();
	ReservarMemoria(copia.capacidad + capacidad_inicial);
	
	CopiarDatos(copia);

	usados=copia.usados;
}

//Funcion que aniade una casilla nueva
//Parametros: el valor que se va a aniadir al vector
//POST: nuevo valor aniadido al final

void TodosResultados::Aniade(const Resultados & nuevo){
	

	//Si lo requiere se redimensiona

	if(usados >= capacidad){
		Redimensiona(); 
	}

	//Se aniade valor

	datos[usados] = nuevo;
	usados++;
}

//Funcion que borra una casilla del vector diamico
//Parametros: referencia al vector, y la casilla a eliminar
//POST: casilla desaparece y las necesarias se mueven a la izquierda

void TodosResultados::Elimina(const int num_casilla) {

	//todo desde num_casilla se mueve a la derecha

	for(int i=num_casilla-1;i<usados;i++){
	
		datos[i]= datos[i+1];
		
	}
    
    usados--;
}
