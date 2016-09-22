#include "almacen_rutas.h"
#include "Paises.h"
#include "rotacion.h"
#include "imagen.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

void Mostrar_Ruta(Paises &pses, Almacen_Rutas &ar, string &s) {
	Ruta R=ar.GetRuta(s);
	Ruta::iterator it;
	Paises::iterator it_p;
	
	for (it=R.begin(); it!=R.end(); ++it) {
		for (it_p=pses.begin(); it_p!=pses.end(); ++it_p) {
			if ((*it)==(*it_p).GetPunto())
				cout << (*it_p).GetPais() << " ";
		}
	}
	cout << endl;
}

void PintarV2(Imagen &mapa, Imagen &avion, Ruta &r) {
	Ruta::iterator it=r.begin();
	Ruta::iterator it_p=r.begin();
	++it_p;
	Punto p1,p2;
	int cont=1;
	for (it_p; it_p!=r.end();) {
		p1=*it;
		p2=*it_p;
			
		int j1=(mapa.num_cols()/360)*(180+p1.GetLON());
		int i1=(mapa.num_filas()/180)*(90-p1.GetLAT());
			
		int j2=(mapa.num_cols()/360)*(180+p2.GetLON());
		int i2=(mapa.num_filas()/180)*(90-p2.GetLAT());
			
		int mitad2=(mapa.num_cols()/360)*(180+(p2.GetLON()+p1.GetLON())/2);
		int mitad1=(mapa.num_filas()/180)*(90-(p2.GetLAT()+p1.GetLAT())/2);
		
		if (cont<r.GetNum()) {
			double angulo = atan2((i2-i1),(j2-j1));
			Imagen Irota=Rota(avion,angulo);
			mapa.PutImagen(i1,j1,Irota,BLENDING);
			
			angulo = atan2((i2-mitad1),(j2-mitad2));
			Imagen Irota2=Rota(avion,angulo);
			mapa.PutImagen(mitad1,mitad2,Irota2,BLENDING);
		}
		if (cont==r.GetNum() - 1) {
			double angulo = atan2((i2-mitad1),(j2-mitad2));
			Imagen Irota=Rota(avion,angulo);
			mapa.PutImagen(mitad1,mitad2,Irota,BLENDING);
			
			angulo = atan2((i2-mitad1),(j2-mitad2));
			Imagen Irota2=Rota(avion,angulo);
			mapa.PutImagen(i2,j2,Irota2,BLENDING);
		}
		
		++it;
		++it_p;
		++cont;
		
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
	f>>Pses;
	//cout<<Pses;
	Imagen I;
	I.LeerImagen(argv[2]);
	
	//Leemos los aviones 
	Imagen avion;
	avion.LeerImagen(argv[5],argv[6]);
	
	Almacen_Rutas Ar;
	f.close();
	f.open (argv[4]);
	f>>Ar;
	cout<<"Las rutas: "<<endl<<Ar;
	cout<<"Dime el codigo de una ruta"<<endl;
	string a;
	cin>>a;
	Mostrar_Ruta(Pses, Ar,a);
	
	Ruta R=Ar.GetRuta(a);
	
	PintarV2(I,avion,R);
	
	Ruta::iterator it;
	Paises::iterator it_p;	
	for (it=R.begin(); it!=R.end(); ++it) {
		for (it_p=Pses.begin(); it_p!=Pses.end(); ++it_p) {
			if ((*it)==(*it_p).GetPunto()) {
				string d, filepath;
 				int j1=(I.num_cols()/360)*(180+(*it).GetLON());
 				int i1=(I.num_filas()/180)*(90-(*it).GetLAT());
				
				d = (*it_p).GetBandera();
				string dir=argv[3];
				filepath = dir + "/" + d;
				Imagen bandera;
				bandera.LeerImagen(filepath.c_str());
				I.PutImagen(i1,j1,bandera,BLENDING);
			}
		}	
	}
	
	I.EscribirImagen("salida.ppm");
}
