#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "autos.h"
#include "validaciones.h"
#include "trabajos.h"

int validarRangoEntero(int valor, int max, int min)
{
	int retorno = 0;

	if(valor>= min && valor<=max)
	{
		retorno =1;
	}

	return retorno;
}

int validarCaracter(char valor,char a,char b)
{
    int retorno=0;

    a=tolower(a);
    b=tolower(b);

    if(valor == a || valor == b)
    {

        retorno=1;
    }

    return retorno;
}

int validarRangoCaracter(char valor, char max, char min)
{
	int retorno=0;


	if(valor>=min && valor<=max)
	{
		retorno = 1;
	}

	return retorno;
}


int validarIdMarcas(int id, eMarca marcas[], int tamM)
{
	int retorno = 0;

	if(marcas!=NULL && tamM>0 && id>0)
	{
		for(int i=0; i<tamM; i++)
		{
			if(marcas[i].id == id)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int validarIdColores(int id, eColor colores[], int tamC)
{
	int retorno = 0;

	if(colores!=NULL && tamC>0 && id>0)
	{
		for(int i=0; i<tamC; i++)
		{
			if(colores[i].id == id)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int validarIdAutos(int id, eAuto autos[], int tamA)
{
	int retorno = 0;

	if(autos!=NULL && tamA>0 && id>0)
	{
		for(int i=0; i<tamA; i++)
		{
			if(autos[i].id == id)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int validarIdServicios(int id, eServicio servicios[], int tamS)
{
	int retorno = 0;

	if(servicios!=NULL && tamS>0 && id>0)
	{
		for(int i=0; i<tamS; i++)
		{
			if(servicios[i].id == id)
			{
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}

int validarFecha(int valorDia, int valorMes, int valorAnio)
{
	int retorno = 0;
	int fechaCorrecta = 0;


	    if ( valorMes >= 1 && valorMes <= 12 )
	    {
	        switch ( valorMes )
	        {
	            case  1 :
	            case  3 :
	            case  5 :
	            case  7 :
	            case  8 :
	            case 10 :
	            case 12 :
	            	if ( valorDia >= 1 && valorDia <= 31 )
	            			{
	                          fechaCorrecta = 1;
	            			}
	                      break;

	            case  4 :
	            case  6 :
	            case  9 :
	            case 11 :
	            	if ( valorDia >= 1 && valorDia <= 30 )
	            			{
	            				fechaCorrecta = 1;
	            			}
	                      break;

	            case  2 :
	            	if ( valorDia >= 1 && valorDia <= 29 )
	            			{
	            	 	 	 	 fechaCorrecta = 1;
	            			}
	        }
	    }

	    if(fechaCorrecta)
	    {
	    	retorno = 1;
	    }

	return retorno;
}

int confirmaSalida(char* pRespuesta, char confirma, char rechaza)
{
	int retorno=0;
	char rta;

	if(pRespuesta!=NULL)
	{
		printf("Si abandona el programa se eliminaran todos los datos.\n¿Desea continuar? s(si) n(no)\n");
		fpurge(stdin);
		scanf("%c", &rta);
		if(rta=='s'){
			*pRespuesta = confirma;
		}
		else
		{
			*pRespuesta = rechaza;
		}
		retorno=1;
	}

	return retorno;
}
