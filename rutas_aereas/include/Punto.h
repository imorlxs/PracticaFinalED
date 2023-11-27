//
// Created by patriiciacoboss on 27/11/23.
//

#ifndef PRACTICAFINALED_PUNTO_H
#define PRACTICAFINALED_PUNTO_H

using namespace std;

class Punto {
private:
    int f, c;
public:
    Punto();

    Punto(int fila, int col);

    int getFila() const;

    void setFila(int fila);

    int getCol() const;

    void setCol(int col);

    pair<int, int> getPunto() const;
};


#endif //PRACTICAFINALED_PUNTO_H
