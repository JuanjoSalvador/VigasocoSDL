// Malaquias.cpp
//
/////////////////////////////////////////////////////////////////////////////

#include "Abad.h"
#include "Berengario.h"
#include "Bernardo.h"
#include "BuscadorRutas.h"
#include "Controles.h"
#include "GestorFrases.h"
#include "Guillermo.h"
#include "Juego.h"
#include "Logica.h"
#include "Malaquias.h"
#include "MotorGrafico.h"
#include "Objeto.h"
#include "Puerta.h"
#include "Severino.h"

#ifdef LENG
#include <stdio.h>
#endif

using namespace Abadia;

/////////////////////////////////////////////////////////////////////////////
// posiciones a las que puede ir el personaje según el estado
/////////////////////////////////////////////////////////////////////////////

PosicionJuego Malaquias::posicionesPredef[9] = {
#ifdef LENG
	//PosicionJuego(ARRIBA, 0x88, 0x84, 0x02),	// posición en la entrada de la abadía
	PosicionJuego(ARRIBA, 0x89, 0x8D, 0x02),	// posición en la entrada de la abadía
	PosicionJuego(ABAJO, 0x64, 0x2B, 0x00),		// posición en la cripta, junto a las calaveras
#else
	PosicionJuego(ABAJO, 0x84, 0x48, 0x02),		// posición en la iglesia
	PosicionJuego(ARRIBA, 0x2f, 0x37, 0x02),	// posición en el refectorio
	PosicionJuego(ABAJO, 0x37, 0x38, 0x0f),		// posición en la mesa que está en la entrada del pasillo para poder subir a la biblioteca
	PosicionJuego(IZQUIERDA, 0x3a, 0x34, 0x0f),	// posición para cerrar el paso al pasillo que lleva a la biblioteca
	PosicionJuego(DERECHA, 0x5d, 0x77, 0x00),	// posición para cerrar las 2 puertas del ala izquierda de la abadía
	PosicionJuego(DERECHA, 0x58, 0x2a, 0x00),	// posición en frente de la mesa de la cocina de delante del pasadizo
	PosicionJuego(ABAJO, 0x35, 0x37, 0x13),		// posición donde deja la llave en la mesa que está en la entrada del pasillo para poder subir a la biblioteca
	PosicionJuego(DERECHA, 0xbc, 0x18, 0x02),	// posición en su celda
	PosicionJuego(DERECHA, 0x68, 0x52, 0x00)	// posición en la celda de severino
#endif
};

/////////////////////////////////////////////////////////////////////////////
// inicialización y limpieza
/////////////////////////////////////////////////////////////////////////////

Malaquias::Malaquias(SpriteMonje *spr) : Monje(spr)
{
	// coloca los datos de la cara de malaquías
	// CPC
	/*
	datosCara[0] = 0xb1cb;
	datosCara[1] = 0xb1cb + 0x32;
	*/
	// VGA
#ifdef LENG
	// En LENG Randolph Carter va encapuchado
	datosCara[0] = 69308;
	datosCara[1] = 69308+0x32*4;
#else
        datosCara[0] = 67708;
        datosCara[1] = 67708+0x32*4;
#endif

	mascarasPuertasBusqueda = 0x3f;

	// asigna las posiciones predefinidas
	posiciones = posicionesPredef;
}

Malaquias::~Malaquias()
{
}

/////////////////////////////////////////////////////////////////////////////
// comportamiento
/////////////////////////////////////////////////////////////////////////////

