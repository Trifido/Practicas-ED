SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
LIB = lib
CPPFLAGS = -Wall -g  -I$(INC) -c

		
all : $(BIN)/pruebarotacion	$(BIN)/pruebapegado $(BIN)/ruta_aerea

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilacion de modulos ************
$(BIN)/ruta_aerea : $(OBJ)/ruta_aerea.o $(LIB)/libimagen.a
	g++ -o $(BIN)/ruta_aerea $(OBJ)/ruta_aerea.o -L$(LIB) -limagen

$(BIN)/pruebarotacion : $(OBJ)/pruebarotacion.o $(LIB)/libimagen.a
	g++ -o $(BIN)/pruebarotacion $(OBJ)/pruebarotacion.o -L$(LIB) -limagen

$(BIN)/pruebapegado : $(OBJ)/pruebapegado.o $(LIB)/libimagen.a
	g++ -o $(BIN)/pruebapegado $(OBJ)/pruebapegado.o -L$(LIB) -limagen

$(LIB)/libimagen.a : $(OBJ)/imagenES.o $(OBJ)/imagen.o
	ar rvs $(LIB)/libimagen.a $(OBJ)/imagenES.o $(OBJ)/imagen.o

$(OBJ)/ruta_aerea.o : $(SRC)/ruta_aerea.cpp $(INC)/Punto.h $(INC)/Ruta.h $(INC)/almacen_rutas.h $(INC)/paises.h
	$(CXX) $(CPPFLAGS) $(SRC)/ruta_aerea.cpp -o $(OBJ)/ruta_aerea.o

$(OBJ)/pruebarotacion.o : $(SRC)/pruebarotacion.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/pruebarotacion.cpp -o $(OBJ)/pruebarotacion.o

$(OBJ)/pruebapegado.o : $(SRC)/pruebapegado.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/pruebapegado.cpp -o $(OBJ)/pruebapegado.o

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/imagen.o: $(SRC)/imagen.cpp  $(INC)/imagen.h $(INC)/imagenES.h  
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(LIB)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
