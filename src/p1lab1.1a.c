/*
 ============================================================================
 Name        : 1a.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "autos.h"
#include "validaciones.h"
#include "trabajos.h"


#define TAM_M 5
#define TAM_C 5
#define TAM_S 4
#define TAM_A 10
#define TAM_T 5



int main(void) {
	setbuf(stdout,NULL);

	char respuesta = 'n';
	int nextIdAuto = 100;
	int nextIdTrabajo = 1;
	eAuto autos[TAM_A];
	eTrabajo trabajos[TAM_T];

	eMarca marcas[TAM_M] = {
			 {1000,"Renault"},
			 {1001,"Ford"},
			 {1002,"Fiat"},
			 {1003,"Chevrolet"},
			 {1004,"Peugeot"}
	};

	eColor colores[TAM_C]={
			 {5000,"Negro"},
			 {5001,"Blanco"},
			 {5002,"Rojo"},
			 {5003,"Verde"},
			 {5004,"Azul"}
	};
	eServicio servicios[TAM_S]={
			 {20000,"Lavado",450},
			 {20001,"Pulido",500},
			 {20002,"Encerado",600},
			 {20003,"Completo",900},
	};

	inicializarAutos(autos, TAM_A);
	inicializarTrabajo(trabajos, TAM_T);
	harcodearAutos(&nextIdAuto, autos, TAM_A, 7);

	do{
		limpiarConsola();
		switch(menuPrincipal())
		{
		 case 'a':
			 limpiarConsola();
			 if(altaAutos(&nextIdAuto, autos, TAM_A, marcas, TAM_M, colores, TAM_C))
			 {
				 printf("\nEl alta se realizo correctamente.\n");
			 }
			 else
			 {
				 printf("Error al realizar el alta.\n");
			 }
			 break;
		 case 'b':
			 if(!modificarAuto(autos, TAM_A, marcas, TAM_M, colores, TAM_C))
			 {
				 printf("No se pudo realizar la modificacion.\n");
			 }
			 else
			 {
				 printf("La modificacion se realizo correctamente.\n");
			 }
			 break;
		 case 'c':
			 if(bajaAuto(autos, TAM_A, marcas, TAM_M, colores, TAM_C))
			 {
				 printf("La baja se realizo correctamente.\n");
			 }
			 else
			 {
				 printf("No pudo realizarse la baja.\n");
			 }
			 break;
		 case 'd':
			 ordenarAutos(autos, TAM_A);
			 mostrarAutos(autos, TAM_A, marcas, TAM_M, colores, TAM_C, 1);
			 break;
		 case 'e':
			 listarMarcas(marcas, TAM_M);
			 break;
		 case 'f':
			 listarColores(colores, TAM_C);
			 break;
		 case 'g':
			 listarServicios(servicios, TAM_S);
			 break;
		 case 'h':
			 if(altaTrabajo(&nextIdTrabajo, trabajos, TAM_T, autos, TAM_A, servicios, TAM_S, marcas, TAM_M, colores, TAM_C))
			 {
				printf("\n El alta se realizo correctamente.\n");
			 }
			 else
			 {
				 printf("Error al realizar el alta'n.");
			 }
			 break;
		 case 'i':
			 mostrarTrabajos(trabajos, TAM_T, autos, TAM_A, servicios, TAM_S, marcas, TAM_M, 0);
			 break;
		 case 'j':
			 limpiarConsola();
			 confirmaSalida(&respuesta, 's', 'n');
			 break;
		 default:
			 printf("La opcion seleccionada no existe.\n");
		}
	pausa();
	limpiarConsola();
	}while(respuesta == 'n');

	return 0;
}


