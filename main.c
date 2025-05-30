#include <stdio.h>
#include <stdlib.h>
#include "procesador_texto.h"

int main()
{
    tDiccionario dic;
    tLista topN;
    tTexto infoTexto;
    infoTexto.cantEspacios = 0;
    infoTexto.cantPalabras = 0;
    infoTexto.cantSignos = 0;

    size_t capacidadRecomendada = calcularCapacidadDiccionario("prueba1.txt");

    printf("%d", (int)capacidadRecomendada);

    crearDiccionario(&dic, capacidadRecomendada, HASH_STRING);
    procesarTexto("prueba1.txt", &dic, &infoTexto);
    printf("CANTIDAD PALABRAS: %d\nCANTIDAD ESPACIOS: %d\nCANTIDAD SIGNOS: %d", infoTexto.cantPalabras, infoTexto.cantEspacios, infoTexto.cantSignos);
    recorrerDiccionario(&dic, mostrarPalabra, NULL);

    ///hacer top N
    printf("\nEl podio con las 5 palabras mas utilizadas en el texto es: \n");
    listaCrear(&topN);
    recorrerDiccionario_insertarTopN(&dic, &topN, cmpApariciones, actualizarPalabra, 5);
    listaRecorrer(&topN, mostrarPalabra, NULL);
    vaciarDiccionario(&dic);
    listaVaciar(&topN);
    return 0;
}
