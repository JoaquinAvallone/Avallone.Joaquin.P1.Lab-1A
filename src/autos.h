/*
 * autos.h
 *
 *  Created on: 19 oct. 2022
 *      Author: mac2020
 */

#ifndef AUTOS_H_
#define AUTOS_H_



typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;


typedef struct{
	int id;
	char descripcion[20];
}eMarca;

typedef struct{
	int id;
	char nombreColor[20];
}eColor;

typedef struct{
	int id;
	int idMarca;
	int idColor;
	char caja;
	int isEmpty;
}eAuto;

typedef struct{
	int id;
	char descripcion[25];
	int precio;
}eServicio;

typedef struct{
	int id;
	int idAuto;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;




#endif /* AUTOS_H_ */

/// @brief Realiza saltos de linea para generar la ilusion de limpiar la consola.
void limpiarConsola();

/// @brief Espera que ingreses un caracter para seguir con el programa
void pausa();


/// @brief Harcodea los datos en el vector de los autos
///
/// @param pLegajo Parametro en el cual colocar el valor harcodeado del legajo
/// @param vec vector a hardcodear
/// @param tam tamaño del vector
/// @param cant cantidad de autos a hardcodear
/// @return retorna 1 en caso de que los parametros aean distintos de null y tam sea mayo a 0, de lo contrario retorna 0
int hardcodearAutos(int* pLegajo, eAuto vec[],int tam, int cant);

/// @brief Imprime el menu de opciones y te pide el ingreso de una opcion
///
/// @return retorna la opcion elegida
int menuPrincipal();

/// @brief recorre el array de autos y pasa el valor de isEmpti a 1 indicando que esta libre
///
/// @param vec vector a inicializar
/// @param tam tamaño del vector
/// @return retorna 1 si el vector es distinto de NULL y si el tam es mayor a 0, de lo contrario retorna 0
int inicializarAutos(eAuto vec[], int tam);

/// @brief recorre el vector en busca del indice en el que isEmpty sea 1
///
/// @param pIndice parametro en el cual colacar el valor del indice buscado
/// @param vec vector a recorrer
/// @param tam tamaño del vector
/// @return retorna 1 si los parametros son distintos de nul y si el tam es mayo a 0, de lo contrario retorna 0
int buscarLibre(int * pIndice, eAuto vec[], int tam);


/// @brief
///
/// @param pFlag
/// @param vec
/// @param tam
/// @return
int buscarOcupado(int * pFlag, eAuto vec[], int tam);


/// @brief busca el indice en el que el vector este libre, de ser asi te manda a cargar la carga de datos
///
/// @param pId parametro en donde colocar el id del auto en caso de que se pueda dar de alta
/// @param vec vector de autos
/// @param tam tam del vector autos
/// @param marcas vector de las marcas
/// @param tamM tamaño del vector marcas
/// @param colores vector de colores
/// @param tamC tamaño del vector colores
/// @return retorna 1 si encontro un lugar libre y se pudo cargar un auto, de lo contrario retorna 0
int altaAutos(int* pId, eAuto vec[], int tam, eMarca marcas[],int tamM, eColor colores[],int tamC);


/// @brief Carga de datos del vector de autos
///
/// @param pAuto parametro del indice libre del vector de autos
/// @param marcas vercotr de marcas
/// @param tamM tamaño del vector de marcas
/// @param colores vector de colores
/// @param tamC tamaño del vector de colores
/// @return retorna 1 en el caso de que los parametros sean distintos de NULL t los tam sean mayor a 0; de lo contrario retorna 0
int cargarAuto(eAuto* pAuto, eMarca marcas[],int tamM, eColor colores[],int tamC);


/// @brief muestras un listado de marcas y sus id
///
/// @param vec vector de las marcas que queremos mostrar
/// @param tam tamaño del vector
/// @return retorna 1 en caso de que el vector sea distinto de NULL y el tam sea mayor a 0, de lo contrario retorna 0
int mostrarMarcas(eMarca vec[], int tam);


/// @brief muestra un listado de los colores y sus id
///
/// @param vec vector de colores a mostrar
/// @param tam tamñao del vector
/// @return retorna 1 en caso de que el vector sea distinto de NULL y el tam sea mayor a 0, de lo contrario retorna 0;
int mostrarColores(eColor vec[], int tam);


/// @brief recorre el vector de autos buscando el lugar en donde isEmpty sea igual a 0, de encontrarlo llama a mostrarAuto y lo muestra
///
/// @param vec vector de autos
/// @param tam tamaño del vector autos
/// @param marcas vector de marcas
/// @param tamM tamaño del vector de marcas
/// @param colores vector de colores
/// @param tamC tamaño del vector de colores
/// @param cls de ser true limpia la pantalla, de lo contrario no lo hace
/// @return retorna 1 en caso de que se hayo podido mostrar al menos un auto
int mostrarAutos(eAuto vec[],int tam, eMarca marcas[],int tamM, eColor colores[],int tamC, int cls);


/// @brief muestra el auto que le llega cargando las descriociones en los id de marca y colores
///
/// @param autos auto a mostrar
/// @param marcas vector de marcas
/// @param tamM taamaño del vetor marcas
/// @param colores vector de coleres
/// @param tamC tamaño del vector de colores
int mostrarAuto(eAuto autos, eMarca marcas[],int tamM, eColor colores[],int tamC);


/// @brief recorre el vec de marcas y busca el indice en el que el id que le pasas y el suyo coincidan, de ser asi te carga la descripcion que este en ese indice en el auxiliar pasado
///
/// @param id id a verificar coincidencia
/// @param descripcion auxiliar en donde cargar la descripcion en caso de conincidencia de ids
/// @param vec vector a recorrer
/// @param tam tamaño del vector
/// @return retorna 1 si los parametros son distintos de NULL y el tam es mayor a 0, de lo contrario retorna 0
int cargarDescripcionMarca(int id, char descripcion[], eMarca vec[], int tam);


/// @brief recorre el vec de colores y busca el indice en el que el id que le pasas y el suyo coincidan, de ser asi te carga la descripcion que este en ese indice en el auxiliar pasado
///
/// @param id d a verificar coincidencia
/// @param descripcion auxiliar en donde cargar la descripcion en caso de conincidencia de ids
/// @param vec vector a recorrer
/// @param tam tamaño del vector
/// @return retorna 1 si los parametros son distintos de NULL y el tam es mayor a 0, de lo contrario retorna 0
int cargarDescripcionColor(int id, char descripcion[], eColor vec[], int tam);


/// @brief  Realiza un brbujeo en el cual primero se fija que si el id en indice i es mayor el ubicado en indice j, de ser asi los cambia de lugar, si los id son iguales los ordena por la caja alfabeticamente
///
/// @param vec vector a ordenar
/// @param tam tamaño del vector
/// @return retorna 1 en el caso que los parametros pasados sean distintos de NULL y el tam sea ayor a 0, de lo contrario retorna 0
int ordenarAutos(eAuto vec[], int tam);


/// @brief
///
/// @param pIndice
/// @param patente
/// @param autos
/// @param tamA
/// @return
int buscarIdAuto(int* pIndice, int patente, eAuto autos[], int tamA);
int modificarAuto( eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);
int menuModificacionAuto();
int bajaAuto( eAuto vec[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC, eTrabajo trabajos[], int tamT);
int listarMarcas(eMarca marcas[], int tamM);
int listarColores(eColor colores[], int tamC);










