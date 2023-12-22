/*
 * @author Patricia Cobos Rueda <pcobosrueda@correo.ugr.es>
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 */

#include "imagen.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char * argv[]){

    Imagen I;

    I.LeerImagen(argv[1]);

    I.EscribirImagen("prueba.ppm");
}
