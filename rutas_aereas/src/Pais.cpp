//
// Created by patriiciacoboss on 27/11/23.
//

#include "Pais.h"

Punto Pais::GetPunto()const {
    return p;
}
string Pais::GetPais()const{
    return pais;
}
string Pais::GetBandera()const{
    return bandera;
}

bool operator<(const Pais &P)const{
    ..............
}
bool operator==(const Pais &P)const{
    ..................
}
bool operator==(const Punto &P)const{
    ..................
}
friend istream & operator>>(istream & is, Pais & P){
    double lat,lng;

    is>>lat>>lng>>P.pais>>P.bandera;

    P.p=Punto(lat,lng,"");
    return is;
}
friend ostream & operator<<(ostream & os, const Pais &P){
    os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
    return os;
}
