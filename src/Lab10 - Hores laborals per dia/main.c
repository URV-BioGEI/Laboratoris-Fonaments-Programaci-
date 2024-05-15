#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>
#include "funcions.h"
#define DIM 8
#define VECTOR 40
int llegir;
char cadena[VECTOR];
int vector[DIM]={0,0,0,0,0,0,0,0};

int main()
{
int i, maxim, minim, horesf;
i=0;
escriure_taula();
escriure_vector();
cadena_versales();
maxim=max();
minim=min();
horesf=vector[5]+vector[6];
printf("\n L'empresa ");
while (cadena[i]!='\r')
    {
        printf("%c",cadena[i]);
        i++;
    }
printf(" ha tingut:");
printf("\n %i nombre maxim d'incidencies", maxim);
printf("\n %i nombre minim d'incidencies", minim);
printf("\n %i nombre d'incidencies al cap de setmana", horesf);
getch();
system("cls");
main();
return 0;
}



