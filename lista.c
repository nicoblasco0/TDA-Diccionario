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

int listaInsertarOrdenadoTopN(tLista * pl, void * pd, size_t tamElem, Cmp cmp, Actualizar actualizar, size_t N)
{
    tLista *p = pl;
    tNodo *nue;
    int rc;
    int cont = 1;

    while (*pl && (rc = cmp(pd, (*pl)->info)) > 0)
        pl = &(*pl)->sig;

    /// Teoricamente, no usariamos actualizar pero lo dejo para que sea generico?) --- Con actualizar da mal, duda.
   /* if(*pl && !rc)
    {
        actualizar((*pl)->info, pd);
        return TODO_OK;
    }*/


    nue = malloc(sizeof(tNodo));
    if (!nue)
    {
        return SIN_MEM;
    }

    nue->info = malloc(tamElem);
    if (!nue->info)
    {
        free(nue);
        return SIN_MEM;
    }
    nue->tam = tamElem;
    memcpy(nue->info, pd, tamElem);
    nue->sig = *pl;
    *pl = nue;

    tLista *iter = p;

    while (*iter && cont < N)
    {
        iter = &(*iter)->sig;
        cont++;
    }

    if (*iter)
    {
        tNodo *elim = (*iter)->sig;
        (*iter)->sig = NULL;
        while (elim)
        {
            tNodo *aux = elim->sig;
            free(elim->info);
            free(elim);
            elim = aux;
        }
    }

    return TODO_OK;
}

/*
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
*/
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
                         ///pd es la clave
/*int listaSacar(tLista * pl, void * pd, Cmp cmp)
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
*/

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
/*
int listaObtener(tLista * pl, void * pd, size_t tam, Cmp cmp)
{
    while(*pl && cmp(pd, (*pl)->info)!=0)
        pl = &(*pl)->sig;

    if(!*pl)
        return NO_EXISTE;

    memcpy(pd, (*pl)->info, MIN(tam, (*pl)->tam));

    return TODO_OK;
}
*/
