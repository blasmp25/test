/*
 * TADTablero.h
 *
 *  Created on: 21 dic. 2020
 *      Author: Alberto Dominguez Mellado_Alberto Moreno Fernández
 */

#ifndef TADTABLERO_H_
#define TADTABLERO_H_

#include "TADPila.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

const int MAX = 12;

typedef TPila VectorTablero[MAX];

struct TTablero{
	VectorTablero vt;
	int pilasCon;
	int pilasSin;
};


/*
  * PRE:  {bolasxpila > 0 && pilasCon > 0 && pilasSin > 0 && MAX > 0}
  * POST: {Inicia el tablero t, relleno de pilas con tamaño bolasxpila y con bolas de colores seǵun la matriz m}
  * Complejidad: O(n²)
  */
void iniciarTablero(TTablero &t, int m[MAX][MAX], int bolasxpila, int pilasCon, int pilasSin);

/*
  * PRE:  {bolasxpila > 0 && pilasCon > 0 && pilasSin > 0 && MAX > 0}
  * POST: {Inicia el tablero t, relleno de pilas con tamaño bolasxpila y con bolas de colores aleatorios}
  * Complejidad: O(n²)
  */
void iniciarTableroAleatorio(TTablero &t, int bolasxpila, int pilasCon, int pilasSin, int m[MAX][MAX]);

/*
  * PRE:  {t debe estar correctamente iniciado. pos >= 0}
  * POST: {Devuelve true si la pila de la posicion pos está vacía y false en caso contrario}
  * Complejidad: O(1)
  */
bool EstaVacia(TTablero t, int pos);


/*
  * PRE:  {t debe estar correctamente iniciado. pos >= 0}
  * POST: {Devuelve true si la pila de la posicion pos está llena y false en caso contrario}
  * Complejidad: O(1)
  */
bool EstaLlena(TTablero t, int pos);


/*
  * PRE:  {t debe estar correctamente iniciado}
  * POST: {Devuelve el numero de pilas del tablero}
  * Complejidad: O(1)
  */
int CuantasPilas(TTablero t);


/*
  * PRE:  {t debe estar correctamente iniciado}
  * POST: {Devuelve el numero de pilas con bolas del tablero}
  * Complejidad: O(1)
  */
int CuantasPilasCon (TTablero t);


/*
  * PRE:  {t debe estar correctamente iniciado}
  * POST: {Devuelve el numero de pilas sin bolas del tablero}
  * Complejidad: O(1)
  */
int CuantasPilasSin (TTablero t);


/*
  * PRE:  {t debe estar correctamente iniciada. puntos >= 0}
  * POST: {Devuelve true si todas las pilas están llenas de bolas del mismo color y están vacías las restantes o si el número de puntos es 0. Devuelve false en caso contrario}
  * Complejidad: O(n)
  */
bool Terminar (TTablero t, int puntos);


/*
  * PRE:  {t debe estar correctamente iniciado. bolasxpila > 0 && pos >= 0}
  * POST: {Inicia la pila p vacía y de tamaño bolasxpila en la posicion pos}
  * Complejidad: O(1)
  */
void CrearPila (TTablero &t, int bolasxpila, int pos);

/*
  * PRE:  {t debe estar correctamente iniciado. bolasxpila > 0 && pos >= 0}
  * POST: {Inicia una pila p vacía adicional y de tamaño bolasxpila en la posicion pos}
  * Complejidad: O(1)
  */
void CrearPilaExtra (TTablero &t, int bolasxpila, int pos);


/*
  * PRE:  {t debe estar correctamente iniciado y la pila no debe estar llena. pos >= 0 && color debe coincidir con uno de los colores establecidos en el entorno}
  * POST: {Pone una bola del color introducido en la cima de la pila de la posicion pos}
  * Complejidad: O(1)
  */
void Apilar (TTablero &t, int pos, int color);


/*
  * PRE:  {t debe estar correctamente iniciado y la pila no debe estar vacía. pos >= 0}
  * POST: {Borra la bola almacenada en la cima de la pila de la posicion pos}
  * Complejidad: O(1)
  */
void Desapilar (TTablero &t, int pos);


/*
  * PRE:  {t debe estar correctamente iniciado. pos >= 0}
  * POST: {Devuelve el color de la bola que se encuentra en la cima de la pila de la posicion pos}
  * Complejidad: O(1)
  */
int Cima (TTablero t, int pos);


/*
  * PRE:  {t debe estar correctamente iniciado. pos >= 0}
  * POST: {Devuelve el número de bolas de la pila de la posicion pos}
  * Complejidad: O(1)
  */
int Cuantos (TTablero t, int pos);


/*
  * PRE:  {t debe estar correctamente iniciado. pos >= 0}
  * POST: {Devuelve true si todas las bolas de la pila son del mismo color y false en caso contrario}
  * Complejidad: O(n)
  */
bool Iguales (TTablero t, int pos);


/*
  * PRE:  {t debe estar correctamente iniciado. pos >= 0}
  * POST: {Devuelve el numero de bolas que puede haber como maximo en la pila de la posicion pos}
  * Complejidad: O(1)
  */
int CuantasBolasxpila(TTablero t, int pos);


/*
  * PRE:  {t debe estar correctamente iniciado. pos >= 0 && color debe coincidir con uno de los colores establecidos en el entorno}
  * POST: {Devuelve true si se puede colocar una bola del color introducido en la pila de la posicion pos y false en caso contrario}
  * Complejidad: O(1)
  */
bool SePuedeColocar(TTablero t, int color, int pos);


/*
  * PRE:  {t debe estar correctamente iniciado. pos >= 0 && color debe coincidir con uno de los colores establecidos en el entorno}
  * POST: {Devuelve true si la bola del color introducido podrá ser colocada en alguna otra pila y false en caso contrario}
  * Complejidad: O(n)
  */
bool SePodraColocar(TTablero t, int color, int pos);

#endif /* TADTABLERO_H_ */
