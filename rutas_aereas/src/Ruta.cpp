//
// Created by patriiciacoboss on 27/11/23.
//

#include "../include/Ruta.h"
#include "iostream"
#include "ostream"

Ruta::Ruta() {
    code = "";
}

void Ruta::Insertar(const Punto &n) {
    puntos.push_back(n);
}

void Ruta::Borrar(const Punto &n) {
    bool encontrado = false;
    for (auto it = puntos.begin(); it != puntos.end() && !encontrado; ++it) {
        if (*it == n) {
            encontrado = true;
            this->puntos.erase(it);
        }
    }

}

const string& Ruta::GetCode() const {
    return code;
}

void Ruta::SetCode(const string &code) {
    this->code = code;
}

bool Ruta::operator==(const Ruta &r) const {

    if (this->puntos.size() == r.puntos.size()) {

        auto it = this->puntos.begin();
        auto it_r = r.puntos.begin();

        bool igual = true;

        while (it != puntos.end() && igual) {
            if (*it != *it_r)
                igual = false;
            ++it;
            ++it_r;
        }

        return igual;
    }
    return false;
}

bool Ruta::operator<(const Ruta &r) const {
    return (this->puntos.size() < r.puntos.size());
}

//Funciones clase iterador
bool Ruta::iterator::operator==(const Ruta::iterator &otro) const{
    return p == otro.p;
}

bool Ruta::iterator::operator!=(const Ruta::iterator &otro) const{
    // Basado en el operador == por si cambia la representación
    return !(*this == otro);
}

Punto &Ruta::iterator::operator*() {
    return *p;
}

Ruta::iterator &Ruta::iterator::operator++() {
    ++p;
    return *this;
}

//Funciones clase const_iterator
bool Ruta::const_iterator::operator==(const Ruta::const_iterator &otro) const{
    return p == otro.p;
}

bool Ruta::const_iterator::operator!=(const Ruta::const_iterator &otro) const{
    return !(*this == otro);
}

const Punto &Ruta::const_iterator::operator*() const {
    return *p;
}

Ruta::const_iterator Ruta::const_iterator::operator++() {
    ++p;
    return *this;
}

//Funciones clase Ruta
Ruta::iterator Ruta::begin() {
    iterator it;
    it.p = puntos.begin();
    return it;
}

Ruta::const_iterator Ruta::cbegin() const {
    const_iterator it;
    it.p = puntos.cbegin();
    return it;
}

Ruta::iterator Ruta::end() {
    iterator it;
    it.p = puntos.end();
    return it;
}

Ruta::const_iterator Ruta::cend() const {
    const_iterator it;
    it.p = puntos.cend();
    return it;
}

Ruta::iterator Ruta::find(const Punto &p) {
    Ruta::iterator it;
    for (auto aux = puntos.begin(); aux != puntos.end() && ((*aux) != p); ++it)
        it.p = aux;
    return it;
}

istream &operator>>(istream &is, Ruta &r) {
    Punto puntos;
    while (is >> puntos) {
        r.Insertar(puntos);
    }

    return is;
}

ostream &operator<<(ostream &os, const Ruta &r) {
    for (auto it = r.cbegin(); it != r.cend(); ++it) {
        os << *it << "\t";
    }
    return os;
}