// Los estados en los que puede estar malaquías son:
//		0x00 -> estado en su mesa de trabajo del scriptorium
//		0x02 -> estado después de coger la llave de su mesa
//		0x03 -> estado después de advertir a guillermo que abandone el scriptorium
//		0x04 -> una vez que guillermo ha bajado del scriptorium, va a cerrar las puertas del ala izquierda
//		0x05 -> una vez cerradas las puertas, se dirige a la cocina
//		0x06 -> va a la iglesia (en vísperas)
//		0x07 -> después de que haya llegado a su sitio en la iglesia
//		0x08 -> si se va a su celda en completas/noche
//		0x09 -> va a la iglesia (en prima)
//		0x0a -> estado en el que va a su mesa de trabajo
//		0x0b -> estado en el que empieza a morirse
//		0x0c -> va a buscar al abad para que eche a guillermo
//
// Estados en LENG
//		0x00 ->  esperando a que Pickman y Harley lleguen a la abadía el segundo día
//
void Malaquias::piensa()
{
#ifdef LENG
	switch (laLogica->dia){
		case 2:
			switch (laLogica->momentoDia){
				case PRIMA:
					// si está esperando a que el jugador llegue a la abadía
					switch (estado) {
						case 0x00: 
						// si el jugador  está cerca , le da la bienvenida y le dice que le siga
						if (estaCerca(laLogica->guillermo)){
							// muestra la frase ESA SOMBRA, SIGAMOSLA
							elGestorFrases->muestraFrase(0x05);

							// cambia de estado y va a por el jugador // TODO: se acerca o se va a la cripta ... que pasa si el jugador no lo sigue y lo pierde de vista
							estado = 0x01;
							aDondeVa = 1; 
//							aDondeVa = POS_GUILLERMO;
						} else {
							// va a la entrada de la abadía
							aDondeVa = 0;
							// TODO: igual tener parte de la lógica del abad hace difícil depurar
							laLogica->abad->aDondeVa=0;
						}
						break;
						return;
						case 0x01: 
							//aDondeVa = 1; 
							//fprintf(stderr,"Logica->mascaraPuertas %d permisosPuertas %d\n",laLogica->mascaraPuertas,permisosPuertas ); 
							if ((aDondeHaLlegado==aDondeVa) && estaCerca(laLogica->guillermo) && !elGestorFrases->mostrandoFrase) {
								elGestorFrases->muestraFrase(0x06);
								estado=0x02;
								estaMuerto=1; // para que se vea la animacion de ascender , ver Malaquias::avanzaAnimacionOMueve
								// TODO, renombrar para LENG la variable a estaFlotando o estaDesapareciendo
							} 
							break;
						case 0x02:
							if (!elGestorFrases->mostrandoFrase) {
								if (altura<0x14) {
									altura++;	
								} else {
									posX=posY=altura=0;
									estado=0x03;
									estaMuerto=0;
									//elBuscadorDeRutas->seBuscaRuta = false;
//TODO : aunque el Sprite ha "ascendido" el hueco sigue "ocupado" y Guillermo no puede pasar por donde estaba Malaquias hasta salir y volver a entrar en la habitación

									// TODO: igual tener parte de la lógica del abad hace difícil depurar
									laLogica->abad->aDondeVa=1;
fprintf(stderr,"elMotorGrafico->numPantalla %d\n",elMotorGrafico->numPantalla);
								}
							}	
							break;
					}
					break;
			}
			break;
	}
return;
#endif
	int momentoDia = laLogica->momentoDia;

	// si malaquías ha muerto, sale
	if (estaMuerto == 2){
		elBuscadorDeRutas->seBuscaRuta = false;

		return;
	}

	// si malaquías está muriendo, incrementa su altura
	if (estaMuerto == 1){
		altura++;

		// si ha desaparecido de la pantalla, muere
		if (altura >= 0x14){
			posX = posY = altura = 0;
			estaMuerto = 2;
			aDondeHaLlegado = 0;
		}
		elBuscadorDeRutas->seBuscaRuta = false;

		return;
	}

	// si el abad va a echar a guillermo de la abadía, se queda quieto
	if (laLogica->abad->estado == 0x0b){
		elBuscadorDeRutas->seBuscaRuta = false;

		return;
	}

	// si es de noche o completas, se va a su celda y cambia al estado 8
	if ((laLogica->momentoDia == NOCHE) || (laLogica->momentoDia == COMPLETAS)){
		aDondeVa = 7;
		estado = 0x08;

		return;
	}

#ifdef LENG
//	if (laLogica->momentoDia == VISPERAS){
	if (laLogica->momentoDia == NONA){
estado=0x04;
#else
	if (laLogica->momentoDia == VISPERAS){
#endif
		// en el estado 0x0c, busca al abad para que eche a guillermo de la abadía
		if (estado == 0x0c){
			aDondeVa = POS_ABAD;

			if (aDondeHaLlegado == POS_ABAD){
				laLogica->abad->estado = 0x0b;
				estado = 0x06;
			}

			return;
		}

		// si está en el estado 0, va a por la llave de su mesa
		if (estado == 0x00){
			mascaraObjetos = LLAVE3;
			aDondeVa = 6;

			if (aDondeHaLlegado == 6){
				estado = 0x02;
			} else {
				return;
			}
		}

		// si aún no se ha ido del scriptorium
		if (estado < 0x04){
			// si guillermo está en el scriptorium, va a por él
			if (laLogica->guillermo->altura >= 0x0c){
				aDondeVa = POS_GUILLERMO;
			} else {
				estado = 0x04;

				return;
			}

			// si está yéndose del scriptorium y pasa cerca de guillermo, le advierte que debe marcharse
			if (estado == 0x02){
				// si está cerca de guillermo, le dice que abandone el scriptorium, pasa al estado 3 e inicia un contador de tiempo
				if (estaCerca(laLogica->guillermo)){
					// pone en el marcador la frase DEBEIS ABANDONAR EDIFICIO, HERMANO
					elGestorFrases->muestraFraseYa(0x09);
					estado = 0x03;
					contadorEnScriptorium = 0;
				}

				return;
			}

			// si le ha advertido a guillermo para que se marche y no le hace caso, advierte al abad
			if (estado == 0x03){
				contadorEnScriptorium++;

				// si no ha hecho caso y no ha abandonado el scriptorium, va a buscar al abad
				if (contadorEnScriptorium >= 0xfa){
					// pone en el marcador la frase ADVERTIRE AL ABAD
					elGestorFrases->muestraFraseYa(0x0a);

					estado = 0x0c;
				}

				return;
			}
		}

		// si guillermo ya se ha marchado del scriptorium, va a cerrar las puertas del ala izquierda de la abadía
		if (estado == 0x04){
			aDondeVa = 4;

			// si ha llegado a las puertas y no han salido berengario o bernardo, los espera
			if (aDondeHaLlegado == 4){
				if (
#ifdef LENG
false ) {
#else
(laLogica->berengario->estaVivo && (laLogica->berengario->posX < 0x62)) || (laLogica->bernardo->estaEnLaAbadia && (laLogica->bernardo->posX < 0x62))){
#endif
					elBuscadorDeRutas->seBuscaRuta = false;
				} else {
					// pasa al estado 5 y cierra las puertas
					estado = 0x05;
					elJuego->puertas[5]->estaFija = false;
					elJuego->puertas[6]->estaFija = false;
				}
			}

			return;
		}

		// después de cerrar las puertas, se va a la mesa de la cocina delante del pasadizo
		if (estado == 0x05){
			aDondeVa = 5;
			laLogica->mascaraPuertas = 0xdf;

			// si guillermo se ha quedado en el ala izquierda de la abadía, advierte al abad
			if (laLogica->guillermo->posX < 0x60){
				estado = 0x0c;
			}

			// si ha llegado a su destino, pasa al siguiente estado
			siHaLlegadoAvanzaEstado();

			return;
		}

		// en el estado 6, va a la iglesia
		if (estado == 0x06){
			aDondeVa = 0;

			// si ha llegado a su destino, pasa al siguiente estado
			siHaLlegadoAvanzaEstado();
		}

		// si está en el estado 0x0b, empieza a morirse
		if (estado == 0x0b){
			if (!elGestorFrases->mostrandoFrase){
				estaMuerto = 0x01;
			}

			return;
		}

		if (estado == 0x07){
			// si es el quinto día y está en la iglesia, pasa al estado en el que empieza a morirse
			if (laLogica->dia == 5){
				if ((elMotorGrafico->numPantalla == 0x22) || (elMotorGrafico->numPantalla == 0x22)){
					// indica que no ha llegado a la iglesia todavía
					aDondeHaLlegado = 1;

					// pasa al estado de morirse
					estado = 0x0b;

					// pone en el marcador la frase ERA VERDAD, TENIA EL PODER DE MIL ESCORPIONES
					elGestorFrases->muestraFraseYa(0x1f);
				}
			}
			return;
		}

		return;
	}

	// si es prima, cambia al estado 9 y va a misa
	if (laLogica->momentoDia == PRIMA){
		estado = 0x09;
		aDondeVa = 0;

		return;
	}

	// si malaquías ha llegado a su puesto en el scriptorium, deja la llave del pasadizo (si la tiene)
	if (aDondeHaLlegado == 2){
		estado = 0x00;
		mascaraObjetos = 0;

		if ((objetos & LLAVE3) == LLAVE3){
			objetos = objetos & 0xfd;

			elJuego->objetos[6]->seHaCogido = false;
			elJuego->objetos[6]->seEstaCogiendo = false;
			elJuego->objetos[6]->personaje = 0;
			elJuego->objetos[6]->posX = 0x35;
			elJuego->objetos[6]->posY = 0x35;
			elJuego->objetos[6]->altura = 0x13;
			elJuego->objetos[6]->orientacion = DERECHA;
		}
	}

	if (estado == 0){
		// si está cerca guillermo
		if (estaCerca(laLogica->guillermo)){
			// si ha ido a cerrarle el paso a guillermo
			if (aDondeVa == 3){
				// si no le ha dicho que no puede subir a la biblioteca
				if ((estado2 & 0x80) == 0){
					// si guillermo quiere entrar en la biblioteca, le dice que no puede
					if (laLogica->guillermo->posY < 0x38){
						estado2 |= 0x80;

						// pone en el marcador la frase LO SIENTO, VENERABLE HERMANO, NO PODEIS SUBIR A LA BIBLIOTECA
						elGestorFrases->muestraFraseYa(0x33);
					}
				} else {
					// si no le ha dicho que berengario le puede enseñar el scriptorium
					if ((estado2 & 0x40) == 0){
						// si es el segundo día y no está reproduciendo una frase, le dice que berengario le puede enseñar el scriptorium
						if ((laLogica->dia == 2) && (!elGestorFrases->mostrandoFrase)){
							estado2 |= 0x40;

							// pone en el marcador la frase SI LO DESEAIS, BERENGARIO OS MOSTRARA EL SCRIPTORIUM
							elGestorFrases->muestraFrase(0x34);
						}
					}
				}

				return;
			}

			// si no ha ido a cerrarle el paso a guillermo, pero éste está cerca

			// descarta los movimientos pensados
			descartarMovimientosPensados();

			// si guillermo no avanza, malaquías se queda quieto
			if (!losControles->estaSiendoPulsado(P1_UP)){
				elBuscadorDeRutas->seBuscaRuta = false;
			} else {
				// en otro caso, sale a cerrarle el paso
				aDondeVa = 3;
			}
		} else {
			// si guillermo no está cerca, va a su mesa
			aDondeVa = 2;
		}
		
		return;
	}

	if (laLogica->momentoDia == TERCIA){
		// si es el quinto día, va a matar a severino
		if ((estado == 0x09) && (laLogica->dia == 5)){
			aDondeVa = 8;

			// si ha llegado a la celda de severino y éste está en la celda, mata a severino y pasa al estado 0x0a
			if ((aDondeHaLlegado == 8) && (laLogica->severino->aDondeHaLlegado == 2)){
				laLogica->severino->estaVivo = false;
				laLogica->severino->posX = laLogica->severino->posY = laLogica->severino->altura = 0;  
				estado = 0x0a;
			}

			return;
		}

		// en el estado 0x0a, va a su mesa de trabajo
		estado = 0x0a;
		aDondeVa = 2;
	}
}

// dependiendo de como esté la animación del personaje, avanza la animación o realiza un movimiento
void Malaquias::avanzaAnimacionOMueve()
{
	// si se está muriendo, actualiza el sprite
	if (estaMuerto == 1){
		actualizaSprite();
	} else {
		// en otro caso, avanza la animación o realiza un movimiento
		PersonajeConIA::avanzaAnimacionOMueve();
	}
}
