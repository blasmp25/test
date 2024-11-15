/*
 * PrTADTablero.cpp
 *
 *  Created on: 2 ene. 2021
 *      Author: Alberto Dominguez Mellado_Alberto Moreno Fernández
 */

#include "PrTADTablero.h"


void pr_iniciarTablero(){
	cout<<endl<<"Inicio Pruebas iniciarTablero";
	TTablero t;
	int m[MAX][MAX] = {{1, 3, 2},{3, 1, 2},{2, 3, 1},{}};
	iniciarTablero(t, m, 3, 3, 1);

	for(int i = 0; i < CuantasPilasCon(t); i++){
		if (!EstaLlena(t, i) || CuantasBolasxpila(t, i) != 3){
			cout<<endl<<"Pruebas iniciarTablero: Error en la prueba 1";
		}
	}

	for(int i = 0; i < CuantasPilasSin(t); i++){
		if (!EstaVacia(t, CuantasPilasCon(t) + i) || CuantasBolasxpila(t, CuantasPilasCon(t) + i) != 3){
			cout<<endl<<"Pruebas iniciarTablero: Error en la prueba 2";
		}
	}

	cout<<endl<<"Prueba supervisada:";
	cout<<endl<<"1 3 2 0";
	cout<<endl<<"3 1 3 0";
	cout<<endl<<"2 2 1 0";
	cout<<endl<<endl<<"Y es:"<<endl;

	for(int j = 0; j < CuantasBolasxpila(t, 0); j++){
		for(int i = 0; i < CuantasPilas(t); i++){

			cout<<m[i][j]<<" ";

		}
		cout<<endl;
	}

	cout<<endl<<"Fin Pruebas iniciarTablero";
}


void pr_iniciarTableroAleatorio(){
	cout<<endl<<"Inicio Pruebas iniciarTableroAleatorio";
	TTablero t;
	int m[MAX][MAX] = {{1, 3, 2},{3, 1, 2},{2, 3, 1},{}};
	iniciarTableroAleatorio(t, 3, 3, 1, m);

	for(int i = 0; i < CuantasPilasCon(t); i++){
		if (!EstaLlena(t, i) || CuantasBolasxpila(t, i) != 3){
			cout<<endl<<"Pruebas iniciarTableroAleatorio: Error en la prueba 1";
		}
	}

	for(int i = 0; i < CuantasPilasSin(t); i++){
		if (!EstaVacia(t, CuantasPilasCon(t) + i) || CuantasBolasxpila(t, CuantasPilasCon(t) + i) != 3){
			cout<<endl<<"Pruebas iniciarTableroAleatorio: Error en la prueba 2";
		}
	}
	cout<<endl<<"Fin Pruebas iniciarTableroAleatorio";
}



void pr_EstaVacia(){
	cout<<endl<<"Inicio Pruebas EstaVacia";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);
	if (EstaVacia(t, 0)){
		cout<<endl<<"Pruebas EstaVacia: Error en la prueba 1";
	}

	if (!EstaVacia(t, 3)){
		cout<<endl<<"Pruebas EstaVacia: Error en la prueba 2";
	}

	Desapilar(t, 1);
	Desapilar(t, 1);
	Desapilar(t, 1);
	if (!EstaVacia(t, 1)){
		cout<<endl<<"Pruebas EstaVacia: Error en la prueba 3";
	}

	Desapilar(t, 2);
	if (EstaVacia(t, 2)){
		cout<<endl<<"Pruebas EstaVacia: Error en la prueba 4";
	}
	cout<<endl<<"Fin Pruebas EstaVacia";
}


void pr_EstaLlena(){
	cout<<endl<<"Inicio Pruebas EstaLlena";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);
	if (EstaLlena(t, 3)){
		cout<<endl<<"Pruebas EstaLlena: Error en la prueba 1";
	}

	if (!EstaLlena(t, 0)){
		cout<<endl<<"Pruebas EstaLlena: Error en la prueba 2";
	}

	Desapilar(t, 1);
	if (EstaLlena(t, 1)){
		cout<<endl<<"Pruebas EstaLlena: Error en la prueba 3";
	}

	Apilar(t, 3, 1);
	if (!EstaLlena(t, 2)){
		cout<<endl<<"Pruebas EstaLlena: Error en la prueba 4";
	}
	cout<<endl<<"Fin Pruebas EstaLlena";
}


