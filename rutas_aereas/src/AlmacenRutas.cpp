//
// Created by patriiciacoboss on 27/11/23.
//

#include "../include/AlmacenRutas.h"
#include "AlmacenRutas.h"
using namespace std;

void AlmacenRutas::Insertar(const Ruta &r){}
void AlmacenRutas::Borrar(const Ruta &r){}
Ruta AlmacenRutas::getRuta(const string &a){}

bool AlmacenRutas::iterator::operator == (AlmacenRutas &almacen){}
bool AlmacenRutas::iterator::operator != (AlmacenRutas &almacen){}
AlmacenRutas::iterator AlmacenRutas::iterator::operator ++(){}
AlmacenRutas::iterator AlmacenRutas::iterator::operator *(){}

bool AlmacenRutas::const_iterator::operator == (AlmacenRutas &almacen){}
bool AlmacenRutas::const_iterator::operator != (AlmacenRutas &almacen){}
AlmacenRutas::const_iterator AlmacenRutas::const_iterator::operator ++(){}
AlmacenRutas::const_iterator AlmacenRutas::const_iterator::operator *(){}



AlmacenRutas::iterator AlmacenRutas::begin(){
    return rutas.begin();
}
AlmacenRutas::const_iterator AlmacenRutas::begin() const{
    rutas.cbegin(); //Por que puedo hacer esto
    return rutas.cbegin(); //y esto no
}
AlmacenRutas::iterator AlmacenRutas::end(){}
AlmacenRutas::const_iterator AlmacenRutas::end() const{}

istream & operator >> (istream & is, AlmacenRutas &almacen){}
ostream & operator << (ostream & is, const AlmacenRutas &almacen){}
