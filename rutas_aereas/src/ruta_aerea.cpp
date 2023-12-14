
/** 
 * @file ruta_aerea.cpp
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 * @author Patricia Cobos Rueda  <pcobosrueda@correo.ugr.es>
 */

#include <iostream>
#include <fstream>
#include "imagen.h"
#include "AlmacenRutas.h"
#include "funciones.h"
#include "Paises.h"

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

    Paises Pses;
    ifstream f(argv[1]);
    if (f) {
        f >> Pses;

    } else
        throw std::ios_base::failure(string("error_de_apertura_del_fichero\n"));

    cout << Pses;
    // 1. Leer Imagen del mapa
    Imagen mapa;
    Imagen avion;
    mapa.LeerImagen(argv[2]);

    // 2. Leer imagen del avión y su máscara
    avion.LeerImagen(argv[5], argv[6]);

    // 3. Leer el conjunto de rutas (se carga en un almacen de rutas)
    AlmacenRutas almacen;
    f.close();
    f.open(argv[4]);
    f >> almacen;
    // 4. Mostrar las rutas y pedirle al usuario que escoja una (pedir un
    //código)
    cout << almacen << endl;
    cout << "Escoja una de las siguientes rutas (introduzca el ID)" << endl;
    string id;

    cin >> id;

    // 5. Pintar el recorrido de la ruta en el mapa pintando las banderas de
    // los países por donde pasa y un avión. Entre dos países se pinta el
    // avión al principio, final y en el punto medio.
    Ruta ruta = almacen.getRuta(id);

    cout << "Has seleccionado los paises: "  << endl;
    for (auto it = ruta.begin(); it != ruta.end(); ++it){
        cout << (*Pses.find(*it)).GetPais() << " ";
    }
    PintarRuta(ruta, mapa, avion, Pses, argv[3]);

    mapa.EscribirImagen(argv[2]);

}