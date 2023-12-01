//
// Created by patriiciacoboss on 27/11/23.
//

#include "../include/AlmacenRutas.h"
#include "AlmacenRutas.h"

using namespace std;

void AlmacenRutas::Insertar(const Ruta & r){
    bool insertado = false;
    auto it = rutas.cbegin();
                                                            //AL INSERTAR UNA RUTA QUE STRING SE PONE???
    for(it; it != rutas.end() && !insertado; ++it){
        if (it->first == ""){
            rutas.insert(r);
            insertado = true;
        }
    }
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

bool AlmacenRutas::iterator::operator == (AlmacenRutas &almacen){}
bool AlmacenRutas::iterator::operator != (AlmacenRutas &almacen){}
AlmacenRutas::iterator AlmacenRutas::iterator::operator ++(){}
AlmacenRutas::iterator AlmacenRutas::iterator::operator *(){}

bool AlmacenRutas::const_iterator::operator == (AlmacenRutas &almacen){}
bool AlmacenRutas::const_iterator::operator != (AlmacenRutas &almacen){}
AlmacenRutas::const_iterator AlmacenRutas::const_iterator::operator ++(){}
AlmacenRutas::const_iterator AlmacenRutas::const_iterator::operator *(){}



AlmacenRutas::iterator AlmacenRutas::begin(){}

AlmacenRutas::const_iterator AlmacenRutas::begin() const{
    rutas.cbegin(); //Por que puedo hacer esto
    return rutas.cbegin(); //y esto no
}

AlmacenRutas::iterator AlmacenRutas::end(){}
AlmacenRutas::const_iterator AlmacenRutas::end() const{}

istream & operator >> (istream & is, AlmacenRutas &almacen){}
ostream & operator << (ostream & is, const AlmacenRutas &almacen){}
