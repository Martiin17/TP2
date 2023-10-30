/*
 * Tablero.cpp
 *
 *  Created on: 24/10/2023
 *      Author: algo2
 */

#include "Tablero.h"
#include "EasyBMP_Geometry.h"
#include "EasyBMP_Font.h"
#include "EasyBMP.h"


#include <iostream> //borrar

Tablero::Tablero(unsigned int ancho, unsigned int alto, unsigned int largo) {
	this->validarDimensiones(ancho, alto, largo);

	this->casilleros = new Lista<Lista<Lista<Casillero *> *> *>();
    this->ancho = ancho;
    this->alto = alto;
    this->largo = largo;

	for(unsigned int i = 1; i <= ancho; i++){
		Lista<Lista<Casillero *> *>* fila = new Lista<Lista<Casillero *>*>();
		for(unsigned int j = 1; j <= alto; j++) {
			Lista<Casillero *> * columna = new Lista<Casillero *>();
            for( unsigned int z = 1; z <= largo; z++) {
            	Casillero* casillero = new Casillero(i, j, z);
            	columna->agregar(casillero);
		    }
            fila->agregar(columna);
		}
		casilleros->agregar(fila);
	}

	this->casilleros->iniciarCursor();
	while(this->casilleros->avanzarCursor()){
		Lista<Lista<Casillero *> *> * fila = this->casilleros->obtenerCursor();
		fila->iniciarCursor();
		while(fila->avanzarCursor()) {
			Lista<Casillero *> * columna = fila->obtenerCursor();
			columna->iniciarCursor();
			while (columna->avanzarCursor()) {
				unsigned int x = columna->obtenerCursor()->getX();
				unsigned int y = columna->obtenerCursor()->getY();
				unsigned int z = columna->obtenerCursor()->getZ();
				Casillero * casillero = this->getCasillero(x,y,z);
				for(int i = -1; i <= 1; i++){
					for(int j = -1; j <= 1; j++){
						for(int k = -1; k <= 1; k++){
							if(this->existeCasillero(x+i, y+j, z+k)){
								if(casillero->tieneElVecino(i, j, k)){//185 vuelas hace (sin este if hace cerca del doble)
									Casillero * vecino = getCasillero(x+i, y+j, z+k);
									casillero->setVecino(vecino, i, j, k);
									vecino->setVecino(casillero, -1 *i, -1 *j, -1 *k);
								}
							}
						}
					}
				}
			}
		}
	}
}
/*
	//Tarea:
	//Optimizar este algoritmo while / cursor
	contador = 0;
	for( unsigned int x = 1; x <= ancho; x++){
		for( unsigned int y = 1; y <= alto; y++) {
			for( unsigned int z = 1; z <= largo; z++) {
				//Por cada casillero
				Casillero * casillero = getCasillero(x, y, z); //recorriendo x * y * z * 13
				//Los vecinos
				for( unsigned int i = -1; i <= 1; i++){
					for( unsigned int j = -1; j <= 1; j++){
						for( unsigned int k = -1; k <= 1; k++){
							if (this->existeCasillero(x+i, y+j, z+k)) {
								//si (0, 0, 0); casillero->setVecino( casillero, 0,0,0);
								if (casillero->tieneElVecino(i, j, k)) {
									Casillero * vecino = getCasillero(x+i, y+j, z+k);
									casillero->setVecino(vecino, i, j, k);
									vecino->setVecino(casillero, -1 *i, -1 *j, -1 *k);
									contador++;
								}
							}
						}
					}
				}
			}
		}
	}
	std::cout << contador << std::endl;
}*/

Tablero::~Tablero() {
	this->casilleros->iniciarCursor();
	while(this->casilleros->avanzarCursor()){
		Lista<Lista<Casillero *> *> * fila = this->casilleros->obtenerCursor();
        fila->iniciarCursor();
        while(fila->avanzarCursor()) {
		    Lista<Casillero *> * columna = fila->obtenerCursor();
            columna->iniciarCursor();
            while (columna->avanzarCursor()) {
                delete columna->obtenerCursor();
            }
            delete columna;
        }
        delete fila;
	}
	delete this->casilleros;
}

unsigned int Tablero::getAncho() {
	return this->ancho;
}

unsigned int Tablero::getAlto() {
	return this->alto;
}

