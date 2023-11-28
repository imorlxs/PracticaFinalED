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
    this->code = code;
}

bool Ruta::operator == (const Ruta &r) const;

bool operator < (const Ruta &r) const;


Ruta::iterator::iterator() {}
bool Ruta::iterator::operator == (const iterator &it){

}
bool Ruta::iterator::operator != (const iterator &it){
    return (this->p != it);
}
bool Ruta::iterator::operator ++ (const iterator &it){
    ++p;
    return (*this);
}
bool Ruta::iterator::operator * (const iterator &it){}

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
    return puntos.cend();
}

Ruta::iterator Ruta::find(const Punto &p){
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