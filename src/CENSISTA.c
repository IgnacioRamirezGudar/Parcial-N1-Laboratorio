/*legCen
 * CENSISTA.c
 *
 *  Created on: 21 may. 2022
 *      Author: ignac
 */

#include "CENSISTA.h"
#include "VIVIENDA.h"
#include "input-UTN.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int initCensista(CENSISTA ListaCENSISTA[], int sizeArray){

	CENSISTA addCensista;

	char nombre[51];
	int edad;
	int telefono;
	int legajo;

	printf("\n========================CENSO NACIONAL 2022/AÑADIR CENSISTA=====================================");
	printf("\n Numero de lejago que quiere añadir: ");
	scanf("%d", &legajo);
	printf("\n Nombre del encargado de la casa: ");
	fflush(stdin);
	gets(nombre);
	printf("\n Edad del encargado: ");
	scanf("%d", &edad);
	//validateEdadCensista(ListaCENSISTA, TAMARRAYCENSISTA, edad);
	printf("\n Numero de telefono o de casa: ");
	scanf("%d", &telefono);

	addCensista.legajoCensista = legajo;
	strcpy(addCensista.nombre,nombre);
	addCensista.edad = edad;
	addCensista.telefono = telefono;
	ListaCENSISTA[sizeArray] = addCensista;

	return 0;
}

int listaCensista(CENSISTA ListaCENSISTA[], int sizeArray){

	for(int i = 1; i <= sizeArray; i++){
		printf("\n N°L: %d-%s\t%d-años\ttel-%d", ListaCENSISTA[i].legajoCensista,ListaCENSISTA[i].nombre,ListaCENSISTA[i].edad,ListaCENSISTA[i].telefono);
	}

	return 0;
}


