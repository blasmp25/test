/*
 * PrTADTablero.h
 *
 *  Created on: 2 ene. 2021
 *      Author: Alberto Dominguez Mellado_Alberto Moreno Fernández
 */

#ifndef PRTADTABLERO_H_
#define PRTADTABLERO_H_

#include "TADTablero.h"
#include <iostream>
using namespace std;


/*
  * EstaLlena = true			CuantasBolasxpila = 3
  * EstaVacia = true			CuantasBolasxpila = 3
*/
void pr_iniciarTablero();


/*
  * EstaLlena = true			CuantasBolasxpila = 3
  * EstaVacia = true			CuantasBolasxpila = 3
*/
void pr_iniciarTableroAleatorio();


/*
  * EstaVacia = false
  * EstaVacia = true
  * EstaVacia = true
  * EstaVacia = false
*/
void pr_EstaVacia();


/*
  * EstaVacia = false
  * EstaVacia = true
  * EstaVacia = false
  * EstaVacia = true
*/
void pr_EstaLlena();


/*
  * CuantasPilas = 4
  * CuantasPilas = 5
  * CuantasPilas = 7
*/
void pr_CuantasPilas();


/*
  * CuantasPilasCon = 3
  * CuantasPilasCon = 3
*/
void pr_CuantasPilasCon();


/*
  * CuantasPilasSin = 1
  * CuantasPilasSin = 2
  * CuantasPilasSin = 4
*/
void pr_CuantasPilasSin();


/*
  * Terminar = true
  * Terminar = false
  * Terminar = true
  * Terminar = false
*/
void pr_Terminar();


/*
  * Cuantos = 3				CuantasBolasxpila = 3
  * Cuantos = 0				CuantasBolasxpila = 3
*/
void pr_CrearPila();


/*
  * EstaVacia = true		CuantasBolasxpila = 3			CuantasPilasSin = 2
*/
void pr_CrearPilaExtra();


/*
  * Cima = 1			Cuantos = 1
  * Cima = 2			Cuantos = 3
  * Cima = 4			Cuantos = 3
*/
void pr_Apilar();


/*
  * Cuantos = 2
  * Cuantos = 1
  * Cuantos = 0
*/
void pr_Desapilar();


/*
  * Cima = 1
  * Cima = 2
  * Cima = 4
*/
void pr_Cima();


/*
  * Cuantos = 3
  * Cuantos = 0
  * Cuantos = 1
*/
void pr_Cuantos();


/*
  * Iguales = true
  * Iguales = true
  * Iguales = false
*/
void pr_Iguales();

/*
  * CuantasBolasxpila = 3
  * CuantasBolasxpila = 3
*/
void pr_CuantasBolasxpila();


/*
  * SePuedeColocar = true
  * SePuedeColocar = false
  * SePuedeColocar = true
  * SePuedeColocar = false
*/
void pr_SePuedeColocar();


/*
  * SePodraColocar = true
  * SePodraColocar = true
  * SePodraColocar = true
  * SePodraColocar = false
*/
void pr_SePodraColocar();


void PruebasTablero();


#endif /* PRTADTABLERO_H_ */
