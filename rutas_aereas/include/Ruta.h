//
// Created by patriiciacoboss on 27/11/23.
//

#ifndef PRACTICAFINALED_RUTA_H
#define PRACTICAFINALED_RUTA_H

#include "string"
#include "list"
#include "Punto.h"

class Ruta {
private:
    list<Punto> puntos;
    string code;

public:
    Ruta();
    void Insertar(const Punto &n);
    void Borrar(const Punto &n);
    string GetCode() const;

    void SetCode( const string &code);
    bool operator == (const Ruta &r) const;
    bool operator < (const Ruta &r) const;

    class iterator{
    private:
        list<Punto>::iterator  p;
    public:
        iterator();
        bool operator == (const Punto &punto);
        bool operator != (const Punto &punto);
        iterator operator ++ ();
        Punto operator * ();

    };
    class const_iterator{
    private:
        list<Punto>::const_iterator p;
    public:
        const_iterator();
        bool operator == (const iterator &it);
        bool operator != (const iterator &it);
        bool operator ++ (const iterator &it);
        bool operator * (const iterator &it);
    };

    iterator begin();
    const_iterator begin() const;

    iterator end();
    const_iterator end() const;

    iterator find(const Punto &p);

    friend istream &operator >>(istream &is, Ruta &r);
    friend ostream &operator <<(ostream &os, Ruta &r);

};


#endif //PRACTICAFINALED_RUTA_H
