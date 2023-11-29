//
// Created by isaacm on 28/11/23.
//

#ifndef PRACTICAFINALED_IMAGEN_H
#define PRACTICAFINALED_IMAGEN_H
#include <string>
#include "imagenES.h"

using namespace std;


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
    void Borrar();
    void Copiar(const Imagen &I);
    void Initialize(int f = 0, int c = 0);
    void Allocate(int f, int c);

public:
    Imagen();

    Imagen(int f,int c);

    Imagen(const Imagen & I);

    Imagen & operator=(const Imagen & I);

    ~Imagen();

    //set y get
    Pixel & operator ()(int i,int j);

    const Pixel & operator ()(int i,int j)const;

    void EscribirImagen(const char * nombre);

    void LeerImagen (const char *nombre,const string &nombremascara="");
    void LimpiarTransp();
    int num_filas()const{return nf;}
    int num_cols()const{return nc;}
    void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);

    /**
     * @brief Crea a partir de una imagen otra igual o de menor tamaño
     * @param posi Fila de la coordenada superior izquierda de la nueva imagen respecto a la anterior
     * @param posj Columna de la coordenada superior izquierda de la nueva imagen respecto a la anterior
     * @param dimi Número de filas de la nueva imagen
     * @param dimj Número de columnas de la nueva imagen
     * @return Una nueva imagen
     * @post La imagen original no se modifica.
     */
    Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj) const;

    bool Empty() const;
};


#endif //PRACTICAFINALED_IMAGEN_H
