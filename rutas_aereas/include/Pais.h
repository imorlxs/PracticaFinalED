//
// Created by patriiciacoboss on 27/11/23.
//

#ifndef PRACTICAFINALED_PAIS_H
#define PRACTICAFINALED_PAIS_H
using namespace std;
#include "string"

class Pais{
private:
    Punto p;
    string pais;
    string bandera;

public:
    Pais();
    Punto GetPunto()const;
    string GetPais()const;
    string GetBandera()const;

    bool operator<(const Pais &P)const;

    bool operator==(const Pais &P)const;

    bool operator==(const Punto &P)const;

    friend istream & operator>>(istream & is, Pais & P);

    friend ostream & operator<<(ostream & os, const Pais &P);
};


#endif //PRACTICAFINALED_PAIS_H
