#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "publicacion.h"

#define DEFINE_DEL_ARCHIVO  "hola"

//Funciones privadas
static int proximoId(void);
static int buscarLugarLibre(Publicacion* arrayP,int limite);
//__________________



/** \brief
 * \param arrayP Publicacion*
 * \param limite int
 * \return int
 *
 */
int publicacion_init(Publicacion* arrayP,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayP[i].isEmpty=1;
        }
    }
    return retorno;
}

int publicacion_mostrarDebug(Publicacion* arrayP,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %s - %f - %d - %d\n",arrayP[i].idPublicacion, arrayP[i].numeroRubro,
                   arrayP[i].textoAviso,arrayP[i].estado,arrayP[i].idCliente, arrayP[i].isEmpty);
        }
    }
    return retorno;
}

int publicacion_mostrar(Publicacion* arrayP,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!arrayP[i].isEmpty)
                printf("[RELEASE] - %d - %d - %s - %d - %d - %d\n",arrayP[i].idPublicacion, arrayP[i].numeroRubro,
                   arrayP[i].textoAviso,arrayP[i].estado,arrayP[i].idCliente, arrayP[i].isEmpty);
        }
    }
    return retorno;
}

int publicacion_alta(Publicacion* arrayP,int limite, int id)
{
    int retorno = -1;
    int i;
    int numeroRubro;
    char textoAviso[64];
    int estado;
    if(limite > 0 && arrayP != NULL)
    {
        i = buscarLugarLibre(arrayP,limite);
        if(i >= 0)
        {
            if(!getValidInt("\nNumero rubro? ","\nEso no es un numero",&numeroRubro,0,100,2))
            {
                if(!getValidString("\nTexto del aviso? ","\nError","El maximo es 63 caracteres",textoAviso,63,2))
                {
                        if(!getValidInt("\nEstado? ","\nError",&estado,0,2,2))
                        {
                            retorno = 0;
                            arrayP[i].numeroRubro=numeroRubro;
                            strcpy(arrayP[i].textoAviso,textoAviso);
                            arrayP[i].estado = estado;
                            arrayP[i].idCliente = id;
                            //------------------------------
                            //------------------------------
                            arrayP[i].idPublicacion = proximoId();
                            arrayP[i].isEmpty = 0;
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

    }
    printf("%d",retorno);
    return retorno;
}


/*int publicacion_baja(Publicacion* arrayP,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = publicacion_buscarPorId(arrayP,limite,id);
    if(indiceAEliminar>=0)
    {
        arrayP[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}*/




/*int publicacion_modificacion(Publicacion* arrayP,int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char buffer[50];

    indiceAModificar = publicacion_buscarPorId(arrayP,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
        {
            retorno = 0;
            strcpy(arrayP[indiceAModificar].nombre,buffer);
            //------------------------------
            //TODO
        }
        else
        {
            retorno = -3;
        }
    }
    return retorno;
}*/

int publicacion_ordenar(Publicacion* arrayP,int limite, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Publicacion auxiliarEstructura;

    if(limite > 0 && arrayP != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!arrayP[i].isEmpty && !arrayP[i+1].isEmpty)
                {
                    if((strcmp(arrayP[i].idCliente,arrayP[i+1].idCliente) > 0 && orden) || (strcmp(arrayP[i].idCliente,arrayP[i+1].idCliente) < 0 && !orden)) //******
                    {
                        auxiliarEstructura = arrayP[i];
                        arrayP[i] = arrayP[i+1];
                        arrayP[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

static int buscarLugarLibre(Publicacion* arrayP,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(arrayP[i].isEmpty==1)
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


int publicacion_buscarPorId(Publicacion* arrayP,int limite, int id)
//static int buscarPorId(Publicacion* arrayP,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayP != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!arrayP[i].isEmpty && arrayP[i].idPublicacion==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



/*int publicacion_altaForzada(Publicacion* arrayP,int limite,char* nombre,char* textoAviso)
{
    int retorno = -1;
    int i;

    if(limite > 0 && arrayP != NULL)
    {
        i = buscarLugarLibre(arrayP,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(arrayP[i].nombre,nombre);
            strcpy(arrayP[i].direccion,direccion);
            arrayP[i].precio = precio;
            arrayP[i].tipo = tipo;
            //------------------------------
            //------------------------------
            arrayP[i].idPublicacion = proximoId();
            arrayP[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}*/








