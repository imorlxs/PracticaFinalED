//
// Created by patriiciacoboss on 27/11/23.
//

#include "../include/Punto.h"
using namespace std;



Punto::double getLatitud() const{
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
    return (this.latitud < p.getLatitud() || (this.latitud == p.getLatitud() && this.longitud < p.getLongitud()));
}

bool Punto::operator==(const Punto &p) const {
    return (this.latitud == p.getLatitud() && longitud == p.getLongitud());
}

friend istream &operator >>(istream &is, Punto &p){
    double lat,lng;

    is>>lat>>lng;
    p=Punto(lat,lng,"");

    return is;
}

friend ostream &operator <<(ostream &os, Punto &p){
    os<<p.latitud<<" "<<p.longitud<<endl;

    return os;
}

