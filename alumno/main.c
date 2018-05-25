#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#include "utn.h"

void mostrar(Alumno* array[],int cantidad);
void cargar(Alumno** array,int cantidadMaxima,int* cantidadActual);

int main()
{

    Alumno* arrayPunteroAlumnos[4000];
    int qtyActualArrayAlumnos = 0;
    int qtyMaximaArrayAlumnos = 4000;



    //cargar(arrayPunteroAlumnos,qtyMaximaArrayAlumnos,&qtyActualArrayAlumnos);


    int menu;

    do
    {
        getValidInt("\n\n1.descargar desde archivo\n2.Guardar a archivo\n3.Mostrar\n4.Eliminar\n5.Salir\n","\nNo valido\n",&menu,1,5,1);
        switch(menu)
        {
            case 1:
            arrayAlumno_loadFromFile(arrayPunteroAlumnos,&qtyActualArrayAlumnos,
                                     qtyMaximaArrayAlumnos,"archivo.pasteleria");
                break;
            case 2:

                arrayAlumno_dumpInFile(arrayPunteroAlumnos,&qtyActualArrayAlumnos,
                             qtyMaximaArrayAlumnos,"archivo2.pasteleria");
                break;
            case 3:
                mostrar(arrayPunteroAlumnos,qtyActualArrayAlumnos);
                arrayPunteroAlumnos[qtyActualArrayAlumnos] = alumno_newParametros("XX",22,-1);
                qtyActualArrayAlumnos++;
                break;
            case 4:

                break;
            case 5:

                break;


            }

         }while(menu != 5);

    return 0;
}


void cargar(Alumno** array,int cantidadMaxima,int* cantidadActual)
{

}

void mostrar(Alumno* array[],int cantidad)
{
    int i;
    char nombre[50];
    float altura;
    int id;
    for(i=0 ; i<cantidad;i++)
    {
        alumno_getNombre(array[i],nombre);
        alumno_getAltura(array[i],&altura);
        alumno_getId(array[i],&id);
        printf("%s - %f - %d\n",nombre,altura,id);

    }

}

void modificar(Alumno* array[],int cantidad)
{

}
