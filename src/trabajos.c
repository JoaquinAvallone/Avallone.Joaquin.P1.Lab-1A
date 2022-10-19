#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "autos.h"
#include "validaciones.h"
#include "trabajos.h"

int listarServicios(eServicio servicios[], int tamS)
{
	int retorno = 0;

	 if(servicios != NULL && tamS > 0)
	 {
		limpiarConsola();

		printf( "======================\n"
				"| Lista de Servicios |\n"
				"======================\n");
		printf( "|Servicios | Precios |\n"
				"----------------------\n");

		for(int i = 0 ; i < tamS ; i++)
		{
			printf("| %-8s |  $%d   |\n"
				"----------------------\n", servicios[i].descripcion, servicios[i].precio);
		}
	 }

	return retorno;
}

int mostrarServicios(eServicio servicios[], int tamS)
{
	int retorno = 0;

	if(servicios != NULL && tamS > 0)
	 {
		limpiarConsola();

		printf( "================================\n"
				"        Lista de Servicios     |\n"
				"================================\n");
		printf("  Id  |   Descripcion | Precio |\n"
				"--------------------------------\n");

		for(int i = 0 ; i < tamS ; i++)
		{
			printf("%d  |   %-8s   |  $%3d  |\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
		}
	 }

	return retorno;
}



int inicializarTrabajo(eTrabajo trabajos[], int tamT)
{
	int retorno = 0;

	if(trabajos != NULL && tamT>0)
	{
		for(int i=0; i<tamT; i++)
		{
			trabajos[i].isEmpty = 1;
		}
	retorno = 1;
	}

	return retorno;
}

int buscarLibreTrabajo(int * pIndice, eTrabajo trabajos[], int tamT)
{
	int retorno = 0;
	int indice = -1;

	if(pIndice!=NULL && trabajos!=NULL && tamT>0)
	{
		for(int i=0; i<tamT; i++)
		{
			if(trabajos[i].isEmpty)
			{
				indice = i;
				break;
			}
		}
	*pIndice = indice;
	retorno = 1;
	}

	return retorno;
}

int altaTrabajo(int* pId, eTrabajo trabajos[], int tamT, eAuto autos[],int tamA, eServicio servicios[],int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
	int retorno = 0;
	int indice;
	eTrabajo auxTrabajo;

	if(pId!=NULL && trabajos!=NULL && tamT>0 && autos!=NULL && tamA>0 && servicios!=NULL && tamS>0)
	{
		limpiarConsola();
		printf("              ***ALTA TRABAJOS***\n\n");
		buscarLibreTrabajo(&indice, trabajos, tamT);
		if(indice==-1)
		{
			printf("No hay lugar disponible\n");
		}
		else
		{
			cargarTrabajo(&auxTrabajo, autos, tamA, servicios, tamS, marcas, tamM, colores, tamC);
			auxTrabajo.id = *pId;
			*pId = *pId+1;
			trabajos[indice] = auxTrabajo;
			retorno = 1;
		}

	}
	return retorno;
}

int cargarTrabajo(eTrabajo* pTrabajo, eAuto autos[],int tamA, eServicio servicios[],int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
	int retorno = 0;
	int auxEntero;
	int auxDia;
	int auxMes;
	int auxAnio;

	if(pTrabajo!=NULL && autos!=NULL && tamA>0 && servicios!=NULL && tamS>0)
	{

		mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, 0);
		printf("\nIngrese id del auto: ");
		fpurge(stdin);
		scanf("%d", &auxEntero);
		while(!validarIdAutos(auxEntero, autos, tamA))
		{
			printf("Id invalido, vuelva a ingresar el id del auto: ");
			fpurge(stdin);
			scanf("%d", &auxEntero);
		}
		pTrabajo->idAuto=auxEntero;

		mostrarServicios(servicios, tamS);
		printf("\nIngrese id del servicio a realizar: ");
		fpurge(stdin);
		scanf("%d", &auxEntero);
		while(!validarIdServicios(auxEntero, servicios, tamS))
		{
			printf("Id invalido, vuelva a ingresar el id del servicio: ");
			fpurge(stdin);
			scanf("%d", &auxEntero);
		}
		pTrabajo->idServicio=auxEntero;

		printf("Ingrese fecha de ingreso: ");
		scanf("%d/%d/%d", &auxDia,
						  &auxMes,
						  &auxAnio);
		while(!validarFecha(auxDia, auxMes, auxAnio))
		{
			printf("Fecha incorrecta, vuelva a intentarlo");
			scanf("%d/%d/%d", &auxDia,
							  &auxMes,
							  &auxAnio);;
		}
		pTrabajo->fecha.dia=auxDia;
		pTrabajo->fecha.mes=auxMes;
		pTrabajo->fecha.anio=auxAnio;

		pTrabajo->isEmpty = 0;
	}


	return retorno;
}

