#include <stdio.h>
#include <stdlib.h>
#include "procesador_texto.h"

int main()
{
    bool finishApp = false;
    bool hayArchivoProcesado = false;
    int opcion, cod, n;
    tDiccionario dic;
    tPodio podioPalabras;
    tTexto infoTexto;

    while(!finishApp)
    {
        fflush(stdin);

        mostrarMenu();
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if(hayArchivoProcesado) //Significa que la persona quiere procesar un 2do o un n archivo.
            {
                vaciarDiccionario(&dic);
                hayArchivoProcesado = false;
            }
            cod = procesarArchivo(&dic, &infoTexto);
            if(cod == TODO_OK)
                hayArchivoProcesado = true;
            break;

        case 2:
            system("cls");
            if(hayArchivoProcesado)
                mostrarEstadisticas(&dic, &infoTexto);
            else
                printf("\nDebe procesar un archivo antes de generar estadisticas.\n");
            break;

        case 3:
            system("cls");
            if(hayArchivoProcesado)
            {
                printf("\nElija el numero de palabras que quiere visualizar en su top de apariciones:\n");
                scanf("%d", &n);
                mostrarTopPalabras(&dic, &podioPalabras, n);
            }
            else
                printf("\nDebe procesar un archivo antes de generar un top N de palabras\n");
            break;

        case 4:
            system("cls");
            if(hayArchivoProcesado)
                mostrarBucketsDiccionario(&dic, mostrarPalabraBucket);
            else
                printf("\nDebe procesar un archivo antes de mostrar los buckets en los que se guardo\n");
            break;

        case 5:
            printf("Saliendo del programa...\n");
            finishApp = true;
            break;

        default:
            system("cls");
            printf("Opcion invalida. Intente de nuevo.\n");
        }
    }

    if(hayArchivoProcesado)
        vaciarDiccionario(&dic);

    return TODO_OK;
}
