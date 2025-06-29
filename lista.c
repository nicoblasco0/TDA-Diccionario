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


int listaInsertarOrdenado(tLista * pl, void * pd, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    tNodo * nue;
    int rc;
///                        >
    while(*pl && (rc=cmp(pd, (*pl)->info))>0)
        pl = &(*pl)->sig;

    if(*pl && !rc)
    {
        actualizar((*pl)->info, pd);
        return TODO_OK;
    }


    nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
    {
        return SIN_MEM;
    }
    nue->info = malloc(tamElem);
    if(!nue->info)
    {
        free(nue);
        return SIN_MEM;
    }

    nue->tam = tamElem;
    memcpy(nue->info, pd, tamElem);
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

int listaSacarOrdenado(tLista * pl, void * pd, Cmp cmp)
{
    tNodo * elim;
    int rc;
    while(*pl && (rc=cmp(pd, (*pl)->info))>0)
        pl = &(*pl)->sig;

    if(!*pl || rc)
        return 0; ///NO_EXISTE

    elim = *pl;

    *pl = elim->sig;
    free(elim->info);
    free(elim);
    return 1;
}

int listaObtenerOrdenado(tLista * pl, void * pd, size_t tamElem, Cmp cmp)
{
    int rc;
    while(*pl && (rc=cmp(pd, (*pl)->info))>0)
        pl = &(*pl)->sig;

    if(!*pl || rc)
        return 0; ///NO_EXISTE


    memcpy(pd,(*pl)->info, MIN(tamElem, (*pl)->tam));

    return 1;
}
