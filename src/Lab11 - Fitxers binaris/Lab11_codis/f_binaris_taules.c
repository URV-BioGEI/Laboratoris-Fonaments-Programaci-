/*----------------------------------------------------------------
|	Autor: Professors de Fonaments de Programacio
|	Data: Novembre 2015                 Versio: 1.0
|-----------------------------------------------------------------|
|	Nom fitxer: fitxers_binaris
|   Descripcio del Programa: exemple d'us de fitxers binaris
|
| ----------------------------------------------------------------*/

/* Incloure E/S i Llibreries Standard */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Definicio de constants */
#define NOM_FITX1   ".\\taula.bin"
#define DIM         10

int main()
{
    double notes[DIM], nota;
    int i, num;
    FILE *f;

    srand(time(NULL));
    /* Operador sizeof */
    printf("\nMida d'un double: %ld", sizeof(double) );
    printf("\nMida total de la taula: %ld", sizeof(notes) );
    num = sizeof(notes)/sizeof(notes[0]);
    printf("\nNombre d'elements de la taula: %d (=%ld)",num, sizeof(notes)/sizeof(double) );
    printf ("\n\nEscriure taula a un fitxer binari:\n\t");
    for (i=0; i<DIM; i++)
    {
        nota = ((float)(rand()%101))/10;
        printf("%.2f, ", nota);
        notes[i]=nota;
    }
    /* Escriure (afegir) a un fitxer binari: taules */
    f=fopen(NOM_FITX1, "wb");
    if (f!=NULL)
    {
        num = fwrite(notes, sizeof(double), 10, f);
        fclose(f);
    }

    /* Llegir un fitxer binari: taules */
    for (i=0; i<DIM; i++) notes[i]=0;
    printf("\n\nBuidem la taula.\n\t");
    for (i=0; i<DIM; i++)
    {
        printf("%.2f, ", notes[i]);
    }
    printf ("\n\nLlegir un fitxer binari:");
    f=fopen(NOM_FITX1, "rb");
    if (f==NULL)
    {
        printf("\n\tEl fitxer no existeix!");
    }
    else
    {
        num = fread(notes, sizeof(double), 10, f);
        printf("\n\tHem llegit %d dades: \n\t", num);
        fclose (f);
    }
    for (i=0; i<DIM; i++)
    {
        printf("%.2f, ", notes[i]);
    }
    printf("\n");

    return 0;
}
