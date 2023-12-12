//
// Created by patriiciacoboss on 27/11/23.
//

#ifndef PRACTICAFINALED_PUNTO_H
#define PRACTICAFINALED_PUNTO_H
#include "string"
using namespace std;

class Punto {
private:
    double latitud, longitud;
    string description;
public:
    Punto(){
        latitud = longitud = 0;
        this->description = "";
    }

    Punto(double lat, double lon, const string &d): latitud(lat), longitud(lon), description(d){}

    double getLatitud() const;

    void setLatitud(double lat);

    double getLongitud() const;

    void setLongitud(double lon);

    bool operator < (const Punto &p) const;

    bool operator == (const Punto &p) const;

    bool operator !=(const Punto &p) const;

    friend istream &operator >>(istream &is, Punto &p);

    friend ostream &operator <<(ostream &os, const Punto &p);
};


#endif //PRACTICAFINALED_PUNTO_H
