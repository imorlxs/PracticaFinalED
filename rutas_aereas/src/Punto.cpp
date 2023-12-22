/*
 * @author Patricia Cobos Rueda <pcobosrueda@correo.ugr.es>
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 */

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

string Punto::getDescription() const {
    return description;
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
    string basura;
    getline(is, basura, '('); // Extrae todo hasta el primer numero
    double numero;
    is >> numero; // Extrae la latitud, sin extraer la coma
    p.latitud = numero;
    getline(is, basura, ','); // Extrae todo hasta la coma
    is >> numero; // Extrae la longitud, sin extraer el ')'
    p.longitud = numero;
    getline(is, basura, ')'); // Extrae todo hasta el final
    return is;
}

ostream &operator<<(ostream &os, const Punto &p){
    os<< '(' << p.getLatitud()<<","<<p.getLongitud()<<')';

    return os;
}

