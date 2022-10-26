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
#include "informes.h"


#define TAM_M 5
#define TAM_C 5
#define TAM_S 4
#define TAM_A 10
#define TAM_T 10



int main(void) {
	setbuf(stdout,NULL);

	char respuesta = 'n';
	int opcionMenuInformes;
	int nextIdAuto = 100;
	int nextIdTrabajo = 1;
	int flagAltaAutos;
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
	//hardcodearAutos(&nextIdAuto, autos, TAM_A, 7);
	//hardcodearTrabajos(&nextIdTrabajo, trabajos, TAM_T, 7);

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
			 pausa();
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
			 pausa();
			 break;
		 case 'c':
			 if(bajaAuto(autos, TAM_A, marcas, TAM_M, colores, TAM_C, trabajos, TAM_T))
			 {
				 printf("La baja se realizo correctamente.\n");
			 }
			 else
			 {
				 printf("No pudo realizarse la baja.\n");
			 }
			 pausa();
			 break;
		 case 'd':
			 ordenarAutos(autos, TAM_A);
			 mostrarAutos(autos, TAM_A, marcas, TAM_M, colores, TAM_C, 1);
			 pausa();
			 break;
		 case 'e':
			 listarMarcas(marcas, TAM_M);
			 pausa();
			 break;
		 case 'f':
			 listarColores(colores, TAM_C);
			 pausa();
			 break;
		 case 'g':
			 listarServicios(servicios, TAM_S);
			 pausa();
			 break;
		 case 'h':
			 if(altaTrabajo(&nextIdTrabajo, trabajos, TAM_T, autos, TAM_A, servicios, TAM_S, marcas, TAM_M, colores, TAM_C))
			 {
				printf("\n El alta se realizo correctamente.\n");
			 }
			 else
			 {
				 printf("Error al realizar el alta.\n");
			 }
			 pausa();
			 break;
		 case 'i':
			 mostrarTrabajos(trabajos, TAM_T, autos, TAM_A, servicios, TAM_S, marcas, TAM_M, 1);
			 pausa();
			 break;
		 case 'j':
			 buscarOcupado(&flagAltaAutos, autos, TAM_A);
			 if(flagAltaAutos)
			 {
				do{
					 switch(menuInformes(&opcionMenuInformes))
					 {
					 case 1:
						 mostrarAutosColor(autos, TAM_A, colores, TAM_C, marcas, TAM_M);
						 pausa();
						 break;
					 case 2:
						 mostrarAutosMarca(autos, TAM_A, colores, TAM_C, marcas, TAM_M);
						 pausa();
						 break;
					 case 3:
						 porcentajesPorCaja(autos, TAM_A);
						 pausa();
						 break;
					 case 4:
						 mostrarAutosPorCaja(autos, TAM_A, marcas, TAM_M, colores, TAM_C);
						 pausa();
						 break;
					 case 5:
						 cantidadAutosColorMarca(autos, TAM_A, marcas, TAM_M, colores, TAM_C);
						 pausa();
						 break;
					 case 6:
						 marcasMasElegidas(autos, TAM_A, marcas, TAM_M, colores, TAM_C);
						 pausa();
						 break;
					 case 7:
						 trabajosAuto(autos, TAM_A, trabajos, TAM_T, servicios, TAM_S, marcas, TAM_M, colores, TAM_C);
						 pausa();
						 break;
					 case 8:
						 importesAuto(autos, TAM_A, trabajos, TAM_T, servicios, TAM_S, marcas, TAM_M, colores, TAM_C);
						 pausa();
						 break;
					 case 9:
						 serviciosPorAuto(autos, TAM_A, trabajos, TAM_T, servicios, TAM_S, marcas, TAM_M, colores, TAM_C);
						 pausa();
						 break;
					 case 10:
						 serviciosPorFecha(trabajos, TAM_T, autos, TAM_A, servicios, TAM_S, marcas, TAM_M);
						 pausa();
						 break;
					 case 11:
						 break;
					 default:
						 printf("La opcion ingresada no existe.\n");
						 pausa();
					 }
				limpiarConsola();
				}while(opcionMenuInformes!=11);
			 }
			 else
			 {
				 printf("No hay autos en sistema para realizar informes.\n");
				 pausa();
			 }
			 break;
		 case 'k':
			 limpiarConsola();
			 confirmaSalida(&respuesta, 's', 'n');
			 break;
		 default:
			 printf("La opcion ingresada no existe.\n");
		}
	//pausa();
	limpiarConsola();
	}while(respuesta == 'n');

	return 0;
}


