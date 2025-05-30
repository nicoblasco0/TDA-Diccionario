#include "procesador_texto.h"

bool proximaPalabra(char** cad, char* pal, tTexto* t)
{
    // Saltar caracteres que no son letras, contando espacios y signos
    while (**cad != '\0' && !esLetra(**cad)) {
        if (**cad == ' ')
            t->cantEspacios++;
        else if(**cad != '\n')
            t->cantSignos++;
        (*cad)++;
    }

    // Si llegamos al final sin encontrar una letra
    if (**cad == '\0') {
        *pal = '\0';
        return false;
    }

    // Construir palabra y contar letras
    while (esLetra(**cad)) {
        *pal = **cad;
        (*cad)++;
        pal++;
    }

    *pal = '\0';
    return true;
}

size_t calcularCapacidadDiccionario(const char* rutaArchivo)
{
    FILE* archivoTexto = fopen(rutaArchivo, "rb");
    if (!archivoTexto)
        return 0;  // O podés definir y retornar un ERROR_ARCHIVO

    // Vamos al final del archivo para medir su tamaño
    fseek(archivoTexto, 0, SEEK_END);
    long tamBytes = ftell(archivoTexto);
    fclose(archivoTexto);

    if (tamBytes <= 0)
        return 0;

    // Estimamos la cantidad de palabras
    double estimacionPalabras = (double)tamBytes / PROMEDIO_LETRAS_POR_PALABRA;

    // Ajustamos con el load factor
    double capacidadIdeal = estimacionPalabras / LOAD_FACTOR;

    // Redondeamos hacia el próximo primo
    return proximoPrimo((size_t)ceil(capacidadIdeal));
}

int cmpPalabra(const void* e1, const void* e2)
{
    tPalabra* p1 = (tPalabra*) e1;
    tPalabra* p2 = (tPalabra*) e2;
    return strcmp(p1->palabra, p2->palabra);
}

int cmpApariciones(const void* e1, const void* e2)
{
    tPalabra* p1 = (tPalabra*) e1;
    tPalabra* p2 = (tPalabra*) e2;
    return (p2->cantApariciones - p1->cantApariciones);
}


void actualizarPalabra(void* e1, const void* e2) ///Con e2 actualizamos e1
{
    tPalabra* p1 = (tPalabra*) e1;
    tPalabra* p2 = (tPalabra*) e2;

    p1->cantApariciones += p2->cantApariciones;
}

int procesarTexto(const char* rutaTxt, tDiccionario* dic, tTexto* txt)
{
    FILE* fp = fopen(rutaTxt, "rt");
    if(!fp)
        return ERR_ARCH;

    char buffer[TAM_BUFFER];
    char palabra[TAM_PAL];
    tPalabra infoPal;

    while(fgets(buffer, TAM_BUFFER, fp))
    {
        char* p = buffer;
        while(proximaPalabra(&p, palabra, txt))
        {
            strcpy(infoPal.palabra, palabra);
            infoPal.cantApariciones = 1;

            ponerDiccionario(dic, palabra, infoPal.palabra, sizeof(tPalabra), cmpPalabra, actualizarPalabra);
            txt->cantPalabras++;
        }
    }

    fclose(fp);
    return TODO_OK;
}

void mostrarPalabra(void* e, void* p)
{
    tPalabra* pal = (tPalabra*)e;
    printf("%s(%d)\t", pal->palabra, pal->cantApariciones);
}
