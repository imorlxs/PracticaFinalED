/*
 * @author Patricia Cobos Rueda <pcobosrueda@correo.ugr.es>
 * @author Isaac Morales Santana <imorsan@correo.ugr.es>
 */
#ifndef PRACTICAFINALED_PAIS_H
#define PRACTICAFINALED_PAIS_H

using namespace std;

#include "string"
#include "Punto.h"


class Pais{
private:
    Punto p;
    string pais;
    string bandera;

public:
/**
 * @brief Constructor por defecto de la clase Pais.
 */
    Pais(){
        this->p = Punto();
        this->pais = this->bandera = "";
    }

    /**
  * @brief saber el objeto Punto de un País
 * @return el atributo privado punto
 */
    Punto GetPunto() const;

    /**
     * @brief saber el nombre de un Pais
     * @return el atributo privado pais
     */
    string GetPais() const;

    /**
     * @brief saber el nombre de la bandera de un objeto País
     * @return atributo privado bandera
     */
    string GetBandera() const;

    /**
     * @brief sobrecarga del operador de comparación menor que para la clase Pais
     * @param P El objeto Pais con el cual se va a comparar.
     * @return `true` si el objeto actual es menor que el objeto proporcionado; `false` en caso contrario.
     */
    bool operator<(const Pais &P)const;

    /**
    * @brief sobrecarga del operador de comparación igual que para la clase Pais
    * @param P El objeto Pais con el cual se va a comparar.
    * @return `true` si el objeto actual es igual que el objeto proporcionado; `false` en caso contrario.
    */
bool operator==(const Pais &P)const;

    /**
     * @brief sobrecarga del operador de comparación distinto para la clase Pais
     * @param P El objeto Pais con el cual se va a comparar.
     * @return `true` si el objeto actual es distinto al objeto proporcionado; `false` en caso contrario.
     */
    bool operator!=(const Pais &P)const;

    /**
     * @brief sobrecarga del operador de entrada para la clase Pais
     * @param is El flujo de entrada desde el cual leer los datos
     * @param p El objeto País que recibirá los datos
     * @return Referencia al flujo de entrada después de la operación
     */
    friend istream & operator>>(istream & is, Pais & P);

    /**
    * @brief sobrecarga del operador de salida para la clase Pais
    * @param os el flujo de salida al cual se enviarán los datos
    * @param P el objeto Pais del cual se obtendrán los datos
    * @return referencia al flujo de salida después de la operación
    */
    friend ostream & operator<<(ostream & os, const Pais &P);
};


#endif //PRACTICAFINALED_PAIS_H
