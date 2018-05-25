#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isValidNombre(char* nombre);
static int isValidAltura(float altura);



Alumno* alumno_new()
{

    return malloc(sizeof(Alumno));
}

Alumno* alumno_newParametros(char* nombre,float altura,int id)
{
    Alumno* auxiliarAlumno = alumno_new();

    if(     !alumno_setNombre(auxiliarAlumno,nombre)
       &&   !alumno_setAltura(auxiliarAlumno, altura)
       &&   !alumno_setId(auxiliarAlumno, id))
    {
         return auxiliarAlumno;
    }
    alumno_delete(auxiliarAlumno);
    return NULL;
}


void alumno_delete(Alumno* this)
{
    free(this);
}

int alumno_setNombre(Alumno* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL && isValidNombre(nombre))
    {
        retorno = 0;
        strcpy(this->nombre,nombre);
    }
    return retorno;
}

int alumno_getNombre(Alumno* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre,this->nombre);
    }
    return retorno;
}


int alumno_setAltura(Alumno* this, float altura)
{
    int retorno = -1;
    if(this != NULL && isValidAltura(altura))
    {
        retorno = 0;
        this->altura = altura;
    }
    return retorno;
}

int alumno_getAltura(Alumno* this, float* altura)
{
    int retorno = -1;
    if(this != NULL && altura != NULL)
    {
        retorno = 0;
        *altura = this->altura;
    }
    return retorno;
}

int alumno_setId(Alumno* this, int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(id >= 0)
        {

            if(id > maximoId)
                maximoId = id;
            this->id = id;
        }
        else
        {
            maximoId++;
            this->id = maximoId;
        }

    }


    return retorno;
}


int alumno_getId(Alumno* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

static int isValidNombre(char* nombre)
{
    return 1;
}

static int isValidAltura(float altura)
{
    return 1;
}








//*************************************

int arrayAlumno_loadFromFile(Alumno* arrayPunterosAlumnos[], int* qtyOcupada, int qtyTotal, char* path)
{
    int retorno = -1;
    char bNombre[4096];
    char bAltura[4096];
    char bId[4096];

    char nombre[50];
    float altura;
    int id;

    FILE* pFile;
    pFile = fopen(path,"r");
    if(pFile != NULL && arrayPunterosAlumnos != NULL && qtyTotal > 0 && *qtyOcupada >= 0 &&  qtyTotal > *qtyOcupada)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bNombre,bAltura,bId);
            printf("%s - %s - %s\n",bNombre,bAltura,bId);
            //Falta validar
            strcpy(nombre, bNombre);
            altura = atof(bAltura);
            id = atoi(bId);

            arrayPunterosAlumnos[*qtyOcupada] = alumno_newParametros(nombre,altura,id);
            (*qtyOcupada)++;
        }
    }
    fclose(pFile);
    return retorno;
}

int arrayAlumno_dumpInFile(Alumno* arrayPunterosAlumnos[], int* qtyOcupada, int qtyTotal, char* path)
{
    int retorno = -1;
    int i;
    char nombre[50];
    float altura;
    int id;

    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL && arrayPunterosAlumnos != NULL && qtyTotal > 0 && *qtyOcupada >= 0 &&  qtyTotal > *qtyOcupada)
    {
        for(i=0;i<*qtyOcupada;i++)
        {
            alumno_getNombre(arrayPunterosAlumnos[i],nombre);
            alumno_getAltura(arrayPunterosAlumnos[i],&altura);
            alumno_getId(arrayPunterosAlumnos[i],&id);
            fprintf(pFile,"%s,%.2f,%d\n",nombre,altura,id);
        }
    }
    fclose(pFile);
    return retorno;
}







Alumno* arrayAlumno_getById (Alumno* array[],int cantidad,int id)
{
    return NULL;
}

void arrayAlumno_add(Alumno* array[],int cantidadMaxima,int* cantidadActual,char* dni, char* nombre, char* apellido, char* cuit,float altura,int id)
{

}

void arrayAlumno_remove(Alumno* array[],int cantidadMaxima,int* cantidadActual, int id)
{

}






