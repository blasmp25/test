//============================================================================
// Name        : BallSort.cpp
// Author      : Profesores de la asignatura IP/FP
// Version     : curso 20/21
// Copyright   : Your copyright notice
// Description : Ejemplo de uso del entorno gráfico para el juego BallSortPuzzle
//============================================================================


#include "entorno.h"
#include "TADJuego.h"
#include "PrTADPila.h"
#include "PrTADTablero.h"

int main() {
	TJuego j;

	PruebasPila();
	PruebasTablero();

	iniciarJuego(j);
	jugar(j);
	//jugarSolo(j);
	return 0;
}
