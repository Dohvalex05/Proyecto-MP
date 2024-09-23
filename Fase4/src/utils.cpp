/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// PROYECTO FASE 1
//
// Fichero: utils.cpp
//
/***************************************************************************/
/***************************************************************************/

#include "utils.h"

using namespace std;


//para pasar de int a string con decoracion
//pide: numero a meter, numero de casillas a rellenar, relleno
//devuelve: el string con estilo

string FormatInt(int numero, int num_casillas, char relleno){

	//paso la informacion del int a modo string

	string numfinal=to_string(numero);

	//hago un puntero al comienzo del string para operar sorbe el

	const char * puntero= &numfinal[0];

	//el largo de este string lo saco mediante el puntero

	int largonumero=strlen(puntero);

	//mientras que haya mas casillas que numero, se reinicia string

	if (num_casillas > largonumero ){

		numfinal="";

		//aniado los espacios y luego el numero

		for(int i=0;i<num_casillas-largonumero;i++){
			numfinal=numfinal + relleno;
		}

		numfinal=numfinal + to_string(numero);
		}

	return numfinal;
	
}

//lo mismo con double
//pide: lo mismo pero ademas se aniade numero de decimales
//devuelve: string con informacion pero bien puesta

string FormatDouble(double numero,int num_casillas,int num_dec,char relleno){

    int parte_entera = static_cast<int>(numero);

    //para la parte decimal primero elimino la parte entera restandosela
    //cuando quedan solo decimales, los multiplico por 10 elevado a el num_dec,
    //de esta forma a la izquierda del punto quedan los decimales que interesan
    //Saco la parte entera de este nuevo numero lo cual es la parte decimal

    int parte_decimal =static_cast<int>(abs((numero-parte_entera)*\
    	pow(10,num_dec)));

    //lo transformo en string y formo el numero como tal

    string parteentera = to_string(parte_entera);
    string partedecimal = to_string(parte_decimal);

    //Le aniado ceros si estos al pasarlo al string desaparecen

    while (strlen(&partedecimal[0]) < num_dec) {
        partedecimal = "0" + partedecimal;
    }

    string numfinal = parteentera + '.' + partedecimal;

    //creo un puntero para realizar operaciones con cstring

    char * puntero=&numfinal[0];

    //si hay mas casillas que elementos en el numero se rellena

    if (num_casillas > strlen(puntero)) {

    	//reinicio numfinal para poner los espacios
    	//es necesario un numfinal con elementos anterior para saber largo

    	numfinal="";

    	for(int i=0;i<num_casillas-strlen(puntero);i++){
    		numfinal=numfinal + relleno;
    	}

    	numfinal=numfinal + to_string(numero);
        
    }

    //caso en el que no hay decimales

    char * puntentero=&parteentera[0];
    if (num_dec == 0){

    	//reinicio numfinal para atenerse al caso
    	
    	numfinal="";

    	for(int i=0;i<num_casillas-strlen(puntentero);i++){
    		numfinal=numfinal + relleno;
    	}

    	numfinal=numfinal + parteentera;
    }
    char * puntdecimal=&partedecimal[0];

    //caso si se piden mas casillas decimales que decimales hay

    if(num_dec > strlen(&partedecimal[0])){

    	numfinal="";

    	numfinal=numfinal + parteentera + '.' + partedecimal;

    	for(int i=0;i<num_casillas-strlen(&numfinal[0]);i++){
    		numfinal=numfinal + '0';
    	}

	}

    return numfinal;
}

//Funcion para dar un estilo a un string
//pide: el string, numero de casillas, la alineacion(IZQ,DER,CENTRO),y relleno
//devuelve: el string con estilo

string FormatString (string la_cadena, int num_casillas,\
TipoAlineacion alineacion, char relleno){

	bool especial=false;

	//puntero al string

	char * puntero=&la_cadena[0];
	string cadfinal="";

	//caso especial, si el num casillas es menor a la longitud del string
	//entonces se devuelve la string y ya

	if(num_casillas < strlen(puntero)){
		cadfinal=cadfinal + la_cadena;
		especial=true;
	}

	//todos los casos son similares, hay un bucle for para anadir el relleno
	//y una asignacion para aniadir el contenido de la cadena

	//caso 1:alineacion por la izquierda

	if((alineacion == TipoAlineacion::Izquierda) && especial==false){

		for(int i=0;i<num_casillas-strlen(puntero);i++){

			cadfinal= cadfinal + relleno;

		}

		cadfinal= cadfinal + la_cadena;
	}

	//caso 2:alineacion por la derecha

	if((alineacion == TipoAlineacion::Derecha) && especial==false){

		cadfinal= cadfinal + la_cadena;

		for(int i=0;i<num_casillas-strlen(puntero);i++){

			cadfinal= cadfinal + relleno;

		}

	}

	//caso 3:alineacion en el centro

	if((alineacion == TipoAlineacion::Centro) && especial==false){


		for(int i=0;i<(num_casillas-strlen(puntero))/2;i++){

			cadfinal= cadfinal + relleno;

		}

		cadfinal= cadfinal + la_cadena;

		for(int i=0;i<(num_casillas-strlen(puntero))/2;i++){

			cadfinal= cadfinal + relleno;

		}

	}

	for(int i=0;i<strlen(puntero);i++){

		cadfinal[i]= toupper(cadfinal[i]);

	}

	return (cadfinal);

}
