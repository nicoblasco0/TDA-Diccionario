#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <stdbool.h>
#include <math.h>
#include "lista.h"
#include "podio.h"

#define LOAD_FACTOR 0.75

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
int ponerDiccionario(tDiccionario* dic, void* clave, void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar);
int sacarDiccionario(tDiccionario* dic, void* clave, Cmp cmp);
int obtenerDiccionario(tDiccionario* dic, void* clave, void* pd, size_t tamElem, Cmp cmp);
bool esPrimo(size_t n);
size_t proximoPrimo(size_t n);
size_t HASH_STRING(const void* clave); //djb2
size_t HASH_INT(const void* clave);
size_t HASH_FLOAT(const void* clave);
void mostrarBucketsDiccionario(tDiccionario* dic, Accion accion);
#endif // DICCIONARIO_H
