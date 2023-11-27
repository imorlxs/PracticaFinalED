//
// Created by patriiciacoboss on 27/11/23.
//

#include "../include/Punto.h"
using namespace std;

Punto::Punto() : Punto(0, 0) {}

Punto::Punto(int fila, int col) : f(fila), c(col) {}

int Punto::getCol() const{
    return c;
}

int Punto::getFila() const{
    return f;
}

void Punto::setCol(int col) {
    c=col;
}

void Punto::setFila(int fila) {
    f=fil;
}

int Punto::getPunto() const {
    return std::make_pair(f, c);
}


