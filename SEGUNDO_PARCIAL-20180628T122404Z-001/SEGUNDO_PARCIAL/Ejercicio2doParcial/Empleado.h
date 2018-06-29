#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;
int em_trabajaMasDe120Horas(void* item);
Empleado* em_new();
Empleado* em_newParametros(char* id, char* nombre, char* horasTrabajadas/*,int sueldo, char* email, char* genero, char* profesion, char* nacionalidad, char* usuario,*/ );
void em_delete(Empleado* this);
//int em_calcularSueldo(void* this);
int em_setNombre(Empleado* this,char* nombre);
int em_getNombre(Empleado* this,char* nombre);
int em_setHorasTrabajadas(Empleado* this,char* horasTrabajadas);
int em_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);
int em_setSueldo(Empleado* this,int sueldo);
int em_getSueldo(Empleado* this,int* sueldo);
int em_setId(Empleado* this,char* id);
int em_getId(Empleado* this,int* id);




#endif // EMPLEADO_H_INCLUDED
