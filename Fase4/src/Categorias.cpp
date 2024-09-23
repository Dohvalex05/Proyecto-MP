/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// FASE 2 Proyecto MP(Modificado Fase 4)
//
// Fichero: Categorias.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include "Categorias.h"



using namespace std;


/***************************************************************************/
/***************************************************************************/

//CONSTRUCTORES

//Constructor sin argumentos
//Parametros:nada
//POST: usadas son 0 y capacidad capacidad_inicial, memoria reservada

Categorias::Categorias(){

	usados=0;

	ReservarMemoria(capacidad_inicial);

}

//Constructor con argumentos
//Parametros: numero de casillas a reservar
//POST: usadas son 0 y capacidad num_casillas, memoria reservada

Categorias::Categorias(const int num_casillas){

	usados=0;

	ReservarMemoria(num_casillas);

}

//Constructor de copia,inicializa vector copiando informacion
//Parametros: Referencia a otro objeto Categorias
//POST: Vector inicializado con informacion de otro

Categorias::Categorias(const Categorias & otro){

	ReservarMemoria(otro.capacidad);
	
	usados = otro.usados;
	
	CopiarDatos(otro);
}

//Constructor nuevo.
//Parametros: referencia a string que contiene nombre de fichero
//POST: Objeto construido a partir de informacion de fichero

Categorias::Categorias(string & nombre){

	ReservarMemoria(capacidad_inicial);

	LeerCategorias(nombre);

}



/***************************************************************************/
/***************************************************************************/

//DESTRUCTOR

//Destructor que acaba con la memoria reservada al acabar la ejecucion

Categorias::~Categorias(){
	LiberarMemoria();
}


/***************************************************************************/
/***************************************************************************/

//METODOS GET
//Serviran para extraer informacion de objeto Categorias

int Categorias::Usados() const{

	return usados;

}

int Categorias::Capacidad() const{

	return capacidad;

}

bool Categorias::EstaVacio() const{

	bool vacio=false;

	if (usados == 0){
		vacio = true;
	}

	return vacio;


}

/***************************************************************************/
/***************************************************************************/

//FUNCIONES QUE MODIFICAN EL CONTENIDO

//Funcion que deja un objeto Categorias vacio
//Parametros:nada
//POST: Vector vacio, usados a 0 y capacidad a 0

void Categorias::EliminaTodos(){

	LiberarMemoria();

}

//Funcion que inserta un valor en una casilla moviendo las demas a la derecha
//Parametros: el valor a anadir, el numero de casilla
//POST: se aniade ese valor a esa casilla moviendo las demas

