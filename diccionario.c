#include "diccionario.h"

int crearDiccionario(tDiccionario* dic, size_t capMax, FuncionHash hashFunc)
{
    dic->ini = malloc(sizeof(tLista)*capMax);
    if(!dic->ini)
        return SIN_MEM;

    dic->capMax = capMax;

    //Admitimos una funcion de hash indicada por el usuario, sino usamos la generica
    if (hashFunc == NULL)
        dic->hashFunc = hashGenerico;
    else
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
}

void recorrerDiccionario(tDiccionario* dic, Accion accion, void* param)
{
    for(int i = 0 ; i < dic->capMax ; i++)
    {
        listaRecorrer(&(dic->ini[i]), accion, param);
    }
}

void ponerDiccionario(tDiccionario* dic, void* elem, size_t tamElem)
{
    //Primero queremos saber en que lista vamos a insertar el elemento

}

size_t hashGenerico(const void* clave, size_t tam){
    const unsigned char* bytes = clave;
    size_t hash = 5381;

    for (size_t i = 0; i < tam; i++) {
        hash = ((hash << 5) + hash) + bytes[i]; // hash * 33 + byte actual
    }

    return hash;
}
/*
 * Funci�n: hashGenerico
 * ----------------------
 * Calcula un valor hash a partir de una secuencia arbitraria de bytes, usando una
 * variante del algoritmo DJB2. Es una funci�n gen�rica que puede aplicarse sobre
 * tipos escalares simples o estructuras sin punteros internos.
 *
 * Par�metros:
 *  - clave: puntero al dato a hashear (ej. int*, struct*, etc.)
 *  - tam:   tama�o del dato en bytes (ej. sizeof(int), sizeof(struct Persona))
 *
 * Usar esta funci�n:
 *  - Si tus claves son simples (int, float, structs sin punteros).
 *  - Si no quer�s definir una funci�n hash espec�fica.
 *
 * No usar esta funci�n:
 *  - Si tus claves son strings (char*): us� una funci�n hash espec�fica como DJB2.
 *  - Si tus estructuras contienen punteros: el hash operar� sobre las direcciones,
 *    no sobre el contenido apuntado, lo que puede generar inconsistencias.
 *
 * Ejemplo de uso:
 *   int clave = 123;
 *   size_t h = hash_generico(&clave, sizeof(int));
 */
