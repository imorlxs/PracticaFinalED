//
// Created by patriiciacoboss on 27/11/23.
//

#ifndef PRACTICAFINALED_PUNTO_H
#define PRACTICAFINALED_PUNTO_H
#include "string"
using namespace std;

class Punto {
private:
    double latitud, longitud;
    string description;
public:
/**
* @brief Constructor por defecto de la clase Punto.
**/
Punto(){
    latitud = longitud = 0;
    this->description = "";
}

/**
 * @brief constructor con todos los parámetros
 * @param lat latitud de un punto (coordenada 1)
 * @param lon longitud de un punto (coordenada 2)
 * @param d breve descripción de un punto
 */
Punto(double lat, double lon, const string &d): latitud(lat), longitud(lon), description(d){}

/**
  * @brief saber el valor de la latitud de un objeto punto
 * @return el atributo privado latitud
 */

double getLatitud() const;

/**
 * @brief saber el valor de la longitud de un objeto punto
 * @return el atributo privado longitud
 */
double getLongitud() const;

/**
 * @brief saber la descripción de un objeto punto
 * @return el atributo privado longitud
 */
string getDescription() const;
/**
 * @brief sustituir la latitud de un punto por el parámetro lat
 * @param lat latitud de un punto
 */
void setLatitud(double lat);

/**
 * @brief sustituir la longitud de un punto por el parámetro lat
 * @param lat longitud de un punto
 */
void setLongitud(double lon);

/**
 * @brief sobrecarga del operador de comparación menor que para la clase Punto
 * @param p punto a comparar
 * @return true si un punto es menor que otro o false si es mayor
 */
bool operator < (const Punto &p) const;

/**
 * @brief evaluar si un punto es igual a un objeto Punto (comparando latitid, longitud y descripción)
 * @param p punto a comparar
 * @return true si un punto es igual a otro o false si es distinto
 */
bool operator == (const Punto &p) const;

/**
 * @brief evaluar si un punto es distinto a un objeto Punto (comparando latitid, longitud y descripción)
 * @param p punto a comparar
 * @return true si un punto es distinto a otro o false si es igual
 */
bool operator !=(const Punto &p) const;

/**
 * @brief sobrecarga del operador de entrada para la clase Punto
 * @param is El flujo de entrada desde el cual leer los datos
 * @param p El objeto Punto que recibirá los datos
 * @return Referencia al flujo de entrada después de la operación
 */
friend istream &operator >>(istream &is, Punto &p);

/**
* @brief sobrecarga del operador de salida para la clase Punto
* @param os el flujo de salida al cual se enviarán los datos
* @param p el objeto Punto del cual se obtendrán los datos
* @return referencia al flujo de salida después de la operación
*/
friend ostream &operator <<(ostream &os, const Punto &p);
};


#endif //PRACTICAFINALED_PUNTO_H
