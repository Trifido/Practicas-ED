#include <iostream>
#include <string>
#include <vector>
#include "Ruta.h"
#include "Punto.h"
using namespace std;

	Ruta::Ruta() { num=0; codigo=""; }
	Ruta::Ruta(string c, int n, vector<Punto> p) {
		codigo=c;
		num=n;
		puntos=p;		
		
	}
	
	string Ruta::GetCode() { return codigo; }		
	// Las siguientes dos funciones solo se utilizan para la entrada y salida de ficheros con rutas y puntos de interés
	void Ruta::SetCode(string code) { codigo=code; }
	void Ruta::SetNum_Puntos_Interes() { num=0; }
	int Ruta::GetNum() { return num; }
	
	void Ruta::AddPunto(Punto p) {
		puntos.push_back(p);
		num++;
	}
	void Ruta::EliminaPunto(Punto p) {
		vector<Punto>::iterator it;
		it=puntos.begin();
		int pos=0;
		while ((*it)!=p) {
			pos++;
			++it;
		}
		
		puntos.erase(puntos.begin()+pos);
		num--;
	}
	 
	
