SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -w

# ************ Generación de códido fuente ******************	
all: $(BIN)/rutas_aereas
 
$(BIN)/rutas_aereas: $(OBJ)/rutas_aereas.o $(OBJ)/rotacion.o $(OBJ)/imagen.o $(OBJ)/Paises.o $(OBJ)/Pais.o $(OBJ)/almacen_rutas.o $(OBJ)/Ruta.o $(OBJ)/imagenES.o
	@echo "Creando ./bin/rutas_aereas..."
	@$(CXX) -o $@ $^

$(OBJ)/rutas_aereas.o: $(SRC)/rutas_aereas.cpp $(OBJ)/rotacion.o $(OBJ)/imagen.o $(OBJ)/Paises.o $(OBJ)/almacen_rutas.o $(OBJ)/Pais.o $(OBJ)/imagenES.o
	@echo "Creando ./obj/rutas_aereas.o..."
	@$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/rotacion.o: $(SRC)/rotacion.cpp $(OBJ)/imagen.o
	@echo "Creando ./obj/rotacion.o..."
	@$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagenES.h
	@echo "Creando ./obj/imagen.o..."
	@$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/Paises.o: $(SRC)/Paises.cpp $(OBJ)/Pais.o $(INC)/Pais.h $(INC)/Punto.h
	@echo "Creando ./obj/Paises.o..."
	@$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/Pais.o: $(SRC)/Pais.cpp $(INC)/Punto.h
	@echo "Creando ./obj/Pais.o..."
	@$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/almacen_rutas.o: $(SRC)/almacen_rutas.cpp $(OBJ)/Ruta.o $(INC)/Ruta.h $(INC)/Punto.h
	@echo "Creando ./obj/almacen_rutas.o..."
	@$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/Ruta.o: $(SRC)/Ruta.cpp $(INC)/Punto.h
	@echo "Creando ./obj/Ruta.o..."
	@$(CXX) $(CPPFLAGS) $< -o $@

$(OBJ)/imagenES.o: $(SRC)/imagenES.cpp
	@echo "Creando ./obj/imagenES.o..."
	@$(CXX) $(CPPFLAGS) $< -o $@



# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* #$(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
