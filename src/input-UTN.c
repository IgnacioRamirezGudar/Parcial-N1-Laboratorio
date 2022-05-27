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


int validateOpcion1(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,char streat[], int cantPersons, int cantRooms, int typeApartment, int legCen){

	VIVIENDAS apartment;

	int errorMaxRooms;
	int errortypeApartment;
	int errorLegajo;
		linebreak();
		errorMaxRooms = errorMaxRooms2(cantRooms);
		errortypeApartment = errortypeApartment2(typeApartment);
		errorLegajo = errorLegajo2(legCen);

		if((errorMaxRooms || errortypeApartment || errorLegajo) == 1){
			printf("\nHUBO UN ERROR AL CARGAR EL FORMULARIO");
			printf("\n==================CENSO NACIONAL 2022 / ERROR================================");
				if(errorMaxRooms == 1){
					printf("\n● ERROR...EL INGRESO MAXIMO DE HABITACIONES ES DE 15");
				}
				if(errortypeApartment == 1){
					printf("\n● ERROR...AL INGRESAR LA OPCION DE TIPO DE VIVIENDA");
				}
				if(errorLegajo == 1){
					printf("\n● ERROR...AL INGRESAR UN N° DE LEGAJO");
				}
			printf("\n=============================================================================");
			printf("\n");
			system("pause");
			printf("\n========================REINGRESAR DATOS=====================================");

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
				errorMaxRooms = errorMaxRooms2(apartment.cantRooms);
				errortypeApartment = errortypeApartment2(apartment.typeApartment);
				errorLegajo = errorLegajo2(apartment.legCen);
				addVIVIENDA(ListaCENSONACIONAL,sizeArray,streat, cantPersons, apartment.cantRooms, apartment.typeApartment, apartment.legCen);
			printf("\n=============================================================================");
			printf("\n");
			system("pause");
		}else{
			addVIVIENDA(ListaCENSONACIONAL,sizeArray,streat, cantPersons, cantRooms, typeApartment, legCen);
			printf("\n==================CENSO NACIONAL 2022 / DATOS CARGADOS======================");
			printf("\n");
			system("pause");
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

/*int validateNumber(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,int numeros){
	//VIVIENDAS changeData;

	char recorrerNumero = numeros + '0';

	if(isdigit(recorrerNumero)){
		while(recorrerNumero == '0'){
	        printf("\nERROR, INGRESE UN NUMERO VALIDO: ");
	        fflush(stdin);
	        scanf("%d",&numeros);
	        recorrerNumero = numeros + '0';
		}
	}

	 return 0;
}

int validateCantPersons(VIVIENDAS ListaCENSONACIONAL[],int sizeArray,int numeros){
	VIVIENDAS changeData;

	char recorrerNumero;

	changeData.cantPersons = numeros;

	recorrerNumero = changeData.cantPersons + '0';

	if(isdigit(recorrerNumero)){
		while(recorrerNumero == '0'){
	        printf("\nERROR, INGRESE UN NUMERO VALIDO: ");
	        fflush(stdin);
	        scanf("%d",&changeData.cantPersons);
	        recorrerNumero = changeData.cantPersons + '0';
		}
	}
	 return 0;
}*/

int errorMaxRooms2(int cantRooms){

	return (cantRooms > MaxRooms);
}

int errortypeApartment2(int typeApartment){

	return (typeApartment > 4 || typeApartment < 1);
}

int errorLegajo2(int legCen){

	return (legCen < 0);
}
