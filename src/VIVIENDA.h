/*
 * VIVIENDA.h
 *
 *  Created on: 20 may. 2022
 *      Author: ignac
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

struct{
	int id;
	char street[25];
	int cantPersons;
	int cantRooms;
	int typeApartment;
	int legCen;
}typedef VIVIENDAS;

int addVIVIENDA(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,char streat[], int cantPersons, int cantRooms, int typeApartment, int legCen);

int searchC(VIVIENDAS ListaCENSONACIONAL[], int sizeArray,int id);

#endif /* VIVIENDA_H_ */
