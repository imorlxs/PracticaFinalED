//
// Created by isaacm on 14/12/23.
//

#ifndef PRACTICAFINAL_FUNCIONES_H
#define PRACTICAFINAL_FUNCIONES_H

#include "imagen.h"
#include "Ruta.h"
#include "Paises.h"

int getColumna(Imagen &mapa, double longitud);

int getFila(Imagen &mapa, double latitud);

void PintarRuta(Ruta &ruta, Imagen &mapa, Imagen &avion, Paises &paises);


#endif //PRACTICAFINAL_FUNCIONES_H
