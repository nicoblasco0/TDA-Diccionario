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

int cmpApariciones(const void* e1, const void* e2)
{
    tPalabra* p1 = (tPalabra*) e1;
    tPalabra* p2 = (tPalabra*) e2;

    if(p2->cantApariciones == p1->cantApariciones)
        return strcmp(p1->palabra, p2->palabra);
    return (p2->cantApariciones - p1->cantApariciones);
}


int podioInsertarOrdenado(tPodio* pp, void * pd, size_t tamElem, Cmp cmp)
{
    tNodoPod *pl = pp->lista;
    tLista *p = pl;
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


    while (*pl && cont < n)
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
