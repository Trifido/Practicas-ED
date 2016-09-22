#ifndef _IMAGEN_H
#define _IMAGEN_H

#include <string>
using namespace std;

struct Pixel{
  unsigned char r,g,b;
  unsigned char transp; //0 no 255 si
}; 

enum Tipo_Pegado {OPACO, BLENDING};

class Imagen{
  private:
    Pixel ** data;
    int nf,nc;
    void Borrar();
    void Copiar(const Imagen &I);

  public:
   Imagen() { nf=0; nc=0; }
   
   Imagen(int f,int c);
   
   Imagen(const Imagen & I);
   
   Imagen & operator=(const Imagen & I);
   
   ~Imagen() {}
  
   Pixel & operator ()(int i,int j);
   
   const Pixel & operator ()(int i,int j)const;
   
   void EscribirImagen(const char * nombre);
   
   void LeerImagen (const char *nombre,const string &nombremascara="");
   int num_filas()const{return nf;}
   int num_cols()const{return nc;}
   void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);
};   

#endif