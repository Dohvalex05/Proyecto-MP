#############################################################################
#
# ALEJANDRO CANO ESPARCIA GRUPO B2
#
# MP_Proyecto_Fase1.mak
#
# makefile para Fase 4 de Proyecto MP
#
#############################################################################

HOME = .
BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

#................................................
all:  	preambulo $(BIN)/MP_Proyecto_Fase4
      

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo
	@echo PROYECTO: MAKEFILE PARA FASE 4 PROYECTO MP	
	@echo
	@echo ALEJANDRO CANO ESPARCIA GRUPO PRACTICAS B2
	@echo
	@echo ------------------------------------------------------------
	@echo

# EJECUTABLES

$(BIN)/MP_Proyecto_Fase4 : $(OBJ)/MP_Proyecto_Fase4.o \
				$(LIB)/libutils.a \
				$(LIB)/libCarrera.a \
				$(LIB)/libCategoria.a \
				$(LIB)/libCorredor.a \
				$(LIB)/libFecha.a \
				$(LIB)/libutils.a \
				$(LIB)/libResultado.a \
				$(LIB)/libTiempo.a \
				$(LIB)/libCarreras.a \
				$(LIB)/libCategorias.a \
				$(LIB)/libCorredores.a \
				$(LIB)/libResultados.a \
				$(LIB)/libTodosResultados.a
	@echo 
	@echo Creando ejecutable: main_MP_Proyecto_Fase4
	@echo 
	g++ -g -o $(BIN)/MP_Proyecto_Fase4 $(OBJ)/MP_Proyecto_Fase4.o \
	       -lCarrera -lCategoria -lCorredor -lFecha -lutils \
	       -lResultado -lutils -lTiempo -lCarreras -lCategorias \
		-lCorredores -lResultados -lTodosResultados -L$(LIB) 

#................................................
# OBJETOS 

$(OBJ)/MP_Proyecto_Fase4.o : $(SRC)/main_MP_Proyecto_Fase4.cpp \
									
	                  
	@echo 
	@echo Creando objeto: main_MP_Proyecto_Fase4.o
	@echo 
	g++ -g -c -o $(OBJ)/MP_Proyecto_Fase4.o \
		  $(SRC)/main_MP_Proyecto_Fase4.cpp \
		  -I$(INCLUDE) -std=c++14
		                    	        
#//////////////////////////////////////////////////////////
#//////////////////////////////////////////////////////////
#//////////////////////////////////////////////////////////
#//////////////////////////////////////////////////////////
#//////////////////////////////////////////////////////////
#................................................
#................................................
# LIBRERIAS 

$(LIB)/libCarrera.a : $(OBJ)/Carrera.o
	@echo 
	@echo Creando biblioteca: libCarrera.a
	@echo
	ar rvs $(LIB)/libCarrera.a \
	$(OBJ)/Carrera.o

$(OBJ)/Carrera.o : \
	$(SRC)/Carrera.cpp \
	$(INCLUDE)/Carrera.h \
	$(INCLUDE)/Fecha.h \
	$(INCLUDE)/utils.h
	@echo 
	@echo Creando objeto: Carrera.o 
	@echo
	g++ -c -o $(OBJ)/Carrera.o \
	$(SRC)/Carrera.cpp \
	-I$(INCLUDE) -std=c++14

#//////////////////////////////////////////////////////////

$(LIB)/libCategoria.a : $(OBJ)/Categoria.o
	@echo 
	@echo Creando biblioteca: libCategoria.a
	@echo
	ar rvs $(LIB)/libCategoria.a \
	$(OBJ)/Categoria.o

$(OBJ)/Categoria.o : \
	$(SRC)/Categoria.cpp \
	$(INCLUDE)/Categoria.h \
	$(INCLUDE)/utils.h \
	$(INCLUDE)/Fecha.h 
	@echo 
	@echo Creando objeto: Categoria.o 
	@echo
	g++ -c -o $(OBJ)/Categoria.o \
	$(SRC)/Categoria.cpp \
	-I$(INCLUDE) -std=c++14

#//////////////////////////////////////////////////////////

$(LIB)/libCorredor.a : $(OBJ)/Corredor.o
	@echo 
	@echo Creando biblioteca: libCorredor.a
	@echo
	ar rvs $(LIB)/libCorredor.a \
	$(OBJ)/Corredor.o

$(OBJ)/Corredor.o : \
	$(SRC)/Corredor.cpp \
	$(INCLUDE)/Corredor.h \
	$(INCLUDE)/Fecha.h \
	$(INCLUDE)/utils.h

	@echo 
	@echo Creando objeto: Corredor.o 
	@echo
	g++ -c -o $(OBJ)/Corredor.o \
	$(SRC)/Corredor.cpp \
	-I$(INCLUDE) -std=c++14

#//////////////////////////////////////////////////////////

$(LIB)/libResultado.a : $(OBJ)/Resultado.o
	@echo 
	@echo Creando biblioteca: libResultado.a
	@echo
	ar rvs $(LIB)/libResultado.a \
	$(OBJ)/Resultado.o

$(OBJ)/Resultado.o : \
	$(SRC)/Resultado.cpp \
	$(INCLUDE)/Resultado.h \
	$(INCLUDE)/Tiempo.h \
	$(INCLUDE)/utils.h
	@echo 
	@echo Creando objeto: Resultado.o 
	@echo
	g++ -c -o $(OBJ)/Resultado.o \
	$(SRC)/Resultado.cpp \
	-I$(INCLUDE) -std=c++14

