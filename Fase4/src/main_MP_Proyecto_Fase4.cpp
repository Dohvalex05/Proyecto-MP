/***************************************************************************/
/***************************************************************************/
// METODOLOGÍA DE LA PROGRAMACIÓN
// 
// ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
//
// FASE 4 Proyecto MP
//
// Fichero: main_MP_Proyecto_Fase4.cpp
//
/***************************************************************************/
/***************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

#include "utils.h"

#include "Fecha.h"
#include "Tiempo.h"

#include "Carrera.h"
#include "Corredor.h"
#include "Categoria.h"
#include "Resultado.h"

#include "Carreras.h"
#include "Corredores.h"
#include "Categorias.h"
#include "Resultados.h"

#include "TodosResultados.h"

using namespace std;

/***************************************************************************/
/***************************************************************************/

string cabecera(string titulo);

/***************************************************************************/
/***************************************************************************/

int main(int argc, char **argv){

    cout.setf(ios::fixed);       // Notación de punto fijo para los reales
    cout.setf(ios::showpoint);  // Mostrar siempre decimales

    //Cada linea se lee en un dato string. 

    string linea;

    if (argc != 2){

        cerr << "numero de argumentos erroneo" << endl;

        cerr << "se debe introducir de esta manera:" << endl;

        cerr << "<Programa> <Fichero>";

        exit(1);
    }

    
    //......................................................................
    //......................................................................
    // INFORMACION DE FICHERO DE CONTROL QUE HAY QUE SALTAR
    //......................................................................
    //......................................................................


    ifstream fi("circuito.cfg");
    if(!fi){
        cerr << "Fichero no existe o no se pudo abrir" << endl;
        exit(1);
    }

    //Empiezo analisis de circuito.cfg para sacar datos

    //Lectura para ver si el archivo abierto es el bueno

    getline(fi,linea);

    if(linea != "CIRCUITO"){

        cout << "Fichero tipo circuito no ha sido abierto";

        cout << endl << "No se puede continuar";

        exit(1);

    }

    //Nueva lectura, compruebo si la linea siguiente es comentario

    getline(fi,linea);

    while(linea[0] == '#'){

        getline(fi,linea);

    }

    //......................................................................
    //......................................................................
    // DATOS GENERALES 
    //......................................................................
    //......................................................................


    //Al terminar de comprobar hay lectura adelantada

    ostringstream oss;

    oss << cabecera("DATOS GENERALES") << endl;

    oss << "CIRCUITO: " << linea << endl;

    getline(fi,linea);
    int NumCarreras = stoi(linea);

    oss << "Carreras:   " << NumCarreras << endl; 
 
    getline(fi, linea); 
    int NumCarrerasMinimo = stoi(linea);

    oss << "Minimo:     " << NumCarrerasMinimo << endl; 

    getline(fi, linea); 
    int NumCarrerasDisputadas = stoi(linea);

    oss << "Disputadas: " << NumCarrerasDisputadas << endl << endl; 


    //......................................................................
    //......................................................................
    // CARRERAS
    //......................................................................
    //......................................................................

    getline(fi,linea);

    Carrera una_carrera;
    Carreras unas_carreras;

    unas_carreras.LeerCarreras(linea);

    oss << cabecera("CARRERAS");

    oss << unas_carreras.ToString("") << endl;

    oss << "Total carreras del circuito = "<<setw(3);
    oss << unas_carreras.Usados() << endl; 

    oss << endl; 


    //......................................................................
    //......................................................................
    // CORREDORES
    //......................................................................
    //......................................................................

    getline(fi,linea);

    Corredor un_corredor;
    Corredores unos_corredores;

    unos_corredores.LeerCorredores(linea);

    oss << cabecera("CORREDORES");

    oss << unos_corredores.ToString("") << endl;

    oss << "Total corredores del circuito = "<<setw(3);
    oss << unos_corredores.Usados() << endl; 

    oss << endl;

    //......................................................................
    //......................................................................
    // CATEGORIAS
    //......................................................................
    //......................................................................

    getline(fi,linea);

    Categoria una_categoria;
    Categorias unas_categorias;

    unas_categorias.LeerCategorias(linea);

    oss << cabecera("CATEGORIAS");

    oss << unas_categorias.ToString("") << endl;

    oss << "Total categorias = "<<setw(3);
    oss << unas_categorias.Usados() << endl; 

    oss << endl; 

    //......................................................................
    //......................................................................
    // RESULTADOS Y COLECCION DE RESULTADOS
    //......................................................................
    //......................................................................

    Resultado un_Resultado;

    Resultados unos_resultados;

    TodosResultados todos_resultados; 

    oss << cabecera("RESULTADOS");

    for(int i=1;i<=NumCarrerasDisputadas;i++){

        fi >> linea;

        unos_resultados.LeerResultados(linea);

        Carrera carrera_actual = unas_carreras[i]; 

        // Operator [] de "Carreras"

        oss << "Guardados los resultados de la carrera " <<
            "[" << i << "] " << carrera_actual.GetNombre() << endl;
             
        oss << "Total finalizados = "
             << setw(3) << unos_resultados.Usados() << endl; 
        oss << endl; 


        todos_resultados += unos_resultados;

    }

    oss << cabecera("TODOS RESULTADOS");

    oss << todos_resultados.ToString("");

    oss << "Total carerras con resultados = "<<setw(3) 
         << todos_resultados.Usados() << endl; 
    oss << endl; 

    cout << oss.str();

    fi.close();


}
    
    
/***************************************************************************/
/***************************************************************************/


string cabecera(string titulo){

    ostringstream oss;

    oss << "-----------------------------------";
    oss << "----------------------------------";

    oss << endl << titulo << endl;

    oss << "-----------------------------------";
    oss << "----------------------------------";

    oss << endl;

    return oss.str();
}
