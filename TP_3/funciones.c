#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"
#define QTY 100

/**\brief Inicializa un array de peliculas
 * \param movieArray puntero al array a inicializar
 * \param longitud del array a inicializar
 * \return 0 si se inicializo ok -1 si no lo logró
 *
 */
 int movie_initArray(EMovie* movieArray, int length)
 {
     int flag=-1;
     int i;
     if(movieArray!=NULL && length>0)
     {
         for(i=0;i<length;i++)
         {
             movieArray[i].isEmpty=1;
         }
     }
     return flag;
 }
 /**\brief Encuentra la primer ocurrencia de un valor solicitado
 * \param movieArray puntero al array en el cual buscar
 * \param cantidadDeElementos Longitud del array
 * \param valor Es el valor a ser hallado
 * \return -1 en caso de Error o la posicion del array buscada
 *
 */
int movie_buscarLibre(EMovie* movieArray,int cantidadDeElementos,int libre)
{
    int i;
    int retorno=-1;
    if(movieArray!=NULL && cantidadDeElementos>0)
    {
        for(i=0; i < cantidadDeElementos; i++)
        {
            if(movieArray[i].isEmpty == libre)
            {
                return i;
            }
        }
    }
    return retorno;
}
/**\brief Busca un elemento en el array por su Id
 * \param movieArray array a recorrer
 * \param arrayLength largo del array
 * \return -1 si no lo encuentra o el indice del mismo si es hallado
 *
 */
int movie_buscarId(EMovie* movieArray,int arrayLenght,int id )
{
    int index=-1;
    int i;

    if(movieArray!=NULL && arrayLenght>0)
    {
        for(i=0; i<arrayLenght; i++)
        {
            if(movieArray[i].idMovie==id && movieArray[i].isEmpty==0 ) //que exista y que este activa
            {
                index=i;
                break;
            }
        }
    }
    return index;
}
 /** \brief Setea los datos de una pelicula
  * \param movieArray Array de estructuras movies
  * \param length longitud del array
  * \param title campo de la estructura que recibe el titulo
  * \param genre campo de la estructura que recibe el genero
  * \param descripcion campo de la estructura que recibe la descripcion de la pelicula
  * \param duracion campo de la estructura que recibe la duracion de la pelicula en minutos
  * \param puntaje campo de la estructura que recibe el valor otorgado al puntaje
  * \param linkImage campo de la estructura que recibe el link de la imagen de la misma
  * \param idMovie campo de la estructura que recibe el id de la pelicula a setear
  * \return -1 en caso de error 0 si todo Ok
  *
  */
 int movie_guardaParametros(EMovie* movieArray,int length,char* titulo,char* genero ,char* descripcion,int duracion,int puntaje,char* linkImagen ,int idMovie)
 {
     int retorno=-1;
     int index;
     if(movieArray!=NULL && length>0)
     {
        index=movie_buscarLibre(movieArray,length,1);
        if(index==-1)
        {
            printf("\nNo queda espacio\n");
            system("pause");
            return retorno;
        }
        else
        {
            movieArray[index].idMovie=idMovie;
            strcpy(movieArray[index].titulo,titulo);
            strcpy(movieArray[index].genero,genero);
            movieArray[index].duracion=duracion;
            strcpy(movieArray[index].descripcion,descripcion);
            movieArray[index].puntaje=puntaje;
            strcpy(movieArray[index].linkImagen,linkImagen);
            movieArray[index].isEmpty=0;
            retorno=0;
            printf("\nCarga y seteo exitosos!!");
        }
     }
    return retorno;
 }
