#include <iostream>
#include "Pais.h"
#include "Punto.h"
using namespace std;

    Punto Pais::GetPunto()const { return p; }
    string Pais::GetPais()const{ return pais; }
    string Pais::GetBandera()const{ return bandera; }
    
    bool Pais::operator<(const Pais &P)const{
	return pais<P.GetPais();
    }	
    bool Pais::operator==(const Pais &P)const{
	return pais==P.GetPais();
    }
    bool Pais::operator==(const Punto &P)const{
	return GetPunto()==P;
    }
    
    

