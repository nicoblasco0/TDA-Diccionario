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
    size_t tam;
    struct sNodo* sig;
}tNodo;



typedef tNodo* tLista;

typedef void (*Accion)(void* elem, void* param);
typedef int (*Cmp)(const void*, const void*);
typedef void (*Actualizar)(void*, const void*);

void listaCrear(tLista* pl);
void listaVaciar(tLista* pl);
int listaInsertarOrdenado(tLista * pl, void * pd, size_t tamElem, Cmp cmp, Actualizar);
void listaRecorrer(tLista * pl, Accion accion, void* param);
int listaSacarOrdenado(tLista * pl, void * pd, Cmp cmp);
int listaObtenerOrdenado(tLista * pl, void * pd, size_t tamElem, Cmp cmp);


#endif // LISTA_H
