/*
 * Tablero.h
 *
 *  Created on: 24/10/2023
 *      Author: algo2
 */

#ifndef TABLERO_H_
#define TABLERO_H_

#include "Casillero.h"
#include "Lista.h"

class Tablero {
private:
	Lista<Lista<Lista<Casillero *> *> *> * casilleros;
    unsigned int ancho;
    unsigned int largo;
    unsigned int alto;

public:
    /**
    pre: Las dimensiones deber ser iguales o mayor a 0
    post: Crea un tablero con las dimensiones dadas e inicia todos los casilleros en NULL
    */
	Tablero(unsigned int ancho, unsigned int alto, unsigned int largo);

    /*
    * pre: -
    * post: elimina el tablero
    */
	virtual ~Tablero();

	/*
	*pre: -
	*post: devuelve el ancho del tablero
	*/
	unsigned int getAncho();

	/*
	*pre: -
    *post: devuelve el alto del tablero
    */
	unsigned int getAlto();

	/*
	*pre: -
    *post: devuelve el largo del tablero
    */
	unsigned int getLargo();

    /*
    *pre: las dimensiones deber ser iguales o mayor a 0 y menos o igual al maximo asignado
    *post: devuelve el casillero indicado
    */
    Casillero *getCasillero(unsigned int ancho, unsigned int alto, unsigned int largo);

    /*
	* pre: Las dimensiones deben ser > 0 (si algunaa dimension es > 15 puede imprimr mal)
	* post: Crea un archivo .bmp con las dimensiones del tablero vacio
	*/
   void imprimirTablero();

    private:
    /*
     * pre: -
     * post: Si los valores no estan en rango, tira una excepcion (Lo que hace esta es que valida tmb por el alto, ancho y largo actual que cuando creo el tablero me tira error)
    */
    void validarRango(unsigned int ancho, unsigned int alto, unsigned int largo);

    /**
     * pre: -
     * post: Devuelve true si el casillero fue creado
     */
    bool existeCasillero(unsigned int ancho, unsigned int alto, unsigned int largo);

    /**
	 * pre: -
	 * post: Verifica que las dimensiones sean > 0
	 */
    void validarDimensiones(unsigned int ancho, unsigned int alto, unsigned int largo);

};


#endif /* TABLERO_H_ */
