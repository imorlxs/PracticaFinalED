//
// Created by patriiciacoboss on 28/11/23.
//

#include <iostream>
#include "../include/Paises.h"
#include "istream"
#include "ostream"

using namespace std;

void Paises::Insertar(const Pais &P) {
    datos.insert(P);
}

void Paises::Borrar(const Pais &P) {
    if (this->datos.find(P) != this->datos.end())
        datos.erase(P);
}

Paises::iterator Paises::begin() {
    iterator it;
    it.p = datos.begin();
    return it;
}

Paises::const_iterator Paises::cbegin() const {
    const_iterator it;
    it.p = datos.cbegin();
    return it;
}

Paises::iterator Paises::end() {
    iterator it;
    it.p = datos.end();
    return it;
}

Paises::const_iterator Paises::cend() const {
    const_iterator it;
    it.p = datos.cend();
    return it;
}

Paises::iterator Paises::find(const Pais &p) {
    iterator it;
    set<Pais>::iterator i;
    for (i = datos.begin(); i != datos.end() && ((*i) != p); ++i)
        it.p = i;
    return it;
}

Paises::iterator Paises::find(const Punto &punto) {
    iterator it;
    set<Pais>::iterator i;
    bool encontrado = false;
    for (i = datos.begin(); i != datos.end() && !encontrado; ++i){
        encontrado = (*i).GetPunto() == punto;
        it.p = i;
    }

    return it;
}

istream &operator>>(istream &is, Paises &R) {
    //leemos el comentario
    if (is.peek() == '#') {
        string a;
        getline(is, a);
    }

    Pais P;
    while (is >> P) {
        R.Insertar(P);
    }
    return is;
}

ostream &operator<<(ostream &os, const Paises &R) {
    for (auto it = R.cbegin(); it != R.cend(); ++it) {
        os << *it << "\t";
    }
    return os;
}


//Class iterator
bool Paises::iterator::operator==(Paises::iterator otro) const {
    return (p == otro.p);
}

bool Paises::iterator::operator!=(Paises::iterator otro) const {
    return !(*this == otro);
}

Paises::iterator Paises::iterator::operator++() {
    ++p;
    return *this;
}

 const Pais& Paises::iterator::operator*(){
    return *p;
}

//Class const_iterator
bool Paises::const_iterator::operator==(Paises::const_iterator otro) const {
    return (p != otro.p);
}

bool Paises::const_iterator::operator!=(Paises::const_iterator otro) const {
    return !(*this == otro);
}

Paises::const_iterator Paises::const_iterator::operator++() {
    ++p;
    return *this;
}

const Pais& Paises::const_iterator::operator*() const {
    return *p;
}