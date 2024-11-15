/*
 * PrTADPila.cpp
 *
 *  Created on: 2 ene. 2021
 *      Author: Alberto Dominguez Mellado_Alberto Moreno Fernández
 */

#include "PrTADPila.h"


void pr_crearPila(){
	cout<<endl<<"Inicio Pruebas crearPila";
	TPila p;

	crearPila(p, 1);
	if (p.ocupadas != 0 || p.bolasxpila != 1){
		cout<<endl<<"Pruebas crearPila: Error en la prueba 1";
	}

	crearPila(p, 2);
	if (p.ocupadas != 0 || p.bolasxpila != 2){
		cout<<endl<<"Pruebas crearPila: Error en la prueba 2";
	}

	crearPila(p, 5);
	if (p.ocupadas != 0 || p.bolasxpila != 5){
		cout<<endl<<"Pruebas crearPila: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas crearPila";
}


void pr_estaVacia(){
	cout<<endl<<"Inicio Pruebas estaVacia";
	TPila p;

	crearPila(p, 2);
	if (!estaVacia(p)){
		cout<<endl<<"Pruebas estaVacia: Error en la prueba 1";
	}

	apilar(p, 1);
	if (estaVacia(p)){
		cout<<endl<<"Pruebas estaVacia: Error en la prueba 2";
	}

	desapilar(p);
	if (!estaVacia(p)){
		cout<<endl<<"Pruebas estaVacia: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas estaVacia";
}


void pr_estaLlena(){
	cout<<endl<<"Inicio Pruebas estaLlena";
	TPila p;

	crearPila(p, 2);
	if (estaLlena(p)){
		cout<<endl<<"Pruebas estaLlena: Error en la prueba 1";
	}

	apilar(p, 2);
	apilar(p, 2);
	if (!estaLlena(p)){
		cout<<endl<<"Pruebas estaLlena: Error en la prueba 2";
	}

	desapilar(p);
	if (estaLlena(p)){
		cout<<endl<<"Pruebas estaLlena: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas estaLlena";
}


void pr_apilar(){
	cout<<endl<<"Inicio Pruebas apilar";
	TPila p;
	crearPila(p, 4);

	apilar(p, 1);
	if (p.v[p.ocupadas - 1] != 1 || p.ocupadas != 1){
		cout<<endl<<"Pruebas apilar: Error en la prueba 1";
	}

	apilar(p, 3);
	if (p.v[p.ocupadas - 1] != 3 || p.ocupadas != 2){
		cout<<endl<<"Pruebas apilar: Error en la prueba 2";
	}

	apilar(p, 7);
	if (p.v[p.ocupadas - 1] != 7 || p.ocupadas != 3){
		cout<<endl<<"Pruebas apilar: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas apilar";
}


void pr_desapilar(){
	cout<<endl<<"Inicio Pruebas desapilar";
	TPila p;
	crearPila(p, 5);
	apilar(p, 1);
	apilar(p, 1);
	apilar(p, 1);
	apilar(p, 1);


	desapilar(p);
	if (p.ocupadas != 3){
		cout<<endl<<"Pruebas desapilar: Error en la prueba 1";
	}

	desapilar(p);
	if (p.ocupadas != 2){
		cout<<endl<<"Pruebas desapilar: Error en la prueba 2";
	}

	desapilar(p);
	if (p.ocupadas != 1){
		cout<<endl<<"Pruebas desapilar: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas desapilar";
}


void pr_cima(){
	cout<<endl<<"Inicio Pruebas cima";
	TPila p;
	crearPila(p, 5);
	apilar(p, 1);
	apilar(p, 3);
	apilar(p, 4);

	if (cima(p) != 4){
		cout<<endl<<"Pruebas cima: Error en la prueba 1";
	}

	desapilar(p);
	if (cima(p) != 3){
		cout<<endl<<"Pruebas cima: Error en la prueba 2";
	}

	desapilar(p);
	if (cima(p) != 1){
		cout<<endl<<"Pruebas cima: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas cima";
}


void pr_cuantos(){
	cout<<endl<<"Inicio Pruebas cuantos";
	TPila p;

	crearPila(p, 5);
	if (cuantos(p) != 0){
		cout<<endl<<"Pruebas cuantos: Error en la prueba 1";
	}

	apilar(p, 1);
	if (cuantos(p) != 1){
		cout<<endl<<"Pruebas cuantos: Error en la prueba 2";
	}

	apilar(p, 2);
	apilar(p, 2);
	if (cuantos(p) != 3){
		cout<<endl<<"Pruebas cuantos: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas cuantos";
}


void pr_iguales(){
	cout<<endl<<"Inicio Pruebas iguales";
	TPila p;
	crearPila(p, 5);

	apilar(p, 2);
	apilar(p, 2);
	apilar(p, 2);
	if (!iguales(p)){
		cout<<endl<<"Pruebas iguales: Error en la prueba 1";
	}

	desapilar(p);
	if (!iguales(p)){
		cout<<endl<<"Pruebas iguales: Error en la prueba 2";
	}

	apilar(p, 1);
	if (iguales(p)){
		cout<<endl<<"Pruebas iguales: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas iguales";
}


void pr_cuantasBolasxpila(){
	cout<<endl<<"Inicio Pruebas cuantasBolasxpila";
	TPila p;

	crearPila(p, 5);
	if (cuantasBolasxpila(p) != 5){
		cout<<endl<<"Pruebas cuantasBolasxpila: Error en la prueba 1";
	}

	crearPila(p, 2);
	if (cuantasBolasxpila(p) != 2){
		cout<<endl<<"Pruebas cuantasBolasxpila: Error en la prueba 2";
	}

	crearPila(p, 6);
	if (cuantasBolasxpila(p) != 6){
		cout<<endl<<"Pruebas cuantasBolasxpila: Error en la prueba 3";
	}
	cout<<endl<<"Fin Pruebas cuantasBolasxpila";
}

void PruebasPila(){

	cout<<"----------Inicio PruebasPila----------";
	pr_crearPila();
	pr_estaVacia();
	pr_estaLlena();
	pr_apilar();
	pr_desapilar();
	pr_cima();
	pr_cuantos();
	pr_iguales();
	pr_cuantasBolasxpila();
	cout<<endl<<"----------Final PruebasPila----------";
}







