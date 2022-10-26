#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "autos.h"
#include "validaciones.h"
#include "trabajos.h"

int menuInformes(int* pOpcion)
{

	if(pOpcion!=NULL)
	{
		limpiarConsola();

		printf("                 ***MENU INFORMES***\n\n"
			   "1.Informe de autos por color seleccionado.\n"
			   "2.Informe de autos por marca seleccionada.\n"
			   "3.Informe del porcentaje de autos por tipo de caja.\n"
			   "4.Informe de autos por tipo de caja.\n"
			   "5.Informe de la cantidad de autos por color y marca seleccionados.\n"
			   "6.Informe de la/s marcas mas elegidas.\n"
			   "7.Informe de trabajos del auto seleccionado.\n"
			   "8.Informe de importe del auto seleccionado.\n"
			   "9.Informe de autos con el servicio seleccionado.\n"
			   "10.Informe de servicios realizados en la fecha ingresada.\n"
			   "11.Volver\n"
			   "Ingrese opcion: ");
		scanf("%d", pOpcion);
	}

	return *pOpcion;
}

int mostrarAutosColor(eAuto autos[], int tamA, eColor colores [], int tamC, eMarca marcas[], int tamM)
{
	int retorno = 0;
	int idColor;
	int flag = 1;

	if(autos!=NULL && tamA>0 && colores!=NULL && tamC && marcas!=NULL && tamM>0)
	{
		 limpiarConsola();
		 printf("      ***AUTOS POR COLOR SELECCIONADO***\n\n");
		 mostrarColores(colores, tamC);
		 printf("Ingrese id del color: ");
		 scanf("%d", &idColor);
		 while(!validarIdColores(idColor, colores, tamC))
		 {
			 printf("Id incorrecto, vuelva a ingresar id del color: ");
			 scanf("%d", &idColor);
		 }
		 printf("=========================================\n"
				"            ***LISTA AUTOS***           |\n"
				"=========================================\n");
		printf( " ID         Marca        Color     Caja |\n"
				"-----------------------------------------\n");

		for(int i = 0; i<tamA; i++)
		{
			if(!autos[i].isEmpty && autos[i].idColor == idColor)
			{
				mostrarAuto(autos[i], marcas, tamM, colores, tamC);
				retorno = 1;
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay autos con el color ingresado.\n");
		}

	}
	return retorno;
}


int mostrarAutosMarca(eAuto autos[], int tamA, eColor colores [], int tamC, eMarca marcas[], int tamM)
{
	int retorno = 0;
	int idMarca;
	int flag = 1;

	if(autos!=NULL && tamA>0 && colores!=NULL && tamC && marcas!=NULL && tamM>0)
	{
		 limpiarConsola();
		 printf("      ***AUTOS POR MARCA SELECCIONADA***\n\n");
		 mostrarMarcas(marcas, tamM);
		 printf("Ingrese id de la marca: ");
		 scanf("%d", &idMarca);
		 while(!validarIdMarcas(idMarca, marcas, tamM))
		 {
			 printf("Id incorrecto, vuelva a ingresar id de la marca: ");
			 scanf("%d", &idMarca);
		 }
		 printf("=========================================\n"
				"            ***LISTA AUTOS***           |\n"
				"=========================================\n");
		printf( " ID         Marca        Color     Caja |\n"
				"-----------------------------------------\n");

		for(int i = 0; i<tamA; i++)
		{
			if(!autos[i].isEmpty && autos[i].idMarca == idMarca)
			{
				mostrarAuto(autos[i], marcas, tamM, colores, tamC);
				retorno = 1;
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay autos con la marca seleccionada\n");
		}
	}
	return retorno;
}


int porcentajesPorCaja(eAuto autos[], int tamA)
{
	int retorno = 0;
	int contadorAutomatico = 0;
	int contadorManual = 0;
	int total;
	float porcentajeAutomatico;
	float porcentajeManual;
	int flagManual = 1;
	int flagAutomatico = 1;

		if(autos!=NULL && tamA>0)
		{
			limpiarConsola();
			printf("        ***PORCENTAJE DE AUTO POR CAJA***\n\n");

			for(int i=0; i<tamA; i++)
			{
				if(!autos[i].isEmpty && autos[i].caja == 'a')
				{
					contadorAutomatico++;
					flagAutomatico = 0;
				}
			}
			for(int i=0; i<tamA; i++)
			{
				if(!autos[i].isEmpty && autos[i].caja == 'm')
				{
					contadorManual++;
					flagManual = 0;
				}
			}
			total=contadorAutomatico+contadorManual;
			porcentajeAutomatico= (float)(contadorAutomatico * 100)/total;
			porcentajeManual= (float)(contadorManual * 100)/total;
			if(!flagAutomatico)
			{
				printf("El porcentaje de autos automaticos es del %.2f porciento.\n", porcentajeAutomatico);
			}
			else
			{
				printf("No hay autos automaticos en el sistema.\n");
			}
			if(!flagManual)
			{
				printf("El porcentaje de autos manuales es del %.2f porciento.\n", porcentajeManual);
			}
			else
			{
				printf("No hay autos manuales en el sistema.\n");
			}
			retorno=1;
		}


	return retorno;
}

int mostrarAutosPorCaja(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
	int retorno = 0;
	int flagAutomatica = 1;
	int flagManual = 1;

	if(autos!=NULL && tamA>0 && colores!=NULL && tamC && marcas!=NULL && tamM>0)
	{
		limpiarConsola();
		printf("      ***LISTA DE AUTOS POR TIPO DE CAJA***\n\n");

		printf("\n");
		printf( "=========================================\n"
				"               CAJA: MANUAL             |\n"
				"=========================================\n");
		printf( "  ID       Marca        Color     Caja  |\n"
				"-----------------------------------------\n");

		for(int i = 0; i<tamA; i++)
		{
			if(!autos[i].isEmpty && autos[i].caja == 'm')
			{
				mostrarAuto(autos[i], marcas, tamM, colores, tamC);
				printf("-----------------------------------------\n");
				flagManual = 0;
				retorno = 1;
			}
		}
		if(flagManual)
		{
			printf("    No hay autos con caja MANUAL.\n");
		}
		printf("\n");
		printf( "=========================================\n"
				"             CAJA: AUTOMATICA           |\n"
				"=========================================\n");
		printf( "  ID       Marca        Color     Caja  |\n"
				"-----------------------------------------\n");
		for(int i = 0; i<tamA; i++)
		{
			if(!autos[i].isEmpty && autos[i].caja == 'a')
			{
				mostrarAuto(autos[i], marcas, tamM, colores, tamC);
				printf("-----------------------------------------\n");
				flagAutomatica = 0;
				retorno = 1;
			}
		}
		if(flagAutomatica)
		{
			printf("    No hay autos con caja AUTOMATICA.\n");
		}

	}


	return retorno;
}

int cantidadAutosColorMarca(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
	int retorno = 0;
	int idColor;
	int idMarca;
	int flag = 1;
	int contador = 0;

	if(autos!=NULL && tamA>0 && colores!=NULL && tamC && marcas!=NULL && tamM>0)
	{
		limpiarConsola();
		printf("      ***CANTIDAD DE AUTOS POR MARCA Y COLOR***\n\n");
		mostrarColores(colores, tamC);
		printf("\nIngrese id del color: ");
		fpurge(stdin);
		scanf("%d", &idColor);
		while(!validarIdColores(idColor, colores, tamC))
		{
			printf("Id invalido, vuelva a ingresar el id del color: ");
			fpurge(stdin);
			scanf("%d", &idColor);
		}


		mostrarMarcas(marcas, tamM);
		printf("\nIngrese id marca: ");
		fpurge(stdin);
		scanf("%d", &idMarca);
		while(!validarIdMarcas(idMarca, marcas, tamM))
		{
			printf("Id invalido, vuelva a ingresar el id de la marca: ");
			fpurge(stdin);
			scanf("%d", &idMarca);
		}

		printf( "=========================================\n"
				"            ***LISTA AUTOS***           |\n"
				"=========================================\n");
		printf( " ID         Marca        Color     Caja |\n"
				"-----------------------------------------\n");

		for(int i=0; i<tamA; i++)
		{
			if(!autos[i].isEmpty && autos[i].idColor == idColor && autos[i].idMarca == idMarca)
			{
				mostrarAuto(autos[i], marcas, tamM, colores, tamC);
				contador++;
				retorno=1;
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay autos con esas especificaciones.\n");
		}
		else
		{
			printf("\nLa cantidad de autos con ese color y marca es: %d.\n", contador);
		}
	}

	return retorno;
}

int marcasMasElegidas(eAuto autos[], int tamA, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
	int retorno = 0;
	int contadores[]={0,0,0,0,0};
	int mayor;

	if(autos!=NULL && tamA>0 && colores!=NULL && tamC && marcas!=NULL && tamM>0)
	{
		limpiarConsola();
		printf("      ***MARCA MAS ELEGIDA***\n\n");

		for(int i=0; i<tamM; i++)
		{
			for(int j=0; j<tamA; j++)
			{
				if(!autos[j].isEmpty && autos[j].idMarca == marcas[i].id)
				{
					contadores[i]++;
				}
			}
		}
		for(int i=0; i<tamM; i++)
		{
			if(i==0 || contadores[i]>mayor)
			{
				mayor=contadores[i];
			}
		}
		for(int i=0; i<tamM; i++)
		{
			if(contadores[i]==mayor)
			{
				printf("La marca mas elegida es: %s con: %d ", marcas[i].descripcion, contadores[i]);
				if(contadores[i] > 1)
				{
					printf("autos.\n");
				}
				else
				{
					printf("auto.\n");
				}
			}
		}
		retorno=1;
	}


	return retorno;
}

int trabajosAuto(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
	int retorno = 0;
	int idAuto;
	int flag=1;

	if(autos!=NULL && tamA>0 && trabajos!=NULL && tamT && servicios!=NULL && tamS>0 && marcas!=NULL && tamM>0 && colores!=NULL && tamC>0)
	{
		limpiarConsola();
		printf("      ***TRABAJOS REALIZADOS POR AUTO***\n\n");
		mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, 0);
		printf("\nIngrese id del auto: ");
		fpurge(stdin);
		scanf("%d", &idAuto);
		while(!validarIdAutos(idAuto, autos, tamA))
		{
			printf("Id invalido, vuelva a ingresar el id del auto: ");
			fpurge(stdin);
			scanf("%d", &idAuto);
		}

		printf( "====================================================\n"
				" ID   Id.Auto    Marca       Servicio     F.Ingreso|\n"
				"----------------------------------------------------\n");

		for(int i=0; i<tamT; i++)
		{
			if(!trabajos[i].isEmpty && trabajos[i].idAuto == idAuto)
			{
				mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS, marcas, tamM);
				flag=0;
				retorno=1;
			}
		}
		if(flag)
		{
			printf("     No hay Trabajos asociados a ese auto\n");
		}
	}


	return retorno;
}

int importesAuto(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eMarca marcas[], int tamM, eColor colores[], int tamC)
{
	int retorno = 0;
	int idAuto;
	int acumulador=0;
	int flag = 1;

	if(autos!=NULL && tamA>0 && trabajos!=NULL && tamT && servicios!=NULL && tamS>0 && marcas!=NULL && tamM>0 && colores!=NULL && tamC>0)
	{
		limpiarConsola();
			printf("      ***IMPORTES POR AUTO***\n\n");
			mostrarAutos(autos, tamA, marcas, tamM, colores, tamC, 0);
			printf("\nIngrese id del auto: ");
			fpurge(stdin);
			scanf("%d", &idAuto);
			while(!validarIdAutos(idAuto, autos, tamA))
			{
				printf("Id invalido, vuelva a ingresar el id del auto: ");
				fpurge(stdin);
				scanf("%d", &idAuto);
			}

			for(int i=0; i<tamT; i++)
			{
				for(int j=0; j<tamS; j++)
				{
					if(!trabajos[i].isEmpty && trabajos[i].idAuto == idAuto && trabajos[i].idServicio == servicios[j].id)
					{
						acumulador= acumulador + servicios[j].precio;
						flag=0;
						retorno = 1;
					}
				}
			}

			if(flag)
			{
				printf("El auto elegido no tiene realizado ningun trabajo.\n");
			}
			else
			{
				printf("El importe del auto elegido es: $%d\n", acumulador);

			}
	}

	return retorno;
}

int serviciosPorAuto(eAuto autos[], int tamA, eTrabajo trabajos[], int tamT, eServicio servicios[], int tamS, eMarca marcas[], int tamM)
{
	int retorno = 0;
	int idServicio;
	char descripcionServicio[20];
	int flag = 1;

	if(autos!=NULL && tamA>0 && trabajos!=NULL && tamT && servicios!=NULL && tamS>0 && marcas!=NULL && tamM>0)
	{
		limpiarConsola();
		printf("      ***SERVICIOS POR AUTO***\n\n");

		mostrarServicios(servicios, tamS);
		printf("\nIngrese id del servicio a realizar: ");
		fpurge(stdin);
		scanf("%d", &idServicio);
		while(!validarIdServicios(idServicio, servicios, tamS))
		{
			printf("Id invalido, vuelva a ingresar el id del servicio: ");
			fpurge(stdin);
			scanf("%d", &idServicio);
		}

		cargarDescripcionServicio(idServicio, descripcionServicio, servicios, tamS);


		printf( "====================================================\n"
				"                 ***LISTA TRABAJOS***              |\n"
				"====================================================\n");
		printf( " ID   Id.Auto    Marca       Servicio     F.Ingreso|\n"
				"----------------------------------------------------\n");
		for(int i=0; i<tamT; i++)
		{
			for(int j=0; j<tamA; j++)
			{
				if(!trabajos[i].isEmpty && trabajos[i].idServicio == idServicio && trabajos[i].idAuto == autos[j].id)
				{
					mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS, marcas, tamM);
					retorno = 1;
					flag = 0;
					break;
				}
			}
		}
		if(flag)
		{
			printf("No hay autos a los que se les haya realizado el servicio %s.\n", descripcionServicio);
		}
	}


	return retorno;
}


