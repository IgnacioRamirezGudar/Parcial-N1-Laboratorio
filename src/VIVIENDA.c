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

int addModVivienda(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,int id,char street[], int cantPersons, int cantRooms, int typeApartment, int leng);

int modifDataVivienda(VIVIENDAS ListaCENSONACIONAL[], int sizeArray, int id);

int addVIVIENDA(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,char street[], int cantPersons, int cantRooms, int typeApartment, int legCen){

	VIVIENDAS addapartment;

	addapartment.id = generateId();
	strcpy(addapartment.street, street);
	addapartment.cantPersons = cantPersons;
	addapartment.cantRooms = cantRooms;
	addapartment.typeApartment = typeApartment;
	addapartment.legCen = legCen;
	ListaCENSONACIONAL[sizeArray] = addapartment;




	return 0;
}

int searchC(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,int id){

	char typeApartment[51];

	for(int i = 0; i <= sizeArray; i++){
		if(id == ListaCENSONACIONAL[i].id){

			if(ListaCENSONACIONAL[i].typeApartment == 1){
				strcpy(typeApartment , "CASA");
			}else {
				if(ListaCENSONACIONAL[i].typeApartment == 2){
					strcpy(typeApartment , "DEPARTAMENTO");
				}else {
					if(ListaCENSONACIONAL[i].typeApartment == 3){
						strcpy(typeApartment , "CASILLA");
					}else {
						if(ListaCENSONACIONAL[i].typeApartment == 4){
							strcpy(typeApartment , "RANCHO");
						}
					}
				}
			}

			printf("\n==================CENSO NACIONAL 2022 / VIVIENDA A MODIFICAR======================");
			printf("\nID: %d", ListaCENSONACIONAL[i].id);
			printf("\nCALLE: %s", ListaCENSONACIONAL[i].street);
			printf("\nCANT PERSONAS: %d", ListaCENSONACIONAL[i].cantPersons);
			printf("\nCANT HABITACIONES: %d", ListaCENSONACIONAL[i].cantRooms);
			printf("\nTIPO: %s", typeApartment);
			printf("\nLEGAJO: %d", ListaCENSONACIONAL[i].legCen);
		}
	}
	modifDataVivienda(ListaCENSONACIONAL, sizeArray, id);
	linebreak();
	return 0;
}

int modifDataVivienda(VIVIENDAS ListaCENSONACIONAL[], int sizeArray, int id){

	VIVIENDAS addNewDataApartment;

	char opcion;
	char newstreet[51];
	int newcantPersons;
	int newcantRooms;
	int newType;
	for(int i = 1; i <= sizeArray; i++){
		if(id == ListaCENSONACIONAL[i].id){
			printf("\n===================================================================================");
			printf("\n1) Cambiar datos de la calle.");
			printf("\n2) Cambiar la cantidad de personas que viven.");
			printf("\n3) Cambiar la cantidad de habitaciones que hay.");
			printf("\n4) Cambiar el tipo de vivienda.");
			printf("\n5) SALIR.");

			printf("\nEliga una opcion: ");
			fflush(stdin);
			scanf("%s", &opcion);
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
						addNewDataApartment.cantRooms = newcantRooms;
						break;
					case '4':
						printf("\n● Nuevo tipo de vivienda: ");
						fflush(stdin);
						scanf("%d", &newType);
						addNewDataApartment.typeApartment = newType;
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
				addNewDataApartment.id = ListaCENSONACIONAL[i].id;
				if(newstreet == NULL){
					strcpy(addNewDataApartment.street, ListaCENSONACIONAL[i].street);
				}else {
					strcpy(addNewDataApartment.street, newstreet);
				}
				if(newcantPersons <= 0){
					addNewDataApartment.cantPersons = ListaCENSONACIONAL[i].cantPersons;
				} else {
					if(newcantPersons > 0){
						addNewDataApartment.cantPersons = newcantPersons;
					}
				}
				if(newcantRooms <= 0){
					addNewDataApartment.cantRooms = ListaCENSONACIONAL[i].cantRooms;
				} else {
					if(newcantRooms > 0){
						addNewDataApartment.cantRooms = newcantRooms;
					}
				}
				if(newType <= 0 || newType >= 5){
					addNewDataApartment.typeApartment = ListaCENSONACIONAL[i].typeApartment;
				} else {
					if(newType > 1 || newType < 4){
						addNewDataApartment.cantRooms = newcantRooms;
					}
				}
				addNewDataApartment.legCen = ListaCENSONACIONAL[i].legCen;
				addModVivienda(ListaCENSONACIONAL, sizeArray,addNewDataApartment.id,addNewDataApartment.street, addNewDataApartment.cantPersons, addNewDataApartment.cantRooms, addNewDataApartment.typeApartment, addNewDataApartment.legCen);
		}
	}

	return 0;
}


int addModVivienda(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,int id,char street[], int cantPersons, int cantRooms, int typeApartment, int leng){

	VIVIENDAS addNewDataApartment2;

	addNewDataApartment2.id = id;
	strcpy(addNewDataApartment2.street,street);
	addNewDataApartment2.cantPersons = cantPersons;
	addNewDataApartment2.cantRooms = cantRooms;
	addNewDataApartment2.typeApartment = typeApartment;
	addNewDataApartment2.legCen = leng;
	ListaCENSONACIONAL[sizeArray] = addNewDataApartment2;


	return 0;
}


int lowerapartment(VIVIENDAS ListaCENSONACIONAL[], int sizeArray,int id){

	char opcion[51];

	for(int i = 0; i <= sizeArray; i++){
		if(id == ListaCENSONACIONAL[i].id){
			printf("\n==================CENSO NACIONAL 2022 / CONFIRMAR BAJA DE VIVIENDA======================");
			printf("\nDESEA BAJAR LA SIGUIENTE ID [%d] ? (ACEPTAR / CANCELAR)", ListaCENSONACIONAL[i].id);
			fflush(stdin);
			gets(opcion);
			if(strcmp(opcion,"ACEPTAR") == 0 || strcmp(opcion,"aceptar") == 0){
				ListaCENSONACIONAL[i].id = 0;
				printf("\n==================CENSO NACIONAL 2022 / SE HA DADO DE BAJA======================");
				printf("\n");
				system("pause");
			} else{
				if(strcmp(opcion,"CANCELAR") == 0 || strcmp(opcion,"cancelar") == 0){
					return 0;
				}
			}

		}
	}
	return 0;
}
