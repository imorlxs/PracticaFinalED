/*
 * @author Patricia Cobos Rueda <pcobosrueda@correo.ugr.es>
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 */
#ifndef PRACTICAFINALED_PAISES_H
#define PRACTICAFINALED_PAISES_H


#include "Pais.h"
#include <set>

using namespace std;

class Paises {
private:
    set<Pais> datos;
public:
    /**
     * @brief Constructor sin parámetros
     */
    Paises() {}

    /**
     * @brief añadir un objeto País al set de la clase Países
     * @param P objeto País a añadiir
     */
    void Insertar(const Pais &P);

    /**
     * @brief eliminar un objeto País del set de la clase Países
     * @param P objeto País a eliminar
     */
    void Borrar(const Pais &P);

    /**
     * @brief Clase iterator para la clase Paises
     */
    class iterator {
    private:
        set<Pais>::iterator p;
    public:
        friend class Paises;

        /**
         * @brief Constructor por defecto del iterador
        */
        iterator() {}

        /**
         * @brief Operador de comparación de desigualdad
         * @param otro Otro iterador con el que se compara
         * @return `true` si los iteradores son diferentes; `false` en caso contrario
         */
        bool operator!=(Paises::iterator otro) const;

        /**
        * @brief Operador de comparación de igualdad
        * @param otro Otro iterador con el que se compara
        * @return `true` si los iteradores son iguales; `false` en caso contrario
        */
        bool operator==(Paises::iterator otro) const;

        /**
       * @brief Operador de incremento (prefijo)
       * @return Una referencia al iterador después de la operación de incremento
       */
        iterator operator++();

        /**
         * @brief Operador de dereferenciación.
         * @return Una referencia constante al objeto Pais.
         */
        const Pais& operator*();
    };

    /**
     * @brief Clase const_iterator para la clase Paises.
     */
    class const_iterator {
    private:
        set<Pais>::const_iterator p;

    public:
        /**
         * @brief Constructor por defecto del iterador constante
         */
        const_iterator(){}

        /**
         * @brief Operador de comparación de desigualdad
         * @param otro Otro iterador constante con el que se compara
         * @return `true` si los iteradores son diferentes; `false` en caso contrario
         */
        bool operator!=(Paises::const_iterator otro) const;

        /**
         * @brief Operador de comparación de igualdad
         * @param otro Otro iterador constante con el que se compara
         * @return `true` si los iteradores son iguales; `false` en caso contrario
         */
        bool operator==(Paises::const_iterator otro) const;

        /**
         * @brief Operador de incremento (prefijo)
         * @return Una referencia al iterador constante después de la operación de incremento
         */
        const_iterator operator++();

        /**
         * @brief Operador de dereferenciación constante
         * @return Una referencia constante al objeto Pais
         */
        const Pais& operator*() const;

        friend class Paises;
    };


    /**
     * @brief primer elemento set
     * @return devuelve el iterador que señala al primer elemento del conjunto
    */
    iterator begin();

    /**
     * @brief primer elemento set
     * @return devuelve el iterador constante que señala al primer elemento del conjunto
    */
    const_iterator cbegin() const;

    /**
     * @brief último elemento set
     * @return devuelve el iterador que señala al último elemento del conjunto
    */
    iterator end();

    /**
     * @brief último elemento set
     * @return devuelve el iterador constante que señala al último elemento del conjunto
    */
    const_iterator cend() const;

    /**
     * @brief buscar un país por objeto Pais
     * @param p objeto País a buscar
     * @return iterator al país encontrado
     */
    iterator find(const Pais &p);

    /**
     * @brief buscar un país por objeto Punto
     * @param p objeto Punto a buscar
     * @return iterator al país encontrado
     */
    iterator find(const Punto &p);

    /**
     * @brief sobrecarga del operador de entrada para la clase Paises
     * @param is flujo de entrada
     * @param R objeto Paises
     * @return flujo de entrada actualizado
     */
    friend std::istream &operator>>(std::istream &is, Paises &R);

    /**
     * @brief sobrecarga del operador de salida para la clase Paises
     * @param os flujo de salida
     * @param R objeto Paises
     * @return flujo de salida actualizado
     */
    friend std::ostream &operator<<(std::ostream &os, const Paises &R);
};


#endif //PRACTICAFINALED_PAISES_H
