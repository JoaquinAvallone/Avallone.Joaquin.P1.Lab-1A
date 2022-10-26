/*
 * informes.h
 *
 *  Created on: 23 oct. 2022
 *      Author: mac2020
 */

#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */

/// @brief Imprime el menu de opciones y te pide el ingreso de una opcion
///
/// @param pOpcion parametro donde guardar el valor de la opcion elegida
/// @return retorna la opcion elegida
int menuInformes(int* pOpcion);


/// @brief pide el ingreso de un color existente y recorre el vector de autos en busca de una conincidencia, de encontrarla, muestra ese auto
///
/// @param autos
/// @param tamA
/// @param colores
/// @param tamC
/// @param marcas
/// @param tamM
/// @return retorna 1 si pudo encontrar conicidencia, de lo contrario devuelve 0
int mostrarAutosColor(eAuto autos[], int tamA, eColor colores [], int tamC, eMarca marcas[], int tamM);


/// @brief pide el ingreso de una marca existente y recorre el vector de autos en busca de una conincidencia, de encontrarla, muestra ese auto
///
/// @param autos
/// @param tamA
/// @param colores
/// @param tamC
/// @param marcas
/// @param tamM
/// @return retorna 1 si pudo encontrar conicidencia, de lo contrario devuelve 0
int mostrarAutosMarca(eAuto autos[], int tamA, eColor colores [], int tamC, eMarca marcas[], int tamM);


/// @brief recorre el vector de autos buscando lo que tengan caja automatica, de encontrar coincidencia va sumando la cantidad, luego lo mismo con los manuales para despues poder sacar el porcentaje
///
/// @param autos
/// @param tamA
/// @return retorna 1 si el vector es distinto de NULL, de lo contrario retorna 0
int porcentajesPorCaja(eAuto autos[], int tamA);



/// @brief recorre el vector de autos buscando los automaticos y luego lo mismo con los manuales imprimiendo las coincidencias si las hay
///
/// @param autos
/// @param tamA
/// @param marcas
/// @param tamM
/// @param colores
/// @param tamC
/// @return retorna 1 en caso de encontrar alguna coincidencia
int mostrarAutosPorCaja(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);



/// @brief Pide el ingreso de una marca y color existentes y busca la coincidencia recorriendo el vector de autos, de encontrarla muestra el auto y dice cuantos hay con esas especificaciones
///
/// @param autos
/// @param tamA
/// @param marcas
/// @param tamM
/// @param colores
/// @param tamC
/// @return retorna 1 en caso de encontrar coincidencia de lo contraio retorna 0
int cantidadAutosColorMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);



/// @brief primero recorre el vector de marcas y dentro el de autos buscando coincidencia, de haberla las va contando en el vector de contadores en la posicion de la marca coincidente
/// 		luego recorre el vec de contadores buscando el contador mas alto y al finalizar imprime la o las mascar con mas coincidencias
///
/// @param autos
/// @param tamA
/// @param marcas
/// @param tamM
/// @param colores
/// @param tamC
/// @return retorna 1 si los vec son diferentes de NULL y los tam mayores a 0, de lo contrario devuelve 0
int marcasMasElegidas(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC);



/// @brief Pide el ingreso del id de un auto existente y recorre el vec de trabajos buscando coincidencia, de haberla muestra los trabajos realizados al auto seleccionado
///
/// @param autos
/// @param tamA
/// @param trabajos
/// @param tamT
/// @param servicios
/// @param tamS
/// @param marcas
/// @param tamM
/// @param colores
/// @param tamC
/// @return retorna 1 de encontrar coincidencia de la contrario retorna 0
int trabajosAuto(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC);



/// @brief Pide el ingreso del id de un auto existente, recorre el vec de trabajos buscando coincidencia del id del auto para ver si tiene trabajos,
/// luego busca la coincidencia de ese trabajo con el id de servicio para poder acumular el precio del mismo
///
/// @param autos
/// @param tamA
/// @param trabajos
/// @param tamT
/// @param servicios
/// @param tamS
/// @param marcas
/// @param tamM
/// @param colores
/// @param tamC
/// @return retorna 1 de encontrsar coincidencia, de lo contrario retorna 0
int importesAuto(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC);



/// @brief Pide el ingreso del id de un servicio existente y luego recorre el vec de trabajos y de autos buscando coincidencia para poder mostrar el auto al que se
/// le realiza el servicio elegido si es que lo hay
///
/// @param autos
/// @param tamA
/// @param trabajos
/// @param tamT
/// @param servicios
/// @param tamS
/// @param marcas
/// @param tamM
/// @param colores
/// @param tamC
/// @return  retorna 1 de encontrsar coincidencia, de lo contrario retorna 0
int serviciosPorAuto(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC);



/// @brief Pide el ingreso de una fecha y recorre los trabajos buscando si se realizo alguno en esa fecha, de encontrarlo muestra el auto con los servicios realizados
/// en la fecha ingresada
///
/// @param trabajos
/// @param tamT
/// @param autos
/// @param tamA
/// @param servicios
/// @param tamS
/// @param marcas
/// @param tamM
/// @return  retorna 1 de encontrsar coincidencia, de lo contrario retorna 0
int serviciosPorFecha(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM);
