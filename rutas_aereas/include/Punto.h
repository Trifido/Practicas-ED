#ifndef _PUNTO_H
#define _PUNTO_H

#include <iostream>
using namespace std;

class Punto {
	private: 
		double latitud,longitud;
		string descripcion;
	public:
		Punto() { latitud=longitud=0; }
		Punto(double x, double y, string d) { latitud=x; longitud=y; descripcion=d; }
		double GetLAT() { return latitud; }
		double GetLON() { return longitud; }
		string GetDES() { return descripcion; }
		void SetLAT(double lat) { latitud=lat; }
		void SetLON(double lon) { longitud=lon; }
		void SetDES(string des) { descripcion=des; }
		
		Punto& operator=(const Punto &original) {
			if (original.latitud!=latitud && original.longitud!=longitud) {
				latitud=original.latitud;
				longitud=original.longitud;
			}
			
			return *this;
		}
		
		bool operator==(const Punto &p) {
			return p.latitud==latitud && p.longitud==longitud;
		}
		
		bool operator!=(const Punto &p) {
			return p.latitud!=latitud && p.longitud!=longitud;
		}
		
		friend ostream & operator<<(ostream &os, Punto &p){	
			return os << "(" << p.GetLAT() << " , " << p.GetLON() << ")";
		}
		
		// Introducimos el Punto de forma; (x,y)
		friend istream & operator>>(istream &is, Punto &p){	
			char c;
			double lat,lon;
			is >> c >> lat >> c >> lon >> c;
			p.SetLAT(lat);
			p.SetLON(lon);
			return is;
		}
};

#endif