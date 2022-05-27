/*
 * CENSISTA.h
 *
 *  Created on: 21 may. 2022
 *      Author: ignac
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

struct{
	int legajoCensista;
	char nombre[51];
	int edad;
	int telefono;
}typedef CENSISTA;


int initCensista(CENSISTA ListaCENSISTA[], int sizeArray);

int listaCensista(CENSISTA ListaCENSISTA[], int sizeArray);

#endif /* CENSISTA_H_ */
