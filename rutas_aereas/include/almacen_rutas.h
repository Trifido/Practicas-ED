#ifndef _ALMACEN_RUTAS_H
#define _ALMACEN_RUTAS_H

#include <list>
#include <fstream>
#include <string>
#include <vector>
#include "Ruta.h"
#include <cstdlib>

class Almacen_Rutas {
	private:
		list<Ruta> almacen;
		vector<Punto> puntos;
	public:
		Almacen_Rutas() {}
		Ruta GetRuta(string &s);
		
		void AddRuta(Ruta &r);
		
		void EliminaRuta(Ruta &r);
		
		Almacen_Rutas GetRutas_Con_Punto(Punto p);
		
		string GetDescripcion_point(Punto p);

		
		friend ostream & operator<<(ostream &os, Almacen_Rutas &ar){
			list<Ruta>::iterator it;
		
			os << endl;
			for (it=ar.almacen.begin(); it!=ar.almacen.end(); ++it) {
				if ((*it).GetNum()>1) {
					os << "Ruta: " << (*it).GetCode() << endl;
					Ruta::iterator it_r;
					for (it_r=(*it).begin(); it_r!=(*it).end(); ++it_r) 
						os << *it_r;
				}
				else 
					if ((*it).GetNum()==1) {
						os << (*it).GetCode() << " ";
						Ruta::iterator it_s=(*it).begin();
						os << *it_s;
					}
				os << endl;
			}
				return os;
		}
	
		friend istream & operator>>(ifstream &is, Almacen_Rutas &ar) {
			char c;
			is >> c;
			if (c!='#') {
				cout << "Error en el archivo de entrada." << endl;
				exit(EXIT_FAILURE);
			}
			else {
				string s;
				is >> s;
				if (s=="Rutas") {
					while(is.get()!=(int)'#' && !is.eof()) {
						string code;
						is >> code;
						int num;
						is >> num;
						Ruta aux;
						aux.SetCode(code);
						Punto p;
						for (int i=0; i<num; ++i) {
							is >> p;
							aux.AddPunto(p);
						}
						ar.AddRuta(aux);
					}
					is >> s;
				}
				if (s=="Puntos_de_Interes") {
					while(!is.eof()) {
						Punto p;
						is >> p;
						string nombre;
						is >> nombre;
						p.SetDES(nombre);
						ar.puntos.push_back(p);
					}
				}
					}
			return is;
		}
		
		class const_iterator;
		class iterator{
			   private:
				typename list<Ruta>::iterator alm;
			   public:
				     iterator(){}
				     iterator & operator ++();
				     iterator & operator --();
				     bool operator ==(const iterator & it);
				     bool operator !=(const iterator & it);
				     Ruta & operator *();
				     friend class Almacen_Rutas;
				     friend class const_iterator;
		 };
		 
		 class const_iterator{
			   private:
				typename list<Ruta>::const_iterator alm;
			   public:
				     const_iterator(){}
				     const_iterator(const iterator &it);
				     const_iterator & operator ++();
				     const_iterator & operator --();
				     bool operator ==(const const_iterator & it);
				     bool operator !=(const const_iterator & it);
				     const Ruta & operator *()const;
				     friend class Almacen_Rutas;
				     
		 };
		 
		iterator  begin(){
		       iterator it;
		       it.alm =almacen.begin();
		       return it;
		}
		iterator end(){
			iterator it;
			it.alm =almacen.end();
			return it;
		}
		
		const_iterator begin()const{
			const_iterator it;
			it.alm=almacen.begin();
			return it;
		}
		const_iterator end()const {
			const_iterator it;
			it.alm=almacen.end();
			return it;
		}
};

#endif