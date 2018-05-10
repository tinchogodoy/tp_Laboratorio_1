#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
#define ITEM 20
#define AZ 0
#define ZA 1
int main()
{
    Epersona arrayPersonas[ITEM];
    int dni;
    char seguir='s';
    int opcion=0;
    int rtaScanf;
    /*per_init(arrayPersonas,ITEM);
    strcpy(arrayPersonas[0].nombre,"Gerardo");
    strcpy(arrayPersonas[1].nombre,"Pablo");
    strcpy(arrayPersonas[2].nombre,"German");
    strcpy(arrayPersonas[3].nombre,"Jose");
    strcpy(arrayPersonas[4].nombre,"alfredo");
    strcpy(arrayPersonas[5].nombre,"Carlos");
    strcpy(arrayPersonas[6].nombre,"Ariel");
    strcpy(arrayPersonas[7].nombre,"Cesar");
    strcpy(arrayPersonas[8].nombre,"Pablo");
    strcpy(arrayPersonas[9].nombre,"Ezequiel");
    strcpy(arrayPersonas[10].nombre,"Olivia");
    strcpy(arrayPersonas[11].nombre,"Elena");
    strcpy(arrayPersonas[12].nombre,"Carolina");
    strcpy(arrayPersonas[13].nombre,"Marcos");
    strcpy(arrayPersonas[14].nombre,"Micaela");
    arrayPersonas[0].dni=23456756;
    arrayPersonas[1].dni=23456764;
    arrayPersonas[2].dni=33000984;
    arrayPersonas[3].dni=23765789;
    arrayPersonas[4].dni=12345433;
    arrayPersonas[5].dni=43234565;
    arrayPersonas[6].dni=43456543;
    arrayPersonas[7].dni=45334543;
    arrayPersonas[8].dni=26356632;
    arrayPersonas[9].dni=15345643;
    arrayPersonas[10].dni=3047394;
    arrayPersonas[11].dni=6438927;
    arrayPersonas[12].dni=6835323;
    arrayPersonas[13].dni=4375432;
    arrayPersonas[14].dni=4375431;
    arrayPersonas[0].edad=12;
    arrayPersonas[1].edad=16;
    arrayPersonas[2].edad=18;
    arrayPersonas[3].edad=14;
    arrayPersonas[4].edad=18;
    arrayPersonas[5].edad=9;
    arrayPersonas[6].edad=22;
    arrayPersonas[7].edad=33;
    arrayPersonas[8].edad=31;
    arrayPersonas[9].edad=19;
    arrayPersonas[10].edad=55;
    arrayPersonas[11].edad=64;
    arrayPersonas[12].edad=68;
    arrayPersonas[13].edad=43;
    arrayPersonas[14].edad=36;
    arrayPersonas[0].estado=0;
    arrayPersonas[1].estado=0;
    arrayPersonas[2].estado=0;
    arrayPersonas[3].estado=0;
    arrayPersonas[4].estado=0;
    arrayPersonas[5].estado=0;
    arrayPersonas[6].estado=0;
    arrayPersonas[7].estado=0;
    arrayPersonas[8].estado=0;
    arrayPersonas[9].estado=0;
    arrayPersonas[10].estado=0;
    arrayPersonas[11].estado=0;
    arrayPersonas[12].estado=0;
    arrayPersonas[13].estado=0;
    arrayPersonas[14].estado=0;
    arrayPersonas[0].id=0;
    arrayPersonas[1].id=1;
    arrayPersonas[2].id=2;
    arrayPersonas[3].id=3;
    arrayPersonas[4].id=4;
    arrayPersonas[5].id=5;
    arrayPersonas[6].id=6;
    arrayPersonas[7].id=7;
    arrayPersonas[8].id=8;
    arrayPersonas[9].id=9;
    arrayPersonas[10].id=10;
    arrayPersonas[11].id=11;
    arrayPersonas[12].id=12;
    arrayPersonas[13].id=13;
    arrayPersonas[14].id=14;*/

    while(seguir=='s')
    {
        system("cls");
        printf("\nTrabajo Practico nro 2 MG");
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");


        printf("ingrese una opcion: ");
        fflush(stdin);
        rtaScanf=scanf("%d",&opcion);

        if(rtaScanf !=1)
        {
            printf("No solo numeros \n");
            system("pause");
            continue;
        }

        switch(opcion)
        {
            case 1:
                per_alta(arrayPersonas,ITEM);
                per_mostrar(arrayPersonas,ITEM);
                system("pause");
                break;
            case 2:
                per_mostrar(arrayPersonas,ITEM);
                getValidInt("\nDNI?","\nNumero valida\n",&dni,0,999999999,2);
                per_baja(arrayPersonas,ITEM,dni);
                system("pause");
                break;
            case 3:
                per_ordenarNombre(arrayPersonas,ITEM,AZ);
                per_mostrar(arrayPersonas,ITEM);
                system("pause");
                break;
            case 4:
                per_graficarEdad(arrayPersonas,ITEM);
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