void pr_CuantasPilas(){
	cout<<endl<<"Inicio Pruebas CuantasPilas";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
    iniciarTablero(t, m, 3, 3, 1);
	if (CuantasPilas(t) != 4){
		cout<<endl<<"Pruebas CuantasPilas: Error en la prueba 1";
	}

	CrearPilaExtra(t, 3, 4);
	if (CuantasPilas(t) != 5){
		cout<<endl<<"Pruebas CuantasPilas: Error en la prueba 2";
	}

	CrearPilaExtra(t, 3, 5);
	CrearPilaExtra(t, 3, 6);
	if (CuantasPilas(t) != 7){
		cout<<endl<<"Pruebas CuantasPilas: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas CuantasPilas";
}


void pr_CuantasPilasCon(){
	cout<<endl<<"Inicio Pruebas CuantasPilasCon";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);
	if (CuantasPilasCon(t) != 3){
		cout<<endl<<"Pruebas CuantasPilasCon: Error en la prueba 1";
	}

	CrearPilaExtra(t, 3, 4);
	if (CuantasPilasCon(t) != 3){
		cout<<endl<<"Pruebas CuantasPilasCon: Error en la prueba 2";
	}
	cout<<endl<<"Fin Pruebas CuantasPilasCon";
}


void pr_CuantasPilasSin(){
	cout<<endl<<"Inicio Pruebas CuantasPilasSin";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);

	if (CuantasPilasSin(t) != 1){
		cout<<endl<<"Pruebas CuantasPilasSin: Error en la prueba 1";
	}

	CrearPilaExtra(t, 3, 4);
	if (CuantasPilasSin(t) != 2){
		cout<<endl<<"Pruebas CuantasPilasSin: Error en la prueba 2";
	}

	CrearPilaExtra(t, 3, 5);
	CrearPilaExtra(t, 3, 6);
	if (CuantasPilasSin(t) != 4){
		cout<<endl<<"Pruebas CuantasPilasSin: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas CuantasPilasSin";
}


void pr_Terminar(){
	cout<<endl<<"Inicio Pruebas Terminar";
	TTablero t;
	int m[MAX][MAX] = {{1, 1, 1},{3, 2, 2},{2, 3, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);

	if (!Terminar(t, 0)){
		cout<<endl<<"Pruebas Terminar: Error en la prueba 1";
	}

	if (Terminar(t, 500)){
		cout<<endl<<"Pruebas Terminar: Error en la prueba 2";
	}

	Desapilar(t, 1);
	Apilar(t, 1, 2);
	Desapilar(t, 2);
	Apilar(t, 2, 3);
	if (!Terminar(t, 100)){
		cout<<endl<<"Pruebas Terminar: Error en la prueba 3";
	}

	Desapilar(t, 2);
	Apilar(t, 3, 3);
	if (Terminar(t, 200)){
		cout<<endl<<"Pruebas Terminar: Error en la prueba 4";
	}
	cout<<endl<<"Fin Pruebas Terminar";
}


void pr_CrearPila(){
	cout<<endl<<"Inicio Pruebas CrearPila";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);

	if (Cuantos(t, 0) != 3 || CuantasBolasxpila(t, 0) != 3){
		cout<<endl<<"Pruebas CrearPila: Error en la prueba 1";
	}

	if (Cuantos(t, 3) != 0 || CuantasBolasxpila(t, 3) != 3){
		cout<<endl<<"Pruebas CrearPila: Error en la prueba 2";
	}
	cout<<endl<<"Fin Pruebas CrearPila";
}


void pr_CrearPilaExtra(){
	cout<<endl<<"Inicio Pruebas CrearPilaExtra";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);

	CrearPilaExtra(t, 3, 4);
	if (!EstaVacia(t, 4) || CuantasBolasxpila(t, 4) != 3 || CuantasPilasSin(t) != 2){
		cout<<endl<<"Pruebas CrearPilaExtra: Error en la prueba 1";
	}
	cout<<endl<<"Fin Pruebas CrearPilaExtra";
}


void pr_Apilar(){
	cout<<endl<<"Inicio Pruebas Apilar";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);


	Apilar(t, 3, 1);
	if (Cima(t, 3) != 1 || Cuantos(t, 3) != 1){
		cout<<endl<<"Pruebas Apilar: Error en la prueba 1";
	}

	Apilar(t, 3, 3);
	Apilar(t, 3, 2);
	if (Cima(t, 3) != 2 || Cuantos(t, 3) != 3){
		cout<<endl<<"Pruebas Apilar: Error en la prueba 2";
	}

	Desapilar(t, 0);
	Apilar(t, 0, 4);
	if (Cima(t, 0) != 4 || Cuantos(t, 0) != 3){
		cout<<endl<<"Pruebas Apilar: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas Apilar";
}


void pr_Desapilar(){
	cout<<endl<<"Inicio Pruebas Desapilar";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);

	Desapilar(t, 0);
	if (Cuantos(t, 0) != 2){
		cout<<endl<<"Pruebas Desapilar: Error en la prueba 1";
	}

	Desapilar(t, 0);
	if (Cuantos(t, 0) != 1){
		cout<<endl<<"Pruebas Desapilar: Error en la prueba 2";
	}

	Desapilar(t, 0);
	if (Cuantos(t, 0) != 0){
		cout<<endl<<"Pruebas Desapilar: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas Desapilar";
}


