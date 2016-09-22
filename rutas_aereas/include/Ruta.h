#ifndef _RUTA_H
#define _RUTA_H

#include <string>
#include <vector>
#include "Punto.h"

class Ruta {
	private:
		string codigo;
		int num;
		vector<Punto> puntos;
		
	public:
		Ruta();
		Ruta(string c, int n, vector<Punto> p);
		
		string GetCode();
		
		// Las siguientes dos funciones solo se utilizan para la entrada y salida de ficheros con rutas y puntos de interés
		void SetCode(string code);
		void SetNum_Puntos_Interes();
		int GetNum();
		
		void AddPunto(Punto p);
		
		void EliminaPunto(Punto p);
		
		class const_iterator;
	class iterator{
		   private:
			typename vector<Punto>::iterator punt;
		   public:
			     iterator(){}
			     iterator & operator ++(){
				       punt++;
				       return *this;
			     }	       
			     iterator & operator --(){
				       punt--;
				       return *this;
			     }	       
			     bool operator ==(const iterator & it){
				       return it.punt==punt;
			     }
			     bool operator !=(const iterator & it){
				       return it.punt!=punt;
			     }
			     Punto & operator *(){
				       return *punt;
			     }
			     friend class Ruta;
			     friend class const_iterator;
	 };
 
	 class const_iterator{
		   private:
			typename vector<Punto>::const_iterator punt;
		   public:
			     const_iterator(){}
			     const_iterator(const iterator &it){
				       punt = it.punt;
			     }	       
			     const_iterator & operator ++(){
				       punt++;
				       return *this;
			     }	       
			     const_iterator & operator --(){
				       punt--;
				       return *this;
			     }	       
			     bool operator ==(const const_iterator & it){
				       return it.punt==punt;
			     }
			     bool operator !=(const const_iterator & it){
				       return it.punt!=punt;
			     }
			     const Punto & operator *()const{
				       return *punt;
			     }
				    friend class Ruta;			     
	};
		 
	iterator  begin(){
		iterator it;
		it.punt =puntos.begin();
		return it;
	}
	 
	iterator end(){
		iterator it;
		it.punt =puntos.end();
		return it;
	 }
		 
	const_iterator begin()const{
		const_iterator it;
		it.punt =puntos.begin();
		return it;
	}
	
	const_iterator end()const {
		const_iterator it;
		it.punt =puntos.end();
		return it;
	}
};

#endif