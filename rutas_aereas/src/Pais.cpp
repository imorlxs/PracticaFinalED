//
// Created by patriiciacoboss on 27/11/23.
//

#include "Pais.h"
using namespace std;
#include "iostream"

Punto Pais::GetPunto()const {
    return p;
}
string Pais::GetPais()const{
    return pais;
}
string Pais::GetBandera()const{
    return bandera;
}

bool Pais::operator<(const Pais &P)const{
    return (this->p < P.GetPunto());
}
bool Pais::operator==(const Pais &P)const{
    return (this->p == P.GetPunto());
}

bool Pais::operator!=(const Pais &P)const{
    return (this->p != P.GetPunto());
}

istream & operator>>(istream & is, Pais & P){
    double lat,lng;

    is>>lat>>lng>>P.pais>>P.bandera;

    P.p=Punto(lat,lng,"");
    return is;
}
ostream & operator<<(ostream & os, const Pais &P){
    os<<P.p<<"\t"<<P.pais<<"\t"<<P.bandera;
    return os;
}
