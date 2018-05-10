#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"
#define OCUPADO 0
#define LIBRE 1

static int buscarLugarLibre(Epersona* array,int limite);
static int proximoId();
/** \brief Obtiene el primer indice libre del array.
 * \param array Epersona* el array se pasa como parametro.
 * \param limite int
 * \return int i el primer indice disponible, -1 error en limite o en la array, -2 no hay espacio libre
 *
 */
static int buscarLugarLibre(Epersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief inicializa como libre toda la array
 *
 * \param array Epersona* se pasa como parametro
 * \param limite int es el limite de la array
 * \return int -1 error de limite o de array, 0 ok
 *
 */
int per_init(Epersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].estado = 1;
        }
    }
    return retorno;
}

/** \brief da de alta una nueva perosona el la array
 * \param array Epersona* es la array como parametro
 * \param limite int es el limite de la array
 * \return int -1 error de limite o array, -2 no hay lugar libre, -3 los datos cargados no son validos, 0 ok
 */
int per_alta(Epersona* array,int limite)
{
    int retorno = -1;
   char nombre[50];
    int edad;
    int dni;
    int indice;
    int id;
    int i;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id=proximoId();
            if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            {
                if(!getValidInt("edad?","Error", &edad,0,99999999,2))
                {
                    if(!getValidInt("DNI?","Error", &dni,0,99999999,2))
                    {
                        for(i=0;i<limite;i++)
                        {
                               if(array[i].estado == OCUPADO && array[i].dni == dni)
                                {
                                    retorno = -2;//dni ya existe
                                    printf("Error! dni existente");
                                    return retorno;
                                }
                        }
                            retorno = 0;
                            strcpy(array[indice].nombre,nombre);
                            array[indice].edad=edad;
                            array[indice].dni=dni;
                            array[indice].id= id;
                            array[indice].estado = OCUPADO;
                     }
                }
            }
        }
    }
    return retorno;
}

/** \brief da de baja una persona
 *
 * \param array Epersona* es la array pasada como parametro
 * \param limite int es el limite de la array
 * \param dni int es el que busca para dar de baja persona
 * \return int -1 error de indice < 0, 0 ok
 *
 */
int per_baja(Epersona* array,int limite, int dni)
{

    int retorno = -1;
    int indice;
    indice = per_buscarPorDni(array,limite,dni);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].estado = LIBRE;
    }
    return retorno;
}

/** \brief busca persona por dni
 *
 * \param array Epersona* es la array como parametro
 * \param limite int es el limite de la array
 * \param dni int es por donde se busca otro igual
 * \return int -1 error en limite o en array, o ok
 *
 */
int per_buscarPorDni(Epersona* array,int limite, int dni)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].estado == OCUPADO && array[i].dni == dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief muestra array con estado de alta
 *
 * \param array Epersona* es la array como parametro
 * \param limite int es el limite de la array
 * \return int -1 error en el limite o en la array
 *
 */
int per_mostrar(Epersona* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        printf("\n   id -   Nombre   -   Edad  -     DNI      - Estado\n");
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado)
            {
               printf(" %4d - %10s -  %5d  -  %10d  -  %2d\n",array[i].id,array[i].nombre,array[i].edad,array[i].dni,array[i].estado );
            }
        }
    }
    return retorno;
}

/** \brief ordena array por nombre
 *
 * \param array Epersona* es la array como parametro
 * \param limite int es el limite de la array
 * \param orden int 0 a-z y 1 z-a.
 * \return int -1 error de limite o array, 0 ok
 *
 */
int per_ordenarNombre(Epersona* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Epersona auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(array[i].estado == OCUPADO && array[i+1].estado == OCUPADO )
                    {
                        if((stricmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden)) //<------------
                        {
                            auxiliar = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }
    return retorno;
}

/** \brief grafica por tres grupos de edades (<18, 19-35, >35)
 *
 * \param array Epersona* es el array como parametro
 * \param limite int es el limite de la array
 * \return int -1 error en el limite o array, 0 ok
 *
 */
int per_graficarEdad(Epersona* array,int limite)
{
    int retorno = -1;
    int flagSwap;
    int i;
    int contUno=0;
    int contDos=0;
    int contTres=0;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(array[i].estado == OCUPADO)
                    {
                        if(array[i].edad<=18) //<------------<18    19-35  >35
                        {
                            contUno++;

                        }else if((array[i].edad>18) && (array[i].edad<36))
                        {
                            contDos++;
                        }else if(array[i].edad>35)
                        {
                            contTres++;
                        }
                    }
            }
        }while(flagSwap);
        printf("\n");
        while(!flagSwap)
        {
            if(contUno>contDos && contUno>contTres)
            {
                printf("  *\n");
                contUno--;
            }else if(contDos>contUno && contDos>contTres)
            {
                printf("         *\n");
                contDos--;
            }else if(contTres>contUno && contTres>contDos)
            {
                printf("                *\n");
                contTres--;
            } else if(contUno==0 && contDos==0 && contTres==0)
            {
                printf("<18    19-35    >35\n");
                flagSwap = 1;
            }else if(contUno==contDos && contDos>contTres)
            {
                printf("  *      *       \n");
                contUno--;
                contDos--;
            }
            else if(contUno==contTres && contTres>contDos)
            {
                printf("  *             *\n");
                contUno--;
                contTres--;
            }
            else if(contDos==contTres && contDos>contUno)
            {
                printf("         *      *\n");
                contDos--;
                contTres--;
            }
            else if(contUno==contDos && contDos==contTres)
            {
                printf("  *      *      *\n");
                contUno--;
                contDos--;
                contTres--;
            }
        }
    }
    return retorno;
}

/** \brief contador que genera un id unico para cada alta
 *
 * \return int retorna el id proximo
 *
 */
static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}