/** \brief Solicita los datos de la pelicula a ingresar
 * \param puntero a la estructura a cargar
 * \param longitud del array de estructuras
 * \return 0 si todo Ok -1 en caso de Error -2 error id
 *
 */
 int movie_cargaUsuarioParametros(EMovie* movieArray,int length)
 {
     int auxPuntaje;
     int auxDuracion;
     int i,id;
     static int maximoId=0;
     int retorno=-1;
     int flag=0;
     int todoOk=-1;
     char auxTitulo[500];
     char auxLinkImage[500];
     char auxGenero[500];
     char auxDescripcion[500];

     if(movieArray!=NULL && length>0)
     {
       for(i=0; i<length; i++)
        {
            if(movieArray[i].isEmpty==0 ) //que exista y que este activa
            {
                id=movieArray[i].idMovie;
                if(id >= 0)
                {
                    if(id > maximoId)
                    {
                        maximoId = id;
                    }
                }
            }
        }
        maximoId++;
     }
     else
     {
         printf("\nError ID!!! \n");
         retorno=-2;
     }
     printf("\nIngrese titulo de la Pelicula: \n");
     fflush(stdin);
     gets(auxTitulo);
     while(strlen(auxTitulo)>50)
     {
         printf("\nEl largo del titulo supera el limite. Reingrese no mas de 50 caracteres: ");
         fflush(stdin);
         gets(auxTitulo);
     }
     while(flag==0)
     {
         getValidString("\nIngrese el genero de la pelicula: \n","\nError genero solo debe contener letras. ","\nError genero solo debe contener 50 letras. ",auxGenero, 50,2);
         if(strlen(auxGenero)>49)
         {
             printf("\nEl genero es demasiado extenso.Reingrese: \n");
             fflush(stdin);
             system("pause");
             continue;
         }
         flag=1;
     }
     printf("\nIngrese descripcion de la Pelicula: \n");
     fflush(stdin);
     gets(auxDescripcion);
     while(strlen(auxDescripcion)>200)
     {
             printf("\nLa descripcion es demasiado extensa.Reingrese... \n");
             fflush(stdin);
             gets(auxDescripcion);
             system("pause");
             continue;
     }
     fflush(stdin);
    getValidInt("\nIngrese puntaje 1-100: ","\nError Reingrese puntaje...",&auxPuntaje,0,100,2);
    printf("Ingrese Link de imagen: \n");
    fflush(stdin);
    gets(auxLinkImage);
    while(strlen(auxLinkImage)>400)
    {
        printf("\nEl link ingresado es demasiado extenso.Reingrese...");
        fflush(stdin);
        gets(auxLinkImage);
        system("pause");
        continue;
    }
    getValidInt("\nIngrese duracion en minutos 20-360: ","\nError Reingrese duracion (20 a 360min.)...",&auxDuracion, 20, 360, 2);
    printf("\n\nIngresado: \nPelicula: %s \nGenero: %s \nDescripcion: %s \nPuntaje: %d \nLink de Imagen: %s \nDuracion: %d\n",auxTitulo,auxGenero,auxDescripcion,auxPuntaje,auxLinkImage,auxDuracion);
    system("pause");
    todoOk=movie_guardaParametros(movieArray,length,auxTitulo,auxGenero,auxDescripcion,auxDuracion,auxPuntaje,auxLinkImage,maximoId);
    retorno=todoOk;
    return retorno;
 }
 /** \brief Muestra un listado de peliculas activas
  * \param movieArray Array de peliculas a listar
  * \param length Longitud del array
  * \return void
  *
  */
 void movie_mostrar(EMovie* movieArray,int length)
 {
     int i;
     if(movieArray!=NULL && length>0)
     {
         for(i=0;i<length;i++)
         {
             if(movieArray[i].isEmpty==0)
             {
                 printf("\n\tTitulo: %s\n\tIdPelicula: %d\n\tGenero: %s\n\tDuracion: %d\n\tPuntaje: %d\n\tDescripcion: %s\n\tLink de Imagen: %s\n",movieArray[i].titulo,movieArray[i].idMovie,movieArray[i].genero,movieArray[i].duracion,movieArray[i].puntaje,movieArray[i].descripcion,movieArray[i].linkImagen);
             }
         }
     }
 }
 /**\brief Da de baja a una pelicula ingresada por id
  * \param movieArray Puntero al array donde buscar la pelicula
  * \param length Longitud del array
  * \return -1 ante error 0 si la baja fue exitosa
  *
  */
 int movie_eliminarMovie(EMovie* movieArray,int length)
 {
     int i,respuesta,retorno=-1;
     int auxId;
     if(movieArray!=NULL && length>0)
     {
         printf("   ID  -        TITULO        \n\n");
        for(i=0;i<length;i++)
        {
          if(movieArray[i].isEmpty==0)
          {
              printf("%6d %20s \n",movieArray[i].idMovie,movieArray[i].titulo);
          }
        }
        getValidInt("Ingrese ID a dar de baja: ","Error Reingrese Id: ",&auxId,0,QTY,2);
        retorno=movie_buscarId(movieArray,length,auxId);
        if(retorno==-1)
        {
            printf("\nError.No se encontro la pelicula ");
        }
        else
        {
            printf("\nUsted dara de baja a la Pelicula: %s -Id Movie: %d\n Confirma la baja? 1=Si 2=No\n",movieArray[retorno].titulo,movieArray[retorno].idMovie);
            fflush(stdin);
            scanf("%d",&respuesta);
            if(respuesta==1)
            {
                movieArray[retorno].isEmpty=1;
                printf("\nBaja exitosa\n");
                system("pause");
            }
            else
            {
                printf("\nLa pelicula no se dio de baja\n\n");
                system("pause");
            }
         }
     }
     return retorno;
 }
