/*
 * @author Patricia Cobos Rueda <pcobosrueda@correo.ugr.es>
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 */
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
    /**
     * @brief Constructor sin parámetros
     */
    Ruta();

    /**
     * @brief añadir un objeto Punto al list de la clase Ruta
     * @param n objeto Punto a añadiir
     */
    void Insertar(const Punto &n);

    /**
     * @brief eliminar un objeto Punto del list de la clase Ruta
     * @param n objeto Punto a eliminar
     */
    void Borrar(const Punto &n);

    /**
     * @brief código del objeto Ruta
     * @return código de una ruta
     */
    const string& GetCode() const;

    /**
     * @brief insertar manualmente nuevo código de la ruta
     * @param code código nuevo
     */
    void SetCode(const string &code);

    /**
     * @brief Operador de comparación de igualdad
     * @param r ruta con la que se compara
     * @return `true` si las rutas son iguales; `false` en caso contrario
     */
    bool operator==(const Ruta &r) const;

    /**
     * @brief Operador de comparación de desigualdad
     * @param r ruta con la que se compara
     * @return `true` si las rutas son distintas; `false` en caso contrario
     */
    bool operator!=(const Ruta &r) const;


    /**
     * @brief sobrecarga del operador de comparación menor que para la clase Ruta
     * @param r El objeto Ruta con el cual se va a comparar
     * @return `true` si el objeto actual es menor que el objeto proporcionado; `false` en caso contrario.
     */
    bool operator<(const Ruta &r) const;

    /**
     * @brief Clase iterator para la clase Ruta
     */
    class iterator {
    private:
        list<Punto>::iterator p;
    public:
        friend class Ruta;

        /**
         * @brief Constructor por defecto del iterador
        */
        iterator() : p() {}

        /**
        * @brief Operador de comparación de igualdad
        * @param otro Otro iterador con el que se compara
        * @return `true` si los iteradores son iguales; `false` en caso contrario
        */
        bool operator==(const Ruta::iterator &otro) const;

        /**
         * @brief Operador de comparación de desigualdad
         * @param otro Otro iterador con el que se compara
         * @return `true` si los iteradores son diferentes; `false` en caso contrario
         */
        bool operator!=(const Ruta::iterator &otro) const;

        /**
       * @brief Operador de incremento (prefijo)
       * @return Una referencia al iterador después de la operación de incremento
       */
        iterator& operator++();

        /**
         * @brief Operador de dereferenciación
         * @return Una referencia constante al objeto Ruta
         */
        Punto& operator*();

    };

    /**
     * @brief Clase const_iterator para la clase Ruta
     */
    class const_iterator {
    private:
        list<Punto>::const_iterator p;
    public:
        friend class Ruta;

        /**
         * @brief Constructor por defecto del iterador constante
         */
        const_iterator() : p() {}

        /**
        * @brief Operador de comparación de igualdad
        * @param otro Otro iterador con el que se compara
        * @return `true` si los iteradores son iguales; `false` en caso contrario
        */
        bool operator==(const Ruta::const_iterator &otro) const;

        /**
         * @brief Operador de comparación de desigualdad
         * @param otro Otro iterador con el que se compara
         * @return `true` si los iteradores son diferentes; `false` en caso contrario
         */
        bool operator!=(const Ruta::const_iterator &otro) const;

        /**
       * @brief Operador de incremento (prefijo)
       * @return Una referencia al iterador después de la operación de incremento
       */
        const_iterator operator++();

        /**
         * @brief Operador de dereferenciación.
         * @return Una referencia constante al objeto Ruta
         */
        const Punto& operator*() const;
    };

    /**
     * @brief primer elemento list
     * @return devuelve el iterador que señala al primer elemento del conjunto
    */
    iterator begin();

    /**
     * @brief primer elemento list
     * @return devuelve el iterador constante que señala al primer elemento del conjunto
    */
    const_iterator cbegin() const;

    /**
     * @brief último elemento list
     * @return devuelve el iterador que señala al último elemento del conjunto
    */
    iterator end();

    /**
     * @brief último elemento list
     * @return devuelve el iterador constante que señala al último elemento del conjunto
    */
    const_iterator cend() const;

    /**
     * @brief buscar un punto por objeto Punto
     * @param p objeto Punto a buscar
     * @return iterator al punto encontrado
     */
    iterator find(const Punto &p);

    /**
     * @brief sobrecarga del operador de entrada para la clase Ruta
     * @param is flujo de entrada
     * @param r objeto Paises
     * @return flujo de entrada actualizado
     */
    friend istream &operator>>(istream &is, Ruta &r);

    /**
     * @brief sobrecarga del operador de salida para la clase Ruta
     * @param os flujo de salida
     * @param r objeto Paises
     * @return flujo de salida actualizado
     */
    friend ostream &operator<<(ostream &os, const Ruta &r);

};


#endif //PRACTICAFINALED_RUTA_H
