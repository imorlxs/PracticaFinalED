
/** 
 * @file ruta_aerea.cpp
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 * @author Patricia Cobos Rueda  <pcobosrueda@correo.ugr.es>
 */

#include <iostream>
#include <fstream>
#include "imagen.h"
#include "AlmacenRutas.h"
#include "Paises.h"
#include "Ruta.h"
#include "Pais.h"
#include "Punto.h"

using namespace std;

int getColumna(Imagen &mapa, double longitud) {
    int totalcolumnas = mapa.num_cols();
    int columna = (totalcolumnas / 360.0) * (180 + longitud);
    return columna;
}

int getFila(Imagen &mapa, double latitud) {
    int totalfilas = mapa.num_filas();
    int fila = (totalfilas / 180.0) * (90 - latitud);
    return fila;
}

void PintarRuta(Ruta &ruta, Imagen &mapa, Imagen &avion, Paises &paises) {
    // 1. Por cada par de puntos p1 y el siguiente p2 de la ruta
    for (Ruta::iterator it = ruta.begin(); it != ruta.end(); ++it) {
        auto it2 = it;
        ++it2;
        if (it2 != ruta.end()) {
            // 1. Buscar el país c1 que se corresponde con el punto p1
            auto c1 = paises.find(*it);

            // 2. Buscar el país c2 que se corresponde con el punto p2
            auto c2 = paises.find(*it2);

            // 3. Leer la imagen de la bandera del país c1
            Imagen imagenc1;
            imagenc1.LeerImagen((*c1).GetBandera().c_str());

            // 4. Leer la imagen de la bandera del país c2
            Imagen imagenc2;
            imagenc2.LeerImagen((*c2).GetBandera().c_str());

            // 5. Obtener la posición en el mapa de p1 sea pos1_mapa
            int fil1_mapa = getFila(mapa, (*it).getLatitud());
            int col1_mapa = getColumna(mapa, (*it).getLongitud());

            // 6. Obtener la posición el el mapa del p2 sea pos2_mapa
            int fil2_mapa = getFila(mapa, (*it2).getLatitud());
            int col2_mapa = getColumna(mapa, (*it2).getLongitud());

            // 7. Pegar el avión en el mapa en las posiciones pos1_mapa, pos2_mapa y punto medio de pos1_mapa,
            // pos2_mapa. Antes de pegar rotar el avión según la línea que une pos1_mapa, pos2_mapa.
            Pintar(fil1_mapa, fil2_mapa, col1_mapa, col2_mapa, mapa, avion, 10, 10);

            // 8. Pegar la bandera del país c1 en pos1_mapa
            mapa.PutImagen(fil1_mapa, col1_mapa, imagenc1, OPACO);

            // 9. 9. Pegar la bandera del país c2 en pos2_mapa
            mapa.PutImagen(fil2_mapa, col2_mapa, imagenc2, OPACO);


        }
    }
}

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
    f >> Pses;
    // 1. Leer Imagen del mapa
    Imagen mapa, avion;
    mapa.LeerImagen(argv[2]);

    // 2. Leer imagen del avión y su máscara
    avion.LeerImagen(argv[5], argv[6]);
    AlmacenRutas Ar;

    // 3. Leer el conjunto de rutas (se carga en un almacen de rutas)
    AlmacenRutas almacen;
    f.close();
    f.open(argv[4]);
    f >> almacen;
    // 4. Mostrar las rutas y pedirle al usuario que escoja una (pedir un
    //código)
    cout << almacen << endl;
    cout << "Escoga una de las siguientes rutas (introduzca el ID)" << endl;
    string id;
    cin >> id;



    // 5. Pintar el recorrido de la ruta en el mapa pintando las banderas de
    // los países por donde pasa y un avión. Entre dos países se pinta el
    // avión al principio, final y en el punto medio.
    Ruta ruta = Ar.getRuta(id);
    PintarRuta(ruta, mapa, avion, Pses);

}