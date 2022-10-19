/*
 * validaciones.h
 *
 *  Created on: 19 oct. 2022
 *      Author: mac2020
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */

int validarRangoEntero(int valor, int max, int min);
int validarCaracter(char valor,char a,char b);
int validarIdMarcas(int id, eMarca marcas[], int tamM);
int validarIdColores(int id, eColor colores[], int tamC);
int validarRangoCaracter(char valor, char max, char min);
int validarIdAutos(int id, eAuto autos[], int tamA);
int validarFecha(int valorDia, int valorMes, int valorAnio);
int validarIdServicios(int id, eServicio servicios[], int tamS);
int confirmaSalida(char* pRespuesta, char confirma, char rechaza);
