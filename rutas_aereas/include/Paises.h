//
// Created by patriiciacoboss on 28/11/23.
//

#ifndef PRACTICAFINALED_PAISES_H
#define PRACTICAFINALED_PAISES_H


#include "Pais.h"
#include <set>

using namespace std;

class Paises {
private:
    set<Pais> datos;
public:
    Paises() {}

    void Insertar(const Pais &P);

    void Borrar(const Pais &P);

    class iterator {
    private:
        set<Pais>::iterator p;
    public:
        friend class Paises;

        iterator() {}

        bool operator!=(Paises::iterator otro) const;

        bool operator==(Paises::iterator otro) const;

        iterator operator++();

        const Pais& operator*();
    };

    class const_iterator {
    private:
        set<Pais>::const_iterator p;
    public:
        const_iterator();

        bool operator!=(Paises::const_iterator otro) const;

        bool operator==(Paises::const_iterator otro) const;

        const_iterator operator++();

        const Pais& operator*() const;

        friend class Paises;

    };

    iterator begin();

    const_iterator cbegin() const;

    iterator end();

    const_iterator cend() const;

    iterator find(const Pais &p);

    iterator find(const Punto &p);

    friend istream &operator>>(istream &is, Paises &R);

    friend ostream &operator<<(ostream &os, const Paises &R);
};


#endif //PRACTICAFINALED_PAISES_H
