/*
 * input-UTN.c
 *
 *  Created on: 20 may. 2022
 *      Author: ignac
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "VIVIENDA.h"
#include "input-UTN.h"

static int MaxRooms = 15;


void linebreak(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int errorMaxRooms2(int cantRooms);
int errortypeApartment2(int typeApartment);
int errorLegajo2(int legCen);
int errorNumeroLegajo(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,int numero);

int validateOpcion1(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,char streat[], int cantPersons, int cantRooms, int typeApartment, int legCen){

	VIVIENDAS apartment;

	int errorMaxRooms;
	int errortypeApartment;
	int errorLegajo;
	int errorNLegajo;

	errorMaxRooms = errorMaxRooms2(cantRooms);
	errortypeApartment = errortypeApartment2(typeApartment);
	errorLegajo = errorLegajo2(legCen);
	errorNLegajo = errorNumeroLegajo(ListaCENSONACIONAL, sizeArray,legCen);
	linebreak();


		if((errorMaxRooms || errortypeApartment || errorLegajo || errorNLegajo) == 1){
			printf("\n==================CENSO NACIONAL 2022 / ERROR================================");
				printf("\nHUBO UN ERROR AL CARGAR EL FORMULARIO: ");
				//PRIMERA VALIDACION
				if(errorMaxRooms == 1){
					printf("\n\t● ERROR...EL INGRESO MAXIMO DE HABITACIONES ES DE 15");
				}
				if(errortypeApartment == 1){
					printf("\n\t● ERROR...AL INGRESAR LA OPCION DE TIPO DE VIVIENDA");
				}
				if(errorLegajo == 1){
					printf("\n\t● ERROR...AL INGRESAR UN N° DE LEGAJO");
				}
				if(errorNLegajo == 1){
					printf("\n\t● ERROR...ESTE N° DE LEGAJO YA ESTA ASIGNADO");
				}

			printf("\n=============================================================================");
			printf("\n");
			system("pause");
			printf("\n========================REINGRESAR DATOS=====================================");
				//PRIMERA VALIDACION
				if(errorMaxRooms == 1){
					printf("\n- CANTIDADA DE HABITACIONES QUE HAY EN LA CASA: ");
					scanf("%d", &apartment.cantRooms);
				}
				if(errortypeApartment == 1){
					printf("\n|1.CASA\t|\t2.DEPARTAMENTO\t|\t3.CASILLA\t|\t4.RANCHO|");
					printf("\n- TIPO DE VIVIENDA: ");
					scanf("%d", &apartment.typeApartment);
				}
				if(errorLegajo == 1){
					printf("\n- INGRESE UN LEGAJO (LEGAJO CENSISTA): ");
					scanf("%d", &apartment.legCen);
				}
				if(errorNLegajo == 1){
					printf("\n- INGRESE UN LEGAJO VALIDO: ");
					scanf("%d", &apartment.legCen);
				}
				//TERCERA VALIDACION, SABER SI SE HICE UN CAMBIO O NO
				if(apartment.cantPersons < 0){
					apartment.cantPersons = cantPersons;
				}
				if(apartment.cantRooms < 0){
					apartment.cantRooms = cantRooms;
				}
				if(apartment.typeApartment > 5 || apartment.typeApartment < 0){
					apartment.typeApartment = typeApartment;
				}
				if(apartment.legCen < 0){
					apartment.legCen = legCen;
				}

				errorMaxRooms = errorMaxRooms2(apartment.cantRooms);
				errortypeApartment = errortypeApartment2(apartment.typeApartment);
				errorLegajo = errorLegajo2(apartment.legCen);
				addVIVIENDA(ListaCENSONACIONAL,sizeArray,streat, apartment.cantPersons, apartment.cantRooms, apartment.typeApartment, apartment.legCen);
			printf("\n=============================================================================");
			printf("\n");
			system("pause");
		}else{
			addVIVIENDA(ListaCENSONACIONAL,sizeArray,streat, cantPersons, cantRooms, typeApartment, legCen);
		}
		linebreak();

	return 0;
}

int validateID(VIVIENDAS ListaCENSONACIONAL[], int sizeArray,int id){


	if(id < 20000){
		printf("\n- INGRESE UN ID VALIDO (APARTIR DE 20001): ");
		scanf("%d", &id);
		searchC(ListaCENSONACIONAL,sizeArray, id);
	} else {
		searchC(ListaCENSONACIONAL,sizeArray, id);
	}
	return 0;
}

int errorNumeroLegajo(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,int numero){

	int retorno;

	for(int i = 0; i <sizeArray; i++){
		if(numero == ListaCENSONACIONAL[i].legCen){
			retorno = 1;
		} else {
			retorno = 0;
		}
	}
	return retorno;
}


int errorMaxRooms2(int cantRooms){

	return (cantRooms > MaxRooms);
}

int errortypeApartment2(int typeApartment){

	return (typeApartment > 4 || typeApartment < 1);
}

int errorLegajo2(int legCen){

	return (legCen < 0 );
}


/*
	VALIDAR EDAD CENSISTA
 */

int validateEdadCensista(CENSISTA ListaCENSISTA[], int TAMARRAYCENSISTA, int edad){

	CENSISTA validateEdad;

	if(edad >= 27){
		for(int i = 1; i < TAMARRAYCENSISTA; i++){
			validateEdad.edad = edad;
			ListaCENSISTA[i].edad = validateEdad.edad;
		}
	} else {
		printf("\n==================CENSO NACIONAL 2022 / ERROR================================");
		printf("\n Debe introducir una edad valida");
		printf("\n Reingrese la edad: ");
		scanf("%d", &validateEdad.edad);
		for(int i = 1; i < TAMARRAYCENSISTA; i++){
			ListaCENSISTA[i].edad = validateEdad.edad;
		}
	}

	return 0;
}
