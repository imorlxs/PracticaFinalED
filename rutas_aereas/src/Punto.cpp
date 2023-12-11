//
// Created by patriiciacoboss on 27/11/23.
//

#include "../include/Punto.h"
using namespace std;
#include "iostream"

double Punto::getLatitud() const{
    return latitud;
}

void Punto::setLatitud(double lat){
    latitud = lat;
}

double Punto::getLongitud() const{
    return longitud;
}

void Punto::setLongitud(double lon){
    longitud = lon;
}

bool Punto::operator<(const Punto &p) const {
    return (this->latitud < p.getLatitud() || (this->latitud == p.getLatitud() && this->longitud < p.getLongitud()));
}

bool Punto::operator==(const Punto &p) const {
    return (this->latitud == p.getLatitud() && this->longitud == p.getLongitud());
}

bool Punto::operator != (const Punto &p) const {
    return !(*this == p);
}

istream &operator >>(istream &is, Punto &p){
    is.get(); // Extrae el '('
    string numero;
    getline(is, numero, ','); // Extrae la latitud, sin extraer la coma
    p.latitud = stof(numero);

    getline(is, numero, ','); // Extrae la longitud, sin extraer el ')'
    p.longitud = stof(numero);

    return is;
}

ostream &operator<<(ostream &os, Punto &p){
    os<< '(' << p.getLatitud()<<","<<p.getLongitud()<<')';

    return os;
}

