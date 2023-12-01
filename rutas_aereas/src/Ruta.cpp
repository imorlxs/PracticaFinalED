//
// Created by patriiciacoboss on 27/11/23.
//

#include "../include/Ruta.h"
#include "iostream"
#include "ostream"

Ruta::Ruta(){
    for(auto it=puntos.begin(); it != puntos.end(); ++it) *it = Punto();
    code = "";
}

void Ruta::Insertar(const Punto &n){
    puntos.push_back(n);
}

void Ruta::Borrar(const Punto &n){
    bool encontrado = false;
    for(auto it = puntos.begin(); it != puntos.end() && !encontrado; ++it){
        if (*it == n){
            encontrado = true;
            this->puntos.erase(it);
        }
    }

}

string Ruta::GetCode() const{
    return code;
}

void Ruta::SetCode( const string &code){
    this->code = code;
}

bool Ruta::operator == (const Ruta &r) const{
    if(this->puntos.size() == r.puntos.size() && this->code == r.code ){

        auto it = this->puntos.begin();
        auto it_r = r.puntos.begin();

        bool igual = true;

        while(it != puntos.end() && igual){
            if (*it != *it_r) igual = false;
            ++it;
            ++it_r;
        }

        return igual;
    }
    return false;
}

bool Ruta::operator < (const Ruta &r) const{
    return (this->puntos.size() < r.puntos.size());
}
//Funciones clase iterador
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
bool Ruta::const_iterator::operator== (const Punto &punto){
    return (*p == punto);
}
bool Ruta::const_iterator::operator!=(const Punto &punto){
    return (*p != punto);
}

Punto Ruta::const_iterator::operator*() const{
    return *p;
}

Ruta::const_iterator Ruta::const_iterator::operator ++() {
    ++p;
    return *this;
}

//Funciones clase Ruta
Ruta::iterator Ruta::begin(){
    iterator it;
    it.p = puntos.begin();
    return it;
}

Ruta::const_iterator Ruta::begin()const{
    const_iterator it;
    it.p = puntos.cbegin();
    return it;
}

Ruta::iterator Ruta::end(){
    iterator it;
    it.p = puntos.end();
    return it;
}

Ruta::const_iterator Ruta::end()const{
    const_iterator it;
    it.p = puntos.cend();
    return it;
}

Ruta::iterator Ruta::find(const Punto &p){
    iterator it;
    list<Punto>::iterator aux;
    for (aux = puntos.begin(); aux != puntos.end() && !((*aux) ==p); ++it);
    it.p = aux;
    return it;
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

ostream &operator <<(ostream &os, const Ruta &r){
    for (auto it = r.begin(); it != r.end(); ++it){
        os<< *it <<"\t";
    }
    return os;
}