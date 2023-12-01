//
// Created by patriiciacoboss on 28/11/23.
//

#include "../include/Paises.h"
#include "istream"
#include "ostream"
using namespace std;

void Paises::Insertar(const Pais &P){
    datos.insert(P);
}

void Paises::Borrar(const Pais &P){
    if (this->datos.find(P) != this->datos.end())
        datos.erase(P);
}

Paises::iterator Paises::begin(){
    iterator it;
    it.p = datos.begin();
    return it;
}

Paises::const_iterator Paises::begin()const{
    const_iterator it;
    it.p = datos.cbegin();
    return it;
}

Paises::iterator Paises::end(){
    iterator it;
    it.p = datos.end();
    return it;
}

Paises::const_iterator Paises::end()const{
    const_iterator it;
    it.p = datos.cend();
    return it;
}

Paises::iterator Paises::find(const Pais &p){
    iterator it;
    set<Pais>::iterator i;
    for (i=datos.begin(); i != datos.end() && !((*i)==p);++i);
    it.p=i;
    return it;
}

Paises::iterator Paises::find(const Punto &punto){
    iterator it;
    set<Pais>::iterator i;
    for(i = datos.begin(); i != datos.end() && !(i->GetPunto() == punto); ++i);
    it.p = i;
    return it;
}

istream & operator>>(istream & is, Paises & R){
    Paises rlocal;
    //leemos el comentario
    if (is.peek()=='#'){
        string a;
        getline(is,a);
    }

    Pais P;
    while (is>>P){
        rlocal.Insertar(P);
    }
    R=rlocal;
    return is;
}

ostream & operator<<(ostream & os, const Paises &R){

    Paises::const_iterator it;
    for (it = R.begin(); it != R.end(); ++it){
        os << *it << "\t";
    }
    return os;
}


//Class iterator
bool Paises::iterator::operator != (Pais &pais){
    return (*p != pais);
}

bool Paises::iterator::operator == (Pais &pais){
    return (*p == pais);
}

Paises::iterator Paises::iterator::operator ++ (){
    ++p;
    return *this;
}

Paises::iterator Paises::iterator::operator* (){
    return *this;
    //No entiendo por que da error si pongo return *p
}

//Class const_iterator
bool Paises::const_iterator::operator != (Pais &pais){
    return (*p != pais);
}

bool Paises::const_iterator::operator == (Pais &pais){
    return (*p == pais);
}

Paises::const_iterator Paises::const_iterator::operator ++ (){
    ++p;
    return *this;
}

Paises::const_iterator Paises::const_iterator::operator* () const{
    return *this;
}