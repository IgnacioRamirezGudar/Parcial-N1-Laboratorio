/*
 ============================================================================
 Name        : Parcial.c
 Author      : Ignacio Ramirez Gudar
 Version     :
 Copyright   : Your copyright notice
 Description : Parcial N°1
 ============================================================================
 */

#include "input-UTN.h"
#include "VIVIENDA.h"
#include "CENSISTA.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static int TAMARRAY = 0;

int arrray(){

	TAMARRAY++;

	return TAMARRAY;
}
//#define tamano TAMARRAY

int addapartment(VIVIENDAS ListaCENSONACIONAL[], int sizeArray);
int modfVIVIENDA(VIVIENDAS ListaCENSONACIONAL[], int sizeArray);

int main(void) {
	setbuf(stdout, NULL);
	char opcion;
	int LongArray;
	VIVIENDAS ListaCENSONACIONAL[TAMARRAY];


	do{
		//printf("\nARRAY 2: %d", tamano);
		printf("\n==================CENSO NACIONAL 2022==================");
		printf("\n1) ALTA VIVIENDA");
		printf("\n2) MODIFICAR VIVIENDA");
		printf("\n3) BAJA VIVIENDA");
		printf("\n4) LISTAR VIVIENDA");
		printf("\n5) LISTAR CENSISTAS");
		printf("\n6) CARGAR DATOS FORZADOS");
		printf("\n=======================================================");
		printf("\nSeleccione una opcion: ");
		scanf("%s", &opcion);
		switch(opcion){
			case '1':
				linebreak();
				LongArray = arrray();
				addapartment(ListaCENSONACIONAL, LongArray);
				break;
			case '2':
				linebreak();
				if(TAMARRAY <= 0){
					printf("\nERROR... PRIMERO DEBE INGRESAR UN DATO");
				} else {
					modfVIVIENDA(ListaCENSONACIONAL, TAMARRAY);
				}
				break;
			case '3':
				break;
			case '4':
				break;
			case '5':
				break;
			case '6':
				break;
			default:
				linebreak();
				printf("\n==================CENSO NACIONAL 2022 / ERROR==================");
				printf("\nERROR ELIJA UNA OPCION VALIDA");
				printf("\n===============================================================");
				break;
		}

	}while(opcion !=6);

	return 0;
}

int addapartment(VIVIENDAS ListaCENSONACIONAL[], int sizeArray){
	setbuf(stdout, NULL);
	VIVIENDAS apartment;

	printf("\n==================CENSO NACIONAL 2022 / INGRESO DE VIVIENDA==================");
	printf("\n- INGRESE CALLE Y DIRECCION DE LA CASA: ");
	fflush(stdin);
	gets(apartment.street);
	printf("\n- CANTIDAD DE PERSONAS QUE VIVEN EN LA CASA: ");
	fflush(stdin);
	scanf("%d", &apartment.cantPersons);
	printf("\n- CANTIDADA DE HABITACIONES QUE HAY EN LA CASA: ");
	fflush(stdin);
	scanf("%d", &apartment.cantRooms);
	printf("\n|1.CASA\t|\t2.DEPARTAMENTO\t|\t3.CASILLA\t|\t4.RANCHO|");
	fflush(stdin);
	printf("\n- TIPO DE VIVIENDA: ");
	fflush(stdin);
	scanf("%d", &apartment.typeApartment);
	printf("\n- INGRESE UN LEGAJO (LEGAJO CENSISTA): ");
	fflush(stdin);
	scanf("%d", &apartment.legCen);
	printf("\n=============================================================================");

	validateOpcion1(ListaCENSONACIONAL,sizeArray,apartment.street,apartment.cantPersons,apartment.cantRooms,apartment.typeApartment,apartment.legCen);

	return 0;
}

int modfVIVIENDA(VIVIENDAS ListaCENSONACIONAL[], int sizeArray){
	setbuf(stdout, NULL);
	int id;

	printf("\n==================CENSO NACIONAL 2022 / MODIFICAR VIVIENDA==================");
	printf("\n- INGRESE ID DE LA VIVIENDA QUE DESEA MODIFICAR (rango de ID apartir desde 20001): ");
	scanf("%d", &id);
	validateID(ListaCENSONACIONAL, sizeArray,id);
	return 0;
}

