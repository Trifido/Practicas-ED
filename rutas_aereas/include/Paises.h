#ifndef PAISES_H
#define PAISES_H

#include <set>
#include "Pais.h"
using namespace std;

class Paises{
  private:
    set<Pais> datos;
  public:
      Paises() {}
      void Insertar(const Pais &P);
      void Borrar(const Pais &P);
      
      class const_iterator;
	class iterator{
	private:
		set<Pais>::iterator ps;
	public:
		iterator(){} 
		iterator & operator ++(){
			ps++;
			return *this;
		}
		
		 iterator & operator --(){
			ps--;
			return *this;
		}
		
		bool operator !=(const iterator & it){
			return it.ps!=ps;
		}
		
		bool operator ==(const iterator & it) {
			return it.ps==ps;
		}
		
		const Pais & operator *(){
			return *ps;
		}
		
		friend class Paises;
	        friend class const_iterator;
	};  
	
	class const_iterator{
	private:
	    set<Pais>::const_iterator ps;
	public:
		const_iterator(){} 
		const_iterator(const iterator &it){
			ps = it.ps;
		}
		const_iterator & operator ++(){
			ps++;
			return *this;
		}
		
		const_iterator & operator --(){
			ps--;
			return *this;
		}
		
		bool operator !=(const const_iterator & it){
			return it.ps!=ps;
		}
		
		bool operator ==(const const_iterator & it) {
			return it.ps==ps;
		}
		
		const Pais & operator *() const{
			return *ps;
		}
	    friend class Paises;
	   
	};
	
	iterator begin(){
		iterator it;
		it.ps = datos.begin();
		return it;
	}  
	
	const_iterator begin()const{
		const_iterator it;
		it.ps = datos.begin();
		return it;
	}
	
	iterator end(){
		iterator it;
		it.ps = datos.end();
		return it;
	}
	
	const_iterator end()const{
		iterator it;
		it.ps = datos.end();
		return it;
	}
	
	iterator find(const Pais &p){
		iterator it;
		set<Pais>::iterator i;
		it.ps=i;
		return it;
	}
	
	iterator find(const Punto &p){
		iterator it;
		set<Pais>::iterator i;
		it.ps=i;
		return it;
	}
	
	friend istream & operator>>(istream & is, Paises & R){
	      Paises rlocal;
	      //leemos el comentario
	      if (is.peek()=='#'){
		string a;
		getline(is,a);
	      }	
	      
	      Pais P;
	      while (is>>P){
		  rlocal.Insertar(P);
		  
	      }
	      R=rlocal;
	      return is;
	}
	
	friend ostream & operator<<(ostream & os, const Paises &R){
	  
	    Paises::const_iterator it;
	    for (it=R.begin(); it!=R.end(); ++it){
		os<<"\t"<<*it;
	    }
	    return os;
	}

};

#endif