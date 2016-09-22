#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <string>
#include <cmath>

enum Tipo_Pegado {OPACO, BLENDING};

using namespace std;

struct Pixel{
  unsigned char r,g,b;
  unsigned char transp; //0 no 255 si
};  
class Imagen{
  private:
    Pixel ** data;
    int nf,nc;
    void Borrar();	//V
    void Copiar(const Imagen &I);	//V

  public:
   Imagen();	//V
   
   Imagen(int f,int c);
   
   Imagen(const Imagen & I);	//V

   void CopiarPixel(int i, int j, const Pixel & p);
   
   Imagen & operator=(const Imagen & I);	//V
   
   ~Imagen();	//V
   
   //set y get
   Pixel & operator ()(int i,int j);	//V
   
   const Pixel & operator ()(int i,int j)const;
   
   void EscribirImagen(const char * nombre);
   
   void LeerImagen (const char *nombre,const string &nombremascara="datos/imagenes/aviones/mascara_avion1.pgm");
   void LimpiarTransp();	//F
   int num_filas()const{return nf;}
   int num_cols()const{return nc;}
   void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);
   Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);	//F
};

Imagen Rota(const Imagen & Io,double angulo);

#endif
