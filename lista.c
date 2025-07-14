#include "lista.h"

void listaDicCrear(tLista* pl)
{
    *pl = NULL;
}



void listaDicVaciar(tLista* pl)
{
    tNodo* elim = *pl;

    while(*pl)
    {
        *pl = elim->sig;
        free(elim->info);
        free(elim->clave);
        free(elim);
        elim = *pl;
    }

}


int listaDicInsertarOrdenado(tLista * pl, void* key, size_t tamKey, void * pd, size_t tamElem, Cmp cmp)
{
    tNodo * nue;
    void* nuevaInfo;
    int rc;
///                        >
    while(*pl && (rc=cmp(key, (*pl)->clave))>0)
        pl = &(*pl)->sig;

    if(*pl && (rc == 0))    ///Pisamos la info ya existente
    {
        nuevaInfo = malloc(tamElem);  //Intermediario para contemplar que si falla el malloc, no perdemos la anterior info.
        if(!nuevaInfo)                //(a diferencia que si haciamos free de la info y reservabamos)
            return SIN_MEM;

        free((*pl)->info);
        memcpy(nuevaInfo, pd, tamElem);
        (*pl)->info = nuevaInfo;
        (*pl)->tamInfo = tamElem;

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
    nue->clave = malloc(tamKey);
    if(!nue->clave)
    {
        free(nue);
        free(nue->info);
        return SIN_MEM;
    }

    nue->tamInfo = tamElem;
    nue->tamClave = tamKey;
    memcpy(nue->info, pd, tamElem);
    memcpy(nue->clave, key, tamKey);
    nue->sig = *pl;

    *pl = nue;

    return TODO_OK;
}



void listaDicRecorrer(tLista * pl, Accion accion, void* param)
{
    while(*pl)
    {
        accion((*pl)->clave, (*pl)->info, param);
        pl = &(*pl)->sig;
    }
}

int listaDicSacarOrdenado(tLista * pl, void * clave, Cmp cmp)
{
    tNodo * elim;
    int rc;
    while(*pl && (rc=cmp(clave, (*pl)->clave))>0)
        pl = &(*pl)->sig;

    if(!*pl || rc)
        return 0; ///NO_EXISTE

    elim = *pl;

    *pl = elim->sig;
    free(elim->info);
    free(elim->clave);
    free(elim);
    return 1;
}

int listaDicObtenerOrdenado(tLista * pl, void* clave, void* pd, size_t tamElem, Cmp cmp)
{
    int rc;
    while(*pl && (rc=cmp(clave, (*pl)->clave)) > 0)
        pl = &(*pl)->sig;

    if(!*pl || rc)
        return 0; ///NO_EXISTE

    memcpy(pd,(*pl)->info, MIN(tamElem, (*pl)->tamInfo));

    return 1;
}
