/*
 * trabajos.h
 *
 *  Created on: 19 oct. 2022
 *      Author: mac2020
 */

#ifndef TRABAJOS_H_
#define TRABAJOS_H_




#endif /* TRABAJOS_H_ */

int hardcodearTrabajos(int* pId, eTrabajo vec[],int tam, int cant);
int listarServicios(eServicio servicios[], int tamS);
int mostrarServicios(eServicio servicios[], int tamS);
int inicializarTrabajo(eTrabajo trabajos[], int tamT);
int buscarLibreTrabajo(int * pIndice, eTrabajo trabajos[], int tamT);
int altaTrabajo(int* pId, eTrabajo trabajos[], int tamT, eAuto autos[],int tamA, eServicio servicios[],int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC);
int cargarTrabajo(eTrabajo* pTrabajo, eAuto autos[],int tamA, eServicio servicios[],int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC);
void mostrarTrabajo(eTrabajo trabajos, eAuto autos[],int tamA, eServicio servicios[],int tamS, eMarca marcas[], int tamM);
int mostrarTrabajos(eTrabajo vec[],int tamT, eAuto autos[],int tamA, eServicio servicios[],int tamS, eMarca marcas[], int tamM, int cls);
int cargarDescripcionServicio(int id, char descripcion[], eServicio vec[], int tam);
int cargarIdAuto(int id, int* pId, eAuto vec[], int tam);
int cargarIdMarca(int id, int* pId, eAuto vec[], int tam);
