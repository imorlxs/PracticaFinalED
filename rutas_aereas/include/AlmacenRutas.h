/*
 * @author Patricia Cobos Rueda <pcobosrueda@correo.ugr.es>
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 */

#ifndef PRACTICAFINALED_ALMACENRUTAS_H
#define PRACTICAFINALED_ALMACENRUTAS_H
#include "Ruta.h"
#include "map"
#include "string"

class AlmacenRutas{
private:
    map<string, Ruta> rutas;
public:
    /**
     * @brief Constructor sin parámetros
     */
    AlmacenRutas(){}

    /**
     * @brief añadir un objeto Ruta al map de la clase AlmacenRutas
     * @param r objeto Ruta a añadiir
     */
    void Insertar(const Ruta &r);

    /**
     * @brief eliminar un objeto Ruta al map de la clase AlmacenRutas
     * @param r objeto Ruta a eliminar
     */
    void Borrar(const Ruta &r);

    /**
     * @brief nombre del objeto Ruta
     * @return nombre de una ruta
     */
    Ruta getRuta(const string &a);

    class iterator{
    private:
        map<string, Ruta>::iterator p;
    public:
        friend AlmacenRutas;

        /**
         * @brief Constructor por defecto del iterador
        */
        iterator(){}

        /**
        * @brief Operador de comparación de igualdad
        * @param ruta parámetro con el que se compara
        * @return `true` si los iteradores son iguales; `false` en caso contrario
        */
        bool operator == (const Ruta &ruta);

        /**
        * @brief Operador de comparación de desigualdad
        * @param ruta parámetro con el que se compara
        * @return `true` si los iteradores son distintos; `false` en caso contrario
        */
        bool operator != (const Ruta &ruta);

        /**
       * @brief Operador de incremento (prefijo)
       * @return Una referencia al iterador después de la operación de incremento
       */
        iterator operator ++();

        /**
       * @brief Operador de dereferenciación
       * @return Una referencia al iterador
       */
        const iterator operator *();

    };

    /**
     * @brief Clase const_iterator para la clase AlmacenRutas
     */
    class const_iterator{
    private:
        map<string, Ruta>::const_iterator p;
    public:
        friend AlmacenRutas;

        /**
         * @brief Constructor por defecto del iterador constante
         */
        const_iterator(){}

        /**
        * @brief Operador de comparación de igualdad
        * @param ruta objeto con el que se compara
        * @return `true` si los objetos son iguales; `false` en caso contrario
        */
        bool operator == (const Ruta &ruta);

        /**
        * @brief Operador de comparación de desigualdad
        * @param ruta objeto con el que se compara
        * @return `true` si los objetos son distintos; `false` en caso contrario
        */
        bool operator != (const Ruta &ruta);

        /**
       * @brief Operador de incremento (prefijo)
       * @return Una referencia al iterador constante después de la operación de incremento
       */
        const_iterator operator ++();

        /**
       * @brief Operador de dereferenciación
       * @return Una referencia constante al iterador
       */
        const_iterator operator *() const;

    };

    /**
     * @brief primer elemento map
     * @return devuelve el iterador que señala al primer elemento del conjunto
    */
    iterator begin();

    /**
     * @brief primer elemento map
     * @return devuelve el iterador constante que señala al primer elemento del conjunto
    */
    const_iterator begin() const;

    /**
     * @brief último elemento map
     * @return devuelve el iterador que señala al último elemento del conjunto
    */
    iterator end();

    /**
     * @brief último elemento map
     * @return devuelve el iterador constante que señala al último elemento del conjunto
    */
    const_iterator end() const;

    /**
     * @brief sobrecarga del operador de entrada para la clase AlmacenRutas
     * @param is flujo de entrada
     * @param almacen objeto AlmacenRutas
     * @return flujo de entrada actualizado
     */
    friend istream & operator >> (istream & is, AlmacenRutas &almacen);

    /**
     * @brief sobrecarga del operador de salida para la clase AlmacenRutas
     * @param os flujo de salida
     * @param almacen objeto AlmacenRutas
     * @return flujo de salida actualizado
     */
    friend ostream & operator << (ostream & is, const AlmacenRutas &almacen);
    
    /**
    * @brief Método para leer un almacén desde un fichero
    * @param nombre, nombre del fichero que contiene el almacén.
    */
    void LeerAlmacen(const char *nombre);
};

#endif //PRACTICAFINALED_ALMACENRUTAS_H
