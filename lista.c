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
                         ///pd es la clave
int listaSacar(tLista * pl, void * pd, Cmp cmp)
{
    tNodo * elim;
    while(*pl && cmp(pd, (*pl)->info)!=0)
        pl = &(*pl)->sig;

    if(!*pl)
        return NO_EXISTE;

    elim = *pl;

    *pl = elim->sig;
    free(elim->info);
    free(elim);
    return TODO_OK;
}

int listaObtener(tLista * pl, void * pd, size_t tam, Cmp cmp)
{
    while(*pl && cmp(pd, (*pl)->info)!=0)
        pl = &(*pl)->sig;

    if(!*pl)
        return NO_EXISTE;

    memcpy(pd, (*pl)->info, MIN(tam, (*pl)->tam));

    return TODO_OK;
}
