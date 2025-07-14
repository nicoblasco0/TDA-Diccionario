#ifndef PODIO_H_INCLUDED
#define PODIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TODO_OK 1
#define SIN_MEM -3
typedef struct sNodoPod
{
    void* info;
    size_t tam;
    struct sNodoPod* sig;
}tNodoPod;

typedef struct
{
    tNodoPod* lista;
    size_t n;

}tPodio;


typedef int (*Cmp)(const void*, const void*);
typedef void (*AccionPod)(void* elem, void* param);

void podioCrear(tPodio* pp, size_t n);
void podioVaciar(tPodio* pp);
void podioRecorrer(tPodio * pp, AccionPod accion, void* param);
int podioInsertarOrdenado(tPodio* pp, void * pd, size_t tamElem, Cmp cmp);
void podioMostrar(tPodio* pp, Cmp cmp, AccionPod mostrar);


#endif // PODIO_H_INCLUDED
