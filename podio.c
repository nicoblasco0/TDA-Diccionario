#include "podio.h"

void podioCrear(tPodio* pp, size_t n)
{
    pp->lista = NULL;
    pp->n = n;
}

void podioVaciar(tPodio* pp)
{
    tNodoPod **pl, *elim;
    pl = &(pp->lista);

    elim = *pl;
    while(*pl)
    {
        *pl = elim->sig;
        free(elim->info);
        free(elim);
        elim = *pl;
    }

}



int podioInsertarOrdenado(tPodio* pp, void * pd, size_t tamElem, Cmp cmp)
{
    tNodoPod **pl = &(pp->lista);

    tNodoPod *nue;
    tNodoPod *elim;

    int rc;
    int cont = 0;

    while (*pl && (rc = cmp(pd, (*pl)->info)) > 0)
    {
        pl = &(*pl)->sig;
        cont++;
    }

    if(cont == pp->n)
        return 0;


    nue = malloc(sizeof(tNodoPod));
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


    while (*pl && cont < pp->n)
    {
        pl = &(*pl)->sig;
        cont++;
    }

    if (*pl)
    {
        elim = *pl;
        *pl = NULL;
        free(elim->info);
        free(elim);

    }

    return TODO_OK;
}


void podioRecorrer(tPodio * pp, Accion accion, void* param)
{
    tNodoPod **pl = &(pp->lista);
    while(*pl)
    {
        accion((*pl)->info, param);
        pl = &(*pl)->sig;
    }
}
