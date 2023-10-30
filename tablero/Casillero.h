/*
 * Casillero.h
 *
 *  Created on: 24/10/2023
 *      Author: algo2
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_

class Casillero {
private:
	char ficha;
	Casillero **** vecinos;
	unsigned int x;
	unsigned int y;
	unsigned int z;

  /*
   * pre: -
   * post: Valida que la posicion sea > 0
   */
	void validarRango(unsigned int x, unsigned int y, unsigned int z);

public:
	/**
	 * pre: las posicion deber ser iguales o mayor a 0
	 * pos: deja un casillero vacio creado de las coordenadas dadas
	 */
	Casillero(unsigned int x, unsigned int y, unsigned int z);

	/**
	 * pre: -
	 * post: elimina el casillero
	 */
	virtual ~Casillero();

	/**
	 * pre: -
	 * post: devuelve la coordenada x del casillero
	 */
	unsigned int getX();

	/**
	 * pre: -
	 * post: devuelve la coordenada y del casillero
	 */
	unsigned int getY();

	/**
	 * pre: -
	 * post: devuelve la coordenada z del casillero
	 */
	unsigned int getZ();

	/**
	 * pre:
	 * post: devuelve la ficha vinculada con el casillero
	 */
	char getFicha();

	/**
	 * pre: .
	 * post: cambia el tipo de casillero
	 */
	void setFicha(char ficha);

	/**
	 * pre: -
	 * post: Devuelve true si el vecino tiene un puntero NULL
	 */
	bool tieneElVecino(unsigned int x, unsigned int y, unsigned int z);

	/**
	 * pre: el rango de x: -1, 0, 1. Rango de y: -1, 0, 1. Rango de z: -1, 0, 1.
	 * post: Agrega el vecino
	 */
	void setVecino(Casillero * casillero, int x, int y, int z);
};




#endif /* CASILLERO_H_ */
