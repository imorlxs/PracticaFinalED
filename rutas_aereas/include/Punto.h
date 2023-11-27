//
// Created by patriiciacoboss on 27/11/23.
//

#ifndef PRACTICAFINALED_PUNTO_H
#define PRACTICAFINALED_PUNTO_H
#include "string"
using namespace std;

class Punto {
private:
    float latitud, longitud;
public:
    Punto();

    Punto(float lat, float lon);

    float getLatitud() const;

    void setLatitud(int lat);

    float getLongitud() const;

    void setLongitud(int lon);

    pair<float, float> getPunto() const;

    string toString();
};


#endif //PRACTICAFINALED_PUNTO_H
