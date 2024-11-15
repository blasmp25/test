/*
 * TADPIla.h
 *
 *  Created on: 1 dic. 2020
 *      Author: Alberto Dominguez Mellado_Alberto Moreno Fernández
 */

#ifndef TADPILA_H_
#define TADPILA_H_

const int TAM = 6;

typedef int VectorPila[TAM];

struct TPila{
	VectorPila v;
	int ocupadas;
	int bolasxpila;
};

/*
  * PRE:  {bolasxpila > 0}
  * POST: {Inicia la pila p vacía y de tamaño bolasxpila}
  * Complejidad: O(1)
  */
void crearPila (TPila &p, int bolasxpila);


/*
  * PRE:  {p debe estar correctamente iniciado}
  * POST: {Devuelve true si la pila está vacía y false en caso contrario}
  * Complejidad: O(1)
  */
bool estaVacia(TPila p);


/*
  * PRE:  {p debe estar correctamente iniciado}
  * POST: {Devuelve true si la pila está llena y false en caso contrario}
  * Complejidad: O(1)
  */
bool estaLlena(TPila p);



/*
  * PRE:  {p debe estar correctamente iniciada y no estar llena. color debe coincidir con uno de los colores establecidos en el entorno}
  * POST: {Pone una bola del color introducido en la cima de la pila}
  * Complejidad: O(1)
  */
void apilar (TPila &p, int color);


/*
  * PRE:  {p debe estar correctamente iniciado y no estar vacía}
  * POST: {Borra la bola almacenada en la cima de la pila}
  * Complejidad: O(1)
  */
void desapilar (TPila &p);




/*
  * PRE:  {p debe estar correctamente iniciado y no estar vacía}
  * POST: {Devuelve el color de la bola que se encuentra en la cima de la pila}
  * Complejidad: O(1)
  */
int cima (TPila p);


/*
   * PRE:  {p debe estar correctamente iniciado}
  * POST: {Devuelve el número de elementos de la pila}
  * Complejidad: O(1)
  */
int cuantos (TPila p);


/*
  * PRE:  {p debe estar correctamente iniciado}
  * POST: {Devuelve true si todas las bolas de la pila son del mismo color y false en caso contrario}
  * Complejidad: O(n)
  */
bool iguales(TPila p);


/*
  * PRE:  {p debe estar correctamente iniciado}
  * POST: {Devuelve el numero de bolas que puede haber como maximo en una pila}
  * Complejidad: O(1)
  */
int cuantasBolasxpila (TPila p);

#endif /* TADPILA_H_ */
