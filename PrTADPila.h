/*
 * PrTADPila.h
 *
 *  Created on: 2 ene. 2021
 *      Author: Alberto Dominguez Mellado_Alberto Moreno Fernández
 */

#ifndef PRTADPILA_H_
#define PRTADPILA_H_

#include "TADPila.h"
#include<iostream>
using namespace std;



/*
  * ocupadas = 0		bolasxpila = 1
  * ocupadas = 0		bolasxpila = 2
  * ocupadas = 0		bolasxpila = 5
*/
void pr_crearPila();


/*
  * estaVacia = true
  * estaVacia = false
  * estaVacia = true
*/
void pr_estaVacia();


/*
  * estaLlena = false
  * estaLlena = true
  * estaLlena = false
*/
void pr_estaLlena();


/*
  * ocupadas = 1		color = 1
  * ocupadas = 2		color = 3
  * ocupadas = 3		color = 7
*/
void pr_apilar();


/*
  * ocupadas = 3
  * ocupadas = 2
  * ocupadas = 1
*/
void pr_desapilar();


/*
  * cima = 4
  * cima = 3
  * cima = 1
*/
void pr_cima();


/*
  * cuantos = 0
  * cuantos = 1
  * cuantos = 3
*/
void pr_cuantos();


/*
  * iguales = true
  * iguales = true
  * iguales = false
*/
void pr_iguales();


/*
  * cuantasBolas = 5
  * cuantasBolas = 2
  * cuantasBolas = 6
*/
void pr_cuantasBolasMax();

void PruebasPila();

#endif /* PRTADPILA_H_ */