unsigned int Tablero::getLargo() {
	return this->largo;
}

Casillero * Tablero::getCasillero(unsigned int ancho, unsigned int alto, unsigned int largo) {
	validarRango(ancho, alto, largo);
	return this->casilleros->obtener(ancho)->obtener(alto)->obtener(largo);
}

void Tablero::validarRango(unsigned int ancho, unsigned int alto, unsigned int largo){
    if(ancho < 1){
        throw "El ancho debe ser mayor igual a 0";
    }
    if(alto < 1){
        throw "El alto debe ser mayor igual a 0";
    }
    if(largo < 1){
        throw "El largo debe ser mayor igual a 0";
    }
    if(ancho > this->getAncho()){
        throw "El x debe ser menor igual a " +  this->getAncho();
    }
    if(alto > this->getAlto()){
        throw "El y debe ser menor igual a " +  this->getAlto();
    }
    if(largo > this->getLargo()){
        throw "El < debe ser menor igual a " + this->getLargo();
    }
}

bool Tablero::existeCasillero(unsigned int ancho, unsigned int alto, unsigned int largo) {
	return ((ancho >= 1) &&
			(ancho <= this->ancho) &&
			(alto >= 1) &&
			(alto <= this->alto) &&
			(largo >= 1) &&
			(largo <= this->largo));
}

void Tablero::validarDimensiones(unsigned int ancho, unsigned int alto, unsigned int largo){
	 if(ancho < 1){
	        throw "El x debe ser mayor igual a 0";
	    }
	    if(alto < 1){
	        throw "El y debe ser mayor igual a 0";
	    }
	    if(largo < 1){
	        throw "El z debe ser mayor igual a 0";
	    }
}

void Tablero::imprimirTablero(){
	BMP Tablero;
	Tablero.SetSize(1920,954);

	RGBApixel negro;
	negro.Red = 0; negro.Green = 0; negro.Blue = 0; negro.Alpha = 225;

	RGBApixel rojo;
	rojo.Red = 225; rojo.Green = 0; rojo.Blue = 0; rojo.Alpha = 0;

	unsigned int separacionHorizontal = 30;
	unsigned int separacionVertical = 30;
	float colocarRectaVertical = 0.0;
	float colocarRectaHorizontal = 0.0;

	for(unsigned int k = 1; k <= alto;k++){// Genera los rectangulos de 250 de ancho x 250 de largo
		DrawAALine(Tablero,separacionHorizontal,separacionVertical,250+separacionHorizontal,separacionVertical,negro);
		DrawAALine(Tablero,separacionHorizontal,separacionVertical,separacionHorizontal,250+separacionVertical,negro);
		DrawAALine(Tablero,250+separacionHorizontal,separacionVertical,250+separacionHorizontal,250+separacionVertical,negro);
		DrawAALine(Tablero,separacionHorizontal,250+separacionVertical,250+separacionHorizontal,250+separacionVertical,negro);
		if(k > 9){
			PrintLetter(Tablero,char(49),100+separacionHorizontal,separacionVertical-30,20,rojo);
			PrintLetter(Tablero,char(k+38),120+separacionHorizontal,separacionVertical-30,20,rojo);
		}else{
			PrintLetter(Tablero,char(k+48),100+separacionHorizontal,separacionVertical-30,20,rojo);
		}
		for(unsigned int i = 1; i <= ancho-1;i++){
			colocarRectaVertical += (250)/ancho;
			DrawAALine(Tablero,separacionHorizontal+colocarRectaVertical,separacionVertical,separacionHorizontal+colocarRectaVertical,250+separacionVertical,negro);
		}
		for(unsigned int j = 1; j <= largo-1;j++){
			colocarRectaHorizontal += (250)/largo;
			DrawAALine(Tablero,separacionHorizontal,separacionVertical+colocarRectaHorizontal,250+separacionHorizontal,separacionVertical+colocarRectaHorizontal,negro);
		}

		colocarRectaHorizontal = 0;
		colocarRectaVertical = 0;
		separacionHorizontal += 350;//separacion

		if(k == 5){
			separacionHorizontal = 30;
			separacionVertical = 330;
		}
		if(k == 10){
			separacionHorizontal = 30;
			separacionVertical = 660;
		}
	}

	Tablero.WriteToFile("Probando.bmp");

}