int serviciosPorFecha(eTrabajo trabajos[], int tamT, eAuto autos[], int tamA, eServicio servicios[], int tamS, eMarca marcas[], int tamM)
{
	int retorno = 0;
	int dia;
	int mes;
	int anio;
	int flag = 1;

	if(autos!=NULL && tamA>0 && trabajos!=NULL && tamT && servicios!=NULL && tamS>0 && marcas!=NULL && tamM>0)
	{
		limpiarConsola();
		printf("      ***SERVICIOS POR FECHA***\n\n");

		printf("Ingrese fecha : ");
		scanf("%d/%d/%d", &dia,
						  &mes,
						  &anio);
		while(!validarFecha(dia, mes, anio))
		{
			printf("Fecha incorrecta, vuelva a intentarlo");
			scanf("%d/%d/%d", &dia,
							  &mes,
							  &anio);;
		}

		printf( "====================================================\n"
				"                 ***LISTA TRABAJOS***              |\n"
				"====================================================\n");
		printf( " ID   Id.Auto    Marca       Servicio     F.Ingreso|\n"
				"----------------------------------------------------\n");

		for(int i=0; i<tamT; i++)
		{
			if(!trabajos[i].isEmpty && trabajos[i].fecha.dia == dia && trabajos[i].fecha.mes == mes && trabajos[i].fecha.anio == anio)
			{
				mostrarTrabajo(trabajos[i], autos, tamA, servicios, tamS, marcas, tamM);
				flag=0;
				retorno=1;
			}
		}
		if(flag)
		{
			printf("\n\nNo hay trabajos realizados en la fecha %02d/%02d/%d\n", dia,mes,anio);
		}
	}

	return retorno;
}







