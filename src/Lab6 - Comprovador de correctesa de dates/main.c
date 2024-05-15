#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

int main()
{
    FILE *dades;
    dades = fopen("dades.txt","r");
    int dia, mes, any;
    bool b;
    b=false;
    dia = 0;
    mes = 0;
    any = 0;
    inf:
    if (b==true)
    {
        printf("Hi ha una dada incorrecta!");
        getch();
          fclose(dades);
        return 0;
    }
    if (dades != NULL)
{
    while (!feof(dades))
    {
    fscanf(dades, "%i", &any);
    fscanf(dades, "%i", &mes);
    fscanf(dades, "%i", &dia);
        if ((dia == 0) && (mes == 0) && (any == 0))
    {
        printf("el fitxer esta buit");
        getch();
          fclose(dades);
        return 0;
    }
    if ((dia>31) || (dia==0))
    {
        b=true;
        goto inf;
    }
    if ((mes > 12) || (mes == 0))
    {
        b=true;
        goto inf;
    }
    if (((mes == 2) || (mes == 4) || (mes == 6) || (mes == 9) || ( mes == 11)) && (dia > 30))
    {
        b=true;
        goto inf;
    }
    if ((mes == 2) && (dia > 29))
    {
        b=true;
        goto inf;
    }
    if ((any % 4 != 0) && (dia == 29))
    {
        b=true;
        goto inf;
    }
    if (((any % 100 == 0) && (any % 400 != 0)) && (dia == 29))
    {
        b=true;
        goto inf;
    }
    }
    printf("El fitxer no conte dades erronies");
    getch();
    fclose(dades);
    return 0;
}
    else
 {
     printf("\nEl fitxer no existeix");
     getch();
    fclose(dades);
     return 0;
 }
return 0;
}
