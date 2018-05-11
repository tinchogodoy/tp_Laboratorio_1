#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                printf("\n\nCuit: %s - Unitario: %.2f - Total: %.2f - Dias: %d\n",
                                    arrayC[i].cuit,
                                    pantallas[indexPantalla].precio,
                                    (arrayC[i].dias * pantallas[indexPantalla].precio),
                                    arrayC[i].dias );
            }
        }

        retorno = 0;
    }
    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    printf("\nCuit: %s - Nombre: %s - Video: %s - Dias: %d\n",
                                        arrayC[i].cuit,
                                        pantallas[indexPantalla].nombre,
                                        arrayC[i].archivo,
                                        arrayC[i].dias );
                }

        }

        retorno = 0;
    }
    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int indexPantalla;
    char ultimoCuit[50];


    cont_ordenarCuit(arrayC,limite,0);
    strcpy(ultimoCuit,"");
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    if(strcmp(ultimoCuit,arrayC[i].cuit) != 0)
                    {
                        printf("\nCuit: %s", arrayC[i].cuit);
                        strcpy(ultimoCuit,arrayC[i].cuit);
                    }

                    indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    printf("\nCuit: %s - Nombre: %s - Video: %s - Dias: %d\n",
                                        arrayC[i].cuit,
                                        pantallas[indexPantalla].nombre,
                                        arrayC[i].archivo,
                                        arrayC[i].dias );

                }


        }

        retorno = 0;
    }
    return retorno;
}

int informar_ListarCantidadContratacionesPorClienteImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)//11.
{
    int retorno = -1;
    int i;
    int indexPantalla;
    char ultimoCuit[50];
    int cantContrataciones=0;
    float auxImporte=0;
    cont_ordenarCuit(arrayC,limite,0);
    strcpy(ultimoCuit,"");
    if(limite > 0 && arrayC != NULL)
    {

        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    if(strcmp(ultimoCuit,arrayC[i].cuit) != 0)
                    {
                        printf("\n\nCuit: %s", arrayC[i].cuit);
                        strcpy(ultimoCuit,arrayC[i].cuit);
                    }
                    cantContrataciones++;
                    indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    auxImporte=auxImporte+(arrayC[i].dias * pantallas[indexPantalla].precio);

                    if(strcmp(ultimoCuit,arrayC[i+1].cuit) != 0)
                    {
                         printf("\nCant.Contrataciones: %d - Total: %.2f",
                                    cantContrataciones,
                                    auxImporte);
                        auxImporte=0;
                        cantContrataciones=0;
                    }
                }
        }
        retorno = 0;
    }
    return retorno;
}

int informar_ListarCantMaxContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    //int indexPantalla;
    char ultimoCuit[50];
    int cantContrataciones=0;
    //float auxImporte=0;
    mayorContrataciones=0;
    cont_ordenarCuit(arrayC,limite,0);
    strcpy(ultimoCuit,"");
    if(limite > 0 && arrayC != NULL)
    {
        for(i=0; i<limite;i++)
        {
                if(!arrayC[i].isEmpty)
                {
                    if(strcmp(ultimoCuit,arrayC[i].cuit) != 0)
                    {
                        printf("\n\nCuit: %s", arrayC[i].cuit);
                        strcpy(ultimoCuit,arrayC[i].cuit);
                    }
                    cantContrataciones++;
                   // indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                    //auxImporte=auxImporte+(arrayC[i].dias * pantallas[indexPantalla].precio);

                    if(strcmp(ultimoCuit,arrayC[i+1].cuit) != 0)
                    {
                             if(cantContrataciones>mayorContrataciones)
                             {
                                mayorContrataciones=cantContrataciones;
                                cantContrataciones=0;
                             }



                        printf("\n Mayor Cant.Contrataciones: %d - Total: %.2f",
                                        cantContrataciones,
                                        auxImporte);
                       // auxImporte=0;
                       // cantContrataciones=0;
                    }
                }
        }
        retorno = 0;
    }
    return retorno;
}
