#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TODO_OK 1
#define SIN_MEM -3

typedef struct sNodo
{
    void* info;
    size_t tam;
    struct sNodo* sig;
}tNodo;

typedef tNodo* tLista;
typedef void (*Accion)(void* elem, void* param);

void listaCrear(tLista* pl);
void listaVaciar(tLista* pl);
int listaInsertar(tLista* pl, void* elem, size_t tamElem);  //Inserta al principio
void listaRecorrer(tLista * pl, Accion accion, void* param);

#endif // LISTA_H
