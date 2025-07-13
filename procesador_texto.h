#ifndef PROCESADOR_TEXTO
#define PROCESADOR_TEXTO
#include "diccionario.h"
#include <ctype.h>
#define PROMEDIO_LETRAS_POR_PALABRA 5.9
#define TAM_BUFFER 1024
#define TAM_PAL 33
#define esLetra(c) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z')) ? 1 : 0
#define ERR_ARCH -7


typedef struct
{
    int cantPalabras;
    int cantEspacios;
    int cantSignos;
}tTexto;

typedef struct
{
    char palabra[33];
    int cantApariciones;
}tPalabra;

bool proximaPalabra(char** cad, char* pal, tTexto* t);
size_t calcularCapacidadDiccionario(const char* rutaArchivo);    ///Retorna 0 si el archivo no existe, falla su apertura o esta vacio.
int cmpPalabra(const void* e1, const void* e2);
int cmpApariciones(const void* e1, const void* e2);
void actualizarPalabra(void* e1, const void* e2); ///Con e2 actualizamos e1
int procesarTexto(const char* rutaTxt, tDiccionario* dic, tTexto* txt);
void mostrarPalabra(void* e, void* p);
void mostrarPalabraPodio(void* e, void* p);
void mostrarPalabraBucket(void* e, void* p);
void mostrarMenu();
int procesarArchivo(tDiccionario* dic, tTexto* text);
void mostrarMensajeError(int cod);
void mostrarEstadisticas(tDiccionario* dic, tTexto* text);
void mostrarPodioPalabras(tDiccionario* dic, tPodio* podioPalabras, int n);
void accionPodio (void *elem, void* param);

#endif // PROCESADOR_TEXTO
