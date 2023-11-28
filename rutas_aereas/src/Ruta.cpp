//
// Created by patriiciacoboss on 27/11/23.
//

#include "../include/Ruta.h"

Ruta::Ruta(){
    for(auto it=puntos.begin(); it < !puntos.end(); ++it) *it = Punto();
    code = "";
}

void Ruta::Insertar(const Punto &n){
    puntos.push_back(n);
}

void Ruta::Borrar(const Punto &n){
    if (find(n) != puntos.end())
        puntos.erase(n);
}


string Ruta::GetCode() const{
    return code;
}

void Ruta::SetCode( const string &code){
    this.code = code;
}

bool Ruta::operator == (const Ruta &r) const;

bool operator < (const Ruta &r) const;


class iterator{
private:
    list<Punto>::iterator  p;
public:
    //....................
};
class const_iterator{
private:
    list<Punto>::const_iterator p;
public:
    //....................
};

iterator Ruta::begin(){
    iterator it;
    it.p = datos.begin();
    return it;
}

const_iterator Ruta::begin()const{
    const_iterator it;
    it.p = datos.cbegin();
    return it;
}
iterator Ruta::end(){
    iterator it;
    it.p = datos.end();
    return it;
}
const_iterator Ruta::end()const{
    const_iterator it;
    it.p = datos.cend();
    return it;
}

iterator Ruta::find(const Punto &p){
    int pos;
    bool encontrado = false;

    for(auto it=puntos.begin(); it < !puntos.end() && !encontrado; ++it) {
        if (*it == p){
            encontrado = true;
            pos = it;
        }
    }

    return pos;
}

friend istream &operator >>(istream &is, Ruta &r){
    Ruta ruta;
    //leemos el comentario
    if (is.peek()=='#'){
        string a;
        getline(is,a);
    }

    Punto puntos;
    while (is>>puntos){
        ruta.Insertar(P);
    }
    r=ruta;
    return is;
}

friend ostream &operator <<(ostream &os, Ruta &r){
    Ruta::const_iterator it;
    for (it=r.begin(); it!=r.end(); ++it){
        os<<*it<<"\t";
    }
    return os;
}