/**\brief Permite modificar los campos de una estructura EMovie
 * \param movieArray Puntero al array de estructuras
 * \param length Longitud del array
 * \return -1 en caso de error y 0 si esta todo Ok
 *
 */
 int movie_modificarMovie(EMovie* movieArray,int length)
 {
    int i;
    int index;
    int auxId=-1;
    int auxPuntaje;
    int auxDuracion;
    int retorno=-1;
    int opcion;
    char auxTitle[100];
    char auxDescripcion[200];
    char auxGenero[20];
    char auxLinkImagen[200];
    if(movieArray!=NULL && length>0)
     {
         printf("   ID  -        TITULO       \n\n");
          for(i=0;i<length;i++)
          {
              if(movieArray[i].isEmpty==0)
              {
                  printf("%6d %20s\n",movieArray[i].idMovie,movieArray[i].titulo);
              }
          }
          getValidInt("Ingrese ID: ","Error Reingrese Id: ",&auxId,0,QTY,2);
          index=movie_buscarId(movieArray,length,auxId);
          if((index)==-1)
          {
              printf("error al ingresar ID...");
              opcion=8;
          }
          else
          {
                printf("\nPelicula a modificar: %s Id de pelicula: %d \n",movieArray[index].titulo,movieArray[index].idMovie);
                getValidInt("\n1.TITULO\n2.GENERO\n3.PUNTUACION\n4.DESCRIPCION\n5.DURACION\n6.LINK IMAGEN\n7.SALIR\
                            \nIngrese una opcion: ","\nIngrese una opcion correcta!...", &opcion, 1, 7, 2);
          }
            switch(opcion)
            {
            case 1:
                 system("cls");
                 printf("\n\tMODIFICAR TITULO\n");
                 printf("\nTitulo actual. %s",movieArray[index].titulo);
                 printf("\nIngrese titulo de la Pelicula: \n");
                 fflush(stdin);
                 gets(auxTitle);
                 while(strlen(auxTitle)>50)
                 {
                  printf("\nEl largo del titulo supera el limite.Reingrese no mas de 50 caracteres: ");
                  fflush(stdin);
                  gets(auxTitle);
                 }
                 for(i=0;i<length;i++)
                 {
                    if(movieArray[i].isEmpty==0 && strcmp(movieArray[i].titulo,auxTitle)==0)
                    {
                        printf("\nEl titulo ingresado ya existe\n");
                        system("pause");
                        break;
                    }
                    else
                    {
                        strcpy(movieArray[index].titulo,auxTitle);
                        printf("\nPelicula modificada\nNuevo Titulo: %s Id de pelicula: %d\t\n",movieArray[index].titulo,movieArray[index].idMovie);
                        system("pause");
                        break;
                    }
                }
                break;
             case 2:
                 system("cls");
                 printf("\n\tMODIFICAR GENERO\n");
                 printf("\nGenero actual: %s",movieArray[index].genero);
                 getValidString("\nIngrese el nuevo genero de la pelicula: ","\nError genero solo debe contener letras. ","\nError genero solo debe contener 50 letras.",auxGenero,50,2);
                 if(strlen(auxGenero)>49)
                 {
                     printf("\nEl genero es demasiado extenso.Reingrese: \n");
                     fflush(stdin);
                 }
                 else
                 {
                     strcpy(movieArray[index].genero ,auxGenero);
                     printf("\nPelicula modificada\nTitulo: %s Id de pelicula: %d Genero: %s\t\n",movieArray[index].titulo,movieArray[index].idMovie,movieArray[index].genero);
                 }
                 system("pause");
                 break;
             case 3:
                 system("cls");
                 printf("\n\tMODIFICAR PUNTUACION\n");
                 printf("\nPuntuacion actual: %d",movieArray[index].puntaje);
                 getValidInt("\nIngrese nuevo puntaje: ","Error.Ingreso invalido",&auxPuntaje, 0, 100, 2);
                 movieArray[index].puntaje=auxPuntaje;
                 printf("\nPelicula modificada: %s Id de pelicula: %d Puntaje: %d\n",movieArray[index].titulo,movieArray[index].idMovie,movieArray[index].puntaje);
                 system("pause");
                 break;
             case 4:
                 system("cls");
                 printf("\n\t**MODIFICAR DESCRIPCION**\n");
                 printf("\nDescripcion actual: %s",movieArray[index].descripcion);
                 printf("\nIngrese Nueva descripcion de la Pelicula: \n");
                fflush(stdin);
                gets(auxDescripcion);
                while(strlen(auxDescripcion)>200)
                {
                     printf("\nLa descripcion es demasiado extensa.Reingrese: \n");
                     fflush(stdin);
                     gets(auxDescripcion);
                     system("pause");
                     continue;
                }
                strcpy(movieArray[index].descripcion,auxDescripcion);
                printf("\nPelicula modificada: %s Id de pelicula: %d Descripcion: %s\n",movieArray[index].titulo,movieArray[index].idMovie,movieArray[index].descripcion);
                system("pause");
                break;
             case 5:
                 system("cls");
                 printf("\n\tMODIFICAR DURACION\n");
                 printf("\nDuracion actual: %d",movieArray[index].duracion);
                 getValidInt("\nIngrese nueva duracion (20-360min): ","Error.Ingreso invalido",&auxDuracion, 20, 360, 2);
                 movieArray[index].duracion=auxDuracion;
                 printf("\nPelicula modificada: %s Id de pelicula: %d Duracion: %d\n",movieArray[index].titulo,movieArray[index].idMovie,movieArray[index].duracion);
                 system("pause");
                 break;
             case 6:
                 system("cls");
                 printf("\n\t**MODIFICAR LINK DE IMAGEN**\n");
                 printf("\nLink de Imagen actual: %s",movieArray[index].linkImagen);
                 printf("Ingrese Link de imagen: ");
                 fflush(stdin);
                 gets(auxLinkImagen);
                 while(strlen(auxLinkImagen)>400)
                 {
                 printf("\nEl link ingresado es demasiado extenso.Reingrese");
                 fflush(stdin);
                 gets(auxLinkImagen);
                 system("pause");
                 continue;
                 }
                 strcpy(movieArray[index].linkImagen,auxLinkImagen);
                 printf("\nPelicula modificada: %s Id de pelicula: %d Link de Imagen: %s\n",movieArray[index].titulo,movieArray[index].idMovie,movieArray[index].linkImagen);
                 system("pause");
                 break;
             case 7:
                printf("\nUsted esta por salir del menu modificar\n");
                system("pause");
                break;
             default:
                 printf("\nERROR.Ingreso invalido\n");
                 system("pause");
                 break;
                retorno=0;
         }
     }
     return retorno;
 }
 /** \brief Carga los archivos desde un archivo binario leido
  * \param movieArray Estructura donde se cargan
  * \param length Longitud del array
  * \return 0 si Ok -1 por error
  *
  */
  int movie_cargaArchivoBinario(EMovie* movieArray,int length)
  {
      int retorno=-1;
      FILE* pFile;
      pFile=fopen("bin.dat","rb");
      if(pFile==NULL)
      {
          pFile=fopen("bin.dat","wb");
          if(pFile==NULL)
          {
              printf("No se pudo abrir el archivo");
              system("pause");
              return retorno;
          }
      }
      fread(movieArray,sizeof(EMovie),length,pFile);
      retorno=0;
      fclose(pFile);
      return retorno;
  }
