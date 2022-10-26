#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "autos.h"
#include "validaciones.h"
#include "trabajos.h"


int hardcodearTrabajos(int* pId, eTrabajo vec[],int tam, int cant)
{
	int retorno =  0;
	eTrabajo almacenTrabajos[] = {
							{1,103,20003,{23,10,2022},0},
						    {2,105,20002,{20,10,2022},0},
						    {3,102,20003,{17,10,2022},0},
						    {4,100,20001,{26,10,2022},0},
						    {5,104,20002,{27,10,2022},0},
					        {6,101,20003,{24,10,2022},0},
						    {7,106,20001,{23,10,2022},0}
			};

	if(vec!=NULL && tam>0 && cant<=tam && cant<=7)
	{
		for(int i=0; i<cant; i++)
		{
			vec[i] = almacenTrabajos[i];
			*pId = *pId + 1;
		}

		retorno = 1;
	}

	return retorno;
}

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
				"======================\n");

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
	int flag = 1;
	eTrabajo auxTrabajo;

	if(pId!=NULL && trabajos!=NULL && tamT>0 && autos!=NULL && tamA>0 && servicios!=NULL && tamS>0)
	{
		limpiarConsola();
		printf("              ***ALTA TRABAJOS***\n\n");
		buscarLibreTrabajo(&indice, trabajos, tamT);
		for(int i = 0; i<tamA; i++)
		{
			if(!autos[i].isEmpty)
			{
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay autos en el sistema.\n");
		}
		else
		{
			if(indice==-1)
			{
				printf("No hay lugar en el sistema para mas trabajos\n");
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

	if(pTrabajo!=NULL && autos!=NULL && tamA>0 && servicios!=NULL && tamS>0 && marcas!=NULL && tamM>0 && colores!=NULL && tamS>0)
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
	int auxIdMarca;
	char auxMarca[20];
	char auxServicio[20];

	cargarIdMarca(trabajos.idAuto, &auxIdMarca, autos, tamA);
	cargarDescripcionMarca(auxIdMarca, auxMarca, marcas, tamM);
	cargarDescripcionServicio(trabajos.idServicio, auxServicio, servicios, tamS);

	printf(" %d     %d      %-9s    %-8s    %02d/%02d/%d|\n",
						trabajos.id,
						trabajos.idAuto,
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
			printf("         No hay Trabajos en el sistema\n");
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

int cargarIdAuto(int id, int* pId, eAuto vec[], int tam)
{
 int retorno = 0;

 if(pId != NULL && vec != NULL && tam > 0)
 {
    for(int i = 0 ; i < tam ; i++)
    {
        if(vec[i].id == id)
        {
            *pId = vec[i].id;
            break;
        }
    }

   retorno = 1;
 }
 return retorno;
}

int cargarIdMarca(int id, int* pId, eAuto vec[], int tam)
{
 int retorno = 0;

 if(pId != NULL && vec != NULL && tam > 0)
 {
    for(int i = 0 ; i < tam ; i++)
    {
        if(vec[i].id == id)
        {
            *pId = vec[i].idMarca;
            break;
        }
    }

   retorno = 1;
 }
 return retorno;
}


