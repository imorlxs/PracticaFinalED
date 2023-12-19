//
// Created by isaacm on 14/12/23.
//

#include "funciones.h"


int getColumna(Imagen &mapa, double longitud) {
    int totalcolumnas = mapa.num_cols();
    int columna = (totalcolumnas / 360.0) * (180 + longitud);
    return columna;
}

int getFila(Imagen &mapa, double latitud) {
    int totalfilas = mapa.num_filas();
    double fila = (totalfilas / 180.0) * (90 - latitud);
    return fila;
}

void PintarRuta(Ruta &ruta, Imagen &mapa, Imagen &avion, Paises &paises, const string &rutabanderas) {
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
            imagenc1.LeerImagen((rutabanderas + (*c1).GetBandera()).c_str());

            // 4. Leer la imagen de la bandera del país c2
            Imagen imagenc2;
            imagenc2.LeerImagen((rutabanderas + (*c2).GetBandera()).c_str());

            // 5. Obtener la posición en el mapa de p1 sea pos1_mapa
            int fil1_mapa = getFila(mapa, (*it).getLatitud());
            int col1_mapa = getColumna(mapa, (*it).getLongitud());

            // 6. Obtener la posición el el mapa del p2 sea pos2_mapa
            int fil2_mapa = getFila(mapa, (*it2).getLatitud());
            int col2_mapa = getColumna(mapa, (*it2).getLongitud());

            // 7. Pegar el avión en el mapa en las posiciones pos1_mapa, pos2_mapa y punto medio de pos1_mapa,
            // pos2_mapa. Antes de pegar rotar el avión según la línea que une pos1_mapa, pos2_mapa.
            Pintar(fil1_mapa, fil2_mapa, col1_mapa, col2_mapa, mapa, avion, 0, 0);

            // 8. Pegar la bandera del país c1 en pos1_mapa
            // Centrar la imagen respecto a la bandera 1
            fil1_mapa -= imagenc1.num_filas() / 2;
            col1_mapa -= imagenc1.num_cols() / 2;

            mapa.PutImagen(fil1_mapa, col1_mapa, imagenc1, BLENDING);

            // 9. 9. Pegar la bandera del país c2 en pos2_mapa
            // Centrar la imagen respecto a la bandera 2
            fil2_mapa -= imagenc2.num_filas() / 2;
            col2_mapa -= imagenc2.num_cols() / 2;
            mapa.PutImagen(fil2_mapa, col2_mapa, imagenc2, BLENDING);


        }
    }
}
