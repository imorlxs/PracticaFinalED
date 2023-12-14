//
// Created by patriiciacoboss on 27/11/23.
//

#include "../include/AlmacenRutas.h"
#include "AlmacenRutas.h"
#include "iostream"
#include "map"
using namespace std;

void AlmacenRutas::Insertar(const Ruta & r){
    rutas.insert(std::pair<string, Ruta>(r.GetCode(), r));
}

void AlmacenRutas::Borrar(const Ruta &r){
    bool encontrado = false;
    auto it = rutas.cbegin();

    for(it; it != rutas.end() && !encontrado; ++it){
        if (it->second == r) encontrado = true;
    }

    rutas.erase(it);
}
Ruta AlmacenRutas::getRuta(const string &a){
    auto it = rutas.find(a);
    if (it != rutas.end()) return it->second;
    return Ruta();
}

AlmacenRutas::iterator AlmacenRutas::begin(){
    iterator it;
    it.p = rutas.begin();
    return it;
}

AlmacenRutas::const_iterator AlmacenRutas::begin() const{
    const_iterator it;
    it.p = rutas.begin();
    return it;
}

AlmacenRutas::iterator AlmacenRutas::end(){
    iterator it;
    it.p = rutas.end();
    return it;
}
AlmacenRutas::const_iterator AlmacenRutas::end() const{
    const_iterator it;
    it.p = rutas.end();
    return it;
}

istream &operator>> (istream & is, AlmacenRutas &almacen) {
    if (is.peek() == '#') {
        string comment;
        getline(is, comment);  // Descartar la línea de comentario
    }

    Ruta ruta;
    while (is >> ruta) {
        almacen.Insertar(ruta);
    }

    return is;
}

ostream & operator << (ostream & os, const AlmacenRutas &almacen){
    for(auto it = almacen.rutas.begin(); it != almacen.rutas.end(); ++it){
        os << (*it).first<< "\t" << (*it).second;
    }
    return os;
}

//Funciones class iterator

bool AlmacenRutas::iterator::operator == (const Ruta &ruta){
    return (p->first==ruta.GetCode() && p->second == ruta);
}

bool AlmacenRutas::iterator::operator != (const Ruta &ruta){
    return (p->first!=ruta.GetCode() || p->second != ruta);
}

AlmacenRutas::iterator AlmacenRutas::iterator::operator ++(){
    ++p;
    return *this;
}
const AlmacenRutas::iterator AlmacenRutas::iterator::operator*(){
    return *this;
}

//Funciones class const_iterator

bool AlmacenRutas::const_iterator::operator == (const Ruta &ruta){
    return (p->first==ruta.GetCode() && p->second == ruta);
}
bool AlmacenRutas::const_iterator::operator!=(const Ruta &ruta){
    return (p->first!=ruta.GetCode() || p->second != ruta);
}
AlmacenRutas::const_iterator AlmacenRutas::const_iterator::operator ++(){
    ++p;
    return *this;
}
AlmacenRutas::const_iterator AlmacenRutas::const_iterator::operator *() const{
    return *this;
}

