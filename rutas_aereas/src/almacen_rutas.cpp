#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include <string>
#include "almacen_rutas.h"
#include "Ruta.h"

using namespace std;

	Ruta Almacen_Rutas::GetRuta(string &s) {
		list<Ruta>::iterator it;
		Ruta r;
		for (it=almacen.begin(); it!=almacen.end(); ++it) 
			if ((*it).GetCode()==s) 
				r=*it;
		return r;
	}
	
	void Almacen_Rutas::AddRuta(Ruta &r) {
		almacen.push_back(r);
	}
	
	void Almacen_Rutas::EliminaRuta(Ruta &r) {
		list<Ruta>::iterator it;
		it=almacen.begin();
		while ((*it).GetCode()!=r.GetCode()) 
			++it;
		almacen.erase(it);
	}
	
	Almacen_Rutas Almacen_Rutas::GetRutas_Con_Punto(Punto p) {
		Almacen_Rutas res;
		list<Ruta>::iterator it;
		
		for (it=almacen.begin(); it!=almacen.end(); ++it) {
			Ruta::iterator it_r;
			bool esta=false;
			for (it_r=(*it).begin(); it_r!=(*it).end() && !esta; ++it_r) {
				if ((*it_r)==p)
					esta=true;
			}
			if (esta)
				res.AddRuta(*it);
		}
		return res;
	}
	
	string Almacen_Rutas::GetDescripcion_point(Punto p) {
		int tam=puntos.size();
		string des;
		for (int i=0; i<tam; i++) {
			if (p==puntos.at(i)) 
				des=puntos.at(i).GetDES();
		}
		return des;
	}
			 
	
	