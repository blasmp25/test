/*
 * TADJuego.h
 *
 *  Created on: 21 dic. 2020
 *      Author: Alberto Dominguez Mellado_Alberto Moreno Fernández
 */

#ifndef TADJUEGO_H_
#define TADJUEGO_H_

#include "TADTablero.h"
#include "TADPila.h"
#include "entorno.h"

struct TJuego{

	TTablero b;
	int puntos;

	int posActual[5];
	int posAnterior[5];
	int color[5];

};


/*
  * PRE:  {}
  * POST: {Inicia el juego}
  * Complejidad: O(n²)
  */
void iniciarJuego(TJuego &j);


/*
  * PRE:  {}
  * POST: {Finaliza el juego}
  * Complejidad: O(1)
  */
void terminarJuego(TJuego &j);


/*
  * PRE:  {}
  * POST: {Controla el funcionamiento del juego a través de las teclas}
  * Complejidad: O(n)
  */
void jugar(TJuego &j);

/*
  * PRE:  {}
  * POST: {Controla el funcionamiento de las teclas}
  * Complejidad: O(n)
  */
void teclas(TJuego &j, TipoTecla tecla, int &col, int &color, int &colBola, bool &enter);


/*
  * PRE:  {}
  * POST: {Completa el juego de forma automática utilizando las teclas}
  * Complejidad: O(n)
  */
void jugarSolo(TJuego &j);


#endif /* TADJUEGO_H_ */
