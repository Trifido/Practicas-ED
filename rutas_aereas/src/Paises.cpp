#include "Pais.h"
#include "Paises.h"
#include <set>
using namespace std;

      void Paises::Insertar(const Pais &P){
	  datos.insert(P);
      }
      void Paises::Borrar(const Pais &P){
	  datos.erase(P);
      }
      
	
