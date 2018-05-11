#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED
typedef struct
{
    int idCliente;
    int numeroRubro;
    char textoAviso[64];
    int estado;

    //------------
    int idPublicacion;
    int isEmpty;
}Publicacion;
#endif // PANTALLA_H_INCLUDED


int publicacion_init(Publicacion* arrayP,int limite);
int publicacion_mostrar(Publicacion* arrayP,int limite);
int publicacion_mostrarDebug(Publicacion* arrayP,int limite);
int publicacion_alta(Publicacion* arrayP,int limite,int id);
//int publicacion_baja(Publicacion* arrayP,int limite, int id);
//int publicacion_modificacion(Publicacion* arrayP,int limite, int id);
int publicacion_ordenar(Publicacion* arrayP,int limite, int orden);
int publicacion_buscarPorId(Publicacion* arrayP,int limite, int id);
int publicacion_altaForzada(Publicacion* arrayP,int limite,char* nombre,char* direccion, float precio, int tipo);
//int buscarLugarLibre(Publicacion* arrayP,int limite);
//int proximoId();
//int publicacion_buscarPorId(Publicacion* arrayP,int limite, int id);

