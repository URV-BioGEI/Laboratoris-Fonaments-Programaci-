#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    FILE *dades;
    int dia, mes, any, diax, mesx, anyx, abans, despres;
    dades = fopen("dades.txt","r");
    abans=0;
    despres=0;
    if (dades != NULL)
    {
    printf("\nIntrodueix l'any: ");
    scanf ("%i", &anyx);
    printf("Introdueix el mes: ");
    scanf("%i", &mesx);
    printf("Introdueix el dia: ");
    scanf("%i", &diax);
    inf:
    while (!feof(dades))
    {
        fscanf(dades, "%i", &any);
        fscanf(dades, "%i", &mes);
        fscanf(dades, "%i", &dia);
        if (any > anyx)
        {
            despres=despres+1;
            goto inf;
        }
        if ((any > anyx)&&(mes > mesx))
        {
            despres=despres+1;
            goto inf;
        }
        if ((dia > diax)&&(any > anyx)&&(mes > mesx))
        {
            despres=despres+1;
            goto inf;
        }
        if ((dia == diax)&&(any == anyx)&&(mes == mesx))
        {
            abans = abans+1;
            goto inf;
        }
        else
        {
            abans =abans+1;
            goto inf;
        }
    }
    }
    else
    {
        printf("\nel fitxer esta buit, torna-ho a intentar");
        getch();
        main();
    }
    printf("\nNombre de dates abans de temps: %i\nNombre de dates despres de temps: %i", abans, despres);
    getch();
    return 0;
}
