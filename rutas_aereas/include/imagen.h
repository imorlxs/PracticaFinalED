//
// Created by isaacm on 28/11/23.
//

#ifndef PRACTICAFINALED_IMAGEN_H
#define PRACTICAFINALED_IMAGEN_H

#include <string>
#include "imagenES.h"

using namespace std;

/**
 * @brief Enumerado para el tipo de pegado
 * OPACO no se copia la transparencia, en BLENDING sí se tiene en cuenta.
 */
enum Tipo_Pegado {
    OPACO, BLENDING
};

using namespace std;
struct Pixel {
    /**
     * @brief Valores de red, green y blue del píxel. Van de 0 a 255
     */
    unsigned char r, g, b;

    /**
     * @brief Valor de transparencia del píxel. 0 no tiene, 255 sí.
     */
    unsigned char transp;
};

class Imagen {
private:
    /**
     * @brief Puntero a la imagen almacenada
     *
     * data apunta a un array-2D dinámico de bytes que contiene la imagen en sí.
     */
    Pixel **data;

    /**
     * @brief Número de filas en la imagen
     */
    int nf;

    /**
    * @brief Número de columnas en la imagen
    */
    int nc;

    /**
     * @brief Borrar una imagen
     *
     * Libera la memoria reservada en la que se almacenaba la imagen que llama a la función. Si la imagen estaba
     * vacía no hace nada
     */
    void Borrar();

    /**
     * @brief Copiar una imagen
     * @param I Referencia a la imagen original que vamos a copiar
     * @pre Asume que no hay memoria reservada o que antes se ha llamado a Borrar()
     * @pre Asume this != &I
     */
    void Copiar(const Imagen &I);

    /**
     * @brief Inicializa una imagen
     * @param f Número de filas que tendrá la imagen, Por defecto 0.
     * @param c Número de columnas que tendrá la imagen. Por defecto 0.
     * @pre f >= 0 y c >= 0
     * @post Reserva memoria para almacenar la imagen y la prepara para usarse.
     */
    void Initialize(int f = 0, int c = 0);

    /**
     * @brief Reserva o copia en memoria una imagen
     * @param f Número de filas que tendrá la imagen
     * @param c Número de columnas que tendrá la imagen.
     * @pre f >= 0 y c >= 0
     * @posr Reserva memoria para almacenar la imagen y la prepara para usarse
     */
    void Allocate(int f, int c);

public:
    /**
     * @brief Constructor por defecto.
     * @post Genera una instancia de la clase Imagen con 0 filas y 0 columnas
     */
    Imagen();

    /**
     * @brief Constructor con parámetros.
     * @param f Número de filas de la imagen
     * @param c Número de columnas de la imagen
     * @pre f > 0 y c > 0
     * @post La imagen creada es de de tamaño f*c. Estará inicializada al valor por defecto (255).
     * @return Imagen, el objeto creado
     */
    Imagen(int f, int c);


    /**
     * Constructor de copia.
     * @param I Referencia a la imagen original que se quiere copiar
     * @re
     * @return Imagen, el objeto creado
     */
    Imagen(const Imagen &I);

    /**
     * @brief Operador de asignación.
     * @param I  Referencia a la imagen original que desea copiarse
     * @return Una referencia al objeto imagen modificado
     * @post Elimina cualquier información que contuviera previamente la imagen que llama al operador de asignación.
     */
    Imagen &operator=(const Imagen &I);

    /**
     * @brief Operador de tipo destructor
     * @return void
     * @post El objeto Imagen destruido no puede usarse salvo que se haga sobre él una operación Imagen()
     */
    ~Imagen();

    /**
     * Operador de acceso y modificación.
     * @param i Fila del píxel a consultar
     * @param j Columna del píxel a consultar
     * @return Una referencia al píxel consultado.
     * @pre 0 <= i < filas y 0 <= j < columnas
     */
    Pixel &operator()(int i, int j);

    /**
     * Operador de acceso.
     * @param i Fila del píxel a consultar
     * @param j Columna del píxel a consultar
     * @return Una referencia constante al píxel consultado.
     * @pre 0 <= i < filas y 0 <= j < columnas
     * @post El píxel consultado no se modifica
     */
    const Pixel &operator()(int i, int j) const;

    /**
     * Escribe una imagen de tipo PGM y PPM
     * @param nombre Nombre del fichero destino.
     */

    void EscribirImagen(const char *nombre);

    /**
     * Lee una imagen de tipo PPM o PGM, aplicándole la máscara pasada por parámetro
     * @param nombre Fichero de la imagen
     * @param nombremascara Fichero de la máscara
     */
    void LeerImagen(const char *nombre, const string &nombremascara = "");

    /**
     * @brief Pone a 0 el valor de la transparencia de todos los píxeles de la imagen
     */
    void LimpiarTransp();

    /**
     * @brief Filas de la imagen
     * @return El número de filas de la imagen
     * @post La imagen no se modifica
     */
    int num_filas() const { return nf; }

    /**
     * @brief Columnas de la imagen
     * @return El número de columnas de la imagen
     * @post La imagen no se modifica
     */
    int num_cols() const { return nc; }

    /**
     * Pega la imagen I sobre la imagen que llama a este método.
     * @param posi Fila del píxel superior izquierda donde empezar el pegado
     * @param posj  Columna del píxel superior izquierda donde empezar el pegado
     * @param I Referencia a la imagen a pegar
     * @param tippegado Tipo de pegado: OPACO si no queremos aplicar transparencias, BLENDING en caso contrario.
     */
    void PutImagen(int posi, int posj, const Imagen &I, Tipo_Pegado tippegado = OPACO);

    /**
     * @brief Crea a partir de una imagen otra igual o de menor tamaño
     * @param posi Fila de la coordenada superior izquierda de la nueva imagen respecto a la anterior
     * @param posj Columna de la coordenada superior izquierda de la nueva imagen respecto a la anterior
     * @param dimi Número de filas de la nueva imagen
     * @param dimj Número de columnas de la nueva imagen
     * @return Una nueva imagen
     * @post La imagen original no se modifica.
     */
    Imagen ExtraeImagen(int posi, int posj, int dimi, int dimj) const;

    /**
     * @return Devuelve true si la imagen está vacía
     */
    bool Empty() const;
};


#endif //PRACTICAFINALED_IMAGEN_H
