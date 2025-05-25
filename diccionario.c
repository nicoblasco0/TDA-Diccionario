#include "diccionario.h"

int crearDiccionario(tDiccionario* dic, size_t capMax, FuncionHash hashFunc)
{
    dic->ini = malloc(sizeof(tLista)*capMax);
    if(!dic->ini)
        return SIN_MEM;

    dic->capMax = capMax;
    dic->hashFunc = hashFunc;

    //Inicializamos cada una de las listas
    for(int i = 0 ; i < capMax ; i++)
    {
        listaCrear(&(dic->ini[i]));
    }

    return TODO_OK;
}

void vaciarDiccionario(tDiccionario* dic)
{
    for(int i = 0 ; i < dic->capMax ; i++)
    {
        listaVaciar(&(dic->ini[i]));
    }

    free(dic->ini);
    dic->capMax = 0;
    dic->ini = NULL;
    dic->hashFunc = NULL;
}

void recorrerDiccionario(tDiccionario* dic, Accion accion, void* param)
{
    for(int i = 0 ; i < dic->capMax ; i++)
    {
        listaRecorrer(&(dic->ini[i]), accion, param);
    }
}

int ponerDiccionario(tDiccionario* dic, void* clave, void* elem, size_t tamElem)
{
    size_t hashValue, indice;

    //Primero queremos saber en que lista vamos a insertar el elemento
    hashValue = dic->hashFunc(clave);
    indice = hashValue % dic->capMax;

    //Ahora insertamos el elemento en esa lista
    return listaInsertar(&(dic->ini[indice]), elem, tamElem);
}

int sacarDiccionario(tDiccionario* dic, void* clave, Cmp cmp)
{
    size_t hashValue, indice;

    hashValue = dic->hashFunc(clave);
    indice = hashValue % dic->capMax;

    return listaSacar(&(dic->ini[indice]), clave, cmp);
}

int obtenerDiccionario(tDiccionario* dic, void* clave, void* pd, size_t tamElem, Cmp cmp)
{
    size_t hashValue, indice;

    hashValue = dic->hashFunc(clave);
    indice = hashValue % dic->capMax;

    return listaObtener(&(dic->ini[indice]), pd, tamElem, cmp);
}