void Categorias::Inserta(const Categoria & valor, const int num_casilla) {

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


void Categorias::Reajusta(){

	//Copio informacion en temporal y al original le cambio capacidad

	Categorias temporal(*this);

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
//Parametros:Referencia a otro objeto Categorias
//POST: Se copia la informacion al implicito

Categorias & Categorias :: operator = (const Categorias & otro){

	LiberarMemoria();

	ReservarMemoria(otro.capacidad);

	usados=otro.usados;

	CopiarDatos(otro);

	return (*this);
}

//Devuelvo valor usando operadores () y []
//PARAMETROS: posicion de elemento Categoria
//Devuelve: Ese elemento

Categoria & Categorias::operator() (const int num_casilla){

	return(datos[num_casilla-1]);


}

Categoria & Categorias::operator() (const int num_casilla) const{

	return(datos[num_casilla-1]);


}
Categoria & Categorias::operator[] (const int num_casilla){

	return(datos[num_casilla-1]);



}

Categoria & Categorias::operator[] (const int num_casilla) const{

	return(datos[num_casilla-1]);


}

/***************************************************************************/
/***************************************************************************/

//Sobrecarga de == y !=
//Parametros: Referencia a otro objeto Categorias(otro)
//Iguales si comparten mismo numero casillas y mismo IdCategoria

//Devuelve: True si son iguales y False si no lo son

bool Categorias::operator == (const Categorias & otro) const{


 	bool iguales=true;

 	//me indica si sigo con el testeo

 	bool sigo=true;

 	if (usados != otro.usados) {
        iguales=false;  
    }

    //Si la primera comprobacion sale cierta el codigo no sigue

    if(iguales){

    	for(int i=0;i<usados && sigo;i++){
    		if (stoi(datos[i].GetIdCategoria()) != 
    			stoi(otro.datos[i].GetIdCategoria())){
    			iguales = false;
    			sigo = false;
    		}
    	}
    }

    return (iguales);

 }

 //Devuelve: False si son iguales y True si no lo son

 bool Categorias::operator != (const Categorias & otro) const{

 	return(!(*this == otro));
 	
 }

 //Sobrecargas de operadores >,>=,<,>=
 //Parametros: Referencia a otro objeto Categorias(otro)

 //Devuelve: True si el objeto es mayor al otro y False si no

 bool Categorias::operator > (const Categorias & otro) const{

 	bool mayor= true;

 	if (usados <= otro.usados){
 		mayor = false;
 	}

 	return mayor;
 }

 //Devuelve: True si el objeto es mayor o igual al otro y False si no

 bool Categorias::operator >= (const Categorias & otro) const{


 	bool mayorigual=true;

 	if (!(*this > otro) || !(*this == otro)){
 		mayorigual=false;
 	}

 	return mayorigual;
 }

 //Devuelve: True si el objeto es menor al otro y False si no

 bool Categorias::operator < (const Categorias & otro) const{

 	return(!(*this >= otro));

 }


 //Devuelve: True si el objeto es menor o igual al otro y False si no

 bool Categorias::operator <= (const Categorias & otro) const{

 	return(!(*this > otro));
 }

 //Sobrecarga de *
 //Parametros: Referencia a otro objeto Categorias(otro)
 //Devuelve: nuevo objeto Categorias que contiene todos los datos comunes

Categorias operator * (const Categorias & este,const Categorias & otro){

	Categorias nuevo;

	//Si coinciden elementos se aniade al nuevo objeto

	for(int i=0;i<este.usados;i++){
		for(int j=0;j<otro.usados;j++){
			if (stoi(este.datos[i].GetIdCategoria()) == 
				stoi(otro.datos[j].GetIdCategoria()))
			{
				nuevo.Aniade(este.datos[i]);
			}
		}
	}

	return nuevo;

}

 //Sobrecarga de &&

 //Parametros: Referencias a dos objetos Categorias(este/otro)
 //Devuelve: True si este contiene a otro y false si no

bool operator && (const Categorias & este,const Categorias & otro){

	bool contiene=false;

	//Si el numero de elementos de otro coincide con el numero de elementos
	//de la interseccion significa que lo contiene

	if (este.Usados() >= otro.Usados()){

		if(otro.Usados() == (este * otro).Usados()){

			contiene=true;
		}

	}

	return contiene;

}

//Parametros: Referencias a un objeto Categorias y otro Categoria(este/otro)
//Devuelve: True si este contiene a otro y false si no

bool operator && (const Categorias & este,const Categoria & otro){

	bool contiene=false;

	Categorias Hotro;

	Hotro.Aniade(otro);

	if(este && Hotro){
		contiene=true;
	}

	return contiene;

}

//Parametros: Referencias a un objeto Categoria y otro Categorias(este/otro)
//Devuelve: True si otro contiene a este y false si no

bool operator && (const Categoria & este,const Categorias & otro){

	return(otro && este);

}

//Parametros: Referencias a un objeto Categorias 
//y un int Numero de IdCategoria(este/NumIdCategoria)
//Devuelve: true si Categorias contiene al dato Categoria cuyo campo
//IdCategoria coincide con el int.

bool operator && (const Categorias & este,int NumIdCategoria){

	bool contiene=false;

	//Repasa hasta encontrar el elemento deseado

	for(int i=0;i<este.Usados() && !contiene;i++){
		if (stoi(este.datos[i].GetIdCategoria()) == NumIdCategoria){
			contiene = true;
		}
	}

	return contiene;

}

//Devuelve: true si Categorias contiene al dato Categoria cuyo campo
//IdCategoria coincide con el int.

bool operator && (int NumIdCategoria,const Categorias & otro){

	return(otro && NumIdCategoria);

}

//Sobrecarga de +

//Parametros: Referencias a dos objetos Categorias(este,otro)
//Devuelve: Nuevo objeto Categorias con suma(sin repeticion) 
//de los dos objetos categorias
 
Categorias operator + (const Categorias & este,const Categorias & otro){

	Categorias nuevo(este);

	//Si no lo contiene se aniade para evitar duplicados

	for(int i=0;i<otro.Usados();i++){

		if(!(este && otro.datos[i])){

			nuevo.Aniade(otro.datos[i]);

		}

	}

	return nuevo;

}

//Parametros: Referencias a un objeto Categorias y otro Categoria(este,otro)
//Devuelve: Nuevo objeto Categorias con el nuevo objeto Categoria sumado

Categorias operator + (const Categorias & este,const Categoria & otro){

	Categorias nuevo;

	nuevo.Aniade(otro);

	return(este + nuevo);

}

//Parametros: Referencias a un objeto Categoria y otro Categorias(este,otro)
//Devuelve: Nuevo objeto Categorias con el nuevo objeto Categoria sumado

Categorias operator + (const Categoria & este,const Categorias & otro){

	return(otro + este);

}


//Sobrecarga de +=

//Parametros: Referencia a otro objeto Categorias(otro)
//Devuelve: Objeto implicito sumado con el derecho

Categorias & Categorias::operator += (const Categorias & otro){

	*this = *this + otro;

	return (*this);

}

//Parametros: Referencia a otro objeto Categoria(otro)
//Devuelve: Objeto implicito sumado con el derecho

Categorias & Categorias::operator += (const Categoria & otro){

	*this = *this + otro;

	return (*this);

}

//Sobrecarga de -

//Parametros: Referencias a dos objetos Categorias(este,otro)
//Devuelve: Nuevo objeto Categorias con elementos comunes con otro eliminados
 
Categorias operator - (const Categorias & este,const Categorias & otro){

	Categorias nuevo(este);

	//Si lo contiene fuera

	for(int i=0;i<otro.Usados();i++){

		if(este && otro.datos[i]){

			nuevo.Elimina(i);

		}

	}

	return nuevo;

}

//Parametros: Referencias a un objeto Categorias y otro Categoria(este,otro)
//Devuelve: Nuevo objeto Categorias con el nuevo objeto Categoria restado

Categorias operator - ( const Categorias & este,const Categoria & otro){

	Categorias nuevo;

	nuevo.Aniade(otro);

	return(este - nuevo);

}

//Parametros: Referencias a un objeto Categoria y otro Categorias(este,otro)
//Devuelve: Nuevo objeto Categorias con el nuevo objeto Categoria restado

Categorias operator - (const Categorias & este,int NumIdCategoria){

	bool sigue=true;

	Categorias nuevo(este);

	//Si lo contiene fuera

	for(int i=0;i<este.Usados() && sigue;i++){
		if (stoi(nuevo.datos[i].GetIdCategoria()) == NumIdCategoria){
			nuevo.Elimina(i);
			sigue=false;
		}
	}
	
	return nuevo;

}

//Sobrecarga de -=

//Parametros: Referencia a otro objeto Categorias(otro)
//Devuelve: Objeto implicito se le resta el explicito

Categorias & Categorias::operator -= (const Categorias & otro){

	*this = *this - otro;

	return (*this);

}

//Parametros: Referencia a otro objeto Categoria(otro)
//Devuelve: Objeto implicito se le resta el explicito

Categorias & Categorias::operator -= (const Categoria & otro){

	*this = *this - otro;

	return (*this);

}

//Parametros: IdCategoria de una categoria(NumIdCategoria)
//Devuelve: Objeto implicito se le resta el explicito

Categorias & Categorias::operator -= (const int NumIdCategoria){

	*this = *this - NumIdCategoria;

	return (*this);

}

/***************************************************************************/
/***************************************************************************/

//FUNCION TO STRING
//Funcion que serializa informacion
//Parametros: titulo que tendrá comienzo de ToString
//Post: Muestra informacion de forma estructurada y facil de leer

string Categorias::ToString(const string titulo){

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
//			  referencia a objeto Categorias


istream & operator >> (istream & in,Categorias & unas_Categorias){

	unas_Categorias.LiberarMemoria();

	unas_Categorias.ReservarMemoria (unas_Categorias.capacidad_inicial);

	//Empiezo lectura

	string linea;

	getline(in,linea);

	while (!in.eof()) {
					
		Categoria una_Categoria (linea,'*');

		// Añadir el dato "Categoria" leido a la colección 
		unas_Categorias += una_Categoria; // Operator += 

		// Leer la siguiente linea 
		getline(in, linea); 
			
	}

	return in;

}

ostream & operator << (ostream & out,const Categorias & unas_Categorias){

	ostringstream oss;

	for(int i=1;i<=unas_Categorias.Usados();i++){

		oss << unas_Categorias[i] << endl;
	}

	string final=oss.str();

	out << final;

	return out;

}

//FUNCIONES QUE GUARDAN O EXTRAEN INFORMACION EN FICHEROS

//Funcion metodo de escritura
//Parametros: referencia a string que contiene el nombre de un fichero
//POST: informacion contenida en Categorias es guardada en un fichero
//PRE: si el fichero no fuese del tipo especificado vector queda vacio

void Categorias::EscribirCategorias (const string & nombre) const{

	if (usados != 0){

		ofstream fo(nombre);

		fo << "CATEGORIAS" << endl;

		fo << *this;

		fo.close();

	}


}

//Funcion metodo de lectura 
//Parametros: referencia a string que contiene el nombre de un fichero
//POST: informacion contenida en fichero es guardada en Categorias
//PRE: si el fichero no fuese del tipo especificado vector queda vacio

void Categorias::LeerCategorias (const string & nombre){

	ifstream fi(nombre);

	//Me salto la primera parte que contiene informacion no guardable

	string linea;

	getline(fi, linea);

	if(linea == "CATEGORIAS"){

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

void Categorias::ReservarMemoria (const int num_casillas){

	if(num_casillas < 0){

		capacidad = 1;

	}

	else{

	capacidad = num_casillas;

	}

	datos = new Categoria[capacidad];
}

//Elimina la memoria usada
//Parametros:nada
//POST: Numero de casillas usadas y capacidad son 0

void Categorias:: LiberarMemoria(){

	if (datos != nullptr && datos != 0){

		delete [] datos;

		usados=0;

		capacidad=0;

	}

}

//Copia Datos de un lugar a otro
//Parametros: referencia a otro objeto Categorias
//POST: Informacion se transfiere

void Categorias::CopiarDatos(const Categorias & otro){

	for(int i=0;i<otro.usados;i++){

		datos[i] = otro.datos[i];

	}

}


//Redimensiona un vector 
//Parametros: nada
//POST: Vector tiene mas capacidad


void Categorias::Redimensiona (void){

	//Objeto temporal copia
	
	Categorias copia(*this);
	
	LiberarMemoria();
	ReservarMemoria(copia.capacidad + capacidad_inicial);
	
	CopiarDatos(copia);

	usados=copia.usados;
}


//Funcion que borra una casilla del vector diamico
//Parametros: referencia al vector, y la casilla a eliminar
//POST: casilla desaparece y las necesarias se mueven a la izquierda

void Categorias::Elimina(const int num_casilla) {

	//todo desde num_casilla se mueve a la derecha

	for(int i=num_casilla-1;i<usados;i++){
	
		datos[i]= datos[i+1];
		
	}
    
    usados--;
}

//Funcion que aniade una casilla nueva
//Parametros: el valor que se va a aniadir al vector
//POST: nuevo valor aniadido al final

void Categorias::Aniade(const Categoria & nuevo){
	

	//Si lo requiere se redimensiona

	if(usados >= capacidad){
		Redimensiona(); 
	}

	//Se aniade valor

	datos[usados] = nuevo;
	usados++;
}
