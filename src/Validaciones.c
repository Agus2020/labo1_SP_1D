#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "ctype.h"


int utn_getEntero(int* pEntero,int reintentos,char* msg,char*msgError,int min,long long int max)
{
    int todoOk = -1;
    int auxInt;

    if(pEntero!=NULL&& msg !=NULL && msgError!=NULL && min<= max && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt<=max)
            {
                *pEntero= auxInt;
                todoOk = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}
int utn_getFlotante(float*pFloat,int reintentos,char* msg,char*msgError,float min,float max)
{
    int todoOk = -1;
    float auxFloat;

    if(pFloat!=NULL&& msg !=NULL && msgError!=NULL && min<= max && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat<=max)
            {
                *pFloat= auxFloat;
                todoOk = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(reintentos >= 0);
    }
    return todoOk;
}

int getCadena(char* pAux,int limite)
{
    char auxString[2000];
    int todoOk =-1;
    if (pAux != NULL && limite >0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);
        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limite)
        {
            strncpy(pAux,auxString,limite);
            todoOk=0;
        }
    }
    return todoOk;
}

int getInt(int* pAux)
{
    char auxString[200];
    int todoOk =-1;
    if(getCadena(auxString,200)==0 && isInt(auxString)==0)
    {
        *pAux=atoi(auxString);
        todoOk=0;
    }
    return todoOk;
}
int isInt(char *pAux)
{
    int todoOk=-1;
    int i=0;
    do
    {
        if(*(pAux+i)<48||*(pAux+i)>57)
        {
            break;
        }
        i++;
    }while (i<strlen(pAux));
    if(i==strlen(pAux))
    {
        todoOk=0;
    }
    return todoOk;
}

int isFloat(char* pAux)
{
    int todoOk=-1;
    int i=0;
    int contadorDePuntos=0;
    do
    {
        if(*(pAux+i)=='.')
        {
            contadorDePuntos++;
            if(contadorDePuntos==2)
            {
                break;
            }
        }
        else if(*(pAux+i)<48||*(pAux+i)>57)
        {
            break;
        }
        i++;
    }while (i<strlen(pAux));
    if(i==strlen(pAux))
    {
        todoOk=0;
    }
    return todoOk;
}

int getFloat(float*pAux)
{
    char auxString[200];
    int todoOk =-1;
    if(getCadena(auxString,200)==0 && isFloat(auxString)==0)
    {
        *pAux=atof(auxString);
        todoOk=0;
    }
    return todoOk;
}

int utn_getCadena(char *pAux,int limite,int reintentos,char* msj,char*msjError){
    int todoOk=-1;
    char auxString[limite];
    if(pAux!=NULL && limite >0 && reintentos >=0){
        do{
            reintentos--;
            printf("%s",msj);
            if(getCadena(auxString,limite)==0 && isLetras(auxString)==0){
                strncpy(pAux,auxString,limite);
                todoOk=0;
                break;
            }else
                printf("%s",msjError);
        }while(reintentos>=0);
    }
    return todoOk;
}

int isLetras(char*pAux){
    int todoOk=-1;
    int i=0;
    if(pAux!=NULL){
        do{
            if((*(pAux+i)<65||*(pAux+i)>90) && (*(pAux+i)<97||*(pAux+i)>122)){
                break;
            }
            i++;
        }while(i<strlen(pAux));
        if(i==strlen(pAux)){
            todoOk=0;
        }
    }
    return todoOk;
}



int pedirCaracter(char* caracter, char* mensaje)
{
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s\n"
				"Confirme la operacion S,N:", mensaje);
		fflush(stdin);
		*caracter = getchar();
		retorno = 0;
	}

	return retorno;
}

void pasarMinuscula(char* cadena)
{
	for (int i = 0; cadena[i] != '\0';i++)
	{
		cadena[i] = tolower(cadena[i]);
	}
}


void pasarMayuscula(char* cadena)
{
	for (int i = 0; cadena[i] != '\0'; i++)
	{
		cadena[i] = toupper(cadena[i]);
	}
}


void clear()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n");
}

int confirmacion(char* cadena)
{
	int ok=-1;
	int index;
	char confirmacion;
	index = pedirCaracter(&confirmacion,cadena);
	if(index!=-1)
	{
		if(confirmacion==83||confirmacion==115)
		{
			ok=0;
		}
	}
	return ok;
}



int systemPause()
{
	int ret=-1;
	fflush(stdin);
	printf("\nPresione una tecla para continuar...\n");
	getchar();
	ret=0;
	return ret;
}
