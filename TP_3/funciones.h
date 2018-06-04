#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
typedef struct{
        int idMovie;
        char titulo[50];
        char genero[50];
        int duracion;
        char descripcion[200];
        int puntaje;
        char linkImagen[400];
        int isEmpty;
}EMovie;
void movie_mostrar(EMovie*,int );
int movie_buscarLibre(EMovie*,int,int );
int movie_buscarId(EMovie*,int,int );
int movie_initArray(EMovie*,int );
int movie_cargaUsuarioParametros(EMovie*,int );
int movie_guardaParametros(EMovie*,int,char*,char*,char*,int,int,char*,int );
int movie_eliminarMovie(EMovie*,int );
int movie_modificarMovie(EMovie*,int );
int movie_cargaArchivoBinario(EMovie*,int );
void movie_guardaBinario(EMovie*,int );
void movie_generaHtml(EMovie*,int );
#endif // FUNCIONES_H_INCLUDED
