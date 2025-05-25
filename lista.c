#include "lista.h"

void listaCrear(tLista* pl)
{
    *pl = NULL;
}

void listaVaciar(tLista* pl)
{
    tNodo* elim = *pl;

    while(*pl)
    {
        *pl = elim->sig;
        free(elim->info);
        free(elim);
        elim = *pl;
    }

}

int listaInsertar(tLista* pl, void* elem, size_t tamElem)
{
    tNodo* nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEM;

    nue->info = malloc(tamElem);
    if(!nue->info)
    {
        free(nue);
        return SIN_MEM;
    }

    memcpy(nue->info, elem, tamElem);
    nue->tam = tamElem;

    nue->sig = *pl;
    *pl = nue;

    return TODO_OK;
}

void listaRecorrer(tLista * pl, Accion accion, void* param)
{
    while(*pl)
    {
        accion((*pl)->info, param);
        pl = &(*pl)->sig;
    }
}

int listaSacar(tLista * pl, void * pd, size_t tam, Comparar cmp)
{
    tNodo * elim;
    while(*pl && cmp(pd, (*pl)->info)!=0)
        pl = &(*pl)->sig;

    if(!*pl)
        return -1; ///NO_EXISTE

    elim = *pl;
    memcpy(pd, elim->info, MINIMO(tam, elim->tamInfo));

    *pl = elim->sig;
    free(elim->info);
    free(elim);
    return TODO_OK;
}
