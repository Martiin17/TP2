/*
 * Casillero.cpp
 *
 *  Created on: 24/10/2023
 *      Author: algo2
 */

#include "Casillero.h"
#include <iostream>

Casillero::Casillero(unsigned int x, unsigned int y, unsigned int z) {
	validarRango(x, y, z);

	this->x = x;
	this->y = y;
    this->z = z;
	this->ficha = '*';
	this->vecinos = new Casillero***[3];
	for(int i = 0; i < 3; i++) {
		this->vecinos[i] = 	new Casillero**[3];
		for(int j=0; j < 3; j++) {
			this->vecinos[i][j] = new Casillero*[3];
			for(int k=0; k < 3; k++) {
				this->vecinos[i][j][k] = NULL;
			}
		}
	}
}

Casillero::~Casillero() {
	for(int i = 0; i < 3; i++) {
		for(int j=0; j < 3; j++) {
			delete [] this->vecinos[i][j];
		}
		delete [] this->vecinos[i];
	}
	delete [] this->vecinos;
}

unsigned int Casillero::getX() {
	return this->x;
}

unsigned int Casillero::getY() {
	return this->y;
}

unsigned int Casillero::getZ() {
	return this->z;
}

void Casillero::setFicha(char ficha) {
	this->ficha = ficha;
}

char Casillero::getFicha() {
	return this->ficha;
}

void Casillero::validarRango(unsigned int x, unsigned int y, unsigned int z){
    if(x < 0){
        throw "El x debe ser mayor igual a 0";
    }
    if(y < 0){
        throw "El y debe ser mayor igual a 0";
    }
    if(z < 0){
        throw "El z debe ser mayor igual a 0";
    }
    /*
    if(x > this->getX()){
    	std::cout << x <<std::endl;
    	std::cout << this->getX() << std::endl;
        throw "El ancho debe ser menor igual a " +  this->getX();
    }
    if(y > this->getY()){
        throw "El largo debe ser menor igual a " +  this->getY();
    }
    if(z > this->getZ()){
        throw "El alto debe ser menor igual a " + this->getZ();
    }
    */ //Estamos inciciando todavia. Si dsp queremos validar que sea menor al Alto,Ancho y Largo lo hacemos en otra fun
}

void Casillero::setVecino(Casillero * casillero, int x, int y, int z) {
	//validar
	//Transformar (-1,0,1) a (0, 1, 2) con el +1 ya ta
	this->vecinos[x+1][y+1][z+1] = casillero;
}

bool Casillero::tieneElVecino(unsigned int x, unsigned int y, unsigned int z){
	return(this->vecinos[x+1][y+1][z+1] == NULL);
}


