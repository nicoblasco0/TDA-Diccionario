#include "diccionario.h"
#include <stdint.h>
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

int ponerDiccionario(tDiccionario* dic, void* clave, void* elem, size_t tamElem, Cmp cmp, Actualizar actualizar)
{
    size_t hashValue, indice;

    //Primero queremos saber en que lista vamos a insertar el elemento
    hashValue = dic->hashFunc(clave);
    indice = hashValue % dic->capMax;

    //Ahora insertamos el elemento en esa lista
    return listaInsertarOrdenado(&(dic->ini[indice]), elem, tamElem, cmp, actualizar);
}

int sacarDiccionario(tDiccionario* dic, void* clave, Cmp cmp)
{
    size_t hashValue, indice;

    hashValue = dic->hashFunc(clave);
    indice = hashValue % dic->capMax;

    return listaSacarOrdenado(&(dic->ini[indice]), clave, cmp);
}

int obtenerDiccionario(tDiccionario* dic, void* clave, void* pd, size_t tamElem, Cmp cmp)
{
    size_t hashValue, indice;

    hashValue = dic->hashFunc(clave);
    indice = hashValue % dic->capMax;

    return listaObtenerOrdenado(&(dic->ini[indice]), pd, tamElem, cmp);
}

bool esPrimo(size_t n)
{
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    for (size_t i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

size_t proximoPrimo(size_t n)
{
    while (!esPrimo(n)) {
        n++;
    }
    return n;
}

size_t HASH_STRING(const void* clave)
{
    const char* str = (const char*)clave;
    size_t hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c

    return hash;
}

size_t HASH_INT(const void* clave)
{
    const int* i = (const int*)clave;
    return (size_t)(*i);
}

size_t HASH_FLOAT(const void* clave)
{
    const float* f = (const float*)clave;
    union {
        float f;
        uint32_t i;
    } conv;

    conv.f = *f;
    return (size_t)(conv.i);
}


void mostrarBucketsDiccionario(tDiccionario* dic, Accion accion)
{
    for(int i = 0 ; i < dic->capMax ; i++)
    {
        printf("bucket %d: ", i+1);
        listaRecorrer(&(dic->ini[i]), accion, NULL);
        printf("\n");
    }
}