void pr_Cima(){
	cout<<endl<<"Inicio Pruebas Cima";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);

	if (Cima(t, 0) != 1){
		cout<<endl<<"Pruebas Cima: Error en la prueba 1";
	}

	Apilar(t, 3, 2);
	if (Cima(t, 3) != 2){
		cout<<endl<<"Pruebas Cima: Error en la prueba 2";
	}

	Apilar(t, 3, 1);
	Apilar(t, 3, 4);
	if (Cima(t, 3) != 4){
		cout<<endl<<"Pruebas Cima: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas Cima";
}


void pr_Cuantos(){
	cout<<endl<<"Inicio Pruebas Cuantos";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);


	if (Cuantos(t, 0) != 3){
		cout<<endl<<"Pruebas Cuantos: Error en la prueba 1";
	}

	if (Cuantos(t, 3) != 0){
		cout<<endl<<"Pruebas Cuantos: Error en la prueba 2";
	}

	Apilar(t, 3, 2);
	if (Cuantos(t, 3) != 1){
		cout<<endl<<"Pruebas Cuantos: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas Cuantos";
}


void pr_Iguales(){
	cout<<endl<<"Inicio Pruebas Iguales";
	TTablero t;
	int m[MAX][MAX] = {{1, 1, 1},{3, 2, 2},{2, 3, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);

	if (!Iguales(t, 0)){
		cout<<endl<<"Pruebas Iguales: Error en la prueba 1";
	}

	Apilar(t, 3, 2);
	if (!Iguales(t, 3)){
		cout<<endl<<"Pruebas Iguales: Error en la prueba 2";
	}

	Apilar(t, 3, 2);
	Apilar(t, 3, 3);
	if (Iguales(t, 2)){
		cout<<endl<<"Pruebas Iguales: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas Iguales";
}


void pr_CuantasBolasxpila(){
	cout<<endl<<"Inicio Pruebas CuantasBolasxpila";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);

	if (CuantasBolasxpila(t, 0) != 3){
		cout<<endl<<"Pruebas CuantasBolasxpila: Error en la prueba 1";
	}

	if (CuantasBolasxpila(t, 3) != 3){
			cout<<endl<<"Pruebas CuantasBolasxpila: Error en la prueba 2";
	}
	cout<<endl<<"Fin Pruebas CuantasBolasxpila";
}


void pr_SePuedeColocar(){
	cout<<endl<<"Inicio Pruebas SePuedeColocar";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);

	if (!SePuedeColocar(t, 1, 3)){
		cout<<endl<<"Pruebas SePuedeColocar: Error en la prueba 1";
	}
	Apilar(t, 3, 1);

	if (SePuedeColocar(t, 3, 0)){
		cout<<endl<<"Pruebas SePuedeColocar: Error en la prueba 2";
	}


	if (!SePuedeColocar(t, 1, 3)){
		cout<<endl<<"Pruebas SePuedeColocar: Error en la prueba 3";
	}
	Apilar(t, 3, 1);

	if (SePuedeColocar(t, 2, 3)){
		cout<<endl<<"Pruebas SePuedeColocar: Error en la prueba 4";
	}
	cout<<endl<<"Fin Pruebas SePuedeColocar";
}


void pr_SePodraColocar(){
	cout<<endl<<"Inicio Pruebas SePodraColocar";
	TTablero t;
	int m[MAX][MAX] = {{1, 2, 3},{1, 2, 3},{1, 2, 3},{}};
	iniciarTablero(t, m, 3, 3, 1);

	if (!SePodraColocar(t, 1, 0)){
		cout<<endl<<"Pruebas SePodraColocar: Error en la prueba 1";
	}
	Desapilar(t, 0);
	Apilar(t, 3, 1);

	if (!SePodraColocar(t, 1, 1)){
		cout<<endl<<"Pruebas SePodraColocar: Error en la prueba 2";
	}
	Desapilar(t, 1);
	Apilar(t, 3, 1);

	if (!SePodraColocar(t, 2, 0)){
		cout<<endl<<"Pruebas SePodraColocar: Error en la prueba 3";
	}
	Desapilar(t, 0);
	Apilar(t, 1, 2);

	if (SePodraColocar(t, 3, 0)){
		cout<<endl<<"Pruebas SePodraColocar: Error en la prueba 4";
	}
	cout<<endl<<"Fin Pruebas SePodraColocar";
}


void PruebasTablero(){
	cout<<endl<<endl<<"----------Inicio PruebasTablero----------";
	pr_iniciarTablero();
	pr_iniciarTableroAleatorio();
	pr_EstaVacia();
	pr_EstaLlena();
	pr_CuantasPilas();
	pr_CuantasPilasCon();
	pr_CuantasPilasSin();
	pr_Terminar();
	pr_CrearPila();
	pr_CrearPilaExtra();
	pr_Apilar();
	pr_Desapilar();
	pr_Cima();
	pr_Cuantos();
	pr_Iguales();
	pr_CuantasBolasxpila();
	pr_SePuedeColocar();
	pr_SePodraColocar();
	cout<<endl<<"----------Final PruebasTablero----------"<<endl;
}














