//
// Created by patriiciacoboss on 27/11/23.
//

#include "../include/Punto.h"
using namespace std;

Punto::Punto() : Punto(0, 0) {}

Punto::Punto(float lat, float lon){
    latitud = lat;
    longitud = lon;
}

Punto::float getLatitud() const{
    return latitud;
}

void Punto::setLatitud(int lat){
    latitud = lat;
}

float Punto::getLongitud() const{
    return longitud;
}

void Punto::setLongitud(int lon){
    longitud = lon;
}

Punto::pair<float, float> getPunto() const{
    return make_pair(latitud, longitud);
}

string Punto::toString(){
    return latitud + " , " + longitud;
}


