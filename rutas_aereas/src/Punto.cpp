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
    return (this->latitud != p.getLatitud() || (this->latitud == p.getLatitud() && this->longitud != p.getLongitud()));
}

istream &operator >>(istream &is, Punto &p){
    double lat,lng;

    is>>lat>>lng;
    Punto punto;
    punto.setLatitud(lat);
    punto.setLongitud(lng);

    return is;
}

ostream &operator<<(ostream &os, Punto &p){
    os<<p.getLatitud()<<" "<<p.getLongitud()<<endl;

    return os;
}

