#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "autos.h"
#include "validaciones.h"
#include "trabajos.h"


void limpiarConsola()
{
	int i;
	for(i=0;i<40;i++)
	{
		printf("\n");
	}
}

void pausa()
{
	char enter;

	printf("Press Enter to continue...");
	fpurge(stdin);
	scanf("%c", &enter);
}

int harcodearAutos(int* pLegajo, eAuto vec[],int tam, int cant)
{
	int retorno =  0;
	eAuto almacenAutos[] = {{100,1003,5001,'m',0},
						    {101,1002,5003,'m',0},
						    {102,1000,5002,'a',0},
						    {103,1004,5004,'m',0},
						    {104,1001,5003,'a',0},
					        {105,1002,5004,'m',0},
						    {106,1003,5000,'a',0}
			};

	if(vec!=NULL && tam>0 && cant<=tam && cant<=10)
	{
		for(int i=0; i<cant; i++)
		{
			vec[i] = almacenAutos[i];
			*pLegajo = *pLegajo + 1;
		}

		retorno = 1;
	}

	return retorno;
}

int menuPrincipal()
{
	char opcion;

	printf("                 ***ABM AUTOS***\n\n"
		   "A.Alta auto\n"
		   "B.Modificar auto\n"
		   "C.Baja auto\n"
		   "D.Listar autos\n"
		   "E.Listar marcas\n"
		   "F.Listar colores\n"
		   "G.Listar servicios\n"
		   "H.Alta trabajo\n"
		   "I.Listar trabajos\n"
		   "J.Salir\n"
		   "Ingrese opcion: ");
	fpurge(stdin);
	scanf("%c", &opcion);
	opcion=tolower(opcion);


	return opcion;
}

int inicializarAutos(eAuto vec[], int tam)
{
	int retorno = 0;

	if(vec != NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			vec[i].isEmpty = 1;
		}
	retorno = 1;
	}

	return retorno;
}