/**\brief Guarda los datos cargados en un archivo binario
 * \param movieArray puntero al array a guardar
 * \param length longitud del array
 * \return void
 *
 */
void movie_guardaBinario(EMovie* movieArray,int length)
{
    FILE* pFile;
    pFile=fopen("bin.dat","wb");
    if(pFile==NULL)
    {
        printf("Error al abrir archivo binario\n");
        exit(1);
    }
    fwrite(movieArray,sizeof(EMovie),length,pFile);
    printf("\nArchivo binario guardado con exito!\n");
    fclose(pFile);
}
/**\brief Genera un archivo HTML
 * \param movieArray puntero al array a guardar
 * \param length longitud del array
 * \return void
 *
 */
void movie_generaHtml(EMovie* movieArray,int length)
{
    int i;
    FILE* pFile;
    pFile=fopen("index.html","w");
    if(pFile==NULL)
    {
        printf("\nError al abrir el archivo\n");
        exit(1);
    }
    for(i=0;i<length;i++)
    {
        if(movieArray[i].isEmpty==0)
        {
            fprintf(pFile,"<article class='col-md-4 article-intro'> <a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>",movieArray[i].linkImagen);
            fprintf(pFile,"</a><h3><a href='#'> %s </a></h3><ul>",movieArray[i].titulo);
            fprintf(pFile,"<li>Género:%s</li> <li>Puntaje:%d</li> <li>Duración:%d</li> </ul>",movieArray[i].genero,movieArray[i].puntaje,movieArray[i].duracion);
            fprintf(pFile,"<p> %s</p></article>",movieArray[i].descripcion);
        }
    }
    fclose(pFile);
    printf("\n Archivo html creado con exito!");
}
