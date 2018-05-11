#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "publicacion.h"



//Funciones privadas
static int proximoId(void);
static int buscarPorId(Cliente* arrayC,int limite, int id);
static int buscarLugarLibre(Cliente* arrayC,int limite);
//__________________

/** \brief
 * \param arrayC Publicacion*
 * \param limite int
 * \return int
 *
 */
int cliente_init(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayC[i].isEmpty=1;
        }
    }
    return retorno;
}

/** \brief muestra array de clientes sea isEmpy 0 o 1
 *
 * \param arrayC Cliente* array como parametro
 * \param limite int limite de la array
 * \return int -1 error limite o array, 0 ok
 *
 */
int cliente_mostrarDebug(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            //printf("[DEBUG] - %d - %s - %s - %d - %d\n",arrayC[i].id, arrayC[i].cuit,arrayC[i].archivo,arrayC[i].dias, arrayC[i].isEmpty);
        }
    }
    return retorno;
}

int cliente_mostrar(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty)
                printf("[RELEASE] - %d - %s - %s - %s - %d\n",arrayC[i].idCliente, arrayC[i].cuit, arrayC[i].nombre,arrayC[i].apellido, arrayC[i].isEmpty);
        }
    }
    return retorno;
}

int cliente_imprimir(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty)
                printf("[RELEASE] - %d - %s - %s - %s - %d\n",arrayC[i].idCliente, arrayC[i].cuit, arrayC[i].nombre,arrayC[i].apellido, arrayC[i].isEmpty);
        }
    }
    return retorno;
}
int cliente_alta(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    char cuit[50];
    //int idPant;
   // int posPant;
    //int diaAux;

          if(limite > 0 && arrayC != NULL)
            {
                i = buscarLugarLibre(arrayC,limite);
                if(i >= 0)
                {
                    if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,2))
                    {
                        if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 40",apellido,50,2))
                        {

                                if(!getValidStringCuit("\nCuit? ","\nEso no es un cuit","El maximo es 40",cuit,99999999999,2))
                                {
                                    retorno = 0;
                                    strcpy(arrayC[i].nombre,nombre);
                                    strcpy(arrayC[i].apellido,apellido);
                                    strcpy(arrayC[i].cuit,cuit);

                                    //------------------------------
                                    //------------------------------
                                    arrayC[i].idCliente = proximoId();
                                    arrayC[i].isEmpty = 0;
                                }
                            }
                        }
                    }
                    else
                    {
                        retorno = -3;
                    }
                }
                else
                {
                    retorno = -2;
                }

    return retorno;
}

int cliente_modificacion(Cliente* arrayC,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    int i;
    char nombre[50];
    char apellido[50];
    char cuit[50];

    indiceAModificar = buscarPorId(arrayC,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 40",apellido,50,2))
                {
                        if(!getValidStringCuit("\nCuit? ","\nEso no es un cuit","El maximo es 40",cuit,99999999999,2))
                        {
                            retorno = 0;
                            strcpy(arrayC[i].nombre,nombre);
                            strcpy(arrayC[i].apellido,apellido);
                            strcpy(arrayC[i].cuit,cuit);

                            //------------------------------
                            //------------------------------
                           // arrayC[i].idCliente = proximoId();
                            // arrayC[i].isEmpty = 0;
                        }

                }
            }
    }
    else
    {
        retorno = -3;
    }

    return retorno;
}

int cliente_baja(Cliente* arrayC,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = buscarPorId(arrayC,limite,id);
    if(indiceAEliminar>=0)
    {
        arrayC[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}


static int buscarLugarLibre(Cliente* arrayC,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayC[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}


static int buscarPorId(Cliente* arrayC,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && arrayC[i].idCliente==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_altaForzada(Cliente* arrayC,int limite,char nombre, char apellido,char* cuit)
{
    int retorno = -1;
    int i;
    int posPant;
    if(limite > 0 && arrayC != NULL)
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayC[i].nombre,nombre);
            strcpy(arrayC[i].apellido,apellido);
            strcpy(arrayC[i].cuit,cuit);
            //------------------------------
            arrayC[i].idCliente = proximoId();
            arrayC[i].isEmpty = 0;
           /* posPant = publicacion_buscarPorId(publicacions,lenPublicacions,idPublicacion);
            if(posPant>=0)
            {
                strcpy(arrayC[i].cuit,cuit);
                strcpy(arrayC[i].archivo,archivo);
                //TODO
                arrayC[i].idPublicacion = idPublicacion; // relacion
                arrayC[i].isEmpty=0;
                arrayC[i].id = proximoId();
            }*/
             retorno = 0;
        }

    }
    return retorno;
}


int cliente_ordenarCuit(Cliente* arrayC,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Cliente auxiliarEstructura;

    if(limite > 0 && arrayC != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!arrayC[i].isEmpty && !arrayC[i+1].isEmpty)
                {
                    if((strcmp(arrayC[i].cuit,arrayC[i+1].cuit) > 0 && orden) || (strcmp(arrayC[i].cuit,arrayC[i+1].cuit) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = arrayC[i];
                        arrayC[i] = arrayC[i+1];
                        arrayC[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}








