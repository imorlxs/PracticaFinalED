//
// Created by patriiciacoboss on 28/11/23.
//

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
 *
 * Esta clase proporciona un iterador constante para la clase Paises, permitiendo recorrer sus elementos de manera inmutable.
 */
    class const_iterator {
    private:
        set<Pais>::const_iterator p;

    public:
        /**
         * @brief Constructor por defecto del iterador constante
         */
        const_iterator();

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


    iterator begin();

    const_iterator cbegin() const;

    iterator end();

    const_iterator cend() const;

    iterator find(const Pais &p);

    iterator find(const Punto &p);

    friend istream &operator>>(istream &is, Paises &R);

    friend ostream &operator<<(ostream &os, const Paises &R);
};


#endif //PRACTICAFINALED_PAISES_H
