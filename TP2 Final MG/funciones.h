#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;
    int id;

}Epersona;
#endif // FUNCIONES_H_INCLUDED

int per_init(Epersona* array,int limite);
int per_alta(Epersona* array,int limite);
int per_baja(Epersona* array,int limite, int dni);
int per_buscarPorDni(Epersona* array,int limite, int dni);
int per_mostrar(Epersona* array,int limite);
int per_ordenarNombre(Epersona* array,int limite, int orden);
int per_graficarEdad(Epersona* array,int limite);


