//
// Created by patriiciacoboss on 28/11/23.
//

#ifndef PRACTICAFINALED_PAISES_H
#define PRACTICAFINALED_PAISES_H


#include "Pais.h"
#include <set>
using namespace std;

class Paises{
private:
    set<Pais> datos;
public:
    Paises(){}
    void Insertar(const Pais &P);
    void Borrar(const Pais &P);

    class const_iterator;
    class iterator{
    private:
        set<Pais>::iterator p;
    public:
        friend class Paises;
        friend class const_iterator;

        iterator(){}
        bool operator != (Pais &pais);
        bool operator == (Pais &pais);
        iterator operator ++ ();
        iterator operator * ();
    };
    class const_iterator{
    private:
        set<Pais>::const_iterator p;
    public:
        const_iterator();
        bool operator != (Pais &pais);
        bool operator == (Pais &pais);
        const_iterator operator ++ ();
        const_iterator operator * () const;

        friend class Paises;

    };

    iterator begin();
    const_iterator begin()const;
    iterator end();
    const_iterator end()const;
    iterator find(const Pais &p);
    iterator find(const Punto &p);

    friend istream & operator>>(istream & is, Paises & R);
    friend ostream & operator<<(ostream & os, const Paises &R);
};



#endif //PRACTICAFINALED_PAISES_H
