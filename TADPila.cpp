/*
 * TADPila.cpp
 *
 *  Created on: 1 dic. 2020
 *      Author: Alberto Dominguez Mellado_Alberto Moreno Fernández
 */

#include "TADPila.h"

void crearPila (TPila &p, int bolasxpila){
	p.ocupadas = 0;
	p.bolasxpila = bolasxpila;
}


bool estaVacia(TPila p){
	bool band = false;

	if (p.ocupadas == 0){
		band = true;
	}

	return band;
}


bool estaLlena(TPila p){
	bool band = false;

		if (p.ocupadas == p.bolasxpila){
			band = true;
		}

	return band;
}


void apilar (TPila &p, int color){
    p.v[p.ocupadas] = color;
	p.ocupadas++;
}


void desapilar (TPila &p){
	p.ocupadas--;
}


int cima (TPila p){
	return p.v[p.ocupadas - 1];
}


int cuantos (TPila p){
	return p.ocupadas;
}

bool iguales (TPila p){

	bool todasIguales = true;

	for (int i = 1; i < p.ocupadas; i++){

		if (p.v[0] != p.v[i]){

			todasIguales = false;

		}
	}
	return todasIguales;
}

int cuantasBolasxpila (TPila p){
	return p.bolasxpila;
}