#//////////////////////////////////////////////////////////

$(LIB)/libFecha.a : $(OBJ)/Fecha.o
	@echo 
	@echo Creando biblioteca: libFecha.a
	@echo
	ar rvs $(LIB)/libFecha.a \
	$(OBJ)/Fecha.o

$(OBJ)/Fecha.o : \
	$(SRC)/Fecha.cpp \
	$(INCLUDE)/Fecha.h \
	$(INCLUDE)/utils.h
	@echo 
	@echo Creando objeto: Fecha.o 
	@echo
	g++ -c -o $(OBJ)/Fecha.o \
	$(SRC)/Fecha.cpp \
	-I$(INCLUDE) -std=c++14

#//////////////////////////////////////////////////////////

$(LIB)/libTiempo.a : $(OBJ)/Tiempo.o
	@echo 
	@echo Creando biblioteca: libTiempo.a
	@echo
	ar rvs $(LIB)/libTiempo.a \
	$(OBJ)/Tiempo.o

$(OBJ)/Tiempo.o : \
	$(SRC)/Tiempo.cpp \
	$(INCLUDE)/Tiempo.h \
	$(INCLUDE)/utils.h
	@echo 
	@echo Creando objeto: Tiempo.o 
	@echo
	g++ -c -o $(OBJ)/Tiempo.o \
	$(SRC)/Tiempo.cpp \
	-I$(INCLUDE) -std=c++14

#//////////////////////////////////////////////////////////

$(LIB)/libutils.a : $(OBJ)/utils.o
	@echo 
	@echo Creando biblioteca: libutils.a
	@echo
	ar rvs $(LIB)/libutils.a \
	$(OBJ)/utils.o

$(OBJ)/utils.o : $(SRC)/utils.cpp $(INCLUDE)/utils.h
		          
	@echo 
	@echo Creando objeto: utils.o
	@echo 
	g++ -c -o $(OBJ)/utils.o \
		  $(SRC)/utils.cpp \
		  -I$(INCLUDE) -std=c++14	

#................................................
#................................................
# LIBRERIAS DINAMICAS

$(LIB)/libCorredores.a : $(OBJ)/Corredores.o
	@echo 
	@echo Creando biblioteca: libCorredores.a
	@echo
	ar rvs $(LIB)/libCorredores.a \
	$(OBJ)/Corredores.o

$(OBJ)/Corredores.o : $(SRC)/Corredores.cpp $(INCLUDE)/Corredores.h
	                  
	@echo 
	@echo Creando objeto: Corredores.o
	@echo 
	g++ -c -o $(OBJ)/Corredores.o \
		  $(SRC)/Corredores.cpp \
		  -I$(INCLUDE) -std=c++14	

#//////////////////////////////////////////////////////////

$(LIB)/libCarreras.a : $(OBJ)/Carreras.o 
	@echo 
	@echo Creando biblioteca: libCarreras.a
	@echo
	ar rvs $(LIB)/libCarreras.a \
	$(OBJ)/Carreras.o

$(OBJ)/Carreras.o : \
	$(SRC)/Carreras.cpp \
	$(INCLUDE)/Carreras.h
	@echo 
	@echo Creando objeto: Carreras.o 
	@echo
	g++ -c -o $(OBJ)/Carreras.o \
	$(SRC)/Carreras.cpp \
	-I$(INCLUDE) -std=c++14

#//////////////////////////////////////////////////////////

$(LIB)/libCategorias.a : $(OBJ)/Categorias.o 
	@echo 
	@echo Creando biblioteca: libCategorias.a
	@echo
	ar rvs $(LIB)/libCategorias.a \
	$(OBJ)/Categorias.o

$(OBJ)/Categorias.o : \
	$(SRC)/Categorias.cpp \
	$(INCLUDE)/Categorias.h
	@echo 
	@echo Creando objeto: Categorias.o 
	@echo
	g++ -c -o $(OBJ)/Categorias.o \
	$(SRC)/Categorias.cpp \
	-I$(INCLUDE) -std=c++14

#//////////////////////////////////////////////////////////

$(LIB)/libResultados.a : $(OBJ)/Resultados.o 
	@echo 
	@echo Creando biblioteca: libResultados.a
	@echo
	ar rvs $(LIB)/libResultados.a \
	$(OBJ)/Resultados.o

$(OBJ)/Resultados.o : \
	$(SRC)/Resultados.cpp \
	$(INCLUDE)/Resultados.h
	@echo 
	@echo Creando objeto: Resultados.o 
	@echo
	g++ -c -o $(OBJ)/Resultados.o \
	$(SRC)/Resultados.cpp \
	-I$(INCLUDE) -std=c++14

#//////////////////////////////////////////////////////////

$(LIB)/libTodosResultados.a : $(OBJ)/TodosResultados.o 
	@echo 
	@echo Creando biblioteca: libTodosResultados.a
	@echo
	ar rvs $(LIB)/libTodosResultados.a \
	$(OBJ)/TodosResultados.o

$(OBJ)/TodosResultados.o : \
	$(SRC)/TodosResultados.cpp \
	$(INCLUDE)/TodosResultados.h
	@echo 
	@echo Creando objeto: TodosResultados.o 
	@echo
	g++ -c -o $(OBJ)/TodosResultados.o \
	$(SRC)/TodosResultados.cpp \
	-I$(INCLUDE) -std=c++14

#//////////////////////////////////////////////////////////

mr.proper:  
	rm $(OBJ)/* $(LIB)/* $(BIN)/*
