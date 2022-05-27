/*legCen
 * CENSISTA.c
 *
 *  Created on: 21 may. 2022
 *      Author: ignac
 */

#include "CENSISTA.h"
#include "VIVIENDA.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static int TAMARRAYCENSISTA = 0;

int addCensista(CENSISTA ListaCENSISTA[], int TAMARRAYCENSISTA,int legCen);

int initCensista(VIVIENDAS ListaCENSONACIONAL[], int sizeArray, int legCen){

	CENSISTA ListaCENSISTA[TAMARRAYCENSISTA];

	TAMARRAYCENSISTA++;

	addCensista(ListaCENSISTA, TAMARRAYCENSISTA, legCen);


	return 0;
}

int addCensista(CENSISTA ListaCENSISTA[], int TAMARRAYCENSISTA,int legCen){

	CENSISTA addCensista;

	addCensista.legajoCensista = legCen;
	printf("\n Numero de lejago N°%d", addCensista.legajoCensista);
	printf("\n Nombre del encargado de la casa: ");
	fflush(stdin);
	gets(addCensista.nombre);
	printf("\n Edad del encargado: ");
	scanf("%d", &addCensista.edad);
	printf("\n Numero de telefono o de casa: ");
	scanf("%d", &addCensista.telefono);
	ListaCENSISTA[TAMARRAYCENSISTA] = addCensista;

	return 0;
}
