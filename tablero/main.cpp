/*
 * main.cpp
 *
 *  Created on: 24/10/2023
 *      Author: algo2
 */


#include "Tablero.h"
#include <iostream>

int main(){
	Tablero *tablero = new Tablero (3,3,3);

	tablero->imprimirTablero();

	tablero->getCasillero(1,1,1)->setFicha('A');

	std::cout << tablero->getCasillero(1,1,1)->getFicha() << std::endl;

	tablero->getCasillero(3,3,3)->setFicha('B');

	std::cout << tablero->getCasillero(3,3,3)->getFicha() << std::endl;

	delete tablero;

	return 0;
}

