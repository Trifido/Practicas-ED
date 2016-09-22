//./bin/ruta_aerea datos/paises.txt datos/imagenes/mapas/mapa1.ppm datos/imagenes/banderas/ datos/almacen_rutas.txt datos/imagenes/aviones/avion1.ppm datos/imagenes/aviones/mascara_avion1.pgm 

#include "imagen.h"
#include "paises.h"
#include "Ruta.h"
#include "almacen_rutas.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void Pintar( int f1,int f2,int c1,int c2,Imagen &I, const Imagen &avion,int mindisf,int mindisc){
	int fila,col;
    if (abs(f2-f1)>=mindisf || abs(c2-c1)>=mindisc){ 
		if (c1!=c2){
	   		double a,b;
	   		a= double(f2-f1)/double(c2-c1);
	   		b= f1-a*c1;
	   		col = (int)(c1+c2)/2;
	   		fila = (int)rint(a*col+b);
	 	}  
	 	else{
	  		col = c1;
	   		fila = (f1+f2)/2;
	 	}  
	  
	  	double angulo = atan2((f2-f1),(c2-c1));
	  	Imagen Irota=Rota(avion,angulo);
	
	  	I.PutImagen(fila,col,Irota);
	  
	   	angulo = atan2((f2-fila),(c2-col));
	  	Irota=Rota(avion,angulo);
	
	  	I.PutImagen(f2,c2,Irota);
	  	angulo = atan2((fila-f1),(col-c1));
	  	Irota=Rota(avion,angulo);
	
	  	I.PutImagen(f1,c1,Irota);
      }
}  
  

int main(int argc, char * argv[]){
	if (argc!=7){
      	cout<<"Los parametros son:"<<endl;
      	cout<<"1.-Fichero con la informacion de los paises"<<endl;
	  	cout<<"2.-Nombre de la imagen con el mapa del mundo"<<endl;
	  	cout<<"3.-Directorio con las banderas"<<endl;
	  	cout<<"4.-Fichero con el almacen de rutas"<<endl;
	  	cout<<"5.- Nombre de la imagen con el avion"<<endl;
	  	cout<<"6.- Nombre de la imagen de la mascara del avion"<<endl;
		return 0;   
	}

	Paises Pses;
	ifstream f (argv[1]);

	Pses.aniadeDir(argv[3]);
	f>>Pses;				//?

  	Imagen I;
  	I.LeerImagen(argv[2]);

  	//Leemos la imagen avion y la mascara 
  	Imagen avion;
	avion.LeerImagen(argv[5],argv[6]);

	Almacen_Rutas Ar;
	f.close();
	//Abrimos el almacen de rutas pasado por consola
	 f.open (argv[4]);
	//Pasamos los datos del fichero a la ED de rutas
	f>>Ar;
	//Muestra las rutas
	cout<<"Las rutas: "<<endl<<Ar;
	//Introducimos la ruta que se desea
	cout<<"Dime el codigo de una ruta"<<endl;
	string a;
	cin>>a;
	//Asignamos la ruta que introducimos por pantalla
	Ruta R=Ar.GetRuta(a);
	
//-------------------

//Lo importante

Ruta::iterator r;
for(r= R.begin(); r!=R.end(); ++r)
{	
	//Pais p;
	//p=Pses.buscarPais((*r).GetDescripcion());
	//Pintar();
	cout << (*r).GetDescripcion() << endl;

}

//-------------------
	char nombreimag[50];
	int j=0;
	while(a[j]!=' '){
		nombreimag[j]=a[j];
		j++;
	}

//Imagen final grabada en disco
	I.EscribirImagen(nombreimag);
	return 0;
}



