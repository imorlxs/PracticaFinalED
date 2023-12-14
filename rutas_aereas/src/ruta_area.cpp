
/** 
 * @file ruta_aerea.cpp
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 * @author Patricia Cobos Rueda  <pcobosrueda@correo.ugr.es>
 */


#include <fstream>
#include "imagen.h"
#include "AlmacenRutas.h"

using namespace std;

/**
 * Muestra ayuda sobre el uso de este programa en el output stream dado
 * @param outputStream El output stream donde la ayuda será mostrada (p.e. cout, cerr, etc)
 */
void mostrarError(ostream &outputStream) {
    outputStream << "Error, ejecutar con los siguientes parámetros:" << endl;
    outputStream << "ruta_aerea paises.txt mapa.ppm dir_banderas almacen_rutas.txt avion.ppm mascara_avion.pgm" << endl;
    outputStream
            << "          Obtiene un mapa del mundo sobre el que se ha pintado una ruta elegida"
            << endl;
    outputStream << endl;
}

/**
 * Este programa obtiene un mapa del mundo sobre el que se ha pintado una ruta elegida. Para
 * tal objetivo el usuario insertará un fichero con un conjunto de países y un almacén de rutas y una
 * imagen de un mapa del mundo junto con la imagen del avión y su máscara.
 * Ejemplo de uso:
 *  > ruta_aerea paises.txt mapa.ppm dir_banderas almacen_rutas.txt avion.ppm mascara_avion.pgm
 * @param argc El número de parámetros por consola
 * @param argv El vector de los parámetros por consola (cstrings)
 * @return 0 Si no hay error; un valor > 0 si lo hay
 */
int main(int argc, char *argv[]) {
    if (argc != 7) {
        mostrarError(cerr);
        exit(EXIT_FAILURE);
    }

    /*
     *  Subtareas a realizar.-
1. Leer Imagen del mapa
2. Leer imagen del avión y su máscara
3. Leer el conjunto de rutas (se carga en un almacen de rutas)
4. Mostrar las rutas y pedirle al usuario que escoja una (pedir un
código)
5. Pintar el recorrido de la ruta en el mapa pintando las banderas de
los países por donde pasa y un avión. Entre dos países se pinta el
avión al principio, final y en el punto medio.
     */

    Imagen mapa, avion, mascara;
    mapa.LeerImagen(argv[2]);
    avion.LeerImagen(argv[5]);
    mascara.LeerImagen(argv[6]);

    AlmacenRutas almacen;

}