/*
 * @author Patricia Cobos Rueda <pcobosrueda@correo.ugr.es>
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 */
#include <cassert>
#include <iostream>
#include <cmath>
#include "imagen.h"

Imagen::Imagen() {
    Initialize();
}

Imagen::Imagen(int f, int c) {
    Initialize(f, c);
}

Imagen::Imagen(const Imagen &I) {
    assert (this != &I);
    Copiar(I);
}

Imagen::~Imagen() {
    Borrar();
}


void Imagen::Allocate(int f, int c) {
    const unsigned char VALOR_DEFECTO_PIXEL = 255;
    nf = f;
    nc = c;
    data = new Pixel *[nf];
    for (int i = 0; i < nf; i++) {
        data[i] = new Pixel[nc];
        for (int j = 0; j < nc; j++) {
            data[i][j].r = VALOR_DEFECTO_PIXEL;
            data[i][j].g = VALOR_DEFECTO_PIXEL;
            data[i][j].b = VALOR_DEFECTO_PIXEL;
            data[i][j].transp = VALOR_DEFECTO_PIXEL;
        }
    }

}

void Imagen::Initialize(int f, int c) {
    if (f == 0 || c == 0) {
        nf = nc = 0;
        data = nullptr;
    } else
        Allocate(f, c);
}

/**********************************************/
Pixel &Imagen::operator()(int i, int j) {
    assert(i >= 0 && i < nf && j >= 0 && j < nc);
    return data[i][j];
}

const Pixel &Imagen::operator()(int i, int j) const {
    assert(i >= 0 && i < nf && j >= 0 && j < nc);
    return data[i][j];
}

/***********************************************/

void Imagen::EscribirImagen(const char *nombre) {
    unsigned char *aux = new unsigned char[nf * nc * 3];
    unsigned char *m = new unsigned char[nf * nc];

    int total = nf * nc * 3;
    for (int i = 0; i < total; i += 3) {
        int posi = i / (nc * 3);
        int posj = (i % (nc * 3)) / 3;

        aux[i] = data[posi][posj].r;
        aux[i + 1] = data[posi][posj].g;
        aux[i + 2] = data[posi][posj].b;
        m[i / 3] = data[posi][posj].transp;

    }

    if (!EscribirImagenPPM(nombre, aux, nf, nc)) {
        cerr << "Ha habido un problema en la escritura de " << nombre << endl;
    }
    delete[]aux;
    string n_aux = "mascara_";
    n_aux = n_aux + nombre;
    std::size_t found = n_aux.find(".ppm");
    if (found != std::string::npos) {
        n_aux = n_aux.substr(0, found);
    }
    n_aux = n_aux + ".pgm";


    if (!EscribirImagenPGM(n_aux.c_str(), m, nf, nc)) {
        cerr << "Ha habido un problema en la escritura de " << n_aux << endl;
    }
    delete[]m;

}

/*********************************/
void Imagen::LeerImagen(const char *nombre, const string &nombremascara) {
    int f, c;
    unsigned char *aux, *aux_mask;

    LeerTipoImagen(nombre, f, c);
    aux = new unsigned char[f * c * 3];
    LeerImagenPPM(nombre, f, c, aux);
    if (!nombremascara.empty()) {
        int fm, cm;
        LeerTipoImagen(nombremascara.c_str(), fm, cm);
        aux_mask = new unsigned char[fm * cm];
        LeerImagenPGM(nombremascara.c_str(), fm, cm, aux_mask);
    } else {
        aux_mask = nullptr;
    }


    Imagen I(f, c);
    int total = f * c * 3;
    for (int i = 0; i < total; i += 3) {
        int posi = i / (c * 3);
        int posj = (i % (c * 3)) / 3;
        //   cout<<posi<<" " <<posj<<endl;
        I.data[posi][posj].r = aux[i];
        I.data[posi][posj].g = aux[i + 1];
        I.data[posi][posj].b = aux[i + 2];
        if (aux_mask != nullptr)
            I.data[posi][posj].transp = aux_mask[i / 3];
        else
            I.data[posi][posj].transp = 255;
    }

    *this = I;
    if (aux_mask != nullptr)
        delete[]aux_mask;

    delete[]aux;

}

/*********************************/

void Imagen::PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tippegado) {
    //assert(nf>=posi+I.nf && nc>=posj+I.nc);

    for (int i = 0; i < I.nf; i++)
        for (int j = 0; j < I.nc; j++)
            if (i + posi >= 0 && i + posi < nf && j + posj >= 0 && j + posj < nc) {
                if (I.data[i][j].transp != 0) {
                    if (tippegado == OPACO)
                        data[i + posi][j + posj] = I.data[i][j];
                    else {
                        data[i + posi][j + posj].r = (data[i + posi][j + posj].r + I.data[i][j].r) / 2;
                        data[i + posi][j + posj].g = (data[i + posi][j + posj].r + I.data[i][j].g) / 2;
                        data[i + posi][j + posj].b = (data[i + posi][j + posj].r + I.data[i][j].b) / 2;
                    }

                }
            }

}

void Imagen::Copiar(const Imagen &I) {
    Initialize(I.nf, I.nc);
    for (int i = 0; i < I.nf; i++) {
        for (int j = 0; j < I.nc; j++)
            (*this)(i, j) = I(i, j);
    }
}

