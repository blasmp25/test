/*
 * TADJuego.cpp
 *
 *  Created on: 21 dic. 2020
 *      Author: Alberto Dominguez Mellado_Alberto Moreno Fernández
 */

#include "TADJuego.h"


void iniciarJuego (TJuego &j){

	//Declaramos las variables para almacenar la información del fichero de configuración
	int deDonde;
	int m[MAX_TAMANO][MAX_TAMANO];
	int col = 0;
	int pos;
	int bolasxpila, pilasCon, pilasSin;

	//Cargamos la información del fichero de configuración en las variables
	if (entornoCargarConfiguracion (pilasCon, pilasSin, bolasxpila, deDonde, j.puntos, m)){

		if (deDonde == 0){
			iniciarTablero(j.b, m, bolasxpila, pilasCon, pilasSin);
		} else {
			iniciarTableroAleatorio(j.b, bolasxpila, pilasCon, pilasSin, m);
		}

		entornoIniciar(CuantasPilas(j.b)); //Iniciamos el entorno gráfico

		for (col = 0; col < CuantasPilas(j.b); col++){
				entornoPintarPila(col, CuantasBolasxpila(j.b, col));
		}

		for (col = 0; col < CuantasPilasCon(j.b); col++){
			pos = CuantasBolasxpila(j.b, col) - 1;
			for (int bola = 0; bola < CuantasBolasxpila(j.b, col); bola++){
				entornoPonerBola(col, m[col][bola], pos, CuantasBolasxpila(j.b, col));
				pos--;
			}
		}

		entornoMarcarPosicion(0);
		entornoPonerPuntuacion(j.puntos);

	}
}


	void terminarJuego (TJuego &j){

		if (j.puntos == 0){
			entornoMostrarMensajeFin("¡¡¡Has perdido!!! :(");
		} else {
			entornoMostrarMensajeFin("¡¡¡Has ganado!!! :)");
		}
	}

	//TipoTecla {TNada, TEnter, TIzquierda, TDerecha,  TSalir, TF1, TF2};
	void jugar(TJuego &j){

		int col = 0;
		int colBola;
		int color = 0;
		int cont = 5;

		bool enter = true; //Determina si al pulsar enter se está seleccionando una bola o se está soltando
		bool salir = false;
		TipoTecla tecla;
		bool sePuedeF1 = true;

		entornoMarcarPosicion(col);
		entornoMostrarMensaje("Pulsa ESC si desea abandonar el juego",1);

		if (Terminar(j.b, j.puntos)){
			terminarJuego(j);
			salir = true;
		}

		while(!salir){

			entornoPonerMvtos(cont);
			entornoPonerPuntuacion(j.puntos);
			tecla = entornoLeerTecla();

			switch(tecla){

			case TEnter:

				if (enter){
					if (!EstaVacia(j.b, col)){
						colBola = col;
						color = Cima(j.b, col);
						entornoSeleccionarBola(col, color);
						Desapilar(j.b, col);
						entornoQuitarBola(col, Cuantos(j.b, col), CuantasBolasxpila(j.b, col));
						enter = false;
					}

				} else {

					if (SePuedeColocar(j.b, color, col)){
						entornoQuitarBolaSeleccion(col);
						for (int i = CuantasBolasxpila(j.b, col) - 1; i >= Cuantos(j.b, col); i--){
							entornoPonerBola(col, color, i, CuantasBolasxpila(j.b, col));
							entornoPausa(0.1);
							entornoQuitarBola(col, i, CuantasBolasxpila(j.b, col));
						}
						entornoPonerBola(col, color, Cuantos(j.b, col), CuantasBolasxpila(j.b, col));
						Apilar(j.b, col, color);
						entornoQuitarBolaSeleccion(col);
						j.puntos = j.puntos - 10;
						if (Terminar(j.b, j.puntos)){
							terminarJuego(j);
							salir = true;
						}
						for(int i = 1; i < cont; i++){
							j.posActual[i] = j.posActual[i+1];
							j.posAnterior[i] = j.posAnterior[i+1];;
							j.color[i] = j.color[i+1];;
						}
						j.posActual[cont] = col;
						j.posAnterior[cont] = colBola;
						j.color[cont] = color;
					} else {
						entornoPonerBola(colBola, color, Cuantos(j.b, colBola), CuantasBolasxpila(j.b, col));
						Apilar(j.b, colBola, color);
						entornoQuitarBolaSeleccion(col);
					}
					enter = true;
				}

				break;


			case TDerecha:
				entornoDesmarcarPosicion(col);
					if (col < (CuantasPilas(j.b) - 1)){
						col++;
						if (!enter){
							entornoSeleccionarBola(col, color);
							entornoQuitarBolaSeleccion(col - 1);
						}
					}else{
						col = 0;
						if (!enter){
							entornoSeleccionarBola(0, color);
							entornoQuitarBolaSeleccion(CuantasPilas(j.b) - 1);
						}
					}
				entornoMarcarPosicion(col);
			break;


			case TIzquierda:
				entornoDesmarcarPosicion(col);
					if (col > 0){
						col--;
						if (!enter){
							entornoSeleccionarBola(col, color);
							entornoQuitarBolaSeleccion(col + 1);
						}
					}else{
						col = (CuantasPilas(j.b)) - 1;
						if (!enter){
							entornoSeleccionarBola((CuantasPilas(j.b)) - 1, color);
							entornoQuitarBolaSeleccion(0);
						}
					}
					entornoMarcarPosicion(col);
			break;


			case TSalir:
				entornoMostrarMensajeFin("Has abandonado");
				salir = true;
				break;


			case TF1:

				if (sePuedeF1){
					entornoPintarPila(CuantasPilas(j.b), CuantasBolasxpila(j.b, col));
					CrearPilaExtra(j.b, CuantasBolasxpila(j.b, col), CuantasPilas(j.b));
					sePuedeF1 = false;
				} else {
					entornoMostrarMensaje("No puedes volver a pedir ayuda", 1);
				}
				break;


			case TF2:

				if (cont > 0){
					if (enter){
						entornoQuitarBola(j.posActual[cont], Cuantos(j.b, j.posActual[cont]) - 1, CuantasBolasxpila(j.b, j.posActual[cont]));
						Desapilar(j.b, j.posActual[cont]);
						Apilar(j.b, j.posAnterior[cont], j.color[cont]);
						entornoPonerBola(j.posAnterior[cont], j.color[cont], Cuantos(j.b, j.posAnterior[cont]) - 1, CuantasBolasxpila(j.b, j.posAnterior[cont]));
						cont--;
						j.puntos = j.puntos - 10;
					}
				} else {
					entornoMostrarMensaje("No puedes volver a deshacer más movimientos", 1);
				}
				break;


			case TNada:
				break;

			}
		}
		entornoTerminar();
}

	void teclas(TJuego &j, TipoTecla tecla, int &col, int &color, int &colBola, bool &enter){

				switch(tecla){

				case TEnter:

					if (enter){
						if (!EstaVacia(j.b, col)){
							colBola = col;
							color = Cima(j.b, col);
							entornoSeleccionarBola(col, color);
							Desapilar(j.b, col);
							entornoQuitarBola(col, Cuantos(j.b, col), CuantasBolasxpila(j.b, col));
							enter = false;
						}

					} else {

						if (SePuedeColocar(j.b, color, col)){
							entornoQuitarBolaSeleccion(col);
							for (int i = CuantasBolasxpila(j.b, col) - 1; i >= Cuantos(j.b, col); i--){
								entornoPonerBola(col, color, i, CuantasBolasxpila(j.b, col));
								entornoPausa(0.1);
								entornoQuitarBola(col, i, CuantasBolasxpila(j.b, col));
							}
							entornoPonerBola(col, color, Cuantos(j.b, col), CuantasBolasxpila(j.b, col));
							Apilar(j.b, col, color);
						} else {
							entornoPonerBola(colBola, color, Cuantos(j.b, colBola), CuantasBolasxpila(j.b, col));
							Apilar(j.b, colBola, color);
							entornoQuitarBolaSeleccion(col);
						}
						enter = true;
					}

					break;


				case TDerecha:
					entornoDesmarcarPosicion(col);
						if (col < (CuantasPilas(j.b)) - 1){
							col++;
							if(!enter){
								entornoSeleccionarBola(col, color);
								entornoQuitarBolaSeleccion(col - 1);
							}
						}else{
							col = 0;
							if(!enter){
								entornoSeleccionarBola(0, color);
								entornoQuitarBolaSeleccion(CuantasPilas(j.b) - 1);
							}
						}
					entornoMarcarPosicion(col);
				break;


				case TIzquierda:
					break;

				case TSalir:
					break;

				case TF1:
					break;

				case TF2:
					break;

				case TNada:
					break;

				}
			}



	void jugarSolo(TJuego &j){

		int col = 0;
		int color;
		int colBola;
		bool salir = false;
		bool enter = true;
		bool colocada;

		if (Terminar(j.b, j.puntos)){
			terminarJuego(j);
			salir = true;
		}

		entornoMarcarPosicion(col);
		while(!salir){

			colocada = false;
			if(SePodraColocar(j.b, Cima(j.b, col), col)){
					teclas(j, TEnter, col, color, colBola, enter);
				while(!colocada){
					entornoPausa(0.1);
					teclas(j, TDerecha, col, color, colBola, enter);
					if(SePuedeColocar(j.b, color, col)){
							teclas(j, TEnter, col, color, colBola, enter);
							teclas(j, TDerecha, col, color, colBola, enter);
							colocada = true;
						if (Terminar(j.b, j.puntos)){
							terminarJuego(j);
							salir = true;
						}
					}
				}
			} else {
				teclas(j, TDerecha, col, color, colBola, enter);
				entornoPausa(0.1);
			}
		}
		entornoTerminar();
	}

