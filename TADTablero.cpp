/*
 * TADTablero.cpp
 *
 *  Created on: 21 dic. 2020
 *      Author: Alberto Dominguez Mellado_Alberto Moreno Fernández
 */

#include "TADTablero.h"


void iniciarTablero(TTablero &t, int m[MAX][MAX], int bolasxpila, int pilasCon, int pilasSin){
	t.pilasCon = pilasCon;
	t.pilasSin = pilasSin;

	for (int i = 0; i < pilasCon+pilasSin; i++){
		crearPila(t.vt[i], bolasxpila);
	}

	for (int x = 0; x < pilasCon; x++){
		for (int j = bolasxpila - 1; j >= 0; j--){
			apilar(t.vt[x], m[x][j]);
		}
	}
}

void iniciarTableroAleatorio(TTablero &t, int bolasxpila, int pilasCon, int pilasSin, int m[MAX][MAX]){

	t.pilasCon = pilasCon;
	t.pilasSin = pilasSin;
	srand (time(NULL));
	int cont = 0;
	int pos1, pos2, pos3, pos4;
	int aux;

	for (int i = 0; i < pilasCon+pilasSin; i++){
		crearPila(t.vt[i], bolasxpila);
	}

	for (int i = 0; i < pilasCon; i++){
		for (int j = 0; j < bolasxpila; j++){
			m[i][j] = i+1;
		}
	}

	while(cont < pilasCon*bolasxpila){
		pos1 = 0+rand()%(t.pilasCon);
		pos2 = 0+rand()%(cuantasBolasxpila(t.vt[0]));
		pos3 = 0+rand()%(t.pilasCon);
		pos4 = 0+rand()%(cuantasBolasxpila(t.vt[0]));

		aux = m[pos1][pos2];
		m[pos1][pos2] = m[pos3][pos4];
		m[pos3][pos4] = aux;

		cont++;
	}

	for (int i = 0; i < pilasCon; i++){
		for (int j = bolasxpila - 1; j >= 0; j--){
			apilar(t.vt[i], m[i][j]);
		}
	}
}

bool EstaVacia(TTablero t, int pos){
	return estaVacia(t.vt[pos]);
}


bool EstaLlena(TTablero t, int pos){
	return estaLlena(t.vt[pos]);
}


int CuantasPilas (TTablero t){
	return t.pilasCon+t.pilasSin;
}


int CuantasPilasCon (TTablero t){
	return t.pilasCon;
}


int CuantasPilasSin (TTablero t){
	return t.pilasSin;
}


bool Terminar (TTablero t, int puntos){

	int cont = 0;
	int pos = 0;
	bool acabar = false;

	if (puntos == 0){
		acabar = true;
	} else {
		while (pos < t.pilasCon+t.pilasSin){
			if (estaVacia(t.vt[pos]) || (iguales(t.vt[pos]) && estaLlena(t.vt[pos]))){
				cont++;
			}
				pos++;
		}
	}
	if (cont == pos){
		acabar = true;
	}

	return acabar;
}


void CrearPila (TTablero &t, int bolasxpila, int pos){
	crearPila(t.vt[pos], bolasxpila);
}


void CrearPilaExtra (TTablero &t, int bolasxpila, int pos){
	crearPila(t.vt[pos], bolasxpila);
	t.pilasSin++;
}


void Apilar (TTablero &t, int pos, int color){
	apilar(t.vt[pos], color);
}


void Desapilar (TTablero &t, int pos){
	desapilar(t.vt[pos]);
}


int Cima (TTablero t, int pos){
	return cima(t.vt[pos]);
}


int Cuantos (TTablero t, int pos){
	return cuantos(t.vt[pos]);
}


bool Iguales (TTablero t, int pos){
	return iguales(t.vt[pos]);
}


int CuantasBolasxpila(TTablero t, int pos){
	return cuantasBolasxpila(t.vt[pos]);
}


bool SePuedeColocar (TTablero t, int color, int pos){

	bool sePuede = false;

	if ((Cima(t, pos) == color || EstaVacia(t, pos)) && !EstaLlena(t, pos)){

		sePuede = true;

	}

	return sePuede;
}


bool SePodraColocar(TTablero t, int color, int pos){

	bool sePodra = false;
	int i = pos + 1;
	int j = pos - 1;

	if (!Iguales(t, pos)){
		while(i < CuantasPilas(t) && !sePodra){
			if(SePuedeColocar(t, color, i)){
				sePodra = true;
			}
			i++;
		}
		while(j >= 0 && !sePodra){
			if(SePuedeColocar(t, color, j)){
				sePodra = true;
			}
			j--;
		}
	}

	i = pos + 1;
	j = pos - 1;
	while(i < CuantasPilas(t) && !sePodra){
		if(Iguales(t, i) && Cima(t, i) == color && Cuantos(t, pos) <= Cuantos(t, i)){
			sePodra = true;
		}
		i++;
	}
	while(j >= 0 && !sePodra){
		if(Iguales(t, j) && Cima(t, j) == color && Cuantos(t, pos) <= Cuantos(t, j)){
			sePodra = true;
		}
			j--;
		}

	return sePodra;
}