int buscarLibre(int * pIndice, eAuto vec[], int tam)
{
	int retorno = 0;
	int indice = -1;

	if(pIndice!=NULL && vec!=NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(vec[i].isEmpty)
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

int altaAutos(int* pId, eAuto vec[], int tam, eMarca marcas[],int tamM, eColor colors[],int tamC)
{
	int retorno = 0;
	int indice;
	eAuto auxAuto;

	if(pId!=NULL && vec!=NULL && tam>0)
	{
		limpiarConsola();
		printf("              ***ALTA AUTOS***\n\n");
		buscarLibre(&indice, vec, tam);
		if(indice==-1)
		{
			printf("No hay lugar disponible\n");
		}
		else
		{
			cargarAuto(&auxAuto, marcas, tamM, colors, tamC);
			auxAuto.id = *pId;
			*pId = *pId+1;
			vec[indice] = auxAuto;
			retorno = 1;
		}

	}
	return retorno;
}

int cargarAuto(eAuto* pAuto, eMarca marcas[],int tamM, eColor colores[],int tamC)
{
	int retorno = 0;
	int auxEntero;
	char auxCaracter;

	if(pAuto!=NULL && marcas!=NULL && tamM>0 && colores!=NULL && tamC>0)
	{

		mostrarMarcas(marcas, tamM);
		printf("\nIngrese id marca: ");
		fpurge(stdin);
		scanf("%d", &auxEntero);
		while(!validarIdMarcas(auxEntero, marcas, tamM))
		{
			printf("Id invalido, vuelva a ingresar el id de la marca: ");
			fpurge(stdin);
			scanf("%d", &auxEntero);
		}
		pAuto->idMarca=auxEntero;

		mostrarColores(colores, tamC);
		printf("\nIngrese id color: ");
		fpurge(stdin);
		scanf("%d", &auxEntero);
		while(!validarIdColores(auxEntero, colores, tamC))
		{
			printf("Id invalido, vuelva a ingresar el id del color: ");
			fpurge(stdin);
			scanf("%d", &auxEntero);
		}
		pAuto->idColor=auxEntero;

		printf("\nIngrese tipo de caja('a' para automatico o 'm' para manual):  ");
		fpurge(stdin);
		scanf("%c", &auxCaracter);
		auxCaracter=tolower(auxCaracter);
		while(!validarCaracter(auxCaracter, 'a', 'm'))
		{
			printf("El caracter ingresado es invalido, vuelva a intentarlo: ");
			fpurge(stdin);
			scanf("%c", &auxCaracter);
		}
		pAuto->caja=auxCaracter;

		pAuto->isEmpty = 0;
		retorno=1;
	}


	return retorno;
}



int mostrarMarcas(eMarca vec[], int tam)
{
	 int retorno = 0;

	 if(vec != NULL && tam > 0)
	 {

		printf( "========================\n"
				"    Lista de Marcas    |\n"
				"========================\n");
		printf("  Id  |   Descripcion  |\n"
				"------------------------\n");

		for(int i = 0 ; i < tam ; i++)
		{
			printf("%d  |   %-9s    |\n", vec[i].id, vec[i].descripcion);
		}
		retorno =1;
	 }
	 return retorno;
}

int mostrarColores(eColor vec[], int tam)
{
	 int retorno = 0;

	 if(vec != NULL && tam > 0)
	 {

		printf( "======================\n"
				"  Lista de Colores   |\n"
				"======================\n");
		printf( " Id   |  Descripcion |\n"
				"----------------------\n");

		for(int i = 0 ; i < tam ; i++)
		{
			printf("%d      %-6s     |\n", vec[i].id, vec[i].nombreColor);
		}
	retorno=1;
	 }
	 return retorno;
}

int mostrarAuto(eAuto autos, eMarca marcas[],int tamM, eColor colores[],int tamC)
{
	int retorno = 0;
	char auxMarca[20];
	char auxColor[20];

	if(marcas!=NULL && tamM>0 && colores != NULL && tamC>0)
	{
		cargarDescripcionColor(autos.idColor, auxColor, colores, tamC);
		cargarDescripcionMarca(autos.idMarca, auxMarca, marcas, tamM);

		printf(" %d     %-9s       %-6s      %c  |\n",
							autos.id,
							auxMarca,
							auxColor, // id idMarca idColor caja isEmpty
							autos.caja);

		retorno = 1;
	}
	return retorno;
}

int mostrarAutos(eAuto vec[],int tam, eMarca marcas[],int tamM, eColor colores[],int tamC, int cls)
{
	int retorno = 0;
	int flag=1;
	if(vec!=NULL && tam>0 && cls>=0 && cls<=1)
	{
		if(cls)
		{
			limpiarConsola();
		}
		printf( "=========================================\n"
				"             ***LISTA AUTOS***          |\n"
				"=========================================\n");
		printf( " ID         Marca        Color     Caja|\n"
			    "-----------------------------------------\n");

		for(int i = 0; i<tam; i++)
		{
			if(!vec[i].isEmpty)
			{
				mostrarAuto(vec[i], marcas, tamM, colores, tamC);
				flag = 0;
				retorno = 1;
			}
		}
		if(flag)
		{
			printf("  No hay autos en el sistema\n");
		}

	}
	return retorno;
}

int cargarDescripcionMarca(int id, char descripcion[], eMarca vec[], int tam)
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


int cargarDescripcionColor(int id, char descripcion[], eColor vec[], int tam)
{
 int retorno = 0;

 if(descripcion != NULL && vec != NULL && tam > 0)
 {
    for(int i = 0 ; i < tam ; i++)
    {
        if(vec[i].id == id)
        {
            strcpy(descripcion, vec[i].nombreColor);
            break;
        }
    }

   retorno = 1;
 }

return retorno;
}

int ordenarAutos(eAuto vec[], int tam)
{
	int retorno = 0;
	eAuto auxAuto;

	if(vec!=NULL && vec>0)
	{
		for(int i = 0; i<tam-1; i++)
		{
			for(int j= i+1; j < tam; j++)
			{
				if((vec[i].idMarca > vec[j].idMarca) || (vec[i].idMarca == vec[j].idMarca && vec[i].caja > vec[j].caja))
				{
					auxAuto = vec[i];
					vec[i] = vec[j];
					vec[j] = auxAuto;
				}
			}
		}
	retorno = 1;
	}



	return retorno;
}

int modificarAuto( eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
	int retorno = 0;
	int indice;
	int id;
	char respuesta;
	int auxIdMarca;
	int auxIdColor;

	if(autos!=NULL && tamA>0)
	{
		limpiarConsola();
		printf("           ***MODIFICAR AUTO***\n\n");
		if(mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, 0))
		{
			printf("\nIngrese id: ");
			scanf("%d", &id);

			buscarIdAuto(&indice, id, autos, tamA);
			if(indice==-1)
			{
				printf("No existe un auto con el id: %d\n", id);
			}
			else
			{
				limpiarConsola();
				printf("EL AUTO QUE DESEA MODIFICAR ES EL SIGUIENTE: \n\n");
				printf( "=========================================\n"
						"             ***LISTA AUTOS***          |\n"
						"=========================================\n");
				printf( " ID       IdMarca       IdColor     Caja|\n"
						"-----------------------------------------\n");
				mostrarAuto(autos[indice], marcas, tamM, colores, tamC);
				printf("\nConfirma modificacion?: \n");
				fpurge(stdin);
				scanf("%c",&respuesta);
				if(respuesta=='s')
				{
					limpiarConsola();
					switch(menuModificacionAuto())
					{
					 case 1:
						 mostrarMarcas(marcas, tamM);
						 printf("Ingrese nueva idMarca: ");
						 scanf("%d", &auxIdMarca);
						 while(!validarIdMarcas(auxIdMarca, marcas, tamM))
						 {
							 printf("Id incorrecto, vuelva a ingresar idMarca: ");
							 scanf("%d", &auxIdMarca);
						 }
						 autos[indice].idMarca = auxIdMarca;
						 break;
					 case 2:
						 mostrarColores(colores, tamC);
						 printf("Ingrese nuevo idColor: ");
						 scanf("%d", &auxIdColor);
						 while(!validarIdColores(auxIdColor, colores, tamC))
						 {
							 printf("Id incorrecto, vuelva a ingresar idColor: ");
							 scanf("%d", &auxIdColor);
						 }
						 autos[indice].idColor = auxIdColor;
						 break;
					 default:
					 {
						 printf("La opcion ingresado no existe.\n");
					 }
					}
					retorno = 1;
				}
				else
				{
					printf("Modificacion cancelada.\n");
				}
			}
		}



	}

	return retorno;

}

int buscarIdAuto(int* pIndice, int id, eAuto autos[], int tamA)
{
	int retorno = 0;
	int indice = -1;

	if(pIndice!=NULL && id>0 && autos!=NULL && tamA > 0)
	{
		for(int i=0; i<tamA; i++)
		{
			if(!autos[i].isEmpty && autos[i].id==id)
			{
				indice=i;
				break;
			}
		}
	*pIndice=indice;
	retorno = 1;
	}

	return retorno;
}

int menuModificacionAuto()
{
	int opcion;

	printf("             ***OPCIONES MODIFICACION DE AUTOS***          \n\n"
			"1.Modificar Marca del auto\n"
			"2.Modificar Color del auto\n");
	scanf("%d",&opcion);

	return opcion;
}

int bajaAuto( eAuto vec[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
	int retorno = 0;
		int indice;
		int patente;
		char respuesta;

		if(vec!=NULL && tamA>0)
		{
			limpiarConsola();
			printf("              ***BAJA AUTO***\n\n");
			if(mostrarAutos(vec, tamA, marcas, tamM, colores, tamC, 0))
			{
				printf("Ingrese id: ");
				scanf("%d", &patente);

				buscarIdAuto(&indice, patente, vec, tamA);
				if(indice==-1)
				{
					printf("No existe el id: %d\n", patente);
				}
				else
				{
					limpiarConsola();
					printf("EL AUTO QUE DESEA DAR DE BAJA ES EL SIGUIENTE: \n\n");
					printf( "=========================================\n"
							"             ***LISTA AUTOS***          |\n"
							"=========================================\n");
					printf( " ID       IdMarca       IdColor     Caja|\n"
							"-----------------------------------------\n");
					mostrarAuto(vec[indice], marcas, tamM, colores, tamC);
					printf("\nConfirma baja?: \n");
					fpurge(stdin);
					scanf("%c",&respuesta);
					if(respuesta=='s')
					{
						vec[indice].isEmpty = 1;
						retorno = 1;
					}
					else
					{
						printf("Baja cancelada.\n");
					}
				}
			}



		}

		return retorno;

}

int listarMarcas(eMarca marcas[], int tamM)
{
	int retorno = 0;

	 if(marcas != NULL && tamM > 0)
	 {
		limpiarConsola();

		printf( "======================\n"
				"    Lista de Marcas  |\n"
				"======================\n");

		for(int i = 0 ; i < tamM ; i++)
		{
			printf("       %-9s     |\n"
					"----------------------\n", marcas[i].descripcion);
		}
	 }

	return retorno;
}

int listarColores(eColor colores[], int tamC)
{
	int retorno = 0;

	 if(colores != NULL && tamC > 0)
	 {
		limpiarConsola();

		printf( "======================\n"
				"   Lista de Colores  |\n"
				"======================\n");

		for(int i = 0 ; i < tamC ; i++)
		{
			printf("        %-6s       |\n"
				"----------------------\n", colores[i].nombreColor);
		}
	 }

	return retorno;
}


