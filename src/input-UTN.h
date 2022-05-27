/*
 * input-UTN.h
 *
 *  Created on: 20 may. 2022
 *      Author: ignac
 */

#ifndef INPUT_UTN_H_
#define INPUT_UTN_H_
#include "VIVIENDA.h"
#include "CENSISTA.h"

void linebreak();

int validateOpcion1(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,char streat[], int cantPersons, int cantRooms, int typeApartment, int legCen);

int validateID(VIVIENDAS ListaCENSONACIONAL[], int sizeArray,int id);

int validateCantPersons(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,int numeros);

int validateEdadCensista(CENSISTA ListaCENSISTA[], int TAMARRAYCENSISTA, int edad);

#endif /* INPUT_UTN_H_ */
