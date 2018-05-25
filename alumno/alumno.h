typedef struct
{
    char nombre[50];
    float altura;
    int id;
}Alumno;


Alumno* alumno_new();
Alumno* alumno_newParametros(char* nombre,float altura,int id);
void alumno_delete(Alumno* this);
int  alumno_setNombre(Alumno* this, char* nombre);
int  alumno_getNombre(Alumno* this, char* nombre);
int  alumno_setAltura(Alumno* this, float altura);
int alumno_getAltura(Alumno* this, float* altura);
int alumno_setId(Alumno* this,int id);
int alumno_getId(Alumno* this,int* id);


int arrayAlumno_dumpInFile(Alumno* arrayPunterosAlumnos[], int* qtyOcupada, int qtyTotal, char* path);
int arrayAlumno_loadFromFile(Alumno* arrayPunterosAlumnos[], int* qtyOcupada, int qtyTotal, char* path);
void arrayAlumno_add(Alumno* array[],int cantidadMaxima,int* cantidadActual,char* dni, char* nombre, char* apellido, char* cuit,float altura,int id);
Alumno* arrayAlumno_getById (Alumno* array[],int cantidad,int id);
