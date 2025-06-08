#ifndef PODIO_H_INCLUDED
#define PODIO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void podioCrear(tPodio* pp, size_t n);
void podioVaciar(tPodio* pp);
int cmpApariciones(const void* e1, const void* e2);
int podioInsertarOrdenado(tPodio* pp, void * pd, size_t tamElem, Cmp cmp);
#endif // PODIO_H_INCLUDED
