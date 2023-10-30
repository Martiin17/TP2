/*
 * ProbandoTablero2.cpp
 *
 *  Created on: 26/10/2023
 *      Author: algo2
 */


#include "EasyBMP_Geometry.h"
#include "EasyBMP_Font.h"
#include "EasyBMP.h"

using namespace std;

/*
int main(){
	BMP Tablero;
	unsigned int ancho= 3, largo= 3, alto = 3;
	//Habria que validar que z no sea mayor a 15

	Tablero.SetSize(1920,954);
	RGBApixel negro;
	negro.Red = 0; negro.Green = 0; negro.Blue = 0; negro.Alpha = 225;
	RGBApixel rojo;
	rojo.Red = 225; rojo.Green = 0; rojo.Blue = 0; rojo.Alpha = 0;


	unsigned int separacionHorizontal = 30;
	unsigned int separacionVertical = 30;
	float colocarRectaVertical = 0.0; //no es unsigned int para tener mas precision al hacer la cuenta
	float colocarRectaHorizontal = 0.0;

	char ficha = '*';

	RGBApixel azul;
	azul.Red = 0; azul.Green = 0; azul.Blue = 225; azul.Alpha = 0;

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


			//PrintLetter(Tablero,ficha,(separacionVertical+colocarRectaHorizontal)/(largo-1),(separacionHorizontal+colocarRectaVertical)/(ancho-1),20,azul);
			//PrintLetter(Tablero,ficha,(separacionHorizontal+colocarRectaVertical)/2,(separacionVertical+colocarRectaHorizontal)/2,20,azul);
		}

		//PrintLetter(Tablero,ficha,62.5+separacionHorizontal,62.5+separacionVertical,20,azul);

		/*
		 * colocarRectaVertical = 0;
		colocarRectaHorizontal = 0;

		for(unsigned int h = 1; h <= largo; h++){
			if(h>1){
				colocarRectaHorizontal += 250/(2*largo); //tengo que sumarlo 2 veces
			}
			colocarRectaVertical = 0;
			colocarRectaHorizontal += 250/(2*largo);
			for(unsigned int l = 1; l <= ancho; l++){
				colocarRectaVertical += 250/(2*ancho);
				PrintLetter(Tablero,ficha,colocarRectaVertical+separacionHorizontal,colocarRectaHorizontal+separacionVertical,5,azul);
				colocarRectaVertical += 250/(2*ancho); //tengo que sumarlo 2 veces
			}
		}
		*/
/*
		//RELLENA CON '*' el tablero
		colocarRectaVertical = 250/(2*largo);
		colocarRectaHorizontal = 250/(2*ancho);

		for(unsigned int h = 1; h <= largo; h++){
			if(h>1){
				colocarRectaHorizontal += 250/(largo);
			}
			colocarRectaVertical = 250/(2*ancho);
			for(unsigned int l = 1; l <= ancho; l++){
				PrintLetter(Tablero,ficha,colocarRectaVertical+separacionHorizontal,colocarRectaHorizontal+separacionVertical,5,azul);
				colocarRectaVertical += 250/(ancho);
			}
		}
		//Hasta aca rellena

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

	unsigned int x= 1, y = 1, z = 1;

	ficha = '1';

	//PrintLetter(Tablero,'1',x*250/(ancho)+30+350*(z-1),y*250/(largo)+30+350*(z-1),5,azul);

	PrintLetter(Tablero,ficha,(250/(2*largo))+30, (250/(2*ancho))+30,5,azul);



	/*unsigned int x= 1, y= 1, z = 1;
	char ficha = '1';

	RGBApixel azul;
	azul.Red = 0; azul.Green = 0; azul.Blue = 225; azul.Alpha = 0;

	PrintLetter(Tablero,ficha,0,100,20,azul);
	PrintLetter(Tablero,ficha,50*x,200*y,20,azul);

	antes:
	for(unsigned int j = 1; j <= largo-1;j++){
		colocarRectaVertical += (250)/largo; //Divido el ancho por la cant de dimensiones
		.....
		*/

/*
	Tablero.WriteToFile("Probando3.bmp");
}*/

