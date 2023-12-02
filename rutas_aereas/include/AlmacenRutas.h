//
// Created by patriiciacoboss on 27/11/23.
//

#ifndef PRACTICAFINALED_ALMACENRUTAS_H
#define PRACTICAFINALED_ALMACENRUTAS_H
#include "Ruta.h"
#include "map"
#include "string"

class AlmacenRutas{
private:
    map<string, Ruta> rutas;
public:
    AlmacenRutas(){}
    void Insertar(const Ruta &r);
    void Borrar(const Ruta &r);
    Ruta getRuta(const string &a);

    class iterator{
    private:
        map<string, Ruta>::iterator p;
    public:
        friend AlmacenRutas;

        iterator(){}
        bool operator == (const Ruta &ruta);
        bool operator != (const Ruta &ruta);
        iterator operator ++();
        iterator operator *();

    };

    class const_iterator{
    private:
        map<string, Ruta>::const_iterator p;
    public:
        friend AlmacenRutas;

        const_iterator(){}
        bool operator == (const Ruta &ruta);
        bool operator != (const Ruta &ruta);
        const_iterator operator ++();
        const_iterator operator *() const;

    };

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;

    friend istream & operator >> (istream & is, AlmacenRutas &almacen);
    friend ostream & operator << (ostream & is, const AlmacenRutas &almacen);

};

#endif //PRACTICAFINALED_ALMACENRUTAS_H
