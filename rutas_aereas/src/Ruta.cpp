//
// Created by patriiciacoboss on 27/11/23.
//

#include "../include/Ruta.h"
#include "iostream"
#include "ostream"

Ruta::Ruta(){
    for(auto it=puntos.begin(); it < !puntos.end(); ++it) *it = Punto();
    code = "";
}

void Ruta::Insertar(const Punto &n){
    puntos.push_back(n);
}

void Ruta::Borrar(const Punto &n){
    Ruta::iterator it = find(n);
    if (it != puntos.end())
        puntos.erase(it);
}


string Ruta::GetCode() const{
    return code;
}

void Ruta::SetCode( const string &code){
    this->code = code;
}

bool Ruta::operator == (const Ruta &r) const{
    if(this->puntos.size() == r.puntos.size()){
        list<Punto>::iterator it = this->puntos.begin();
        list<Punto>::iterator it_r = r.puntos.begin();
        bool iguales = true;
        while ((it != puntos.end()) && !iguales){
            if (*it != *it_r) iguales = false;
            ++it;
            ++it_r;
        }
        return iguales;
    }
    return false;
}

bool Ruta::operator < (const Ruta &r) const{
    return (this->puntos.size() < r.puntos.size());
}
//Funciones clase iterador
Ruta::iterator::iterator() {}

bool Ruta::iterator::operator== (const Punto &punto){
    return (*p == punto);
}
bool Ruta::iterator::operator!=(const Punto &punto){
    return (*p != punto);
}

Punto Ruta::iterator::operator*(){
    return *p;
}

Ruta::iterator Ruta::iterator::operator++() {
    ++p;
    return *this;
}

//Funciones clase const_iterator
Ruta::const_iterator::const_iterator() {}

bool Ruta::const_iterator::operator== (const Punto &punto){
    return (this->p == p);
}
bool Ruta::const_iterator::operator!=(const Punto &punto){
    return (this->p != p);
}

Punto Ruta::const_iterator::operator*() const{
    return *p;
}

Ruta::const_iterator Ruta::const_iterator::operator++() {
    ++p;
    return *this;
}

//Funciones clase Ruta
Ruta::iterator Ruta::begin(){
    Ruta::iterator it = puntos.begin();
    return it;
}

Ruta::const_iterator Ruta::begin()const{
    Ruta::const_iterator it = puntos.cbegin();
    return it;
}

Ruta::iterator Ruta::end(){
    Ruta::iterator it = puntos.end();
    return it;
}

Ruta::const_iterator Ruta::end()const{
    Ruta::const_iterator it = puntos.cend();
    return it;
}

Ruta::iterator Ruta::find(const Punto &p){
    for (auto it = puntos.begin(); it != puntos.end(); ++it){
        if (*it == p) return it;
    }
    return puntos.end();
}

istream &operator >>(istream &is, Ruta &r){
    Ruta ruta;

    if (is.peek()=='#'){
        string a;
        getline(is,a);
    }

    Punto puntos;
    while (is >> puntos){
        ruta.Insertar(puntos);
    }
    r=ruta;
    return is;
}

ostream &operator <<(ostream &os, Ruta &r){

    Ruta::iterator it;
    for (it = r.begin(); it != r.end(); ++it){
        os<< *it <<"\t";
    }
    return os;
}