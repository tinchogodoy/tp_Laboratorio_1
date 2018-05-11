#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "utn.h"
#include "Cliente.h"
//#include "informar.h"

#define QTY_CLIENTE 100
#define LEN_PUBLICACION 1000

int main()
{
    Publicacion arrayP[LEN_PUBLICACION];
    Cliente arrayC[QTY_CLIENTE];
    int menu;
    int auxiliarId;

    publicacion_init(arrayP,LEN_PUBLICACION);
    cliente_init(arrayC,QTY_CLIENTE);

    /*publicacion_altaForzada(arrayP,LEN_PUBLICACION,"Wilde","Las Flores 50",50,0);
    publicacion_altaForzada(arrayP,LEN_PUBLICACION,"Avellaneda","Belgrano 250",2000,0);
    publicacion_altaForzada(arrayP,LEN_PUBLICACION,"Bernal","Cerrito 300",3000,0);
    publicacion_altaForzada(arrayP,LEN_PUBLICACION,"Quilmes","Lavalle 450",1000,1);
    publicacion_altaForzada(arrayP,LEN_PUBLICACION,"Berazategui","Mitre 150",5000,1);

    cliente_altaForzada(arrayC,QTY_CLIENTE,arrayP,QTY_CLIENTE,"Juan","Perez","20911911915");*/
   /* cliente_altaForzada(arrayC,QTY_CLIENTE,arrayP,QTY_CLIENTE,0,"vidClienteeo1.avi","20911911915",400);
    cliente_altaForzada(arrayC,QTY_CLIENTE,arrayP,QTY_CLIENTE,0,"video2.avi","30911911915",300);
    cliente_altaForzada(arrayC,QTY_CLIENTE,arrayP,QTY_CLIENTE,2,"video3.avi","30911911915",400);
    cliente_altaForzada(arrayC,QTY_CLIENTE,arrayP,QTY_CLIENTE,2,"video4.avi","40911911915",500);
    cliente_altaForzada(arrayC,QTY_CLIENTE,arrayP,QTY_CLIENTE,2,"video5.avi","40911911915",600);*/

    //informar_ConsultaFacturacion(arrayC,LEN_PUBLICACION,arrayP,LEN_PUBLICACION,"20911911915");
   // informar_ListarClientees(arrayC,LEN_PUBLICACION,arrayP,LEN_PUBLICACION);
   // informar_ListarCantidadClienteesImporte(arrayC,LEN_PUBLICACION,arrayP,LEN_PUBLICACION);
   // informar_ListarCantidadClienteesPorClienteImporte(arrayC,LEN_PUBLICACION,arrayP, LEN_PUBLICACION);

    do
    {
        getValidInt("\n\n1.Alta\n2.Modificar\n3.Baja\n4.Publicar\n5.Pausar publicacion\n6.Reanudar publicacion\n7.Imprimir clientes\n8.Imprimir publicaciones\n9.Informar clientes\n10.Informar publicaciones\n11.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                cliente_alta(arrayC,QTY_CLIENTE);
                break;
            case 2:
                getValidInt("ID Cliente?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_modificacion(arrayC,QTY_CLIENTE,auxiliarId);
                break;
            case 3:
                getValidInt("ID Cliente?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_baja(arrayC,QTY_CLIENTE,auxiliarId);

                break;
            case 4:
                getValidInt("ID Cliente?","\nNumero valida\n",&auxiliarId,0,200,2);
                publicacion_alta(arrayP,LEN_PUBLICACION, auxiliarId);

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
                cliente_mostrar(arrayC,QTY_CLIENTE);

                break;
            case 8:
                publicacion_mostrar(arrayP,LEN_PUBLICACION);

                break;
            case 9:

                break;
            case 10:

                break;
        }

    }while(menu != 11);

    return 0;
}
