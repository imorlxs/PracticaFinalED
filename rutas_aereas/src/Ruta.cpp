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
    if (find(n) >= 0 && find(n) < puntos.size()){
        int pos = find(n);
        puntos.erase(pos);
    }

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
    return puntos.begin();
}
const_iterator Ruta::begin() const{
    return puntos.cbegin();
}

iterator Ruta::end(){
    return puntos.end();
}
const_iterator Ruta::end() const{
    return puntos.cend();
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

friend istream &operator >>(istream &is, Ruta &r);
friend ostream &operator <<(ostream &os, Ruta &r);