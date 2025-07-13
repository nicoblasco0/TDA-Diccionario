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

int podioInsertarOrdenado(tPodio* pp, void* pd, size_t tamElem, Cmp cmp)
{
    tNodoPod **pl = &(pp->lista);
    tNodoPod *nue, *elim;

    int cont = 0;   //Cont representa la cantidad de grupos distintos, no la cantidad de elementos.
    int rc;
    void* valorAnterior = NULL;

    while (*pl && (rc = cmp(pd, (*pl)->info)) > 0)
    {
        if (!valorAnterior || cmp((*pl)->info, valorAnterior) != 0) //Comparamos cada elemento contra el anterior valor para detectar cuando aumentar cont.
        {
            cont++;
            valorAnterior = (*pl)->info;
        }
        pl = &(*pl)->sig;
    }

    if (!valorAnterior || cmp(pd, valorAnterior) != 0)
        cont++;

    if (cont > pp->n)
        return 0;

    //Creamos el nodo
    nue = malloc(sizeof(tNodoPod));
    if (!nue) return SIN_MEM;

    nue->info = malloc(tamElem);
    if (!nue->info) {
        free(nue);
        return SIN_MEM;
    }

    nue->tam = tamElem;
    memcpy(nue->info, pd, tamElem);
    nue->sig = *pl;
    *pl = nue;

    //Recalculamos la cantidad de grupos para poder eliminar el ultimo si es que lo hay.
    pl = &(pp->lista);
    valorAnterior = NULL;
    cont = 0;

    while (*pl)
    {
        if (!valorAnterior || cmp((*pl)->info, valorAnterior) != 0)
        {
            cont++;
            if (cont > pp->n)
                break;  //Dejamos a pl en el inicio del grupo n+1, osea el sobrante, para poder eliminarlo

            valorAnterior = (*pl)->info;
        }
        pl = &(*pl)->sig;
    }

    //Eliminamos desde el puntero hacia adelante
    while (*pl)
    {
        elim = *pl;
        *pl = elim->sig;
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

void podioMostrar(tPodio* pp, Cmp cmp, Accion mostrar)
{
    unsigned difEntrePos = 0;
    unsigned pos = 1;
    tNodoPod **pl = &(pp->lista);
    printf("***********************\nPodio\n***********************\n\n");
    while(*pl)
    {
        printf("Pos %d :  ", pos);
        mostrar((*pl)->info, NULL);

        if((*pl)->sig && cmp((*pl)->info, (*pl)->sig->info) == 0)
            difEntrePos ++;
        else
        {
            pos++;
            pos+=difEntrePos;
            difEntrePos = 0;
        }

        pl = &(*pl)->sig;
    }
}
