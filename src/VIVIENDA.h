/*
 * VIVIENDA.h
 *
 *  Created on: 20 may. 2022
 *      Author: ignac
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

#include "CENSISTA.h"

struct{
	int id;
	char street[25];
	int cantPersons;
	int cantRooms;
	int typeApartment;
	int legCen;
}typedef VIVIENDAS;

struct{
	int id;
}typedef IDBAJAS;

int addVIVIENDA(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,char streat[], int cantPersons, int cantRooms, int typeApartment, int legCen);

int searchC(VIVIENDAS ListaCENSONACIONAL[], int sizeArray,int id);

int lowerapartment(VIVIENDAS ListaCENSONACIONAL[], int sizeArray,int id);

int showlistApartment(VIVIENDAS ListaCENSONACIONAL[], int sizeArray);

#endif /* VIVIENDA_H_ */