bool Imagen::Empty() const {
    return (nf == 0 || nc == 0);
}

void Imagen::Borrar() {
    if (!Empty()) {
        for (int i = 0; i < nf; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
}

Imagen &Imagen::operator=(const Imagen &I) {
    if (this != &I) {
        Borrar();
        Copiar(I);
    }
    return *this;
}

void Imagen::LimpiarTransp() {
    for (int i = 0; i < nf; i++) {
        for (int j = 0; j < nc; j++) {
            (*this)(i, j).transp = 255;
        }
    }
}

Imagen Imagen::ExtraeImagen(int posi, int posj, int dimi, int dimj) const {
    // Verificamos que la imagen que se desa crear sea de igual o menor tamaño.
    assert (dimi < nf - posi);
    assert (dimj < nc - posj);

    // Creamos la imagen resutlante
    Imagen subimagen(dimi, dimj);

    // Copiamos los elementos seleccionados en la nueva imagen
    for (int i = posi; i < dimi + nf; i++) {
        for (int j = posj; j < dimj + nc; j++)
            subimagen(i - posi, j - posj) = (*this)(i, j);
    }

    return subimagen;
}

//*****************************************************************************
// Funciones para editar imagenes


Imagen Rota(const Imagen &Io, double angulo) {
    double rads = angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);
    //Para obtener las dimensiones de la imagen
    int rcorners[4], ccorners[4];
    int newimgrows, newimgcols;
    double new_row_min, new_col_min, new_row_max, new_col_max;
    double inter, inter1;
    rcorners[0] = 0;
    rcorners[1] = 0;
    ccorners[0] = 0;
    ccorners[2] = 0;
    rcorners[2] = Io.num_filas() - 1;
    rcorners[3] = Io.num_filas() - 1;
    ccorners[1] = Io.num_cols() - 1;
    ccorners[3] = Io.num_cols() - 1;
    new_row_min = 0;
    new_col_min = 0;
    new_row_max = 0;
    new_col_max = 0;
    newimgrows = 0;
    newimgcols = 0;
    for (int count = 0; count < 4; count++) {
        inter = rcorners[count] * coseno + ccorners[count] * seno;

        if (inter < new_row_min)
            new_row_min = inter;
        if (inter > new_row_max)
            new_row_max = inter;
        inter1 = -rcorners[count] * seno + ccorners[count] * coseno;

        if (inter1 < new_col_min)
            new_col_min = inter1;
        if (inter1 > new_col_max)
            new_col_max = inter1;
    }

    newimgrows = (unsigned) ceil((double) new_row_max - new_row_min);
    newimgcols = (unsigned) ceil((double) new_col_max - new_col_min);

    Imagen Iout(newimgrows, newimgcols);
    for (int rows = 0; rows < newimgrows; rows++) {
        for (int cols = 0; cols < newimgcols; cols++) {
            float oldrowcos = ((float) rows + new_row_min) * cos(-rads);
            float oldrowsin = ((float) rows + new_row_min) * sin(-rads);
            float oldcolcos = ((float) cols + new_col_min) * cos(-rads);
            float oldcolsin = ((float) cols + new_col_min) * sin(-rads);
            float old_row = oldrowcos + oldcolsin;
            float old_col = -oldrowsin + oldcolcos;
            old_row = ceil((double) old_row);
            old_col = ceil((double) old_col);
            if ((old_row >= 0) && (old_row < Io.num_filas()) &&
                (old_col >= 0) && (old_col < Io.num_cols())) {
                Iout(rows, cols) = Io(old_row, old_col);

            } else
                Iout(rows, cols).r = Iout(rows, cols).g = Iout(rows, cols).b = Iout(rows, cols).transp = 0;
        }
    }
    return Iout;

}


void Pintar(int f1, int f2, int c1, int c2, Imagen &I, const Imagen &avion, int mindisf, int mindisc) {
    f1 = f1 - avion.num_filas() / 2;
    f2 = f2 - avion.num_filas() / 2;
    c1 = c1 - avion.num_cols() / 2;
    c2 = c2 - avion.num_cols() / 2;

    int fila, col;
    if (abs(f2 - f1) >= mindisf || abs(c2 - c1) >= mindisc) {

        if (c1 != c2) {
            double a, b;
            a = double(f2 - f1) / double(c2 - c1);
            b = f1 - a * c1;
            col = (int) (c1 + c2) / 2;
            fila = (int) rint(a * col + b);
        } else {
            col = c1;
            fila = (f1 + f2) / 2;
        }


        double angulo = atan2((f2 - f1), (c2 - c1));
        Imagen Irota = Rota(avion, angulo);

        I.PutImagen(fila, col, Irota, OPACO);//pensar si debe ser opaco o blending

        angulo = atan2((f2 - fila), (c2 - col));
        Irota = Rota(avion, angulo);

        I.PutImagen(f2, c2, Irota, OPACO);//pensar si debe ser opaco o blending
        angulo = atan2((fila - f1), (col - c1));
        Irota = Rota(avion, angulo);

        I.PutImagen(f1, c1, Irota);//pensar si debe ser opaco o blending


    }

}







