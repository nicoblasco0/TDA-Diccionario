#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "lista.h"

typedef size_t (*FuncionHash)(const void*);

typedef struct
{
    size_t capMax;
    tLista* ini;
    FuncionHash hashFunc;
}tDiccionario;

int crearDiccionario(tDiccionario* dic, size_t capMax, FuncionHash hashFunc);
void vaciarDiccionario(tDiccionario* dic);
void recorrerDiccionario(tDiccionario* dic, Accion accion, void* param);
int ponerDiccionario(tDiccionario* dic, void* clave, void* elem, size_t tamElem);
int sacarDiccionario(tDiccionario* dic, void* clave, Cmp cmp);
int obtenerDiccionario(tDiccionario* dic, void* clave, void* pd, size_t tamElem, Cmp cmp);


#endif // DICCIONARIO_H