void mostrarTrabajo(eTrabajo trabajos, eAuto autos[],int tamA, eServicio servicios[],int tamS, eMarca marcas[], int tamM)
{
	int auxIdAuto;
	int auxIdMarca;
	char auxMarca[20];
	char auxServicio[20];

	cargarIdAuto(trabajos.idAuto, &auxIdAuto, autos, tamA);
	cargarIdMarca(trabajos.idAuto, &auxIdMarca, autos, tamA);
	cargarDescripcionMarca(auxIdMarca, auxMarca, marcas, tamM);
	cargarDescripcionServicio(trabajos.idServicio, auxServicio, servicios, tamS);

	printf(" %d     %d     %-9s      %-8s   %02d/%02d/%d|\n",
						trabajos.id,
						auxIdAuto,
						auxMarca,
						auxServicio,
						trabajos.fecha.dia,
						trabajos.fecha.mes,
						trabajos.fecha.anio);

}

int mostrarTrabajos(eTrabajo vec[],int tamT, eAuto autos[],int tamA, eServicio servicios[],int tamS, eMarca marcas[], int tamM, int cls)
{
	int retorno = 0;
	int flag=1;
	if(vec!=NULL && tamT>0 && autos!=NULL && tamA>0 && servicios!=NULL && tamS>0 && marcas!=NULL && tamM>0 && cls>=0 && cls<=1)
	{
		if(cls)
		{
			limpiarConsola();
		}
		printf( "====================================================\n"
				"                 ***LISTA TRABAJOS***              |\n"
				"====================================================\n");
		printf( " ID   Id.Auto    Marca       Servicio     F.Ingreso|\n"
			    "----------------------------------------------------\n");

		for(int i = 0; i<tamT; i++)
		{
			if(!vec[i].isEmpty)
			{
				mostrarTrabajo(vec[i], autos, tamA, servicios, tamS, marcas, tamM);
				flag = 0;
				retorno = 1;
			}
		}
		if(flag)
		{
			printf("  No hay Trabajos en el sistema\n");
		}

	}
	return retorno;
}

int cargarDescripcionServicio(int id, char descripcion[], eServicio vec[], int tam)
{
 int retorno = 0;

 if(descripcion != NULL && vec != NULL && tam > 0)
 {
    for(int i = 0 ; i < tam ; i++)
    {
        if(vec[i].id == id)
        {
            strcpy(descripcion, vec[i].descripcion);
            break;
        }
    }

   retorno = 1;
 }
 return retorno;
}

int cargarIdAuto(int id, int* descripcion, eAuto vec[], int tam)
{
 int retorno = 0;

 if(descripcion != NULL && vec != NULL && tam > 0)
 {
    for(int i = 0 ; i < tam ; i++)
    {
        if(vec[i].id == id)
        {
            *descripcion = vec[i].id;
            break;
        }
    }

   retorno = 1;
 }
 return retorno;
}

int cargarIdMarca(int id, int* descripcion, eAuto vec[], int tam)
{
 int retorno = 0;

 if(descripcion != NULL && vec != NULL && tam > 0)
 {
    for(int i = 0 ; i < tam ; i++)
    {
        if(vec[i].id == id)
        {
            *descripcion = vec[i].idMarca;
            break;
        }
    }

   retorno = 1;
 }
 return retorno;
}


