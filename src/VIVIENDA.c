/*
 * VIVIENDA.c
 *
 *  Created on: 20 may. 2022
 *      Author: ignac
 */

#include "VIVIENDA.h"
#include "input-UTN.h"
#include "CENSISTA.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static int valId = 20000;

int generateId(){

	valId++;

	return valId;
}

int modifDataVivienda(VIVIENDAS ListaCENSONACIONAL[], int sizeArray, int id);

int addVIVIENDA(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,char street[], int cantPersons, int cantRooms, int typeApartment, int legCen){

	setbuf(stdout, NULL);

	VIVIENDAS addapartment;

	addapartment.id = generateId();
	strcpy(addapartment.street, street);
	addapartment.cantPersons = cantPersons;
	addapartment.cantRooms = cantRooms;
	addapartment.typeApartment = typeApartment;
	addapartment.legCen = legCen;
	ListaCENSONACIONAL[sizeArray] = addapartment;


	initCensista(ListaCENSONACIONAL, sizeArray, addapartment.legCen);
	return 0;
}

int searchC(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,int id){

	for(int i = 0; i <= sizeArray; i++){
		if(id == ListaCENSONACIONAL[i].id){
			printf("\n==================CENSO NACIONAL 2022 / VIVIENDA A MODIFICAR======================");
			printf("\nID: %d", ListaCENSONACIONAL[i].id);
			printf("\nCALLE: %s", ListaCENSONACIONAL[i].street);
			printf("\nCANT PERSONAS: %d", ListaCENSONACIONAL[i].cantPersons);
			printf("\nCANT HABITACIONES: %d", ListaCENSONACIONAL[i].cantRooms);
			printf("\nTIPO: %d", ListaCENSONACIONAL[i].typeApartment);
			printf("\nLEGAJO: %d", ListaCENSONACIONAL[i].legCen);
		}
	}
	modifDataVivienda(ListaCENSONACIONAL, sizeArray, id);
	linebreak();
	return 0;
}


int modifDataVivienda(VIVIENDAS ListaCENSONACIONAL[], int sizeArray, int id){

	char opcion;
	char newstreet[51];
	int newcantPersons;
	int newcantRooms;
	int newType;

	for(int i = 0; i <= sizeArray; i++){
		if(id == ListaCENSONACIONAL[i].id){
			printf("\n===================================================================================");
			printf("\n1) Cambiar datos de la calle.");
			printf("\n2) Cambiar la cantidad de personas que viven.");
			printf("\n3) Cambiar la cantidad de habitaciones que hay.");
			printf("\n4) Cambiar el tipo de vivienda.");
			printf("\n5) CANCELAR.");
			fflush(stdin);
			scanf("%s", &opcion);
			do{
				switch(opcion){
					case '1':
						printf("\n● Nuevo dato de la calle: ");
						fflush(stdin);
						gets(newstreet);
						break;
					case '2':
						printf("\n● Nuevo dato de la cantidad de personas que viven: ");
						fflush(stdin);
						scanf("%d", &newcantPersons);
						break;
					case '3':
						printf("\n● Nuevo dato de la cantidad de habitaciones que hay: ");
						fflush(stdin);
						scanf("%d", &newcantRooms);
						break;
					case '4':
						printf("\n● Nuevo tipo de vivienda: ");
						fflush(stdin);
						scanf("%d", &newType);
						break;
					case '5':
						return 0;
						break;
					default:
						printf("\nERROR...SELECCIONE UNA OPCION VALIDA: ");
						fflush(stdin);
						scanf("%s", &opcion);
						break;
				}
			}while(opcion != 5);
			strcpy(ListaCENSONACIONAL[i].street, newstreet);
			ListaCENSONACIONAL[i].cantPersons = newcantPersons;
			ListaCENSONACIONAL[i].cantRooms = newcantRooms;
			ListaCENSONACIONAL[i].typeApartment = newType;
		}
	}
	return 0;
}
