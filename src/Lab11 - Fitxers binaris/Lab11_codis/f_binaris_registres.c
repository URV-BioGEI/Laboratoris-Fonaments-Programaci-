/*----------------------------------------------------------------
|	Autor: Professors de Fonaments de Programacio
|	Data: Novembre 2015                 Versio: 1.0
|-----------------------------------------------------------------|
|	Nom fitxer: f_binaris_registres
|   Descripcio del Programa: exemple d'us de fitxers binaris amb
|       registres.
| ----------------------------------------------------------------*/

/* Incloure E/S i Llibreries Standard */
#include <stdio.h>
#include <stdlib.h>


/* Definicio de constants */
#define NOM_FITX1       ".\\registres.bin"

/* Definicio d'estructures */
typedef struct
{
    int dia,mes,any;
} data_t;


int main()
{
    data_t data1;
    int i, num, num_dates;
    FILE *f;

    /* Operador sizeof */
    printf("\nMida d'un enter: %ld", sizeof(int) );
    printf("\nMida total de l'estructura data_t: %ld (=%ld)", sizeof(data_t), sizeof (data1));

    /* Escriure un fitxer binari: afegir */
    f=fopen(NOM_FITX1, "ab");
    if (f != NULL)
    {
        printf("\n\nQuantes dates vols afegir? ");
        scanf("%d", &num_dates);
        printf("\nIntrodueix %d dates:\n",num_dates);
        for (i=0; i<num_dates; i++)
        {
            printf("dd mm aaaa: ");
            scanf("%i %i %i", &data1.dia, &data1.mes, &data1.any );
            num = fwrite(&data1, sizeof(data1), 1, f);
        }
        fclose(f);
    }

    /* Llegir un fitxer binari */
    printf ("\n\nLlegir un fitxer binari:\n");
    f=fopen(NOM_FITX1, "rb");
    if (f==NULL)
    {
        printf("\nEl fitxer no existeix!");
    }
    else
    {
        num = fread(&data1, sizeof(data1), 1, f);
        while (num!=0)
        {
            printf("\n\t%2d - %2d - %4d", data1.dia, data1.mes, data1.any);
            num = fread(&data1, sizeof(data1), 1, f);
        }
        printf("\n");
        fclose (f);
    }

    return 0;
}
