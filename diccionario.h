#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "lista.h"

typedef size_t (*FuncionHash)(const void*, size_t);

typedef struct
{
    size_t capMax;
    tLista* ini;
    FuncionHash hashFunc;
}tDiccionario;

int crearDiccionario(tDiccionario* dic, size_t capMax, FuncionHash hashFunc);
void vaciarDiccionario(tDiccionario* dic);
void recorrerDiccionario(tDiccionario* dic, Accion accion, void* param);
void ponerDiccionario(tDiccionario* dic, void* elem, size_t tamElem);
size_t hashGenerico(const void* clave, size_t tam);



#endif // DICCIONARIO_H
