#ifndef _PAISES_H_
#define _PAISES_H_

#include <iostream>
#include <string.h>
#include "imagen.h"
#include <set>
#include<list>
using namespace std;


struct Pais{
	double lat, lon;
	string nombre;
	Imagen bandera;
};

char direcBand[50];

class Paises{
	private:
		list<Pais> paises;//set

	public:
		void aniadePais(Pais p){
			paises.push_back(p);
		}

		void aniadeDir(char *direc){
			strcat(direcBand,direc);
			strcat(direcBand,"/");
		}
		
		Pais buscarPais(string nom){
			Pais encontrado;
			list<Pais>::iterator it;
			for(it= paises.begin(); it!=paises.end(); ++it)
				if(nom==((*it).nombre))
					return *it;
			cout << "No encontrado." << endl;
			return encontrado;
		}

		friend istream & operator>>(istream & is, Paises & P){
	      	Pais plocal;  
		  	char bandera[50];
		  	for(int i=0;i<52;i++){
		 		is>>plocal.lat;
		 		is>>plocal.lon;
		 		is>>plocal.nombre;
		 		is>>bandera;

				strcat(direcBand,bandera);
				Imagen I;
				I.LeerImagen(direcBand);
				plocal.bandera=I;

				P.aniadePais(plocal);
		 	}
		  	return is;
		}

//----------------------------------------------------------------------

class const_iterator;
	class iterator{
	private:
	    list<Pais>::iterator p;
	public:
	    iterator(){}
	    iterator & operator ++(){
		++p;
		return * this;
	    }
	    
	    iterator & operator --(){
		--p;
		return * this;
	    }
	    bool operator ==(const iterator  & it){
		return it.p ==p;
	    }
	    bool operator !=(const iterator  & it){
		return it.p !=p;
	    }
	     Pais & operator*(){
		  return *p;
	    }
	    friend class Paises;
	    friend class const_iterator;
	};    
	class const_iterator{
	private:
	    list<Pais>::const_iterator p;
	public:
	    const_iterator(){}
	    const_iterator(const iterator & it){
	      p=it.p;
	      
	    }
	    const_iterator & operator=(const iterator & it){
		p=it.p;
		return *this;
	    }	
	    const_iterator & operator ++(){
		++p;
		return * this;
	    }
	    
	    const_iterator & operator --(){
		--p;
		return * this;
	    }
	    bool operator ==(const const_iterator  & it){
		return it.p ==p;
	    }
	    bool operator !=(const const_iterator  & it){
		return it.p !=p;
	    }
	    const Pais &operator*()const {
		  return *p;
	    }
	    friend class Paises;
	   
	};
	iterator begin(){
	  iterator it;
	  it.p = paises.begin();
	  return it;
	}  
	
	const_iterator begin()const{
	  const_iterator it;
	  it.p = paises.begin();
	  return it;
	}
	iterator end(){
	  iterator it;
	  it.p = paises.end();
	  return it;
	}
	const_iterator end()const{
	  const_iterator it;
	  it.p = paises.end();
	  return it;
	}

//----------------------------------------------------------------------

};

#endif
