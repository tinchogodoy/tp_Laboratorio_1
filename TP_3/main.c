#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define QTY 100

int main()
{
    char seguir='s';
    EMovie arrayMovie[QTY];
    movie_initArray(arrayMovie,QTY);
    movie_cargaArchivoBinario(arrayMovie,QTY);
    int menu;
    while(seguir=='s')
    {
        system("cls");
        getValidInt(
                "  TP nro 3:\
                   \n1. AGREGAR PELICULA\
                   \n2. BORRAR PELICULA\
                   \n3. MODIFICAR PELICULA\
                   \n4. GENERAR PAGINA WEB\
                   \n5. SALIR\
                    \nIngrese una opcion: ","\nIngrese una opcion correcta!...", &menu, 1, 5, 2);
        switch(menu)
        {
        case 1:
            system("cls");
            printf("\n\tAGREGAR PELICULA\t\n");
            movie_cargaUsuarioParametros(arrayMovie,QTY);
            movie_guardaBinario(arrayMovie,QTY);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("\n\tBORRAR PELICULA\t\n");
            movie_eliminarMovie(arrayMovie,QTY);
            movie_guardaBinario(arrayMovie,QTY);
            system("pause");
            break;
        case 3:
            system("cls");
            movie_generaHtml(arrayMovie,QTY);
            printf("\n\tMODIFICAR PELICULA\t\n");
            movie_modificarMovie(arrayMovie,QTY);
            movie_guardaBinario(arrayMovie,QTY);
            system("pause");
            break;
        case 4:
            system("cls");
            printf("\n\tGENERAR PAGINA WEB\t\n");
            movie_generaHtml(arrayMovie,QTY);
            system("pause");
            break;
        case 5:
            seguir='n';
            break;
        }
    }
    return 0;
}
