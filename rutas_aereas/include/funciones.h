/*
 * @author Patricia Cobos Rueda <pcobosrueda@correo.ugr.es>
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 */
#ifndef PRACTICAFINAL_FUNCIONES_H
#define PRACTICAFINAL_FUNCIONES_H

#include "imagen.h"
#include "Ruta.h"
#include "Paises.h"

/**
*@brief Método para extraer la columna de la imagen mapa según la longitud del mapa.
*@param mapa objeto del que extraer la información.
*@param longitud, número para calcular la columna de la imagen.
*@return int, columna de la imagen.
*/
int getColumna(Imagen &mapa, double longitud);

/**
*@brief Método para extraer la fila de la imagen mapa según la latitud del mapa.
*@param mapa objeto del que extraer la información.
*@param latitud, número para calcular la fila de la imagen.
*@return int, fila de la imagen.
*/
int getFila(Imagen &mapa, double latitud);

/**
*@brief Método para pintar una ruta sobre una imagen.
*@param ruta objeto a pintar.
*@param mapa objeto sobre el que se pinta.
*@param avion objeto con el icono que se pintará en la ruta.
*@param paises objeto con el conjunto de paises para calcular la ruta.
*@param rutabanderas ruta a la carpeta banderas que contiene todas las banderas del mundo.
*/
void PintarRuta(Ruta &ruta, Imagen &mapa, Imagen &avion, Paises &paises, const string &rutabanderas);


#endif //PRACTICAFINAL_FUNCIONES_H
