/*
 * CENSISTA.h
 *
 *  Created on: 21 may. 2022
 *      Author: ignac
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#include "VIVIENDA.h"

struct{
	int legajoCensista;
	char nombre[51];
	int edad;
	int telefono;
}typedef CENSISTA;


int initCensista(VIVIENDAS ListaCENSONACIONAL[], int sizeArray, int legCen);

#endif /* CENSISTA_H_ */
