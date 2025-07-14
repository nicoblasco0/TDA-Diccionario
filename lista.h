#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 1
#define SIN_MEM -3
#define NO_EXISTE -2
#define MIN(X,Y) ((X)<(Y)?(X):(Y))

typedef struct sNodo
{
    void* info;
    void* clave;
    size_t tamInfo;
    size_t tamClave;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;

typedef void (*Accion)(void* clave, void* elem, void* param);
typedef int (*Cmp)(const void*, const void*);

void listaDicCrear(tLista* pl);
void listaDicVaciar(tLista* pl);
int listaDicInsertarOrdenado(tLista * pl, void* key, size_t tamKey, void * pd, size_t tamElem, Cmp cmp);
void listaDicRecorrer(tLista * pl, Accion accion, void* param);
int listaDicSacarOrdenado(tLista * pl, void * clave, Cmp cmp);
int listaDicObtenerOrdenado(tLista * pl, void* clave, void* pd, size_t tamElem, Cmp cmp);



#endif // LISTA_H
