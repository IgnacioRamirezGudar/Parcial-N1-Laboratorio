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
static int TAMARRAY2 = 0;
int arrray(){

	TAMARRAY++;

	return TAMARRAY;
}

int arrray2(){

	TAMARRAY2++;

	return TAMARRAY2;
}

int lowerAparment(VIVIENDAS ListaCENSONACIONAL[], int sizeArray);
int addapartment(VIVIENDAS ListaCENSONACIONAL[], int sizeArray);
int modfVIVIENDA(VIVIENDAS ListaCENSONACIONAL[], int sizeArray);
int listApartment(VIVIENDAS ListaCENSONACIONAL[], int sizeArray);
int listCensista(CENSISTA ListaCENSISTA[],VIVIENDAS ListaCENSONACIONAL[], int TAMARRAY);

int main(void) {
	setbuf(stdout, NULL);
	char opcion;
	int LongArray;
	int LongArray2;
	VIVIENDAS ListaCENSONACIONAL[TAMARRAY];

	CENSISTA ListaCENSISTA[TAMARRAY2];

	do{
		printf("\n==================CENSO NACIONAL 2022==================");
		printf("\n1) ALTA VIVIENDA");
		printf("\n2) MODIFICAR VIVIENDA");
		printf("\n3) BAJA VIVIENDA");
		printf("\n4) LISTAR VIVIENDA");
		printf("\n5) LISTAR CENSISTA");
		printf("\n6) CARGAR DATOS FORZADOS");
		printf("\nSeleccione una opcion: ");
		scanf("%s", &opcion);
		switch(opcion){
			case '1':
				linebreak();
				LongArray = arrray();
				LongArray2 = arrray2();
				addapartment(ListaCENSONACIONAL, LongArray);
				initCensista(ListaCENSISTA,LongArray2);
				printf("\n==================CENSO NACIONAL 2022 / DATOS CARGADOS======================");
				printf("\n");
				system("pause");
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
				linebreak();
				if(TAMARRAY <= 0){
					printf("\nERROR... PRIMERO DEBE INGRESAR UN DATO");
				} else {
					lowerAparment(ListaCENSONACIONAL, TAMARRAY);
				}
				break;
			case '4':
				if(TAMARRAY <= 0){
					printf("\nERROR... PRIMERO DEBE INGRESAR UN DATO");
				} else {
					listApartment(ListaCENSONACIONAL, TAMARRAY);
				}
				break;
			case '5':
				if(TAMARRAY <= 0){
					printf("\nERROR... PRIMERO DEBE INGRESAR UN DATO");
				} else {
					listCensista(ListaCENSISTA,ListaCENSONACIONAL, TAMARRAY);
				}
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
	fflush(stdin);
	printf("\n- CANTIDADA DE HABITACIONES QUE HAY EN LA CASA: ");
	fflush(stdin);
	scanf("%d", &apartment.cantRooms);
	fflush(stdin);
	printf("\n|1.CASA\t|\t2.DEPARTAMENTO\t|\t3.CASILLA\t|\t4.RANCHO|");
	fflush(stdin);
	printf("\n- TIPO DE VIVIENDA: ");
	fflush(stdin);
	scanf("%d", &apartment.typeApartment);
	fflush(stdin);
	printf("\n- INGRESE UN LEGAJO (LEGAJO CENSISTA): ");
	fflush(stdin);
	scanf("%d", &apartment.legCen);
	fflush(stdin);
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

int lowerAparment(VIVIENDAS ListaCENSONACIONAL[], int sizeArray){

	int id;

	printf("\n==================CENSO NACIONAL 2022 / BAJAR VIVIENDA==================");
	printf("\n- INGRESE ID DE LA VIVIENDA QUE DESEA BAJAR (rango de ID apartir desde 20001): ");
	scanf("%d", &id);

	lowerapartment(ListaCENSONACIONAL, sizeArray, id);

	return 0;
}

int listApartment(VIVIENDAS ListaCENSONACIONAL[], int sizeArray){


		VIVIENDAS lastStreet;

		char typeApartment[51];

		printf("\n\t\t\t\t\t    LISTA DE VIVIENDAS");
		printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
		printf("\n|ID\t|\tCALLE\t|\tCANTIDAD DE PERSONAS\t|\tCANTIDAD DE HABITACIONES\t\t|\tTIPO DE VIVIENDA\t|\tLEGAJO\t|");
		printf("\n|=======================================================================================================================================================|");
		for(int i = 1; i <= sizeArray;i++){
			if(ListaCENSONACIONAL[i].id > 0){
				for(int i = 1; i < sizeArray - 1; i++){
					for(int x = i + 1; x < sizeArray; x++){
						if(strcmp(ListaCENSONACIONAL[i].street, ListaCENSONACIONAL[x].street) > 0){
							lastStreet = ListaCENSONACIONAL[i];
							ListaCENSONACIONAL[i] = ListaCENSONACIONAL[x];
							ListaCENSONACIONAL[x] = lastStreet;
						}
						if(strcmp(ListaCENSONACIONAL[i].street, ListaCENSONACIONAL[x].street) == 0){
							if(ListaCENSONACIONAL[i].cantPersons > ListaCENSONACIONAL[x].cantPersons){
								lastStreet = ListaCENSONACIONAL[i];
								ListaCENSONACIONAL[i] = ListaCENSONACIONAL[x];
								ListaCENSONACIONAL[x] = lastStreet;
							}
						}
					}
				}
				if(ListaCENSONACIONAL[i].typeApartment == 1){
					strcpy(typeApartment , "CASA");
				} else {
					if(ListaCENSONACIONAL[i].typeApartment == 2){
						strcpy(typeApartment , "DEPARTAMENTO");
					} else {
						if(ListaCENSONACIONAL[i].typeApartment == 3){
							strcpy(typeApartment , "CASILLA");
						}  else {
							if(ListaCENSONACIONAL[i].typeApartment == 4){
								strcpy(typeApartment , "RANCHO");
							}
						}
					}
				}
				printf("\n|%d\t|\t%s\t|\t\t%d\t\t|\t\t%d\t\t\t\t|\t%s\t\t\t|\t%d\t|", ListaCENSONACIONAL[i].id, ListaCENSONACIONAL[i].street,ListaCENSONACIONAL[i].cantPersons,ListaCENSONACIONAL[i].cantRooms,typeApartment,ListaCENSONACIONAL[i].legCen);
				printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
			}
		}
		linebreak();


	return 0;
}

int listCensista(CENSISTA ListaCENSISTA[],VIVIENDAS ListaCENSONACIONAL[], int TAMARRAY){

	printf("\n\t\t\t\t\t    LISTA DE CENSISTAS");
	printf("\n|---------------------------------------------------------------------------------------|");
	printf("\n|N°LEGAJO\t|\tNOMBRE\t\t|\tEDAD\t|\tTELEFONO\t\t|");
	printf("\n|=======================================================================================|");
	for(int i = 1; i <= TAMARRAY;i++){
		if(ListaCENSONACIONAL[i].id > 0){
			for(int x = 1; x <= TAMARRAY;x++){
				printf("\n|%d\t\t|\t%s\t\t|\t%d\t|\t%d		\t|", ListaCENSISTA[x].legajoCensista, ListaCENSISTA[x].nombre,ListaCENSISTA[x].edad,ListaCENSISTA[x].telefono);
				printf("\n|---------------------------------------------------------------------------------------|");
			}
		}
	}

	linebreak();
	return 0;
}
